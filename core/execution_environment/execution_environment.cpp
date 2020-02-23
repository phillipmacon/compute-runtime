/*
 * Copyright (C) 2018-2020 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "execution_environment/execution_environment.h"

#include "compiler_interface/compiler_interface.h"
#include "compiler_interface/default_cache_config.h"
#include "debugger/debugger.h"
#include "execution_environment/root_device_environment.h"
#include "gmm_helper/gmm_helper.h"
#include "helpers/hw_helper.h"
#include "opencl/source/built_ins/built_ins.h"
#include "opencl/source/memory_manager/os_agnostic_memory_manager.h"

namespace NEO {
ExecutionEnvironment::ExecutionEnvironment() {
    hwInfo = std::make_unique<HardwareInfo>();
};

ExecutionEnvironment::~ExecutionEnvironment() {
    debugger.reset();
    compilerInterface.reset();
    builtins.reset();
    if (memoryManager) {
        memoryManager->commonCleanup();
    }
    rootDeviceEnvironments.clear();
}

void ExecutionEnvironment::initGmm() {
    if (!gmmHelper) {
        gmmHelper.reset(new GmmHelper(rootDeviceEnvironments[0]->osInterface.get(), hwInfo.get()));
    }
}

void ExecutionEnvironment::setHwInfo(const HardwareInfo *hwInfo) {
    *this->hwInfo = *hwInfo;
}

void ExecutionEnvironment::initializeMemoryManager() {
    if (this->memoryManager) {
        return;
    }

    int32_t setCommandStreamReceiverType = CommandStreamReceiverType::CSR_HW;
    if (DebugManager.flags.SetCommandStreamReceiver.get() >= 0) {
        setCommandStreamReceiverType = DebugManager.flags.SetCommandStreamReceiver.get();
    }

    switch (setCommandStreamReceiverType) {
    case CommandStreamReceiverType::CSR_TBX:
    case CommandStreamReceiverType::CSR_TBX_WITH_AUB:
    case CommandStreamReceiverType::CSR_AUB:
        memoryManager = std::make_unique<OsAgnosticMemoryManager>(*this);
        break;
    case CommandStreamReceiverType::CSR_HW:
    case CommandStreamReceiverType::CSR_HW_WITH_AUB:
    default:
        memoryManager = MemoryManager::createMemoryManager(*this);
        break;
    }
    DEBUG_BREAK_IF(!this->memoryManager);
}

void ExecutionEnvironment::initDebugger() {
    debugger = Debugger::create(hwInfo.get());
}

void ExecutionEnvironment::calculateMaxOsContextCount() {
    for (const auto &rootDeviceEnvironment : this->rootDeviceEnvironments) {
        auto &hwHelper = HwHelper::get(rootDeviceEnvironment->getHardwareInfo()->platform.eRenderCoreFamily);
        auto osContextCount = hwHelper.getGpgpuEngineInstances().size();
        auto subDevicesCount = HwHelper::getSubDevicesCount(rootDeviceEnvironment->getHardwareInfo());
        bool hasRootCsr = subDevicesCount > 1;

        MemoryManager::maxOsContextCount += static_cast<uint32_t>(osContextCount * subDevicesCount + hasRootCsr);
    }
}

GmmHelper *ExecutionEnvironment::getGmmHelper() const {
    return gmmHelper.get();
}
GmmClientContext *ExecutionEnvironment::getGmmClientContext() const {
    return gmmHelper->getClientContext();
}
CompilerInterface *ExecutionEnvironment::getCompilerInterface() {
    if (this->compilerInterface.get() == nullptr) {
        std::lock_guard<std::mutex> autolock(this->mtx);
        if (this->compilerInterface.get() == nullptr) {
            auto cache = std::make_unique<CompilerCache>(getDefaultCompilerCacheConfig());
            this->compilerInterface.reset(CompilerInterface::createInstance(std::move(cache), true));
        }
    }
    return this->compilerInterface.get();
}

BuiltIns *ExecutionEnvironment::getBuiltIns() {
    if (this->builtins.get() == nullptr) {
        std::lock_guard<std::mutex> autolock(this->mtx);
        if (this->builtins.get() == nullptr) {
            this->builtins = std::make_unique<BuiltIns>();
        }
    }
    return this->builtins.get();
}

bool ExecutionEnvironment::isFullRangeSvm() const {
    return hwInfo->capabilityTable.gpuAddressSpace >= maxNBitValue(47);
}

void ExecutionEnvironment::prepareRootDeviceEnvironments(uint32_t numRootDevices) {
    if (rootDeviceEnvironments.size() < numRootDevices) {
        rootDeviceEnvironments.resize(numRootDevices);
    }
    for (auto rootDeviceIndex = 0u; rootDeviceIndex < numRootDevices; rootDeviceIndex++) {
        if (!rootDeviceEnvironments[rootDeviceIndex]) {
            rootDeviceEnvironments[rootDeviceIndex] = std::make_unique<RootDeviceEnvironment>(*this);
        }
    }
}
} // namespace NEO

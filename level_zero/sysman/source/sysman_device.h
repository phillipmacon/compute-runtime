/*
 * Copyright (C) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once
#include "shared/source/execution_environment/execution_environment.h"

#include "level_zero/core/source/device/device.h"
#include <level_zero/ze_api.h>
#include <level_zero/zes_api.h>

namespace L0 {
namespace Sysman {

struct SysmanDevice : _ze_device_handle_t {

    static SysmanDevice *fromHandle(zes_device_handle_t handle) { return static_cast<SysmanDevice *>(handle); }
    inline zes_device_handle_t toHandle() { return this; }
    virtual ~SysmanDevice() = default;
    static SysmanDevice *create(NEO::ExecutionEnvironment &executionEnvironment, const uint32_t rootDeviceIndex);
    virtual const NEO::HardwareInfo &getHardwareInfo() const = 0;
};

} // namespace Sysman
} // namespace L0

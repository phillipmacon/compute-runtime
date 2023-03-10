/*
 * Copyright (C) 2020-2023 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "shared/source/helpers/state_base_address.h"

namespace NEO {

template <typename GfxFamily>
void StateBaseAddressHelper<GfxFamily>::appendStateBaseAddressParameters(
    StateBaseAddressHelperArgs<GfxFamily> &args) {

    if (args.sbaProperties) {
        if (args.sbaProperties->surfaceStateBaseAddress.value != StreamProperty64::initValue) {
            args.stateBaseAddressCmd->setBindlessSurfaceStateBaseAddressModifyEnable(true);
            args.stateBaseAddressCmd->setBindlessSurfaceStateBaseAddress(static_cast<uint64_t>(args.sbaProperties->surfaceStateBaseAddress.value));
            args.stateBaseAddressCmd->setBindlessSurfaceStateSize(static_cast<uint32_t>(args.sbaProperties->surfaceStateSize.value));
        }
    }

    if (!args.useGlobalHeapsBaseAddress && args.ssh) {
        args.stateBaseAddressCmd->setBindlessSurfaceStateBaseAddressModifyEnable(true);
        args.stateBaseAddressCmd->setBindlessSurfaceStateBaseAddress(args.ssh->getHeapGpuBase());
        uint32_t size = uint32_t(args.ssh->getMaxAvailableSpace() / 64) - 1;
        args.stateBaseAddressCmd->setBindlessSurfaceStateSize(size);
    }

    StateBaseAddressHelper<GfxFamily>::appendIohParameters(args);
}

template <typename GfxFamily>
uint32_t StateBaseAddressHelper<GfxFamily>::getMaxBindlessSurfaceStates() {
    return (1 << 20) - 1;
}
} // namespace NEO

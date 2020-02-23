/*
 * Copyright (C) 2019-2020 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "command_stream/preemption.h"
#include "command_stream/preemption.inl"

namespace NEO {

using GfxFamily = TGLLPFamily;

template void PreemptionHelper::programCmdStream<GfxFamily>(LinearStream &cmdStream, PreemptionMode newPreemptionMode,
                                                            PreemptionMode oldPreemptionMode, GraphicsAllocation *preemptionCsr);
template size_t PreemptionHelper::getRequiredPreambleSize<GfxFamily>(const Device &device);
template void PreemptionHelper::programCsrBaseAddress<GfxFamily>(LinearStream &preambleCmdStream, Device &device, const GraphicsAllocation *preemptionCsr);
template void PreemptionHelper::programStateSip<GfxFamily>(LinearStream &preambleCmdStream, Device &device);
template size_t PreemptionHelper::getRequiredStateSipCmdSize<GfxFamily>(const Device &device);
template size_t PreemptionHelper::getRequiredCmdStreamSize<GfxFamily>(PreemptionMode newPreemptionMode, PreemptionMode oldPreemptionMode);
template size_t PreemptionHelper::getPreemptionWaCsSize<GfxFamily>(const Device &device);
template void PreemptionHelper::applyPreemptionWaCmdsBegin<GfxFamily>(LinearStream *pCommandStream, const Device &device);
template void PreemptionHelper::applyPreemptionWaCmdsEnd<GfxFamily>(LinearStream *pCommandStream, const Device &device);
template void PreemptionHelper::programInterfaceDescriptorDataPreemption<GfxFamily>(INTERFACE_DESCRIPTOR_DATA<GfxFamily> *idd, PreemptionMode preemptionMode);
} // namespace NEO

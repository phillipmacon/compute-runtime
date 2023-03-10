/*
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once
#include "shared/source/gen12lp/hw_info_gen12lp.h"

namespace NEO {

struct ADLN;

template <>
struct HwMapper<IGFX_ALDERLAKE_N> {
    enum { gfxFamily = IGFX_GEN12LP_CORE };

    static const char *abbreviation;
    using GfxFamily = GfxFamilyMapper<static_cast<GFXCORE_FAMILY>(gfxFamily)>::GfxFamily;
    using GfxProduct = ADLN;
};
} // namespace NEO

/*
 * Copyright (C) 2020-2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "shared/source/gen9/hw_cmds_cfl.h"
#include "shared/source/gen9/hw_info.h"

#include "level_zero/core/source/image/image_hw.inl"

namespace L0 {

template <>
struct ImageProductFamily<IGFX_COFFEELAKE> : public ImageCoreFamily<IGFX_GEN9_CORE> {
    using ImageCoreFamily::ImageCoreFamily;
};

static ImagePopulateFactory<IGFX_COFFEELAKE, ImageProductFamily<IGFX_COFFEELAKE>> populateCFL;

} // namespace L0

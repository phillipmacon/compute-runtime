/*
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "level_zero/core/source/xe_hpg_core/image_xe_hpg_core.inl"

namespace L0 {

template <>
struct ImageProductFamily<IGFX_METEORLAKE> : public ImageCoreFamily<IGFX_XE_HPG_CORE> {
    using ImageCoreFamily::ImageCoreFamily;

    ze_result_t initialize(Device *device, const ze_image_desc_t *desc) override {
        return ImageCoreFamily<IGFX_XE_HPG_CORE>::initialize(device, desc);
    };
};

static ImagePopulateFactory<IGFX_METEORLAKE, ImageProductFamily<IGFX_METEORLAKE>> populateMTL;

} // namespace L0

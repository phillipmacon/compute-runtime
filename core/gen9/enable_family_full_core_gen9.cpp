/*
 * Copyright (C) 2017-2020 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "gen8/hw_cmds.h"
#include "helpers/hw_helper.h"

#include <type_traits>

namespace NEO {

extern HwHelper *hwHelperFactory[IGFX_MAX_CORE];

typedef SKLFamily Family;
static const auto gfxFamily = IGFX_GEN9_CORE;

struct EnableCoreGen9 {
    EnableCoreGen9() {
        hwHelperFactory[gfxFamily] = &HwHelperHw<Family>::get();
    }
};

static EnableCoreGen9 enable;
} // namespace NEO

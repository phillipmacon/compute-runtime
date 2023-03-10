/*
 * Copyright (C) 2018-2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "shared/source/gen8/hw_cmds.h"
#include "shared/test/common/helpers/default_hw_info.h"
#include "shared/test/common/test_macros/header/per_product_test_definitions.h"
#include "shared/test/common/test_macros/test.h"

using namespace NEO;

using BroadwellOnlyTest = ::testing::Test;

BDWTEST_F(BroadwellOnlyTest, WhenGettingProductFamilyThenBroadwellIsReturned) {
    EXPECT_EQ(IGFX_BROADWELL, defaultHwInfo->platform.eProductFamily);
}

using Gen8OnlyTest = ::testing::Test;

GEN8TEST_F(Gen8OnlyTest, WhenGettingRenderCoreFamilyThenGen8CoreIsReturned) {
    EXPECT_EQ(IGFX_GEN8_CORE, defaultHwInfo->platform.eRenderCoreFamily);
}

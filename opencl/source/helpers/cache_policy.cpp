/*
 * Copyright (C) 2017-2020 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "helpers/cache_policy.h"

#include "helpers/aligned_memory.h"
#include "memory_manager/graphics_allocation.h"

namespace NEO {

bool isL3Capable(void *ptr, size_t size) {
    return isAligned<MemoryConstants::cacheLineSize>(ptr) &&
           isAligned<MemoryConstants::cacheLineSize>(size);
}

bool isL3Capable(const NEO::GraphicsAllocation &graphicsAllocation) {
    return isL3Capable(graphicsAllocation.getUnderlyingBuffer(), graphicsAllocation.getUnderlyingBufferSize());
}

} // namespace NEO

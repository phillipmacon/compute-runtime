#
# Copyright (C) 2020-2022 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

set(NEO_CORE_SRCS_BUILT_INS_OPS
    ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/built_in_ops.h
)
add_subdirectories()

set_property(GLOBAL PROPERTY NEO_CORE_SRCS_BUILT_INS_OPS ${NEO_CORE_SRCS_BUILT_INS_OPS})

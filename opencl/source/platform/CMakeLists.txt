#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

set(RUNTIME_SRCS_PLATFORM
    ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/platform.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/platform.h
    ${CMAKE_CURRENT_SOURCE_DIR}/platform_info.h
)
target_sources(${NEO_STATIC_LIB_NAME} PRIVATE ${RUNTIME_SRCS_PLATFORM})
set_property(GLOBAL PROPERTY RUNTIME_SRCS_PLATFORM ${RUNTIME_SRCS_PLATFORM})

#
# Copyright (C) 2018-2022 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

set(RUNTIME_SRCS_CONTEXT
    ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/context.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/context.h
    ${CMAKE_CURRENT_SOURCE_DIR}/context.inl
    ${CMAKE_CURRENT_SOURCE_DIR}/context_type.h
    ${CMAKE_CURRENT_SOURCE_DIR}/driver_diagnostics.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/driver_diagnostics.h
    ${CMAKE_CURRENT_SOURCE_DIR}${BRANCH_DIR_SUFFIX}pool_buffer_additional_checks.cpp
)

target_sources(${NEO_STATIC_LIB_NAME} PRIVATE ${RUNTIME_SRCS_CONTEXT})
set_property(GLOBAL PROPERTY RUNTIME_SRCS_CONTEXT ${RUNTIME_SRCS_CONTEXT})

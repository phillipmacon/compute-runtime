#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

set(RUNTIME_SRCS_UTILITIES_BASE
    ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/cl_logger.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cl_logger.h
)

set_property(GLOBAL PROPERTY RUNTIME_SRCS_UTILITIES_BASE ${RUNTIME_SRCS_UTILITIES_BASE})

target_sources(${NEO_STATIC_LIB_NAME} PRIVATE ${RUNTIME_SRCS_UTILITIES_BASE})
if(WIN32)
  target_sources(${NEO_STATIC_LIB_NAME} PRIVATE ${NEO_CORE_UTILITIES_WINDOWS})
else()
  target_sources(${NEO_STATIC_LIB_NAME} PRIVATE ${NEO_CORE_UTILITIES_LINUX})
endif()

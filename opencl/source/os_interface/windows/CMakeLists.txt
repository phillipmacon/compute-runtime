#
# Copyright (C) 2018-2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

set(RUNTIME_SRCS_OS_INTERFACE_WINDOWS
    ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/api_win.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/d3d10_11_sharing_functions.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/d3d9_sharing_functions.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/d3d_sharing_functions.h
    ${CMAKE_CURRENT_SOURCE_DIR}/device_caps_init_win.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ocl_reg_path.cpp
)

if(WIN32)
  target_sources(${NEO_STATIC_LIB_NAME} PRIVATE
                 ${RUNTIME_SRCS_OS_INTERFACE_WINDOWS}
  )
endif()

add_subdirectories()

set_property(GLOBAL PROPERTY RUNTIME_SRCS_OS_INTERFACE_WINDOWS ${RUNTIME_SRCS_OS_INTERFACE_WINDOWS})

#
# Copyright (C) 2021-2023 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

set(L0_SRCS_TOOLS_SYSMAN_PERFORMANCE_WINDOWS
    ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/os_performance_imp.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/os_performance_imp.h
)

if(WIN32)
  target_sources(${L0_STATIC_LIB_NAME}
                 PRIVATE
                 ${L0_SRCS_TOOLS_SYSMAN_PERFORMANCE_WINDOWS}
  )
endif()

# Make our source files visible to parent
set_property(GLOBAL PROPERTY L0_SRCS_TOOLS_SYSMAN_PERFORMANCE_WINDOWS ${L0_SRCS_TOOLS_SYSMAN_PERFORMANCE_WINDOWS})

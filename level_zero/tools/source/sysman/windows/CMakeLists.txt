#
# Copyright (C) 2020-2023 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

set(L0_SRCS_TOOLS_SYSMAN_WINDOWS
    ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/os_sysman_imp.h
    ${CMAKE_CURRENT_SOURCE_DIR}/kmd_sys.h
    ${CMAKE_CURRENT_SOURCE_DIR}/kmd_sys_manager.h
    ${CMAKE_CURRENT_SOURCE_DIR}/kmd_sys_manager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/os_sysman_imp.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/os_sysman_driver_imp.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/os_sysman_driver_imp.h
)

if(WIN32)
  target_sources(${L0_STATIC_LIB_NAME}
                 PRIVATE
                 ${L0_SRCS_TOOLS_SYSMAN_WINDOWS}
  )
endif()

# Make our source files visible to parent
set_property(GLOBAL PROPERTY L0_SRCS_TOOLS_SYSMAN_WINDOWS ${L0_SRCS_TOOLS_SYSMAN_WINDOWS})

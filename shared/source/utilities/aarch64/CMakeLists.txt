#
# Copyright (C) 2021 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

if(${NEO_TARGET_PROCESSOR} STREQUAL "aarch64")
  set_property(GLOBAL APPEND PROPERTY NEO_CORE_UTILITIES
               ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
               ${CMAKE_CURRENT_SOURCE_DIR}/cpu_info_aarch64.cpp
  )
endif()

#
# Copyright (C) 2020-2022 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

if(SUPPORT_GEN8)
  set(HW_SOURCES_GEN8
      ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
      ${CMAKE_CURRENT_SOURCE_DIR}/enable_family_full_l0_gen8.cpp
  )

  target_sources(${L0_STATIC_LIB_NAME} PRIVATE ${HW_SOURCES_GEN8})
  set_property(GLOBAL PROPERTY L0_HW_SOURCES_GEN8 ${HW_SOURCES_GEN8})
endif()

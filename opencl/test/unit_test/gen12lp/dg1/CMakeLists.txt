#
# Copyright (C) 2020-2022 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

if(TESTS_DG1)
  set(IGDRCL_SRCS_tests_gen12lp_dg1_excludes
      ${CMAKE_CURRENT_SOURCE_DIR}/excludes_ocl_dg1.cpp
  )
  set_property(GLOBAL APPEND PROPERTY IGDRCL_SRCS_tests_excludes ${IGDRCL_SRCS_tests_gen12lp_dg1_excludes})

  set(IGDRCL_SRCS_tests_dg1
      ${IGDRCL_SRCS_tests_gen12lp_dg1_excludes}
      ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
      ${CMAKE_CURRENT_SOURCE_DIR}/test_cl_device_caps_dg1.cpp
  )
  target_sources(igdrcl_tests PRIVATE ${IGDRCL_SRCS_tests_dg1})
  add_subdirectories()
endif()

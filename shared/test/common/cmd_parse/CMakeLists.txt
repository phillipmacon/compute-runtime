#
# Copyright (C) 2020-2022 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

target_sources(neo_libult_common PRIVATE
               ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
               ${CMAKE_CURRENT_SOURCE_DIR}/cmd_parse_3d_state_btd.inl
               ${CMAKE_CURRENT_SOURCE_DIR}/cmd_parse_base.inl
               ${CMAKE_CURRENT_SOURCE_DIR}/cmd_parse_base_mi_arb.inl
               ${CMAKE_CURRENT_SOURCE_DIR}/cmd_parse_compute_mi_arb.inl
               ${CMAKE_CURRENT_SOURCE_DIR}/cmd_parse_compute_mode.inl
               ${CMAKE_CURRENT_SOURCE_DIR}/cmd_parse_compute_walker.inl
               ${CMAKE_CURRENT_SOURCE_DIR}/cmd_parse_gpgpu_walker.inl
               ${CMAKE_CURRENT_SOURCE_DIR}/cmd_parse_l3_control.inl
               ${CMAKE_CURRENT_SOURCE_DIR}/cmd_parse_mi_arb.inl
               ${CMAKE_CURRENT_SOURCE_DIR}/cmd_parse_sip.inl
               ${CMAKE_CURRENT_SOURCE_DIR}/gen_cmd_parse.h
               ${CMAKE_CURRENT_SOURCE_DIR}/hw_parse.h
               ${CMAKE_CURRENT_SOURCE_DIR}/hw_parse.inl
)

if(TESTS_XEHP_AND_LATER)
  target_sources(neo_libult_common PRIVATE
                 ${CMAKE_CURRENT_SOURCE_DIR}/cmd_parse_l3_control_xehp_and_later.inl
                 ${CMAKE_CURRENT_SOURCE_DIR}/cmd_parse_xehp_and_later.inl
  )
endif()

if(TESTS_PVC_AND_LATER)
  target_sources(neo_libult_common PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/cmd_parse_pvc_and_later.inl)
endif()
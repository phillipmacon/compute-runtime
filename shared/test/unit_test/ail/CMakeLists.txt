#
# Copyright (C) 2021-2023 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

target_sources(neo_shared_tests PRIVATE
               ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
               ${CMAKE_CURRENT_SOURCE_DIR}/ail_tests.cpp
               ${CMAKE_CURRENT_SOURCE_DIR}/ail_tests_base.cpp
)

add_subdirectories()
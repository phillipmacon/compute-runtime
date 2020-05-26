#
# Copyright (C) 2019-2020 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

target_sources(igdrcl_tests PRIVATE ${NEO_SOURCE_DIR}/opencl/test/unit_test/core_unit_tests_files.cmake)

append_sources_from_properties(NEO_CORE_UNIT_TESTS_SOURCES
  NEO_CORE_COMMAND_CONTAINER_TESTS
  NEO_CORE_DEBUG_SETTINGS_TESTS
  NEO_CORE_DIRECT_SUBMISSION_TESTS
  NEO_CORE_DIRECT_SUBMISSION_DISPATCHERS_TESTS
  NEO_CORE_INDIRECT_HEAP_TESTS
  NEO_CORE_ENCODERS_TESTS
  NEO_CORE_IMAGE_TESTS
  NEO_CORE_MEMORY_MANAGER_TESTS
)

if(WIN32)
  append_sources_from_properties(NEO_CORE_UNIT_TESTS_SOURCES
    NEO_CORE_DIRECT_SUBMISSION_WINDOWS_TESTS
    NEO_CORE_OS_INTERFACE_TESTS_WINDOWS
  )
else()
  append_sources_from_properties(NEO_CORE_UNIT_TESTS_SOURCES
    NEO_CORE_DIRECT_SUBMISSION_LINUX_TESTS
    NEO_CORE_OS_INTERFACE_TESTS_LINUX
  )

endif()

set_property(GLOBAL PROPERTY NEO_CORE_UNIT_TESTS_SOURCES ${NEO_CORE_UNIT_TESTS_SOURCES})

target_sources(igdrcl_tests PRIVATE ${NEO_CORE_UNIT_TESTS_SOURCES})

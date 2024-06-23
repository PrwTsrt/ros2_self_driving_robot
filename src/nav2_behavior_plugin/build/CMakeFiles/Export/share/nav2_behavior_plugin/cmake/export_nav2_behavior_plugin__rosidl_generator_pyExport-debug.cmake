#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "nav2_behavior_plugin::nav2_behavior_plugin__rosidl_generator_py" for configuration "Debug"
set_property(TARGET nav2_behavior_plugin::nav2_behavior_plugin__rosidl_generator_py APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(nav2_behavior_plugin::nav2_behavior_plugin__rosidl_generator_py PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libnav2_behavior_plugin__rosidl_generator_py.so"
  IMPORTED_SONAME_DEBUG "libnav2_behavior_plugin__rosidl_generator_py.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS nav2_behavior_plugin::nav2_behavior_plugin__rosidl_generator_py )
list(APPEND _IMPORT_CHECK_FILES_FOR_nav2_behavior_plugin::nav2_behavior_plugin__rosidl_generator_py "${_IMPORT_PREFIX}/lib/libnav2_behavior_plugin__rosidl_generator_py.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

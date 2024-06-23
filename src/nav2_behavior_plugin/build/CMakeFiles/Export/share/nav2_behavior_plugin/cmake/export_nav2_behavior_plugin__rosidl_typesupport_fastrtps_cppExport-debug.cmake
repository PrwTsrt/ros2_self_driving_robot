#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "nav2_behavior_plugin::nav2_behavior_plugin__rosidl_typesupport_fastrtps_cpp" for configuration "Debug"
set_property(TARGET nav2_behavior_plugin::nav2_behavior_plugin__rosidl_typesupport_fastrtps_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(nav2_behavior_plugin::nav2_behavior_plugin__rosidl_typesupport_fastrtps_cpp PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libnav2_behavior_plugin__rosidl_typesupport_fastrtps_cpp.so"
  IMPORTED_SONAME_DEBUG "libnav2_behavior_plugin__rosidl_typesupport_fastrtps_cpp.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS nav2_behavior_plugin::nav2_behavior_plugin__rosidl_typesupport_fastrtps_cpp )
list(APPEND _IMPORT_CHECK_FILES_FOR_nav2_behavior_plugin::nav2_behavior_plugin__rosidl_typesupport_fastrtps_cpp "${_IMPORT_PREFIX}/lib/libnav2_behavior_plugin__rosidl_typesupport_fastrtps_cpp.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

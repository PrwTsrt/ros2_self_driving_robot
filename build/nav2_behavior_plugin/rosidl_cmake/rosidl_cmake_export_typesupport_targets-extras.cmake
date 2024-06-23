# generated from
# rosidl_cmake/cmake/template/rosidl_cmake_export_typesupport_targets.cmake.in

set(_exported_typesupport_targets
  "__rosidl_generator_c:nav2_behavior_plugin__rosidl_generator_c;__rosidl_typesupport_fastrtps_c:nav2_behavior_plugin__rosidl_typesupport_fastrtps_c;__rosidl_generator_cpp:nav2_behavior_plugin__rosidl_generator_cpp;__rosidl_typesupport_fastrtps_cpp:nav2_behavior_plugin__rosidl_typesupport_fastrtps_cpp;__rosidl_typesupport_introspection_c:nav2_behavior_plugin__rosidl_typesupport_introspection_c;__rosidl_typesupport_c:nav2_behavior_plugin__rosidl_typesupport_c;__rosidl_typesupport_introspection_cpp:nav2_behavior_plugin__rosidl_typesupport_introspection_cpp;__rosidl_typesupport_cpp:nav2_behavior_plugin__rosidl_typesupport_cpp;__rosidl_generator_py:nav2_behavior_plugin__rosidl_generator_py")

# populate nav2_behavior_plugin_TARGETS_<suffix>
if(NOT _exported_typesupport_targets STREQUAL "")
  # loop over typesupport targets
  foreach(_tuple ${_exported_typesupport_targets})
    string(REPLACE ":" ";" _tuple "${_tuple}")
    list(GET _tuple 0 _suffix)
    list(GET _tuple 1 _target)

    set(_target "nav2_behavior_plugin::${_target}")
    if(NOT TARGET "${_target}")
      # the exported target must exist
      message(WARNING "Package 'nav2_behavior_plugin' exports the typesupport target '${_target}' which doesn't exist")
    else()
      list(APPEND nav2_behavior_plugin_TARGETS${_suffix} "${_target}")
    endif()
  endforeach()
endif()

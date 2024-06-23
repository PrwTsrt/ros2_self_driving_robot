// generated from
// rosidl_typesupport_fastrtps_cpp/resource/rosidl_typesupport_fastrtps_cpp__visibility_control.h.in
// generated code does not contain a copyright notice

#ifndef NAV2_BEHAVIOR_PLUGIN__MSG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP__VISIBILITY_CONTROL_H_
#define NAV2_BEHAVIOR_PLUGIN__MSG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP__VISIBILITY_CONTROL_H_

#if __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_nav2_behavior_plugin __attribute__ ((dllexport))
    #define ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPORT_nav2_behavior_plugin __attribute__ ((dllimport))
  #else
    #define ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_nav2_behavior_plugin __declspec(dllexport)
    #define ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPORT_nav2_behavior_plugin __declspec(dllimport)
  #endif
  #ifdef ROSIDL_TYPESUPPORT_FASTRTPS_CPP_BUILDING_DLL_nav2_behavior_plugin
    #define ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nav2_behavior_plugin ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_nav2_behavior_plugin
  #else
    #define ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nav2_behavior_plugin ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPORT_nav2_behavior_plugin
  #endif
#else
  #define ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_nav2_behavior_plugin __attribute__ ((visibility("default")))
  #define ROSIDL_TYPESUPPORT_FASTRTPS_CPP_IMPORT_nav2_behavior_plugin
  #if __GNUC__ >= 4
    #define ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nav2_behavior_plugin __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nav2_behavior_plugin
  #endif
#endif

#if __cplusplus
}
#endif

#endif  // NAV2_BEHAVIOR_PLUGIN__MSG__ROSIDL_TYPESUPPORT_FASTRTPS_CPP__VISIBILITY_CONTROL_H_

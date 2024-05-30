import os
from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare

from launch_ros.actions import Node

MAP_NAME = '2_map_save' 

def generate_launch_description():

    robot_navigation_dir = get_package_share_directory("robot_navigation")
    robot_bringup_dir = get_package_share_directory("robot_bringup")
    nav2_dir = get_package_share_directory("nav2_bringup")

    default_map_path = PathJoinSubstitution(
        [FindPackageShare('robot_navigation'), 'maps', '2_map_save.yaml']
    )

    map_arg = DeclareLaunchArgument(
            name='map', 
            default_value=default_map_path,
            description='Navigation map path'
        )

    sim_arg = DeclareLaunchArgument(
            name='sim', 
            default_value='false',
            description='Enable use_sime_time to true'
        )

    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="screen",
        arguments=["-d", os.path.join(robot_navigation_dir, "rviz", "navigation.rviz")],
    )
    
    bringup = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(PathJoinSubstitution(
            [robot_bringup_dir, "launch", "bringup.launch.py"]
        )),
        launch_arguments={
                'rviz': 'false',
                'sim': LaunchConfiguration("sim")            
            }.items()
    )

    nav = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(PathJoinSubstitution(
                [nav2_dir, 'launch', 'navigation_launch.py']
            )),
            launch_arguments={
                # 'map' : LaunchConfiguration("map"),
                'use_sim_time': LaunchConfiguration("sim"),
                'params_file':  PathJoinSubstitution(
                    [robot_navigation_dir, "config", "navigation.yaml"]),
                'map_subscribe_transient_local' : 'true'
            }.items()
        )
    amcl = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(PathJoinSubstitution(
                [nav2_dir, 'launch', 'localization_launch.py']
            )),
            launch_arguments={
                'map' : LaunchConfiguration("map"),
                'use_sim_time': LaunchConfiguration("sim"),
                # 'params_file':  PathJoinSubstitution(
                #     [robot_navigation_dir, "config", "navigation.yaml"])
            }.items()
        )

    return LaunchDescription([
        map_arg,
        sim_arg,
        bringup,
        amcl,
        nav,
        rviz_node,
    ])
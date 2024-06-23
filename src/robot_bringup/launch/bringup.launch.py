import os
from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, SetEnvironmentVariable
from launch.substitutions import Command, LaunchConfiguration

from launch.conditions import IfCondition

from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue


def generate_launch_description():
    robot_description_dir = get_package_share_directory("robot_description")
    robot_bringup_dir = get_package_share_directory("robot_bringup")
    foxglove_dir = get_package_share_directory("foxglove_bridge")

    domain_arg = DeclareLaunchArgument(
            'ros_domain_id',
            default_value='19',
            description='ROS Domain ID'
        )
    
    set_domain = SetEnvironmentVariable('ROS_DOMAIN_ID', LaunchConfiguration('ros_domain_id'))

    model_arg = DeclareLaunchArgument(name="model", default_value=os.path.join(
                                        robot_description_dir, "urdf", "bb_bot.urdf.xacro"
                                        ),
                                      description="Absolute path to robot urdf file")
    
    rviz_arg = DeclareLaunchArgument(
            name='rviz', 
            default_value='true',
            description='Run rviz'
        )
    
    sim_arg = DeclareLaunchArgument(
            name='sim', 
            default_value='false',
            description='Enable use_sime_time to true'
        )

    robot_description = ParameterValue(Command(["xacro ", LaunchConfiguration("model")]),
                                       value_type=str)

    robot_state_publisher_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        parameters=[{"robot_description": robot_description}]
    )

    joint_state_publisher_node = Node(
        package="joint_state_publisher",
        executable="joint_state_publisher"
    )

    rviz_node = Node(
        package="rviz2",
        executable="rviz2",
        name="rviz2",
        output="screen",
        arguments=["-d", os.path.join(robot_description_dir, "rviz", "bringup.rviz")],
        condition=IfCondition(LaunchConfiguration("rviz")),
        parameters=[{'use_sim_time': LaunchConfiguration("sim")}]
    )
    
    scan = IncludeLaunchDescription(os.path.join(
        get_package_share_directory("sllidar_ros2"),
        "launch",
        "sllidar_c1_launch.py")
    )

    camera = IncludeLaunchDescription(os.path.join(
        robot_bringup_dir,
        "launch",
        "camera.launch.py")
    )

    robot_localization = Node(
            package='robot_localization',
            executable='ekf_node',
            name='ekf_filter_node',
            output='screen',
            parameters=[os.path.join(robot_bringup_dir, "config", "ekf.yaml")],
            remappings=[("odometry/filtered", "odom")]
        ) 
    
    micro_ros_esp32 = Node(
            package='micro_ros_agent',
            executable='micro_ros_agent',
            name='micro_ros_esp32',
            output='screen',
            arguments=['serial', '--dev', '/dev/ttyUSB1', '-b', '921600', '-v4']
    )

    micro_ros_raspico = Node(
            package='micro_ros_agent',
            executable='micro_ros_agent',
            name='micro_ros_raspico',
            output='screen',
            arguments=['serial', '--dev', '/dev/ttyACM0', '-b', '921600', '-v4']
    )

    foxglove_bridge = IncludeLaunchDescription(os.path.join(
        foxglove_dir,
        "launch",
        "foxglove_bridge_launch.xml")
    )

    # teleop = Node(
    #         package='teleop_twist_keyboard',
    #         executable='teleop_twist_keyboard',
    #         name='teleop_twist_keyboard_node',
    #         output='screen'
    #     )

    return LaunchDescription([
        domain_arg,
        set_domain,
        model_arg,
        sim_arg,
        rviz_arg,
        micro_ros_esp32,
        micro_ros_raspico,  
        camera, 
        robot_state_publisher_node,
        joint_state_publisher_node,   
        scan,
        rviz_node,
        robot_localization,
        #foxglove_bridge
    ])

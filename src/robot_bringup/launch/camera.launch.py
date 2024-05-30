
from launch import LaunchDescription 
from launch_ros.actions import Node 
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    usb_cam_config_path=PathJoinSubstitution(
            [FindPackageShare("robot_bringup"), "config", "usbcam.yaml"]
        )
    
    return LaunchDescription([
        Node(
            package='usb_cam', executable='usb_cam_node_exe', output='screen',
            name="usb_camera",
            parameters=[usb_cam_config_path]
        )
    ]
    )

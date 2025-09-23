  ros2 launch articubot_one launch_sim.launch.py world:=./src/articubot_one/worlds/obstacles.world 
  rviz2
   ros2 run teleop_twist_keyboard teleop_twist_keyboard   --ros-args -r /cmd_vel:=/diff_cont/cmd_vel_unstamped


  

   <xacro:arg name="use_ros2_control" default="true"/>

    <xacro:include filename="robot_core.xacro" />

    <xacro:if value="$(arg use_ros2_control)">
        <xacro:include filename="ros2_control.xacro" /> 
    </xacro:if>
    <xacro:unless value="$(arg use_ros2_control)">
        <xacro:include filename="gazebo_control.xacro" /> 
    </xacro:unless>

    <!-- <xacro:include filename="depth_camera.xacro" /> -->

    <xacro:include filename="camera.xacro" />
    <xacro:include filename="lidar.xacro" />

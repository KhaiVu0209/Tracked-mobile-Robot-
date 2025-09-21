  ros2 launch articubot_one launch_sim.launch.py world:=./src/articubot_one/worlds/obstacles.world 
  rviz2
   ros2 run teleop_twist_keyboard teleop_twist_keyboard   --ros-args -r /cmd_vel:=/diff_cont/cmd_vel_unstamped


  


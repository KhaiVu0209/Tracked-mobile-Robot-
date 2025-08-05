đẻ mở mô hình urdf trong rviz 
B1 : chạy lệnh roslaunch my_bot rsp.launch use_sim_time:=
B2 : chạy lệnh rviz rồi thêm TF, Robot Model (sẽ báo kh có TF của 2 bánh xe) chạy tiếp lệnh rosrun joint_state_publisher_gui joint_state_publisher_gui

chạy gazebo : chạy lệnh roslaunch my_bot launch_sim.launch (thì sẽ load giống như trên với mô hình trong gazebo)


# OMRON B5L ROS
## Description
A ROS package for the sensor OMRON B5L 3D TOF.

this package was base from [example dir](example) [file omron_b5l_a_ROS1.zip](example/omron_b5l_a_ROS1.zip)

---
## Connect OMRON B5L

    sudo modprobe usbserial vendor=0x0590 product=0x00ca
    sudo chgrp dialout /dev/ttyUSB0
    sudo chmod 666 /dev/ttyUSB0
    sudo adduser $USER dialout

---
## ROS Topics
ROS topics published by this ROS Node:
- **omron_b5l/pointcloud2** [(sensor_msgs/PointCloud2 )](https://docs.ros.org/en/api/sensor_msgs/html/msg/PointCloud2.html)
    
---
### Build
Perform a build of your workspace

    cd ~/ros_ws
    catkin build

---
### Running the ROS2 node
Run the `omron_b5l_a` ROS node with default parameters:
    
    source devel/setup.bash
    # run the node:
    rosrun omron_b5l_a omron_b5l_a

Run launch file:

    roslaunch omron_b5l_a omrom_b5l_a.launch
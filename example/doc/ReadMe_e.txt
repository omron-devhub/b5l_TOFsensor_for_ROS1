------------------------------------------------
 B5L ROS Publisher Sample Code （C++ version）
------------------------------------------------

（1）Contents
  This code is a C++ sample code which provide measurement data from
  B5L(3D TOF Sensor Module) as a Topic on ROS.
  With this sample code, you can initialize B5L according to the parameters
  specified in ToF_Sample.prm and get data from the Topic as
  sensor_msgs/PointCloud2 form.

（2）File description
  The following files exist in the TOFSensorSampleROS1CPP/ folder.

    omron_b5l_a/include/omron_b5l_a/*              Header Files
    omron_b5l_a/src/config/ToF_Sample.prm          Parameter File
    omron_b5l_a/src/publisher_member_function.cpp  Sample Code Main
    omron_b5l_a/src/ToF_Sample.cpp                 ToF Communication Process
    omron_b5l_a/src/TOFApiZ.cpp                    ToF Command Class
    omron_b5l_a/src/uart_linux.c                   UART Communication Routines
    omron_b5l_a/CMakeLists.txt                     CMake Setting File
    omron_b5l_a/connect_tof.sh                     Shell Script for connecting B5L
    omron_b5l_a/package.xml                        Package Definition File
    Quick Setup Guide_ROS.pdf                      Setup Guide
    Quick Setup Guide_ROS_JP.pdf                   Setup Guide(Japanese)

（3）How to build this Sample Code
  1. This Sample Code was confirmed on Ubuntu18.04 / ROS Melodic Morenia.
  2. Please see Quick Setup Guide_ROS.pdf for specific setup instructions.


[NOTES ON USAGE]
* This sample code and documentation are copyrighted property of OMRON Corporation
* This sample code does not guarantee proper operation
* This sample code is distributed in the Apache License 2.0.

----
OMRON Corporation 
Copyright 2020-2022 OMRON Corporation、All Rights Reserved.

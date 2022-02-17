/*---------------------------------------------------------------------------*/
/* Copyright(C)  2020-2021  OMRON Corporation                                */
/*                                                                           */
/* Licensed under the Apache License, Version 2.0 (the "License");           */
/* you may not use this file except in compliance with the License.          */
/* You may obtain a copy of the License at                                   */
/*                                                                           */
/*     http://www.apache.org/licenses/LICENSE-2.0                            */
/*                                                                           */
/* Unless required by applicable law or agreed to in writing, software       */
/* distributed under the License is distributed on an "AS IS" BASIS,         */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  */
/* See the License for the specific language governing permissions and       */
/* limitations under the License.                                            */
/*---------------------------------------------------------------------------*/

/*******************************************************************************
 * File Name    : publisher_member_function.hpp
 * revision		: 0.1
 * Description  : main publisher module source file.
 ******************************************************************************/
/******************************************************************************
 * History      : DD.MM.YYYY Version Description
 * 				: 15.07.2020	0.1		Initial Version
 * 				: 02.07.2021	0.2		Modified for ROS1
 *****************************************************************************/

#include <chrono>
#include <memory>
#include <iostream>
#include <cstdlib>
#include <pcl_conversions/pcl_conversions.h>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>

#include <std_msgs/String.h>

#include <sensor_msgs/PointCloud2.h>

#include "ToF_Sample.hpp"

using namespace std::chrono_literals;

/* Maximum number of ROS message queue */
#define PUB_MSG_QUEUE_DEPTH 10

/* Topic string macro */
#define PUB_TOPIC_FRMT_001_002 "omron_b5l/pointcloud2"
#define PUB_TOPIC_FRMT_257_258 "omron_b5l/pointcloud2"

/* Config file string */
#define CONFIG_FILE_PATH "/src/config/ToF_Sample.prm"

/* for ROS */
ros::WallTimer timer_;
ros::Publisher publisher_;
sensor_msgs::PointCloud2Ptr pc2_msg_;
std::string frame_id_ = "omron_b5l";
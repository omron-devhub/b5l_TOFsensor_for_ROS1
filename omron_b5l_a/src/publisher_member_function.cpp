/*---------------------------------------------------------------------------*/
/* Copyright(C)  2019-2021  OMRON Corporation                                */
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
 * File Name    : publisher_member_function.cpp
 * revision		: 0.2
 * Description  : main publisher module source file.
 ******************************************************************************/
/******************************************************************************
 * History      : DD.MM.YYYY Version Description
 * 				: 15.07.2020	0.1		Initial Version
 * 				: 02.07.2021	0.2		Modified for ROS1
 *****************************************************************************/


#include <ros/ros.h>
#include "publisher_member_function.hpp"
#include <unistd.h>
using PointT = pcl::PointXYZI;
using PointCloudT = pcl::PointCloud<PointT>;

int ShutDownFlag;

/* Topc string */
std::string topic = "";

/* Output formate */
INT32 Tof_output_format = 0;

/*****************************************************************************
 * Function Name : terminate
 *****************************************************************************/
/**
 * @brief	This function is for stop communication and shutdown application
 *
 * @param[in/out]	None
 *
 * @return	None
 */
void terminate_application()
{
	CTOFSample::Stop();
}

/*****************************************************************************
 * Function Name : timer_callback
 *****************************************************************************/
/**
 * @brief	This function is Timer callback function which publish ROS msg on particuler time interval
 *
 * @param[in/out]	Timer Event
 *
 * @return	None
 */
void timer_callback(const ros::WallTimerEvent& event)
{

	pcl::PointCloud<pcl::PointXYZI> cloud_;
	int Ret = CTOFSample::Run(&cloud_);
	if (Ret == 0)
	{
		/* Convert cloud data to ROS msg type */
		pcl::toROSMsg(cloud_, *pc2_msg_);
		pc2_msg_->header.frame_id = frame_id_;
		pc2_msg_->header.stamp = ros::Time::now();
		/* Publish ROS message */
		publisher_.publish(*pc2_msg_);
	}
	else
	{
		ShutDownFlag = 1;
		terminate_application();
	}
}

/*****************************************************************************
 * Function Name : main
 *****************************************************************************/
/**
 * @brief	main function for init and start application
 *
 * @param[in/out]	None
 *
 * @return	0 on successful shutdown
 */
int main(int argc, char *argv[])
{
	/* for ROS init */
	ros::init(argc, argv, "omron_b5l_node");
	ros::NodeHandle nh;

	std::string config_file = SOURCE_DIR_PREFIX;
	ShutDownFlag = 0;
	/* Load USB serial module */
	system("sudo modprobe usbserial vendor=0x0590 product=0x00ca");

	config_file.append(CONFIG_FILE_PATH);

	std::cout<< "omron_b5l_a application version 0.2 started"<< std::endl;
	int Ret = CTOFSample::Init(config_file, Tof_output_format); // Init camera and UART
	/* Here we are supporting output format 257 || 258 || 1 || 2 */
	/* Format validation done in Init function and if fails then it returns non zero value */
	if (Ret == 0)
	{
		if (Tof_output_format == 257 || Tof_output_format == 258)
		{
			topic = PUB_TOPIC_FRMT_257_258;
			ROS_INFO(PUB_TOPIC_FRMT_257_258);
		}
		else
		{
			topic = PUB_TOPIC_FRMT_001_002;
			ROS_INFO(PUB_TOPIC_FRMT_001_002);
		}
		
		/* Create pulisher with topic as per config file 'OUTPUT_FORMAT' parameter */
		/* Here 10 represents max number of messages in publisher queue */
		publisher_ = nh.advertise<sensor_msgs::PointCloud2>(topic, PUB_MSG_QUEUE_DEPTH);
		pc2_msg_ = boost::make_shared<sensor_msgs::PointCloud2>();

		/* Create timer for 80ms to achive approx 10/12 Fps */
		timer_ = nh.createWallTimer(ros::WallDuration(0.08), timer_callback);

		ros::spin();

		if (ShutDownFlag == 0)
		{			
			terminate_application();
		}
	}

	return 0;
}

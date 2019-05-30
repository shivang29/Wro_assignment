
#include "husky_highlevel_controller/HuskyHighlevelController.hpp"
#include <ros/ros.h>
#include <string>
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

namespace husky_highlevel_controller {

	int queueSize_;

  HuskyHighlevelController::HuskyHighlevelController(ros::NodeHandle& nodeHandle)
      : nodeHandle_(nodeHandle)
  {
    // check if the parameters exists, and if not exists send error and shutdown
    if (!readParameters()) {
      ROS_ERROR("Could not read parameters.");
      ros::requestShutdown();
    }

    // create a subscriber to the topic_name
    subscriber_ = nodeHandle_.subscribe(scanTopic_,1,
                                        &HuskyHighlevelController::topicCallback, this);
    ROS_INFO("Successfully launched node.");
  }

  HuskyHighlevelController::~HuskyHighlevelController()
  {
  }

bool HuskyHighlevelController::readParameters()
{
  if(!nodeHandle_.getParam("scan_topic_name", scanTopic_))return false;
  if(!nodeHandle_.getParam("scan_topic_queue_size",queueSize_))return false;
  return true;
}

  void HuskyHighlevelController::topicCallback(const sensor_msgs::LaserScan::ConstPtr& message) {
    // search for the min value in the vector of msg.ranges
	 int a=message->ranges.size();
   
  float minValue;
  for(int i=0;i<a;i++)
  {
    if(i==0)
    minValue=message->ranges[i];
    if((message->ranges)[i]<minValue)
    {
      minValue=(message->ranges)[i];
    }
}
    
    // display the ming value
    ROS_INFO_STREAM("smallest distance(m):%f", minValue);

  }
}

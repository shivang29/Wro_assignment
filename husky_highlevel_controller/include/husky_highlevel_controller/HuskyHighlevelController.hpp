#pragma once

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>


namespace husky_highlevel_controller {

/*!
 * Class containing the Husky Highlevel Controller
 */
class HuskyHighlevelController {
public:
	/*!
	 * Constructor.
	 */
	HuskyHighlevelController(ros::NodeHandle& nodeHandle);

	/*!
	 * Destructor.
	 */
	virtual ~HuskyHighlevelController();

private:
	
	void scanCallback(const sensor_msgs::LaserScan& meg);
  
	 
  //! ROS node handle.
  ros::NodeHandle& nodeHandle_;

  //! ROS topic subscriber.
  ros::Subscriber subscriber_;

  //! ROS topic name to subscribe to.
  std::string topic_name_;

  std::int32_t topic_size_queue_; 


};

} /* namespace */

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

	bool readParameters();
	
	void topicCallback(const sensor_msgs::LaserScan& message);
  
	 
  
  ros::NodeHandle& nodeHandle_;

  
  ros::Subscriber scanSubscriber_;

 
  std::string scanTopic_;


};

} /* namespace */

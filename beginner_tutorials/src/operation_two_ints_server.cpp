
#include "ros/ros.h"
#include "beginner_tutorials/OperationOnTwoInts.h"
using namespace std;

bool operate(beginner_tutorials::operation_On_two_ints::Request  &req,
         beginner_tutorials::operation_on_two_ints::Response &res)
{
  if((req.operation).compare("add")==0){
    res.value = req.a + req.b;
  }
  else if((req.operation).compare("sub")==0){
   res.value = req.a - req.b;  
  }
  else if((req.operation).compare("multiply")==0){
   res.value = req.a * req.b;   
 }
  else if((req.operation).compare("div")==0){
   res.value =((float)req.a)/req.b;
    }
  else{
  ROS_INFO("OPERATION NOT DEFINED");
  }

  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%f]",res.value);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "operation_two_ints_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("operation_two_ints", operate);
  ROS_INFO("Ready to solve");
  ros::spin();

  return 0;
}

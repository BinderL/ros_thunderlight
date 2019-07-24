/*
  LightController - Library for controlling Thunder Light in "Atelier Franck Genser" Thunder Light project.
  Created by Quentin Marmouget, binders@laposte.net.
  This main class aims at controlling in real time the different strips and synchronised   
*/

#include <ThunderLightControl/LightController.h>


LightController::LightController(ros::NodeHandle* n)
{
  _Topos.SetServerParam(n);
  buildingTopology();
}

LightController::~LightController()
{
  
}

void LightController::buildingTopology(void)
{
  int ID_tab[3] = {0,1,2} ;
  bool link_tab[3] = {false, true, true};
  int howManyElement_tab[3] = {1,3,4};
  _Topos.buildingNode(ID_tab, link_tab, howManyElement_tab);
}

void LightController::initGuiParameters(void)
{
//  ros::ServiceServer service = n->advertiseService("add_two_ints", add);
//  ROS_INFO("Ready to add two ints.");
}



//bool add(beginner_tutorials::AddTwoInts::Request  &req,
//         beginner_tutorials::AddTwoInts::Response &res)
//{
//  res.sum = req.a + req.b;
//  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
//  ROS_INFO("sending back response: [%ld]", (long int)res.sum);
//  return true;
//}

//int main(int argc, char **argv)
//{
//  ros::init(argc, argv, "add_two_ints_server");
//  ros::NodeHandle n;

//  ros::ServiceServer service = n.advertiseService("add_two_ints", add);
//  ROS_INFO("Ready to add two ints.");
//  ros::spin();

//  return 0;
//}

void LightController::startController(void)
{
  _Topos.startComputing();
}






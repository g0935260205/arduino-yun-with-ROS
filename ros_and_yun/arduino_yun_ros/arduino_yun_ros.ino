#include <Bridge.h>
#include "yun_ros.h"
#include <ros.h>
#include <std_msgs/String.h>
#define port 11411

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);
ros::NodeHandle_<WiFiHardware, 6, 6, 150, 150> nh;
IPAddress server(192,168,1,13); 
char hello[20] = "good";

void setup() {
  Bridge.begin();
  delay(2000);
  nh.getHardware()->setConnection(server, port);
  nh.initNode();
  nh.advertise(chatter);
}

void loop() {
  str_msg.data = hello;
  chatter.publish( &str_msg );
  nh.spinOnce();
  delay(1);
}

#ifndef YUN_ROS_H_
#define YUN_ROS_H_
#include <BridgeClient.h>
class WiFiHardware{

public:
  WiFiHardware(){};
  void setConnection(IPAddress &server, int port = 11411){
    server_ = server;
    serverPort_ = port;
  }
  void init(){
    if (tcp_.connected()){
      tcp_.stop();
    }
    tcp_.connect(server_, serverPort_);
  }

  int read(){
    if (tcp_.connected()){
      return tcp_.read();
    }
    else{
      tcp_.stop();
      tcp_.connect(server_, serverPort_);
    }
    return -1;
  }
  void write(uint8_t *data, int length){
    tcp_.write(data, length);
  }
  unsigned long time(){
    return millis();
  }
  bool connected(){
    return tcp_.connected();
  }

protected:
  BridgeClient tcp_;
  IPAddress server_;
  uint16_t serverPort_ = 11411;
};
#endif

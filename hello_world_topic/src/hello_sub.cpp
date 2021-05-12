#include <ros/ros.h>
#include <hello_world/str.h>
#include <std_msgs/Float32.h>

//回调函数，函数类型为ConstPtr 类型的指针，它被定义在之前编译生成的 str.h 中，执行str的消息
void strCallback(const hello_world::str::ConstPtr &msg){
    ROS_INFO("ROS_listener : I get %s from talker ! ", msg->str.c_str());  //打印收到的信息
}

int main(int argc, char** argv){
    ros::init(argc,argv,"listener");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("str_info",1,strCallback);  //执行回调函数，订阅str_info
    ros::spin();    //轮询等待消息发布
    return 0;
}
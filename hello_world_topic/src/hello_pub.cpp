#include <ros/ros.h>
#include <hello_world/str.h>
#include <std_msgs/Float32.h>

int main(int argc , char **argv){
    ros::init(argc,argv,"talker");      //解析参数，命名节点为talker
    ros::NodeHandle nh;                   //创建句柄，实例化node
    hello_world::str msg;                 //创建msg消息
    msg.str = "hello world";              //设置str初始值
    ros::Publisher pub = nh.advertise<hello_world::str>("str_info",20);  //创建 publisher 对象
    ros::Rate loop_rate(1.0);             //创建 rate 对象，定义循环发布频率1HZ,1s
    while(ros::ok()){                     //只要ros没有关闭，一直循环
        ROS_INFO("ROS_talker: %s",msg.str.c_str());    //相当于printf()输出
        pub.publish(msg);                 //发布消息
        loop_rate.sleep();                //延时
    }
    return 0;
}
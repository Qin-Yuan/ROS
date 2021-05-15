#include <ros/ros.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    //初始化节点
    ros::init(argc,argv,"stu_param");
    //节点句柄实例化为 p 全局命名
    ros::NodeHandle p;
    // 局部命名 pa
    ros::NodeHandle pa("~");
    //定义一个变量用于存储读取 param参数
    std::string get_name;
    /**************************************
    *   理解全局和局部 句柄、param对应性质     *
    **************************************/
    //全局句柄 p 读取全局param参数 name = Qinyuan
    p.getParam("name",get_name);
    ROS_INFO("global_p_global_name -> %s ",get_name.c_str());
    //全局句柄 p 读取局部param参数 name = Benny ，需要加 (node name)/   节点名字
    p.getParam("stu_param/name",get_name);
    ROS_INFO("global_p_local_name -> %s ",get_name.c_str());
    
    //局部命名句柄 pa 读取局部param参数 name = Benny
    pa.getParam("name",get_name);
    ROS_INFO("local_pa_local_name -> %s ",get_name.c_str());
    //局部命名句柄 pa 读取去全局param参数 name = Qinyuan  ,需要加 "/"
    pa.getParam("/name",get_name);
    ROS_INFO("local_p_global_name -> %s ",get_name.c_str());

    /*****************************************
    *  使用setParam 修改全局param参数 再读取出来  *
    *****************************************/
    //读取全局param参数name = Qinyuan
    p.getParam("name",get_name);
    ROS_INFO("get_global_name -> %s" , get_name.c_str());
    //设置name = "set_Qinyuan"
    p.setParam("name","set_Qinyuan");
    //再次读取显示
    p.getParam("name",get_name);
    ROS_INFO("get_global_name -> %s" , get_name.c_str());
    ros::spinOnce();
}
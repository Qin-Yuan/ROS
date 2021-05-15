#include "ros/ros.h" 
#include <student_service/stu.h>

int main(int argc, char **argv){
    //初始化，节点命名为"student_client" 
    ros::init(argc, argv, "student_client");
    //创建节点句柄 cl
    ros::NodeHandle cl;
    //创建客户端 client 目标为stu.srv  命名为stu_client
    ros::ServiceClient client = cl.serviceClient<student_service::stu>("stu_server");
    //实例化 stu.srv 文件为 stu
    student_service::stu stu ;
    //修改 Client r_name参数 r_age参数 
    stu.request.r_name = "Benny" ;
    stu.request.r_age = 21 ;
    //申请 stu ，如果成功执行以下语句
    if (client.call(stu)){
        // 获取显示服务端给出的信息 s_name  s_age
        ROS_INFO("Response from %s with age %d", stu.response.s_name.c_str() , stu.response.s_age);
    }
    //如果失败，则输出以下语句
    else{
        ROS_ERROR("Failed to call service Student_service"); 
        return 1;
    }
    return 0;
}
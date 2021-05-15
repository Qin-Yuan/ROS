#include <ros/ros.h>
#include <student_topic/student.h>
#include <std_msgs/String.h>

//回调函数，函数类型为ConstPtr 类型的指针，它被定义在之前编译生成的 student.h 中，执行student的消息，stu为实例化的对象(可任意取值)
void strCallback(const student_topic::student::ConstPtr &stu){
    ROS_INFO("ROS_listener : name=%s , num=%s , score=%d ! ", stu->name.c_str() , stu->num.c_str() , stu->score);  //打印收到的信息
}

int main(int argc, char** argv){
    ros::init(argc,argv,"listener");   //解析参数，命名节点为talker
    ros::NodeHandle st;                //创建句柄，实例化nod出
	//             创建订阅                发布者     队列大小  回调函数
    ros::Subscriber sub = st.subscribe("stu_info" , 3 , strCallback);  //执行回调函数，订阅str_info
    ros::spin();    //轮询等待消息发布
    return 0;
}
#include <ros/ros.h>                  //必要
#include <student_topic/student.h>    //msg头文件
#include <std_msgs/String.h>          //字符串依赖

//主函数
int main(int argc , char **argv){
    ros::init(argc,argv,"talker");        //解析参数，命名节点为talker
    ros::NodeHandle st;                   //创建句柄，实例化node
    student_topic::student stu;           //实例化 msg 消息 为 stu
    stu.name = "Qinyuan";                 //设置 name 姓名值 
	stu.num = "123456" ;                  //设置 num 学号值 
	stu.score = 100 ;                     //设置 score 分数值 
	/* 下面是advertise()函数 官方给出的解释
	* The advertise() function is how you tell ROS that you want to
	* publish on a given topic name. This invokes a call to the ROS
	* master node, which keeps a registry of who is publishing and who
	* is subscribing. After this advertise() call is made, the master
	* node will notify anyone who is trying to subscribe to this topic name,
	* and they will in turn negotiate a peer-to-peer connection with this
	* node.  advertise() returns a Publisher object which allows you to
	* publish messages on that topic through a call to publish().  Once
	* all copies of the returned Publisher object are destroyed, the topic
	* will be automatically unadvertised.
	*
	* The second parameter to advertise() is the size of the message queue
	* used for publishing messages.  If messages are published more quickly
	* than we can send them, the number here specifies how many messages to
	* buffer up before throwing some away.
	*                                         创建的msg         发布者   参数队列大小  */
    ros::Publisher pub = st.advertise<student_topic::student>("stu_info",3);  //创建 publisher 对象
    ros::Rate loop_rate(0.5);             //创建 rate 对象，定义循环发布频率1HZ,1s
    while(ros::ok()){                     //只要ros没有关闭，一直循环
        ROS_INFO("ROS_talker: name=%s , num=%s , score=%d",stu.name.c_str(),stu.num.c_str(),stu.score); //相当于printf()输出,注意字符串不能直接输出会乱码，需要使用c.str()函数
        pub.publish(stu);                 //发布消息
        loop_rate.sleep();                //延时
    }
    return 0;
}
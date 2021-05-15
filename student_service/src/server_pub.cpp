#include <ros/ros.h>
#include <student_service/stu.h>

//                    实例化stu.srv中Request结构体为 req                     Responce实例化为 res
bool handle_function(student_service::stu::Request &req, student_service::stu::Response &res){
	//显示请求信息
	ROS_INFO("Request from %s with age %d", req.r_name.c_str() , req.r_age);
	//处理请求，结果写入 response
	res.s_name = "Qinyuan";     //Server 的名字
	res.s_age = 22;			//Server 的年龄
	//返回 true，正确处理了请求
	return true;
}

//主函数
int main(int argc, char** argv){
	ros::init(argc, argv, "student_server"); //解析参数，命名节点
	ros::NodeHandle sr; //创建句柄，实例化为 sr
	// 创建服务，命名为 stu_server 功能函数为 handle_function
	ros::ServiceServer service = sr.advertiseService("stu_server", handle_function);
	//单线程阻塞等待 Client 申请
	ros::spin();
	return 0;
}
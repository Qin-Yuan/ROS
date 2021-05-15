#!/usr/bin/env python 
#coding:utf-8

import rospy
from student_service.srv import *

#定义服务函数
def server_srv():
    # 初始化节点，命名为 stu_server node
    rospy.init_node("stu_server")
    # 创建一个服务端，第一个参数为服务名，第二个参数为srv文件的名称，第三个参数为处理函数，第二个参数传递给第三个参数
    s = rospy.Service("stu_srv" , stu , handle_func)
    # 单线程阻塞式
    rospy.spin()

#定义处理函数
def handle_func(req):
    # 输出 client 请求方信息
    rospy.loginfo("Request from %s , age %d" % (req.r_name,req.r_age))
    # 回复消息 ，相当于执行了 req.s_name = "Qinyuan" ， req.s_age = 21
    return stuResponse("Qinyuan" , 21 )

#主函数
if __name__ == '__main__':
    server_srv()
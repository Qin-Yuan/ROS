#!/usr/bin/env python 
# coding:utf-8 

import rospy
from student_service.srv import *

# 定义客户端函数
def client_srv():
    rospy.init_node("stu_client")
    # 等待又可用的服务 stu_srv
    rospy.wait_for_service("stu_srv")
    try:
        # 创建客户端，订阅 stu_srv 服务器，类型为 stu
        c = rospy.ServiceProxy("stu_srv" , stu)
        # 向服务端发起请求
        req = c.call("Benny",20)
        # 输出 srv 中的消息传递
        rospy.loginfo("Response from %s , age %d" % (req.s_name,req.s_age))
    #如果连接不成功输出 错误
    except rospy.ServiceException , e:
        rospy.logwarn("Service call failed: %s"%e)

# 主函数
if __name__ == '__main__':
    client_srv()
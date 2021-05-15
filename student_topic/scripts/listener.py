#!/usr/bin/env python
#coding:utf-8   #使python文件支持中文注释，否则会报错

import rospy
from student_topic.msg import student

#定义回调函数
def callback(msg):
    #输出 msg 日志
    rospy.loginfo("Listener: name=%s num=%s score=%d" % (msg.name, msg.num, msg.score))

#消息订阅函数
def listener():
    # 初始化节点 ，命名为pylistener
    rospy.init_node("pylistener" , anonymous=True)
    # 订阅 stu_talker 话题的消息 ，一旦发布消息触发callback回调函数，将student.msg作为参数传递给回调函数
    rospy.Subscriber("stu_talker" , student , callback)
    # rospy中没有spinOnce()，只用spin()
    rospy.spin()

if __name__ == '__main__' :
    # 执行订阅函数
    listener()
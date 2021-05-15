#!/usr/bin/env python
#coding:utf-8   #使python文件支持中文注释，否则会报错

import rospy   # 导入rospy库
from student_topic.msg import student  #导入msg消息 

def talker():
    # 创建消息发布者
    # stu_talker 为定义的话题名称，供其他程序订阅
    # student 是数据类型，就是创建的msg文件名称
    # queue_size 缓冲区大小，队列长度，不宜过大也不宜过小
    # pub 为实例化的消息发布者，方便后面发布消息
    pub = rospy.Publisher("stu_talker",student,queue_size=10)
    # 初始化节点，节点命名为 pytalker
    rospy.init_node("pytalker", anonymous=True)
    # 设置频率，1HZ 即1s
    rate = rospy.Rate(1)
    # 对msg中的参数进行赋值
    name = "Qinyuan"
    num = "123456"
    score = 100
    # 判断节点是否关闭rospy.is_shutdown() , roscpp中用 ros::ok() 判断
    while not rospy.is_shutdown():
        # rospy中使用loginfo输出日志，与roscpp中的ROS_INFO作用相同
        rospy.loginfo("talker：name=%s num=%s score=%d" % (name,num,score))
        # 发布消息，stutent为创建的msg名称
        pub.publish(student(name,num,score))
        # 相当延时 1s
        rate.sleep()

# python中的主函数，会默认重复执行该函数
if __name__ == '__main__' :
    # 定义的功能函数
    talker()

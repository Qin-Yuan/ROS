#!/usr/bin/env python 
#coding:utf-8

import rospy

def param_do():
    rospy.init_node("param_do")
    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        # 获取全局param值 name = Qinyuan
        param_global = rospy.get_param("/name")
        rospy.loginfo("param_global -> %s" % param_global)
        # 添加参数，如果获取失败把参数赋值给param_error
        param_error = rospy.get_param("/name1",default="error")
        rospy.loginfo("param_erro -> %s" % param_error)
        # 获取局部param值 name =  Benny
        param_local = rospy.get_param("param_do/name")
        rospy.loginfo("param_local -> %s" % param_local)

        #输出 所有的 param 参数
        params = rospy.get_param_names()
        rospy.loginfo("params list : %s" % params)
        #周期1s
        rate.sleep()
if __name__ == '__main__':
    param_do()
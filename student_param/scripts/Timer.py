#!/usr/bin/env python 
#coding:utf-8

import rospy


'''
rospy.TimerEvent 类型包括以下属性：
    last_expected
    理想情况下为上一次回调应该发生的时间
    last_real
    上次回调实际发生的时间
    current_expected
    本次回调应该发生的时间
    current_real
    本次回调实际发生的时间
    last_duration
    上次回调所用的时间（结束-开始）
'''
# 回调函数 event 是 回调函数的传入值 TimerEvent类型
def callback(event):
    print("回调函数触发应该的时间 current_real：" + str(event.current_real))

if __name__ == '__main__':
    rospy.init_node("Timer_test") # 必须初始化节点
    rospy.Timer(rospy.Duration(2), callback) #每2s触发一次callback函数
    rospy.spin()   # 触发回调函数，必须要
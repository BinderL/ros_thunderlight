#!/usr/bin/env python
import rospy
from std_msgs.msg import String
from std_msgs.msg import Int32
from Tkinter import *
import Application


def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "I heard %i", data.data)

def initTKspace():
  root = Tk()
  ex = Application.Application(master=root)
  root.geometry("400x100+300+300")
  root.mainloop()
  root.destroy()
    
def listener():

    # In ROS, nodes are uniquely named. If two nodes with the same
    # name are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'listener' node so that multiple listeners can
    # run simultaneously.
    initTKspace()
    rospy.init_node('listener', anonymous=True)

    rospy.Subscriber("chatter", Int32, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()













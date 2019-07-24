#!/usr/bin/env python

"""
ThunderLight Project : graphical Gui for thunderLight simulation

this class is the link between ros callback listener and the gui App. 

Author: Quentin Marmouget
Last modified:  

"""

import rospy
from std_msgs.msg import String
from std_msgs.msg import Int32
from Tkinter import *
import Application

def listener():
    # In ROS, nodes are uniquely named. If two nodes with the same
    # name are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'listener' node so that multiple listeners can
    # run simultaneously.
  rospy.init_node('DMX_listener', anonymous=True)

#  rospy.Subscriber("DMX_Canal1", Int32, callback)

    # spin() simply keeps python from exiting until this node is stopped
  root.mainloop()
  root.destroy()
  while not rospy.is_shutdown():
    rospy.spin()

if __name__ == '__main__':
  root = Tk()
  App = Application.Application(master=root)
  listener()













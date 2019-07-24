#!/usr/bin/env python

"""
ThunderLight Project : graphical Gui for thunderLight simulation

this class aims at providing a sustainable way to represent independent part of the light called strips
basically a Strip is a rectangle filled with several rectangles with colours depends on intensity and Led colours.
There is (30 * n_element) rectangles on one strips. (n_element is an integer from 1 to 8).  

Author: Quentin Marmouget
Last modified:  

"""

import rospy
from Tkinter import *
import Element
from std_msgs.msg import Int32

class Strip(Frame):

  def __init__(self, master=None, Id = 0 ,angle = 0, antecedent = 0, size_barette = 1):
    self.isStripInit = False
    Frame.__init__(self, master)
    self._angle = angle
    self._id = Id
    self._antecedent = antecedent
    self._size_barette = size_barette
    self.element_tab = []
    self.initUI()
    self.listen = rospy.Subscriber("DMX_Canal" + str(self._id), Int32, self.update)
    

  def initUI(self):

    for i in range(0, self._size_barette):
       self.element_tab.append(Element.Element(master = self.master))
#    self.element_tab.append(Element.Element(master = self.master))
#    self.element_tab.append(Element.Element(master = self.master))
    print("geometrie initialized")
    self.isStripInit = True



  def update(self, data):
    if self.isStripInit == True :
      print("callback fct for strips number = " + str(self._id), data)
      for i in range(0, self._size_barette):
        self.element_tab[i].dmx_update(data.data)

  def shutdown(self) :
    self.listen.unregister()





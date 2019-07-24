#!/usr/bin/env python

"""
ThunderLight Project : graphical Gui for thunderLight simulation

this class is the main container application. 

Author: Quentin Marmouget
Last modified:  

"""

from Tkinter import *
from ttk import *
import Strip
import rospy


class Application(Frame):

  def __init__(self, master=None):
    Frame.__init__(self, master)
    self.initUI()

  def initUI(self):

    self.master.title("ThunderLight IHM")
    self.pack(fill=BOTH)
    Style().configure("TFrame", background="#E0E0E0")
    self.centerWindow()
    self.setMainButton()
    self._strips = []

  def centerWindow(self):

#    sw = self.master.winfo_screenwidth()
#    sh = self.master.winfo_screenheight()
    sw = 1366 # my screen
    sh = 768 # my screen

    self.w = 290*3
    self.h = 150*3

    x = (sw - self.w)/2
    y = (sh - self.h)/2
    self.master.geometry('%dx%d+%d+%d' % (self.w, self.h, x, y))

  def setMainButton(self):
    self.frame = Frame(self.master)
    self.frame.pack(side = BOTTOM, fill=BOTH)
 
    quitButton = Button(self.frame, text="Quit",
      command=self.exit, width= 5)
    quitButton.pack(side=RIGHT, padx=5, pady=20)
#    quitButton.place(x= self.w - 80, y= self.h - 40)

    add_strips = Button(self.frame, text="Add Strip", command=self.addStrip, width= 20)
#    add_strips.place(x= self.w - 80, y= self.h - 40)
    add_strips.pack(side=LEFT, padx=5, pady=20)


  def addStrip(self):
    _strip = Strip.Strip(master = self.master, Id =  len(self._strips), angle = 0, antecedent = 0, size_barette = 1) 
    self._strips.append(_strip)

  def exit(self):
    #self.destroy
    for element in self._strips :
      element.shutdown()
    self.quit()
    rospy.signal_shutdown("shutdown") 
    self.destroy()



  
     
    








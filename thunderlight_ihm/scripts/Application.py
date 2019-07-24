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
    self.initCanvas()

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

    add_strips = Button(self.frame, text="Add Strips", command=self.addStrips, width= 20)
#    add_strips.place(x= self.w - 80, y= self.h - 40)
    add_strips.pack(side=LEFT, padx=5, pady=20)

  def initCanvas(self) :
    self.canvas = Canvas(self)
    self.canvas.pack(fill=BOTH)


  def addStrips(self):
    _antecedent = [(0,0),(1,0),(2,1)]
    angle = [0, 0, 30]
    elem = [1, 1, 1]
    for i in range(0,3) : #_antecedent
      print(i)
      if _antecedent[i][0] == 0 :                        #origine depend de la taille de la fenetre
        antecedent = [0,200] 
      else :
        antecedent = self._strips[_antecedent[i][1]].getEndStrip()
      _strip = Strip.Strip(master = self.master, 
                           canvas = self.canvas,
                           Id =  _antecedent[i][0], 
                           angle = angle[_antecedent[i][0]], 
                           antecedent_x = antecedent[0], 
                           antecedent_y = antecedent[1], 
                           size_barette = elem[i]) 
      self._strips.append(_strip)
    print("geometrie initialized with " + str(len(self._strips)) + " independent Strips" )

  def exit(self):
    #self.destroy
    for element in self._strips :
      element.shutdown()
    self.quit()
    rospy.signal_shutdown("shutdown") 
    self.destroy()



  
     
    








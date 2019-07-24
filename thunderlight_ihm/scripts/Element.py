#!/usr/bin/env python

"""
ThunderLight Project : graphical Gui for thunderLight simulation

this class aims at providing a sustainable way to represent element from strips
basically a Strip is a rectangle filled with several element means rectangles with colours depends on intensity and Led colours.
an element is a geometrical representation 
Author: Quentin Marmouget
Last modified:  
"""

from Tkinter import *
import cmath, math
import time;  


class Element(Frame):

  def __init__(self, master=None, canvas = None, angle = 0, x_antecedent = 0, y_antecedent = 0, elem = 1):
    Frame.__init__(self, master)
    self._canvas = canvas
    self._Led = 32
    self._lengthLED = 4                  # distance between leds
    self._largeur = 15
    self._Cypher = 0.2 #coeff for design part between elements
    self._lengthE = self._Led * self._lengthLED + 2 * self._largeur # 10 mm between leds and 5mm at the begin and the end of the board.
    self._e = 2
    self._angle = angle
    self.led_tab = []
    self.x_antecedent = x_antecedent
    self.y_antecedent = y_antecedent
    self.initUI() 
     

  def fromDegtoRad(self):
    self._angle = self._angle * math.pi / 180

  def computeCAngleFromAngle(self):
    cangle = cmath.exp(angle*1j) # angle in radians

  def computeCangleFromdxdy(self):
    cangle = complex(dx, dy) #
    cangle = cangle / abs(cangle)

  def computeXY(self):
    x = 0   #modify self._length
    y = 0
    center_rot = complex(self.x_antecedent, self.y_antecedent)
   
    for x, y in coordinates:
      v = cangle * (complex(x, y) - center_rot) + center_rot

  def initUI(self):

#origine and end element 
    self.setNodeElement()

#Body element
    self.setCore_element()

  def _create_circle(self, x, y, r, **kwargs):
    self._canvas.create_oval(x-r, y-r, x+r, y+r, **kwargs)

  def setCore_element(self,_stringHEX = "#fb0" ):
    xy = [(self.xy_origin[0] + self._Cypher * self._largeur, self.xy_origin[1] - self._largeur),
          (self.xy_origin[0] + self._Cypher * self._largeur, self.xy_origin[1] + self._largeur), 
          (self.xy_origin[0] + self._Cypher * self._largeur + self._lengthLED, self.xy_origin[1] + self._largeur), 
          (self.xy_origin[0] + self._Cypher * self._largeur + self._lengthLED, self.xy_origin[1] - self._largeur)
    ]
    newxy = []
    for i in range(0, self._Led ) :
      for x, y in xy: 
        newxy.append(x + self._lengthLED * i + i * self._e)
        newxy.append(y)
      self.led_tab.append(self._canvas.create_polygon(newxy,
            outline= _stringHEX, fill= _stringHEX))

  def setNodeElement(self) :
#ORIGINE
    if self.x_antecedent == 0 & self.y_antecedent == 0 :
      self.xy_origin = (self.x_antecedent,self.y_antecedent)
    else :
      self.xy_origin= (self.x_antecedent,self.y_antecedent)
    self._create_circle(self.xy_origin[0], self.xy_origin[1], self._Cypher * self._largeur, outline="#ff0", fill="#ff0")
#END
    self.xy_end = [self.xy_origin[0] + self._Led * self._lengthLED + (self._Led - 1) * self._e + 2 * self._Cypher * self._largeur, self.xy_origin[1]]   
    self._create_circle(self.xy_end[0], self.xy_end[1], self._Cypher * self._largeur, outline="#ff0", fill="#ff0")


  def dmx_update(self, data):
# data value from 0 to 255
    _hex = hex(data)
    _hex = _hex[1:]
    _hex = _hex.replace("x", "#")
    _stringHEX = _hex +'0000'
    ticks = time.time()
    self.setColor(_stringHEX)
    ticks = ticks - time.time()
    print ticks

  def setColor(self, _stringHEX) : #  self._id
    for _id in self.led_tab : 
      self._canvas.itemconfig(_id, outline= _stringHEX, fill= _stringHEX)




#Exemple for allows the user to use the mouse to rotate an item around a given center point
#def getangle(event):
  #  dx = c.canvasx(event.x) - center[0]
  #  dy = c.canvasy(event.y) - center[1]
  #  try:
 #       return complex(dx, dy) / abs(complex(dx, dy))
  #  except ZeroDivisionError:
  #      return 0.0 # cannot determine angle

#def press(event):
 #   # calculate angle at start point
 #   global start
#    start = getangle(event)

#def motion(event):
    # calculate current angle relative to initial angle
 #   global start
#    angle = getangle(event) / start
#    offset = complex(center[0], center[1])
#    newxy = []
#    for x, y in xy:
#        v = angle * (complex(x, y) - offset) + offset
#        newxy.append(v.real)
#        newxy.append(v.imag)
#    c.coords(polygon_item, *newxy)

#c.bind("<Button-1>", press)
#c.bind("<B1-Motion>", motion)

#mainloop()




























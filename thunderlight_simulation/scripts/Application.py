#!/usr/bin/env python3

"""
ZetCode Tkinter tutorial

This program draws three
rectangles filled with different
colours.

Author: Jan Bodnar
Last modified: April 2019
Website: www.zetcode.com
"""

from Tkinter import *


class Application(Frame):

  def __init__(self, master=None):
    Frame.__init__(self, master)
    self.initUI()

  def initUI(self):

    self.master.title("Colours")
    self.pack(fill=BOTH, expand=1)

    canvas = Canvas(self)
    canvas.create_rectangle(30, 10, 120, 80,
            outline="#fb0", fill="#fb0")
    canvas.create_rectangle(150, 10, 240, 80,
            outline="#f50", fill="#f50")
    canvas.create_rectangle(270, 10, 370, 80,
            outline="#05f", fill="#05f")
    canvas.pack(fill=BOTH, expand=1)








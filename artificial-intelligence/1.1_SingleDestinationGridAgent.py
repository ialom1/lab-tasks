# -*- coding: utf-8 -*-
"""
Created on Sat May 29 15:56:43 2019

@author: Sarwar
"""

print("Grid size 10x10")
sr = int(input('starting row position '))
sc = int(input('starting column position '))

gr = int(input('goal row position '))
gc = int(input('goal column position '))

if gr>sr:
    a = gr-sr
    while a > 0:
        print("DOWN")
        a-=1
else:
    a = sr-gr
    while a > 0:
        print("UP")
        a-=1

if gc>sc:
    a = gc-sc
    while a > 0:
        print("RIGHT")
        a-=1
else:
    a = sc-gc
    while a > 0:
        print("LEFT")
        a-=1
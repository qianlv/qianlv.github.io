#!/bin/env python
#encoding=utf-8

value = 1.0/(1<<4) + 1.0/(1<<5) + 1.0/(1<<8)+ 1.0/(1<<9)+ 1.0/(1<<12)+ 1.0/(1<<13)+ 1.0/(1<<16)+ 1.0/(1<<17)+ 1.0/(1<<20)+ 1.0/(1<<21)
value = 0.1 - value
print value
diff = value * 100*60*60*10
print diff
diff_dis = value * diff
print diff_dis


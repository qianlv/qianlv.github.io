#!/usr/bin/env python
#encoding=utf-8
'''
把一个Unicode字符串用utf-8编码写入文件中,然后再读取出来
'''
CODEC = 'utf-8'
FILE = 'unicode.txt'

hello_out = u"Hello world\n"
bytes_out = hello_out.encode(CODEC)
f = open(FILE, "w")
f.write(bytes_out)
f.close()

f = open(FILE, "r")
bytes_in = f.read()
f.close()
hello_in = bytes_in.decode(CODEC)
print hello_in

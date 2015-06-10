---
layout: post
title: Python核心编程笔记-Python数字
tag: Python, Python Numbers, 笔记, 读书笔记
---

{{ page.title }}
================

1. 数字类型
-------------
*****
# 
>&nbsp;&nbsp;&nbsp;&nbsp;数字是不可更改的类型，变更数字的值会生成新的对象（python一切都是对象) <br />
>&nbsp;&nbsp;&nbsp;&nbsp;在Python 中, 变量更像一个指针指向装变量值的盒子。 对不可改变类型来说, 你无法
改变盒子的内容, 但你可以将指针指向一个新盒子。

        # 创建数值对象
        anInt = 1
        aLong = -9999999999L
        aFloat = 3.141592638
        # 更新对象
        anInt += 1
        aFloat = 2.1415
        # 删除对象，事实上你无法真正删除一个数值对象，你只
        ＃能删除一个数值对象的引用
        del anInt
        del aLong, aFloat

2. 整型(types of integers)
--------------------------
*****
# 
*   Boolean(布尔型)
*   "0"开始为八进制数, "0x"或"0X"开始为十六进制数
*   整型和长整型同一(支持高精)

        print 1 << 65

3. 浮点数
----------
*****
# 
>&nbsp;&nbsp;&nbsp;&nbsp;类似C语言中的double类型，完全遵守 IEEE754 号规范, (52M/11E/1S) ,
其中 52 个比特用于表示底,11 个比特用于表示指数(可表示的范围大约是正负 10 的 308.25 次方) 剩下的一个比特表示符号。

4. 复数
----------
****
# 
*   虚数不能单独存在,它们总是和一个值为 0.0 的实数部分一起来构成一个复数。
*   复数由实数部分和虚数部分构成
*   表示虚数的语法: real+imagj
*   实数部分和虚数部分都是浮点数
*   虚数部分必须有后缀 j 或 J。
        
        aComplex = -7.0 - 1.7j
        print aComplex.real # 实部
        print aComplex.imag # 虚部
        print aComplex.conjugate() # 对应的共轭复数
        #-7.0,  -1.7  (-7.0 + 1.7j)

5. 运算符　
------------
*****
# 
运算中类型转换规则(coerce函数规则)
# 
![Alt Python-style-change-rule](/images/coerce-style-change-rule.png)

6. 数值工厂函数和内建函数
--------------
*****
工厂函数: 

*   bool(obj)           __nonzero__()方法的返回值
*   int(obj, base=10)   字符串或数值对象的整数表示
*   long(obj, base=10)  字符串或数值对象的长整数表示当obj是字符串时,可以用base指定进制
*   float(obj)          字符串或数值对象的浮点数表示
*   complex(str) or complex(real, imag=0.0) 返回复数表示

        int('1011', 2) # 11

内建函数:
        
        abs(-1)
        abs(3 - 4j) # 5.0 sqrt(3^2 + 4^2)
        coerce(1.3, 124L) # (1.3, 134.0)
        coerce(1.23 - 42j, 124L) # ((1.23 - 42j), (134 + 0j))
        divmod(10, 3)   # (3, 1)
        pow(2,10, 6)    # 2^10 % 6
        round(3.49999, 1)     # 四舍五入3.5
        import math
        math.floor(3.4)       # 小于等于的整数

进制转换和ASCII转换

*   hex(num)    返回16进制数的字符串
*   oct(num)    返回8进制数的字符串
*   chr(num)    ASCII值数字转换为ASCII字符, 0 <= num <= 255
*   ord(chr)    接受一个ASCII或Unicode 字符(长度为1字符串), 返回对应ASCII或Unicode值
*   unichr(num) 接受Unicode码值, 返回 Unicode 字符,0 <= i <= 0x10ffff

        unichr(1234) # u'\u04d2'
        ord(u'\u04d2') # 1234

7. 伪随即数生成器(random模块)
------------------
****
# 

*   randint(a, b)   返回[a,b]的随机整数
*   randrange([start,] stop [,step]) 返回随机整数
*   uniform(a,b)　Get a random number in the range [a, b) or [a, b] depending on rounding.
*   random()    返回[0, 1) 随机数
*   choice(seq) 随机返回序列中的一个数

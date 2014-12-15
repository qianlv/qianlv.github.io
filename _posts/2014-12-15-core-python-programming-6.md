---
layout: post
title: Python核心编程笔记-Python序列
tag: Python, Python 序列, Python Strings, Python Lists, Python Tuples,笔记, Note
---
{{ page.title }}
===============

1. 序列
-------------
***
序列索引:

![Alt Python-sequence](/images/Python-sequence.png) 

序列类型操作符:

*   `seq[index]`
*   `seq[ind1:ind2]`
*   `[ ], [ : ], [ : : ] 切片操作`
*   `seq * expr      重复`
*   `seq1 + seq2     连接`
*   `obj in seq`
*   `obj not in seq`

        s = 'abcdefgh'
        s[::-1] # 翻转'hgfedcba'
        s[::2] # 'aceg'
        print ('zero', 'one', 'two')[-100:100]
        # 切片索引超过范围也不会报错
        for i in [None] + range(-1, -len(s), -1):
            print s[:i]

工厂函数(将对象浅拷贝到新生成的对象中):

*   `list(iter)  把可迭代对象转换为列表`
*   `str(obj)    将对象转换成字符串`
*   `unicode(obje) 将对象转换成Unicode字符串`
*   `basestring() str 和 unicode 的父类, 抽象工厂函数, 不能被实例化，无法调用`
*   `tuple(iter) 把可迭代对象转换为元组对象`

>__Python objects are created, we cannot change their identity or their type. If
you pass a list to *list()*, a (shallow) copy of the list’s objects will be made
and inserted into the new list. This is also similar to how the concatenation
and repetition operators that we have seen previously do their work.A shallow 
copy is where only references are copied...no new objects are made!__

内建函数:

*   `enumetate(iter)`
*   `len(seq)`
*   `max(iter)`
*   `min(iter)`
*   `reversed(seq)`
*   `sorted(iter, func=None), key=None, reverse=False)`
*   `sum(seq, init=0)`
*   `zip([iter0, iter1, ..., iterN])`

# 
2. 字符串(Strings)
------------------
***


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
>   Python中字符串单引号和双引号是一样的，是一种不可修改(Immutable)的类型. <br />
>   字符串类型: 普通字符串(*str*), Unicode的字符串(*unicode*), 抽象类basestring.

        # Create and Assign Strings
        aString = 'Hello World!'
        s = str(range(4)) # '[0, 1, 2, 3]'
        # Access Values in Strings
        print aString[0]
        print aString[1:] 
        # Update Strings by reassigning 
        aString = aString[:6] + 'Python!'
        # Remove Characters and Strings 
        # 由于String对象不可改变,所以只可以重新赋值或del变量
        aString = 'Hello World!'
        aString = aString[:3] + aString[4:]
        print aSting
        aString = ''
        del aString

>   字符串一些操作

        # string模块
        import string
        print string.uppercase # 大写字母
        print string.lowercase # 小写字母
        print string.letters   # 字母
        print string.digits    # 数字
        print 'I ' + 'Love ' + 'You'
        print string.upper(string.lowercase)
        # % 格式化操作符
        '%s %s' % ('abc', 'edf')
        s = ' '.join(('abc', 'edf', 'ghi'))
        #'abc edf ghi'
        'hell' + u'' # str 转换为unicode

>   字符串模版(Template)

        from string import Template
        s = Template('There are ${howmay} ${lang} Quotation Symbols')
        # safe_substitute(self, *args, **kws)
        # substitute(self, *args, **kws)

        print s.substitute(lang='Python', howmay=3)
        # There are 3 Python Quotation Symbols
        # print s.substitute(lang='Python') 抛出 KeyError 异常
        print s.safe_substitute(lang='Python')
        # 缺少时按原字符串输出
        # There are ${howmay} Python Quotation Symbols
        
        # 修改分隔符
        class MyTemplate(Template):
            delimiter = '#'
        s = MyTemplate("This is my new #template")
        print s.substitute(Template = 'TEMPLATE')

>   原始字符串(r/R) <br />
>   一般用于正则表达式创建

        print '\n'
        print r'\n'
        print '\\n'
        # f = open('C:\windows\temp\readme.txt', 'r'), 其中'\t' 和 'r' 被当做特殊符号, 从而无法打开文件
        f = open(r'C:\windows\temp\readme.txt', 'r')

        import re
        m = re.search('\\[rtfvn]', r'Hello World\n')




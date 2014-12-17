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

>   __字符串一些操作__

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

>   __字符串模版(Template)__

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

>   __原始字符串(r/R)__ <br />
>   一般用于正则表达式创建

    print '\n'
    print r'\n'
    print '\\n'
    # f = open('C:\windows\temp\readme.txt', 'r'), 其中'\t' 和 'r' 被当做特殊符号, 从而无法打开文件
    f = open(r'C:\windows\temp\readme.txt', 'r')

    import re
    m = re.search('\\[rtfvn]', r'Hello World\n')
    if m is not None: m.group()
    # m 等于 None
    m = re.search(r'\\[rtfvn]', r'Hello World\n')
    if m is not None: m.group()
    # m.group() 等于'\\n'

>   __unicode String(u/U)__

        u'abc'

>   __String Built-in Methods__

    quest = 'what is your favorite color?'
    quest.capitalize()
    # 'What is your favorite color?'
    quest.count('or')
    # 2
    quest.endswith('blue')
    # False
    quest.endswith('color?')
    # True
    quest.find('or', 30)
    # -1
    quest.find('or', 22)
    # 25
    quest.index('or',10) # 等于find, 如果没找到字符串那么抛出异常(valueError)
    ':'.join(quest.split())
    # 'what:is:your:favorite:color?'
    quest.replace('favorite color', 'quest')
    # 'what is your quest?'
    quest.upper()


3.  Unicode
--------------------
******

>   Unicode 使用一个或多个字节表示一个字符
>   codec是Coder/DECoder的首字母组合,它定义了文本跟二进制值的装换方式，
>   codec常见的四种编码方式是: ASCII, ISO8859-1/Latin-1, UTF-8, UTF-16
>   UTF-8兼容ASCII最为著名

>   __编码(encode)解码(decode)__<br />

>   Unicode支持多种编码格式,这为程序员带来了额外的负担,每当你向一个文件写入字符串的时候,
你必须定义一个编码(encoding参数)用于把对应的Unicode内容转换成你定义的格式,Python
通过Unicode字符串的encode()函数解决了这个问题,该函数接受字符串中的字符为参数,输出
你指定的编码格式的内容.<br />
>   所以,每次我们写一个Unicode字符串到磁盘上我们都要用指定的
编码器给他"编码"一下,相应地,当我们从这个文件读取数据时,我们必须"解码"该文件,使之成
为相应的Unicode字符串对象.

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

[源代码uniFile.py](/code/core_python_programming/uniFile.py)

>   Unicode应用到实际应用中, 遵循一些规则

*   Always prefix your string literals with 'u'
*   Never use str()...always use unicode() instead
*   Never use the outdated string module－it blows up when pass it any non-ASCII characters.
*   __Avoid unnecessary encoding and decode of Unicode strings in your pragram,
    Only call the encode() method right before you write your text to a file, database(数据库),
    or teh network, and only call the decode() method when your are reading it back in.__

*   [对于Unicode理解参考](http://blog.jobbole.com/50345/)
























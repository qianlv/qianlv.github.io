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

*   [对于Unicode理解参考](http://www.cnblogs.com/huxi/archive/2010/12/05/1897271.html)
*   [stackoverflow](http://stackoverflow.com/questions/11339955/python-string-encode-decode/11339995#11339995)

4.  列表(List)
---------------
***

>   列表使可修改的(mutable), 可添加任意数量的对象, 对象可以是标准类型或是用户定义的。

    # create and assgin lists
    aList = [123, 'abc', 456, ['inner', 'list'], 7-9j]
    antherList = [None, 'something to see here']
    print list('foo')
    #['f', 'o', 'o']

    # access values in lists
    print aList[0]
    print aList[:3]
    print aList[3][1]

    # update lists
    aList[2] = 'float opeator'
    aList.append('append')

    # remove list elements and lists
    del aList[1]
    aList.remove('float opeator')
    del aList
    
>   

5. 元组
-------------
***

>   元组创建: `aTuple = (123, 'abc',)`, `aTuple = 123, 'abc'` , __逗号才是tuple构造语法__  
>   空元组: (,) 区分普通括号. 单个元素的元组必须有逗号`(123,)`  
>   PS:元组最后一个元素后加逗号，方便拓展而且不会出错.   
>   __元组是不可修改的__  
>   元组可以通过重新创建对象修改, 并且元组内的__可变对象__是可以改变的  
>   __字典关键字__:不可改变对象的值是不可改变的，因此它们hash后的值是相同的，
    这是字典键值的的一个必备条件,因此tuple符合这个条件, list不行  
>   tuple 和 list 可以简单地通过内建函数tuple()和list()转换  

    t = ('123', '456',)
    t = t + (1, 2,)
    print t
    t = (['xyz', 123], 23, -103.4,)
    t[0][1] = ['abc', 'def']
    print t
    # (['xyz', ['abc', 'def']], 23, -103.4,)

    # 使用圆括号表达式表示元组，用于避免一些副作用
    t = 4, 2 < 3, 5 # (4, True, 5)
    (4, 2) < (3, 5) # False

    # 单元素元组 
    type(('xyz')) # <type 'str'> 圆括号被当作了分组操作符
    type(('xyz',)) # <type 'tuple'>

    # 字典关键字
    t = {}
    t[(1, 2,)] = 1
    t[[1, 2]] = 2 # TypeError: unhashable type: 'list'

6. 浅拷贝和深拷贝
-----------------
***

>   浅拷贝: 就是新创建一个相同类型的对象，它的内容是原来对象元素的引用，
    也就是说，拷贝的对象本身是新的, 当它的内容不是。  
>   浅拷贝几种方式: (1). 完全切边操作 (2). 工厂函数, 如list(), tuple()等 (3). copy模块的copy函数

    persons = ['name', ['savings', 100.00]]
    hubby = persons[:] # slice copy
    wifey = list(persons) # fac func copy
    [id(x) for x in persons, hubby, wifey]
    # 内存地址不同, 这里没有同时改变是字符串是不可改变对象
    hubby[0] = 'joe'
    wifey[0] = 'jane'
    hubby, wifey
    # (['joe', ['savings', 100.00]], ['jane', ['savings', 100.00]])

    hubby[1][1] = 50.0 # 原有内容的引用, 因此一起改变了
    hubby, wifey, persons
    # (['joe', ['savings', 50.0]], ['jane', ['savings', 50.0]], ['name', ['savings', 50.0]]

>   __深拷贝__：创建一个新的__容器对象__，包含对原对象元素(引用)全新拷贝的引用。  
    方式: copy.deepcopy()  
>   __一些警告:__  
    (1). 非容器类型(如数字, 字符串, 其他'原子(atomic)'对象, 
    如代码(code), 类型(type)和xrange对象等)没有被拷贝一说  
    (2). 如果元组中只包含原子类型对象, 它的深拷贝不会进行  

    persons = ['name', ['savings', 100.00]]
    import copy
    wifey = copy.deepcopy(persons)
    [(id(x), id(y)) for x, y in zip(persons, wifey)]
    # [(140587125259888, 140587125259888), (140587071805920, 140587071898256)]
    # 字符串'name' 没有进行深拷贝

    persons = ['name', ('savings', 100.00)]
    newPersons = copy.deepcopy(persons)
    id(persons) == id(newPersons) # False
    [id(x) == id(y) for x, y in zip(persons, newPersons)]
    # [True, True] 没有进行深拷贝



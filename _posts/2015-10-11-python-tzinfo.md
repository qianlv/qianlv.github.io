---
layout: post
title: python时区
tag: python, datetime, tzinfo, 时区
---

{{ page.title }}
==================

## 1. utc

协调世界时（英：Coordinated Universal Time ，法：Temps Universel Coordonné），又称世界统一时间，
世界标准时间，国际协调时间。英文（CUT）和法文（TUC）的缩写不同，作为妥协，简称UTC, 实际为英国伦敦本地时间.  
UTC + 时差 = 本地时间(UTC + (+8000) = 北京时间)

## 2. datetime时区
datetime object 有2中类型:   
1. offset-native, 不带有时区信息, python默认都是这种类型, tzinfo属性为None.  
2. offset-aware, 带有时区信息, 需要自己实现tzinfo类(标准库中的tzinfo为抽象类).  
offset-native的datetime object可以通过replace方式替换tzinfo, 替换属性不会根据时间差改变.
offset-aware的datetime object 通过astimezone修改时区.  

下面就是一个继承tzinfo的子类, 然后实现不同时区间的转换的例子:  

    # encoding=utf-8
    class UTC(datetime.tzinfo):
        def __init__(self, utc):
            utc = str(utc.strip().upper())
            re_utc = re.compile(r'^([\+\-])([0-9]{1,2})\:([0-9]{1,2})$')
            mt = re_utc.match(utc)
            if mt:
                minus = mt.group(1) == '-'
                hours = int(mt.group(2))
                minutes = int(mt.group(3))
                if minus:
                    hours, minutes = -hours, -minutes
                self._tzname = 'UTC{}'.format(utc)
                self._utcoffset = datetime.timedelta(
                    hours=hours, minutes=minutes)
            else:
                raise ValueError('bad utc time zone')

        def utcoffset(self, dt):
            return self._utcoffset

        def tzname(self, dt):
            return self._tzname

        # 夏令时
        def dst(self, dt):
            return datetime.timedelta(0)

        def __str__(self):
            return 'UTC tzinfo object ({})'.format(self._tzname)

        __repr__ = __str__

    # 默认的datetime不带时区信息
    curdate = datetime.datetime.now()
    print curdate.tzinfo
    curdate = datetime.datetime.now(tz=UTC('-2:00'))  # 西2区的当前时间
    print curdate
    print curdate.tzinfo

    utc7 = UTC('+07:00')
    utc8 = UTC('+08:00')
    test_tuple = (2015, 10, 11, 14, 58)
    # utc8_time, utc7_time 不同时区的同一时刻
    utc8_time = datetime.datetime(*test_tuple, tzinfo=utc8)
    utc7_time = utc8_time.astimezone(utc7)
    print utc8_time
    print utc7_time
    timespan = utc8_time - utc7_time
    print type(timespan), timespan.total_seconds()


[完整代码](https://github.com/qianlv/learning/blob/master/python/datetime_tzinfo.py)

## 3. pytz库
获取tzinfo子类对象:  

    # 对于国家的时区列表
    print pytz.country_timezones('cn')  # [u'Asia/Shanghai', u'Asia/Urumqi']
    tz = pytz.timezone('Asia/Shanghai')

上述获取tz对象都是LMT(local Mean Time)为本地平均时间的时区,并不是标准时间(Standard Time):  

    test_tuple = (2015, 10, 11, 14, 58)
    dt = datetime.datetime(*test_tuple, tzinfo=tz)
    print repr(dt)
    # datetime.datetime(2015, 10, 11, 14, 58, tzinfo=<DstTzInfo 'Asia/Shanghai' LMT+8:06:00 STD>)
    # dt有一个LMT(local Mean Time)为本地平均时间, 时间是+8:06, 比北京时间快6分钟
    dt_cst = datetime.datetime(*test_tuple, tzinfo=utc8)
    print dt_cst == dt  # False 

正确方法:  

    # 正确获取构造offset-aware类型datetime object的方法是:
    # 使用timezone.localize()方法生成带时区的datetime, 不要通过构造函数中传入tzinfo的方式实现
    dt2 = datetime.datetime(*test_tuple)
    dt2 = tz.localize(dt2)
    print repr(dt2)
    # datetime.datetime(2015, 10, 11, 14, 58,
    # tzinfo=<DstTzInfo 'Asia/Shanghai' CST+8:00:00 STD>)
    # dt2 变为CST(China Standard Time), 时间+8:00:00也是对的
    print dt2 == dt_cst  # True

## 4. 夏令时
pytz处理normalize函数处理[夏令时](http://zh.wikipedia.org/w/index.php?title=%E6%97%A5%E5%85%89%E7%AF%80%E7%B4%84%E6%99%82%E9%96%93&variant=zh-cn), 特别是时区转换时.  

    eastern = pytz.timezone('US/Eastern')
    dt3 = datetime.datetime(2002, 10, 27, 1, 0)
    dt3 = eastern.localize(dt3)
    print dt3   # 2002-10-27 01:00:00-05:00
    dt4 = dt3 - datetime.timedelta(minutes=10)
    print dt4   # 2002-10-27 00:50:00-05:00
    dt5 = eastern.normalize(dt4)
    print dt5   # 2002-10-27 01:50:00-04:00
    print repr(dt4.tzinfo)
    print repr(dt5.tzinfo)
    # <DstTzInfo 'US/Eastern' EST-1 day, 19:00:00 STD>
    # <DstTzInfo 'US/Eastern' EDT-1 day, 20:00:00 DST>

## 5. 参考  
 
1.  [用datetime和pytz来转换时区](http://www.keakon.net/2010/12/14/%E7%94%A8datetime%E5%92%8Cpytz%E6%9D%A5%E8%BD%AC%E6%8D%A2%E6%97%B6%E5%8C%BA)
2.  [python时区设置——pytz模块](http://blog.csdn.net/starrain00/article/details/18323807)
3.  [understanding-datetime-tzinfo-timedelta-amp-timezo](http://agiliq.com/blog/2009/02/understanding-datetime-tzinfo-timedelta-amp-timezo/)

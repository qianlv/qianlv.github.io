---
layout: post
title: 《深入理解计算机系统》第二章 信息的表示和处理
tag: 深入理解计算机系统, 信息
---

&#160; &#160; &#160; &#160;

{{ page.title }}
==================

>   In isolation, a single bit is not very useful. When we group bits together and
apply some interpretation that gives meaning to the different possible bit patterns,
however, we can represent the elements of any finite set.

>   计算机用有限数量的位对数字编码，结果太大时，某些运算会溢出(overflow)
>   计算机整数运算满足真正整数运算的定律, 例如: 乘法的结合和交换律,下列运算都等于-884901888(int为32位时溢出)
>   (500\*400)\*(300\*200)  
>   ((500\*400)\*300)\*200  
>   ((200\*500)\*300)\*400  
>   400\*(200\*(300\*500))  

>   浮点运算溢出时特殊的值+∞, 由于表示的精度有限，浮点运算是不可以结合的.  
    例如多数机器上: (3.14\+1e20)\-1e20的值为0.0, 而3.14\+(1e20\-1e20)为3.14  
>   大量计算机的安全漏洞都是由于计算机算术运算的微妙细节引起的

1.  信息存储
--------------
>   __机器级程序将存储器视为一个非常大的字节数组,称为虚拟存储器(virtual memory)__,  
>   存储器的每个字节由唯一的数字标识,称为地址(address),所有可能的地址的集合称为  
>   虚拟地址空间(virtual address space).  

###1.1 寻址和字节顺序
>   考虑一个w位的整数[Xw-1, Xw-2,...X2,X1,X0],假设w是8的倍数,那么最高有效字节为  
>   [Xw-1,Xw-2,...,Xw-8],最低有效字节[X7,X6,...,X0]. 在存储器中低有效字节在前面  
>   方式为小端法(little endian),多数Intel兼容机采用这种规则. 高有效字节在前面的  
>   方式为大端法(big endian)  
![Alt endian](/images/endian.png)

>   小端法字节序列的阅读和显示相反, 例如:  64 94 04 08 实际表示08 04 94 64  
>   一个打印程序对象的字节表示的程序([源代码](/code/computer-systems-a-programmers-perspective/the_byte_representation_of_program_objects.c))

    #include <stdio.h>
    #include <string.h>
    
    typedef unsigned char *byte_pointer;
    
    void show_bytes(byte_pointer start, int len)
    {
        int i;
        for (i = 0; i < len; ++i)
        {
            printf(" %.2x", start[i]);
        }
        printf("\n");
    }
    
    void show_int(int x)
    {
        show_bytes((byte_pointer) &x, sizeof(int));
    }
    
    void show_float(float x)
    {
        show_bytes((byte_pointer) &x, sizeof(float));
    }
    
    void show_pointer(void *x)
    {
        show_bytes((byte_pointer) &x, sizeof(void *));
    }
    
    int main()
    {
        show_int(3);
        show_float(3.0);
        int t = 3;
        int *p = &t;
        show_pointer((void *)p);
        // 练习2.5
        int val = 0x87654321;
        byte_pointer valp = (byte_pointer) &val;
        show_bytes(valp, 1); // 小端法: 21 大端法: 87
        show_bytes(valp, 2); // 小端法: 21 43 大端法: 87 65
        show_bytes(valp, 3); // 小端法: 21 43 65 大端法: 87 65 43
        // 练习2.7
        const char *s = "abcedf";
        show_bytes((byte_pointer) s, sizeof(s));
    }

### 1.2 表示代码 
>   不同的机器类型使用不同的且不兼容的指令和编码方式, 因此生成的二进制  
>   代码是不兼容的  

### 1.3 布尔代数
>   __布尔环(boolean ring)__一个属性: a\^a=0, 且与排列顺序无关(a\^b)\^a=b  
>   2个应用:  
>   1.  数据加密:  
>   假设b看作加密数据, a是加密的密钥. 对数据进行加密的过程为c=a\^b(c为密文).  
>   解码过程c\^a = a\^b\^a => b = c\^a  
>   2.  交换两个数:  

    void inplace_swap(int *x, int *y) {
        *y = *x ^ *y;
        *x = *x ^ *y;
        *y = *x ^ *y;
    }

>   用位向量表示有限集合,例如: a=[01101001]表示集合A={0,3,5,6}  

>   掩码运算: 表示从一个字中选出位集合.  
>   例如：掩码0xFF, x&0xFF取x的最低有效字节组成的值  
>   表达式~0生成全1的掩码,且不管机器的字大小是多少
>   练习2.12([代码](/code/computer-systems-a-programmers-perspective/2-12.c)):

    int x = 0x87654321;
    int A = x&0xFF;
    int B = (~x) & (~0xFF) | A;
    int B = x ^ (~0xFF);
    int C = x | 0xFF;

>   练习2.13:   

    x|y = bis(x, y);
    // X = bic(x, y) 结果为值为0的位不变,值为1的位是仅仅x对于位为1而y对应位不是1.
    // Y = bic(y, x) 结果与上面类似.
    // bis(X, Y) 结果为1的位是x或y对应位为1,同时为1或0时值为0.
    x^y = bis(bic(x,y), bic(y,x))

>   C语言中的移位运算:  
>   假设x = [Xn-1, Xn-2,...,X0], 左移x<<k = [Xn-k-1, Xn-k-2,...X0, 0,...0]  
>   逻辑右移:　x >> k 左端补零[0,...,0,Xn-1, Xn-2,...Xk]  
>   算术右移:　x >> k 左端补最高有效位[Xn-1, Xn-1,...,Xn-1, Xn-2,...Xk]  
>   __对于几乎所有的编译器/机器组合都是用算术右移__  

2.  整数表示
-----------

###2.1 无符号数的编码
![Alt binary-to-unsigned](/images/binary-to-unsigned.png)

###2.2 补码编码
![Alt binary-to-two\'-complement](/images/binary-to-two-complement.png)

>   UMaxw, TMinw, and TMaxw的范围  

![Alt important-numbers](/images/important-numbers.png)

>   确定大小的整数类型: 头文件stdint.h定义了形如intN_t, uintN_t表示长度为N(8,16,32,64)位的整型数.  
>   最大值和最小值宏名INTN_MIN, INTN_MAX, UINTN_MAX.

###2.3 有符号数和无符号数之间的转换

>   __强制类型转换的结果保持位值不变,只改变了解释这些位的方式__
>   转换的原则:__数值可能改变, 但是位模式不变__

    unsigned u = 0xFFFFFFFFu;
    int tu = (int) u;
    printf("u = %u, tu = %d\n", u, tu);
    // 结果: u = 4294967295, tu = -1

![Alt T2U](/images/T2U.png)
![Alt T2U-figure](/images/T2U-figure.png)
![Alt U2T](/images/U2T.png)
![Alt U2T-figure](/images/U2T-figure.png)

>   __当执行一个运算时,如果它的一个运算数是有符号的而另一个是无符号的,那么C语言会隐式地
＞  将有符号的参数强制类型转换为无符号数,并假设两个数都是非负的.

    printf("%d\n", 0 == 0U); // 1
    printf("%d %d\n", -1 < 0, -1 < 0U); // 1 0
    printf("%d %d %d\n", 2147483647 > -2147483647 -1, 2147483647U > -2147483647 - 1, 2147483647 > (int)2147483648U); // 1 0
    printf("%d %d\n", -1 > -2, (unsigned) -1 > -2); // 1 1

###2.4 拓展一个数字的位表示  

1.  零扩展(zero extension): 将无符号数转换为一个更大的数据类型，只需简单地在开头添加0.
2.  符号扩展(sign extension): 将一个补数字转换为一个更大的数据类型，规则是在表示中添加最高有效位的值的副本
3.  从一个数据大小到另一个数据大小的转换,以及无符号和有符号数字之间的转换的相对顺序：先改变大小.之后再从改变符号(即先进行上面中的扩展，然后改变位模式的解释方法, C语言标准的要求)

[Xw-1,Xw-2, ..., X0] -> [Xw-1,Xw-1, ...,Xw-1,Xw-2, ..., X0]

[源代码](/code/computer-systems-a-programmers-perspective/zero-sign-extension.c)

    short sx = -12345;
    unsigned short usx = sx;
    int x = sx;
    unsigned int ux = usx;

    printf("sx = %d:\t", sx);
    show_bytes((byte_pointer) &sx, sizeof(short));

    printf("usx = %u:\t", usx);
    show_bytes((byte_pointer) &usx, sizeof(unsigned short));

    printf("x = %d:\t", x);
    show_bytes((byte_pointer) &x, sizeof(int));

    printf("ux = %d:\t", ux);
    show_bytes((byte_pointer) &ux, sizeof(unsigned int));

    unsigned int uy = sx; // uy = (unsigned)(int)sx;
    printf("uy = %u:\t", uy);
    show_bytes((byte_pointer) &uy, sizeof(unsigned int));

    /*
     * 假设short为16位, int为32位, 大端法机器:
     * sx = -123456:    cf c7
     * usx = 53191:     cf c7
     * x = -12345:      ff ff cf c7
     * ux = 53191:      00 00 cf c7
     * uy = 4294954952: ff ff cf c7
     */

__符号扩展证明__:

![Alt sign-extension-prove1](/images/sign-extension-prove1.png)
![Alt sign-extension-prove2](/images/sign-extension-prove2.png)

### 2.4 无符号和有符号数使用中一些细微错误
>   避免错误的一种方法就是绝不使用无符号数  

    float sum_element(float *a, unsigned length) {
        int i;
        float result = 0;
        for (i = 0; i <= length - 1; ++i)
            result += a[i];
        return result;
    }
    /／当length = 0时, 0 - 1进行无符号运算结果0xFFFFFFFF
    
    size_t strlen(const char *s);

    int strlonger(char *s, char *t) {
        return strlen(s) - strlen(t) > 0;    
        // 正确做法 return strlen(s) > strlen(t);
    }
    // 错误原因: size_t 为unsigned int(32位系统), long unsigned int(64位系统)

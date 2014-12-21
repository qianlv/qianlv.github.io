// =====================================================================================
// 
//       Filename:  the_byte_representation_of_program_objects.c
// 
//    Description:  打印程序对象的字节表示
// 
//        Version:  1.0
//        Created:  2014年12月20日 13时27分51秒 CST
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  肖守冬, qianlv@qq.com
//        License:  Copyright © 2014 肖守冬. All Rights Reserved.
// 
// =====================================================================================

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
    show_pointer(p);
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

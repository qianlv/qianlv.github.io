// =====================================================================================
// 
//       Filename:  2-56.c
// 
//    Description:  练习2-56
// 
//        Version:  1.0
//        Created:  2014年12月26日 10时44分29秒 CST
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

void show_short(short x)
{
    show_bytes((byte_pointer) &x, sizeof(short));
}
void show_long(long x)
{
    show_bytes((byte_pointer) &x, sizeof(long));
}

void show_double(double x)
{
    show_bytes((byte_pointer) &x, sizeof(double));
}

int main()
{
    short sx = 10;
    long lx = 10;
    double dx = 10.0;
    show_short(sx);
    show_long(lx);
    show_double(dx);
}


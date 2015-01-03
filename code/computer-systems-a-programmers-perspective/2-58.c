// =====================================================================================
// 
//       Filename:  2-58.c
// 
//    Description:  2-58 判断机器大小端
// 
//        Version:  1.0
//        Created:  2014年12月26日 10时51分01秒 CST
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  肖守冬, qianlv@qq.com
//        License:  Copyright © 2014 肖守冬. All Rights Reserved.
// 
// =====================================================================================

#include <stdio.h>
typedef unsigned char *byte_pointer;

int is_little_endian()
{
    int i;
    int x = 0x1;
    byte_pointer x_pointer = (byte_pointer) &x;
    if (x_pointer[0] != 0)
        return 1;
    return 0;
}

int main()
{
    printf("%d\n", is_little_endian());
}

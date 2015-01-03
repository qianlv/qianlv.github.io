// =====================================================================================
// 
//       Filename:  tool2.h
// 
//    Description:  一些公共用到的函数
// 
//        Version:  1.0
//        Created:  2014年12月29日 15时50分26秒 CST
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  肖守冬, qianlv@qq.com
//        License:  Copyright © 2014 肖守冬. All Rights Reserved.
// 
// =====================================================================================


#include <stdio.h>
typedef unsigned char *byte_pointer;

// 输出十六进制表示
void show_bytes(byte_pointer start, int len)
{
    int i;
    for (i = 0; i < len; ++i)
    {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

// 返回指定字节值
int get_sign_byte(int x, int pos)
{
    int shift_val = pos << 3; 
    int xright = x >> shift_val;
    return xright & 0xFF;
}

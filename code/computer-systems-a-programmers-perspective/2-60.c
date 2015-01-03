// =====================================================================================
// 
//       Filename:  2-60.c
// 
//    Description:  2.60 
// 
//        Version:  1.0
//        Created:  2014年12月29日 14时57分55秒 CST
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  肖守冬, qianlv@qq.com
//        License:  Copyright © 2014 肖守冬. All Rights Reserved.
// 
// =====================================================================================

#include <stdio.h>
#include "show_bytes.h"

unsigned replace_byte (unsigned x, unsigned char b, int i)
{
    unsigned y = x & (~(0xFF<<(i * 8)));
    return (y | (b << (i * 8)));
}

int main()
{
    size_t i;
    for (i = 0; i < sizeof(unsigned); i++)
    {
        unsigned ans = replace_byte(0x12345678, 0xAB, i);
        show_bytes((byte_pointer) &ans, sizeof(unsigned));
    }
}

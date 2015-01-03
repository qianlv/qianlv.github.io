// =====================================================================================
// 
//       Filename:  2-59.c
// 
//    Description:  2.59 练习
// 
//        Version:  1.0
//        Created:  2014年12月26日 11时06分19秒 CST
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  肖守冬, qianlv@qq.com
//        License:  Copyright © 2014 肖守冬. All Rights Reserved.
// 
// =====================================================================================

#include <stdio.h>
#include "show_bytes.h"

int main()
{
    int x = 0x89ABCDEF;
    int y = 0x76543210;
    int low = x & 0xFF;
    show_bytes((byte_pointer) &low, sizeof(int));
    int left = y & (~0xFF);
    show_bytes((byte_pointer) &left, sizeof(int));
    int ans = low | left;
    show_bytes((byte_pointer) &ans, sizeof(ans));
}

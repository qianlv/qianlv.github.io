// =====================================================================================
// 
//       Filename:  2-62.c
// 
//    Description:  2-62
// 
//        Version:  1.0
//        Created:  2014年12月29日 16时20分26秒 CST
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  肖守冬, qianlv@qq.com
//        License:  Copyright © 2014 肖守冬. All Rights Reserved.
// 
// =====================================================================================

#include <stdio.h>

int int_shifts_are_logical()
{
    int x = ~0x01;
    return !(~(x>>1));
}

int main()
{
    printf("%d\n", int_shifts_are_logical());
}

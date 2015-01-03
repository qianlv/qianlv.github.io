// =====================================================================================
// 
//       Filename:  2-61.c
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  2014年12月29日 15时23分50秒 CST
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  肖守冬, qianlv@qq.com
//        License:  Copyright © 2014 肖守冬. All Rights Reserved.
// 
// =====================================================================================

#include <stdio.h>
#include "tool2.h"

// 所有位都是1
int all_pos_one(int x)
{
    return !(~x);
}

int all_pos_zero(int x)
{
    return !x;
}


int high_all_pos_one(int x)
{
    int high_byte =  get_sign_byte(x, sizeof(int) - 1);
    return !(high_byte - 0xFF);
}

int low_all_pos_zero(int x)
{
    int low_byte = get_sign_byte(x, 0);
    return !low_byte;
}

int main()
{
    printf("%d %d\n", all_pos_one(0xFFFFFFFF), all_pos_one(0x8FFFFFFF));
    printf("%d %d\n", all_pos_zero(0x00000000), all_pos_zero(0x8FFFFFFF));
    printf("%d %d\n", high_all_pos_one(0xFF000000), high_all_pos_one(0x8FFFFFFF));
    printf("%d %d\n", low_all_pos_zero(0xFF000000), low_all_pos_zero(0x8FFFFFFF));
}

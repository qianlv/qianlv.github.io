// =====================================================================================
// 
//       Filename:  test.c
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  2014年12月20日 17时59分41秒 CST
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  肖守冬, qianlv@qq.com
//        License:  Copyright © 2014 肖守冬. All Rights Reserved.
// 
// =====================================================================================

#include <stdio.h>

int main()
{
    int x = 0x87654321;
    int A = x & 0xFF;
    int B = (~x) & (~0xFF) | A;
    int C = x | 0xFF;
    printf("%.2x %.2x %.2x", A, B, C);
    
}

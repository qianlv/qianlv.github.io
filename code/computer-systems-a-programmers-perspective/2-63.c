// =====================================================================================
// 
//       Filename:  2-63.c
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  2014年12月29日 16时38分47秒 CST
//       Revision:  none
//       Compiler:  gcc
// 
//         Author:  肖守冬, qianlv@qq.com
//        License:  Copyright © 2014 肖守冬. All Rights Reserved.
// 
// =====================================================================================

#include <stdio.h>
#include "tool2.h"

int sra(int x, int k)
{
    int xsrl = (unsigned) x >> k;
    int tmp = ~0;
    int tmp = tmp << (8 * sizeof(int) - k);
    int judge = (~0) << ( 8 * sizeof(int) - 1);
    return 
}

// 逻辑右移
int srl(unsigned x, int k)
{
    unsigned xsra = (int) x >> k;
    int tmp = ~0; // 0xFFFFFFFF
    int tmp = tmp << (8 * sizeof(int) - k); // k = 3: 1110 0000 0000 0000 0000 0000 0000 0000
    int tmp = ~tmp;  // k = 3: 0001 1111 1111 1111 1111 1111 1111 1111
    return tmop & xsra;
}

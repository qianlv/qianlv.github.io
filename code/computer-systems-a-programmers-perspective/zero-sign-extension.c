// =====================================================================================
// 
//       Filename:  zero-sign-extension.c
// 
//    Description:  数字零扩展和符号扩展
// 
//        Version:  1.0
//        Created:  2014年12月21日 13时28分15秒 CST
//       Revision:  none
//       Compiler:  gcc
// 
//         Author:  肖守冬, qianlv7@qq.com
//        License:  Copyright © 2014 肖守冬. All Rights Reserved.
// 
// =====================================================================================

#include <stdio.h>

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

int main()
{
    short sx = -12345;
    unsigned short usx = sx;
    int x = sx;
    unsigned int ux = usx;
    int y = usx;

    printf("sx = %d:\t", sx);
    show_bytes((byte_pointer) &sx, sizeof(short));

    printf("usx = %u:\t", usx);
    show_bytes((byte_pointer) &usx, sizeof(unsigned short));

    printf("x = %d:\t", x);
    show_bytes((byte_pointer) &x, sizeof(int));

    printf("ux = %d:\t", ux);
    show_bytes((byte_pointer) &ux, sizeof(unsigned int));

    printf("y = %d:\t", y);
    show_bytes((byte_pointer) &y, sizeof(int));
    
}

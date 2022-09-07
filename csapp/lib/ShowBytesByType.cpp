// Created by Zcr on 2022/9/7.
#include "ShowBytesByType.h"

void showBytes(bytePointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; ++i)
        printf("%p\t0x%.2x\n", start + i, start[i]);
    printf("\n");
}

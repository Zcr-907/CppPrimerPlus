#include <iostream>

// 定义字节指针
//typedef char *bytePointer;
#include "ShowBytesByType.h"

void lab02() {
    using namespace std;
    int a = 15213;
    cout << "int a = 15213;" << endl;
    showBytes((bytePointer) &a, sizeof(int));
}

//// 函数定义
//void showBytes(bytePointer start, size_t len) {
//    size_t i;
//    for (i = 0; i < len; ++i)
//        printf("%p\t0x%.2x\n", start + i, start[i]);
//    printf("\n");
//}




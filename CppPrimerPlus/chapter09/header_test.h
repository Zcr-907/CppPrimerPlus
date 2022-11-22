// 使用 #ifndef HEADER_TEST_H \n #define HEADER_TEST_H \n #endif: 防止一个文件包含同一个头文件多次,例如同一个结构声明被使用了多次
#ifndef HEADER_TEST_H
#define HEADER_TEST_H
// 头文件通常包含的内容
// * 函数原型
// * 使用#define或const定义的符号常量
// * 类声明
// * 模版声明
// * 内联函数
struct HeaderStruct {   // 为什么结构可以? 因为结构声明并不创建变量,而只是在源代码文件中声明结构变量时,告诉编译器如何创建该结构变量
    int a;
    int b;
};

void plus_HeaderStruct_h2_to_h1(HeaderStruct &h1, HeaderStruct h2);

#endif

// Info:
// #include <XXX.h>: 从存储标准头文件的主机系统的文件系统中查找
// #include "XXX.h": 编译器首先从当前工作目录或源代码目录中查找,如果没找到则在标准位置查找

// Waring:
// * 为什么不能在头文件中放入函数定义和变量声明 => 如果同一个可执行程序的2个文件引用了该文件,就会造成函数定义冲突
//                                       => 变量声明也是一样的道理,总不能两次 int a;吧

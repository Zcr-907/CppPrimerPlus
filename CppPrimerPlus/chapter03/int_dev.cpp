#include <iostream>

void int_dev() {
    using namespace std;
    cout << "-------> int_dev <-------" << endl;
    cout << "010  => 十进制: " << 010 << endl;
    cout << "0X10 => 十进制: " << 0X10 << endl;
    int a = 10;
    int b = 10;
    int c = 10;
    cout << "42 => 十进制: " << a << endl;
    cout << hex;
    cout << "42 => 十六进制: " << b << endl;
    cout << oct;
    cout << "42 => 八进制: " << c << endl;
    // 整形提升: 对于char bool short进行表达式计算的时候会将这些类型(无论是有符号还是无符号)提升至int来表示
    // 类型转换: 计算表达式中的2个操作数提升至级别较高的操作数类型
    //          计算表达式中的2个操作数,无符号数类型>=有符号数类型,那么全部转为无符号数
    //                              有符号数类型可以表示无符号数类型的最大值,那么就转为有符号数
    unsigned int ua = 0;
    long ia = -1;
    cout << "ua > ia: " << (ua > ia) << endl;   // output:0
    cout << "-------> int_dev <-------" << endl;
}



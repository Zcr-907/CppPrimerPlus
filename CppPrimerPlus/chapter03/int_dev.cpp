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
    cout << "-------> int_dev <-------" << endl;
}



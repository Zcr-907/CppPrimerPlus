#include <iostream>

using namespace std;

void enum_func() {
    // 定义 枚举
    enum color {
        red, orange, yellow, green
    };
    // 只使用枚举常量,而不打算使用枚举变量的话,可以进行如下声明
    enum {
        one, two, three
    };
    // A=0,B=100,C=101
    enum {
        A, B = 100, C
    };
    // a=b=0,c=d=1
    enum {
        a, b = 0, c, d = 1
    };
    cout << "-------> enum_func <-------" << endl;
    color room_color = red;
    // color road = 1; // 不能如此定义,因为1不是所定义的枚举类型,只能为枚举变量赋值枚举值
    // red, orange, yellow, green => 对应正数值0～4
    cout << "room_color: " << room_color << endl;
    // 对于枚举变量而言,不能通过枚举值进行算术运算
    // 但是对于其他整型,枚举值可以被提升为整型进行计算
    // 怎么理解上述表达? 其实C++并没有为枚举值定义算术运算,但是二者在双数运算的时候提升至整型,整型不能被赋值给枚举变量
    int val_a = orange + red + 1;
    color road_color;
    road_color = color(430000);  // 为 使用整型值为枚举变量赋值的方式
    cout << "int a: " << val_a << endl;
    cout << "road_color: " << road_color << endl;
    cout << "one: " << one << endl;
    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    cout << "C: " << C << endl;

    cout << "-------> enum_func <-------" << endl;

}


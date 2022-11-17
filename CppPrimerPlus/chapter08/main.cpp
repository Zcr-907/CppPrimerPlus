#include <iostream>

using namespace std;

struct Offset {
    int x;
    int y;
};

struct Location {
    Offset o1;
    int height;
};

// 1.内联函数
// 声明一个内联函数
// 内联函数在程序执行时将二进制代码复制到程序调用处,以节省程序花在函数调用处的时间,但如果多处调用的话,内存开销也不小
inline int incr_int(int a) {
    return ++a;
}

// 2.默认参数
//   函数的默认参数实现通过函数声明实现,定义携带默认参数的函数时,必须从从右往左设置默认值( invalid eg:  int a=1, int b, int c = 3)
//   使用时: 从左往右进行赋值
//          print_3_int_can_default(1);         valid       a=1,b=2,c=3
//          print_3_int_can_default(1,12);      valid       a=1,b=12,c=3
//          print_3_int_can_default(1,12,13);   valid       a=1,b=12,c=13
//          print_3_int_can_default(1,,13);     invalid
void print_3_int_can_default(int a, int b = 2, int c = 3);

int main() {
    cout << "using inline func incr_int: " << incr_int(2) << endl;

    // 2.引用变量,在&符号出现在赋值表达式的左侧时,表示左侧变量名为右侧值的引用,修改左侧值 => 修改右侧值
    //   这为在函数传参时处指针以外多提供了一种使用引用的方式,这样修改这个值其实就是修改其原始值,而不是副本
    int a = 1;
    int b = 1;
    int &ref_a = a; // 声明引用变量时必须初始化,一旦建立便不可更改引用变量的管理关系
    ref_a++;
    cout << "使用引用变量修改a的值,a= : " << a << endl;
    ref_a = b;

    // 看起来ref_a=b=1,好像将ref_a和b关联起来,其实这等价与a=b
    // 查看&ref_a , &a ,&b会发现  &ref_a = &a != &b
    cout << "修改引用关系的关联对象,a= : " << a << endl;

    // 声明一个使用引用变量为参数的函数来修改引用变量的值
    void update_int_val(int &original, int update);
    update_int_val(a, 1001);
    cout << "使用引用变量参数的函数修改a的值,a= : " << a << endl;


    // 3.引用结构变量 引用类变量其实也一致的
    //   如果试图返回函数内的临时变量的引用,并在外部调用的话那会报错,因为程序内部变量会随着方法栈的出栈而销毁
    Location l1 = {
            {1, 2}, 3
    };
    void update_struct(Location &original);
    update_struct(l1);
    cout << "l1.o1.x: " << l1.o1.x << endl;
    cout << "l1.o1.y: " << l1.o1.y << endl;
    cout << "l1.height: " << l1.height << endl;


    print_3_int_can_default(1);
    print_3_int_can_default(1, 12);
    print_3_int_can_default(1, 12, 13);

}

void update_int_val(int &original, int update) {
    original = update;
}

void update_struct(Location &original) {
    original = {
            {4, 5}, 6
    };
}

void print_3_int_can_default(int a, int b, int c) {
    using namespace std;
    cout << "-------> print_3_int_can_default <-------" << endl;
    cout << "a= " << a << endl;
    cout << "b= " << b << endl;
    cout << "c= " << c << endl;
    cout << "-------> print_3_int_can_default <-------" << endl;


}


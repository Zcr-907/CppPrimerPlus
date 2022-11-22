#include <iostream>
#include "header_test.h"

using namespace std;

int static_external;        // 静态变量: 其他文件可访问
static int static_internal; // 静态变量: 仅限当前文件访问

void incr_static_var_in_block();

int main() {
    HeaderStruct h1{1, 2};
    HeaderStruct h2{-1, -2};

    plus_HeaderStruct_h2_to_h1(h1, h2);
    cout << "h1.a: " << h1.a << endl;
    cout << "h1.b: " << h1.b << endl;

    cout << "-------> 存储持续性,作用域和链接性 <-------" << endl;
    // 1.main中定义了a
    int a = 1;
    {
        // main中局部代码块又定义了a: 这会使得代码块内对外部的a隐藏,使用的是代码块内的a
        // 代码块内的所有修改都是针对代码块内的a
        int a = -1;
        cout << "局部代码块: a= " << a << endl;
    }
    cout << "main代码块: a= " << a << endl;
    // 离开代码块时,外部的a又恢复了可见性
    // 2.静态持续变量: 由于静态变量的树木在程序运行期间是不变的,所以只需要在固定的位置存储他们即可,而不需要使用栈
    //   对于静态持续变量: 如果没有进行显式的初始化,编译器将他们设置为0
    cout << "static_external= " << static_external << endl;
    cout << "static_internal= " << static_internal << endl;
    incr_static_var_in_block();
    incr_static_var_in_block();

    cout << "-------> 存储持续性,作用域和链接性 <-------" << endl;
}

/**
 * 对于静态局部变量: 和静态变量一样,虽然函数外的其他位置不可见,但是它的值会在程序运行期间一直存在
 */
void incr_static_var_in_block() {
    static int func_var;
    cout << "func_var= " << func_var++ << endl;
}


#include <iostream>
#include "header_test.h"

using namespace std;

// 3.静态变量: 其他文件可访问
//   变量的声明有2种方式: int header_test_CPP=2;     => 定义声明: 它会为变量分配存储空间,且程序中只能被定义一次
//                     extern int header_test_CPP => 引用声明: 不会为它分配存储空间,只是引用已有变量,可以声明多次
//                                                          虽然可以声明多次,但是定义赋值只能有一次  extern int header_test_CPP=1就不行
extern string static_external;
// 3.静态变量: 仅限当前文件访问
static string static_internal = "static_internal";

// 5.声明一个静态内部函数,和静态内部变量的特性一致
static void incr_static_var_in_block();

// 4.静态内部变量static_inner_test覆盖了header_test.cpp中的静态外部变量static_inner_test
static string static_inner_test = "main.cpp static_inner_test";

int main() {
    // 1.头文件的基本使用
    cout << "-------> invoke by headed <-------" << endl;
    HeaderStruct h1{1, 2};
    HeaderStruct h2{-1, -2};
    cout << "change before: h1.a: " << h1.a << endl;
    cout << "change before: h1.b: " << h1.b << endl;
    plus_HeaderStruct_h2_to_h1(h1, h2);
    cout << "change after: h1.a: " << h1.a << endl;
    cout << "change after: h1.b: " << h1.b << endl;
    cout << "-------> invoke by headed <-------" << endl;

    // 2.变量的作用域: 在局部代码块中,申明了外层同名的变量,
    //   * 将使得外层同名变量暂时隐藏
    //   * 内层代码块执行过程中,操作同名变量是内层的变量,而不是外层
    //   * 当离开内存代码块时,外层变量又变可见了
    cout << "-------> 变量的作用域 <-------" << endl;
    string main_a = "main_a";
    {
        string main_a = "main_block_a";
        cout << "局部代码块: main_a= " << main_a << endl;
    }
    cout << "main代码块: a= " << main_a << endl;
    cout << "-------> 变量的作用域 <-------" << endl;

    cout << "-------> 静态变量 <-------" << endl;
    // 3.静态持续变量: 由于静态变量的树木在程序运行期间是不变的,所以只需要在固定的位置存储他们即可,而不需要使用栈
    //   对于静态持续变量: 如果没有进行显式的初始化,编译器将他们设置为0
    cout << "全局可见的静态变量: " << static_external << endl;
    cout << "当前文件可见的静态变量: " << static_internal << endl;
    incr_static_var_in_block();
    incr_static_var_in_block();
    incr_static_var_in_block();
    cout << "-------> 静态变量 <-------" << endl;


    // 4.作用域解析运算符,表示将使用变量的全局版本
    cout << "-------> ::作用域解析运算符 <-------" << endl;
    string static_external = "main_static_external";
    cout << "main static_external= " << static_external << endl;
    cout << "extern static_external= " << ::static_external << endl;
    cout << "-------> ::作用域解析运算符 <-------" << endl;

    cout << "-------> 静态内部变量覆盖静态外部变量 <-------" << endl;
    cout << "static_inner_test: " << ::static_inner_test << endl;
    cout << "-------> 静态内部变量覆盖静态外部变量 <-------" << endl;

    cout << "-------> 动态分配内存并初始化 <-------" << endl;
    int *p_init_val = new int(6);
    int *p_init_arr_val = new int[]{1, 2, 3, 4};
    auto *p_init_struct_val = new HeaderStruct{1, 2};
    cout << "p_init_val: " << *p_init_val << endl;
    delete p_init_val;
    delete[] p_init_arr_val;
    delete p_init_struct_val;
    cout << "-------> 动态分配内存并初始化 <-------" << endl;


}

/**
 * 对于静态局部变量: 和静态变量一样,虽然函数外的其他位置不可见,但是它的值会在程序运行期间一直存在
 */
static void incr_static_var_in_block() {
    static int func_var;
    cout << "函数内声明的静态变量= " << func_var++ << endl;
}


#include <iostream>

// 使用函数指针完成AOP调用
void aop_func(void (*pf)(int), int a) {
    using namespace std;
    cout << "-------> para_is_arr_func <-------" << endl;
    // 虽然二者方式都可以成功调用函数,但是第一种形式强有力的生命当前正在使用函数指针
    (*pf)(a + 1);
    pf(a + 2);
    cout << "-------> para_is_arr_func <-------" << endl;
}


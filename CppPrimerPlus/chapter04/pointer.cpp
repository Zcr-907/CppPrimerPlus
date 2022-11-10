#include <iostream>

using namespace std;

void pointer_func() {
    int a = 3;
    // 指针的声明与初始化: &a  => 取出变量a的地址,
    //                  int => 表示p_a存储的是一个存储int类型值的地址
    //                  *   => "解引用"操作符,表明p_a是一个指针
    int *p_a = &a;
    cout << "-------> pointer_func <-------" << endl;
    // Waring: 野指针
    // 第一行: 程序为p_int分配了内存,但没有为p_int的值分配内存
    // 第二行: 由于并不知道p_int所存储的值什么,那么也就无法确定,程序到底将哪个内存地址赋值为2333
    // int *p_int;
    // *p_int = 2333;

    int *p_new_int = new int;
    *p_new_int = 1;
    cout << "*p_new_int: " << *p_new_int << endl;

    // 释放通过new而得到的内存
    // 1.new出的内存与变量的内存并不处于一个区域: 变量处于栈空间,new出的处于堆空间
    // 2.只能通过delete释放掉new出的内存,delete 和 new 应当配对使用,及时的使用delete,避免造成内存泄露
    // 3.delete释放的是new出的内存,并不是new所赋值的变量,也就是说再后续,仍然可以使用那个指针
    delete p_new_int;

    // 通过new创建动态数组
    // new 返回的是数组首元素的首地址=> 可以使用数组的[]形式来使用指针
    int *p_arr_int = new int[a];
    p_arr_int[0] = 0;
    p_arr_int[1] = 1;
    p_arr_int[2] = 2;
    cout << "p_arr_int[0]: " << p_arr_int[0] << endl;
    cout << "p_arr_int[1]: " << p_arr_int[1] << endl;
    cout << "p_arr_int[2]: " << p_arr_int[2] << endl;
    // 对指针进行加一之后=> p_arr_int不在指向数组首元素,而是指向了第二个元素了 => 可以发现指针的+1操作与整型并不一致
    p_arr_int += 1;
    cout << "After Add 1 p_arr_int[0]: " << p_arr_int[0] << endl;
    cout << "After Add 1 p_arr_int[1]: " << p_arr_int[1] << endl;
    cout << "After Add 1 p_arr_int[2]: " << p_arr_int[2] << endl;
    // 释放数组内存时需要添加[]
    // 释放的首地址必须是分配时的首地址
    p_arr_int -= 1;
    delete[] p_arr_int;

    // 指针运算
    int int_arr[] = {1, 2, 3};
    int *p_arr_1 = int_arr;     // 数组名int_arr为数组首元素地址
    int (*p_arr)[3] = &int_arr; // &int_arr虽然在数字表示上和int_arr一致,但是
    cout << "p_arr_1: " << p_arr_1 << "\tp_arr_1+1: " << p_arr_1 + 1 << endl; // p_arr_1 = &int_arr[0] + sizeof(int)
    cout << "p_arr  : " << p_arr << "\tp_arr+1  : " << p_arr + 1
         << endl;         // p_arr+1 = &int_arr[0] + sizeof(int_arr)
    // 指针也可以使用数组表示法
    cout << "*p_a -> p_a[0]: " << p_a[0] << endl;
    cout << "-------> pointer_func <-------" << endl;

}


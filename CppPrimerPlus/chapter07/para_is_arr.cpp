#include <iostream>

// const int *arr:
// p = &arr[0] => 允许将p = &arr1[0]; 也就是修改p本身所存储的值
// p[0]=1      => 这是不允许的,因为被const修饰,不能修改p所存储地址所存储的值
// const数据只能交由const指针来处理
// 非const数据可以交由任意指针
int para_is_arr_func(const int *arr, int size) {
    using namespace std;
    cout << "-------> para_is_arr_func <-------" << endl;
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    cout << "-------> para_is_arr_func <-------" << endl;
    return sum;
}

void update_arr_element(int *arr, int index, int update_val) {
    arr[index] = update_val;
}

void const_func() {
    // 1.const地址只能交由const指针
    const int a = 1;
    const int *p_a = &a;
    // int *p_a = &a; // not allow

    // 2.非const地址可以交由任何指针
    int b = 2;
    const int *p_b1 = &b;
    int *p_b2 = &b;

    // 3.const int *p_c1: 这种方式声明的指针只能禁止修改p_c1所存储的地址&c处所存储的值,但是不能禁止p_c1修改为存储其他值
    int c = 3;
    const int *p_c1 = &c;
    p_c1 = &b;

    // 4.int *const p_c2: 这种形式可以禁止p_c2指向其他的地址,但是可以修改p_c2处所存储地址&c所指向地址的数据
    int *const p_c2 = &c;
    *p_c2 = 2;
//    p_c2 = &b;
}

// int arr[][4] => int(*arr)[]4 != int *arr[4]
// int arr[][4] => int(*arr)[]4 :    表示指向包含四个int的指针
// int *arr[4]                  :    表示四个int类型的指针的数组
// 传递二维数组时,只需要在行参处声明列即刻,而且该函数只能接受x行4列的数组
void multiple_arr(int arr[][4], int row) {

}



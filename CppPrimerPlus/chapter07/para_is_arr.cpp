#include <iostream>

// 1.一维数组作为实参
//   函数声明: int arr[] 与int *arr是可以互相替换的
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
    // p_c2 = &b;
}

// int arr[][4] => int(*arr)[]4 != int *arr[4]
// int arr[][4] => int(*arr)[]4 :    表示指向包含四个int的指针
// int *arr[4]                  :    表示四个int类型的指针的数组
// 传递二维数组时,只需要在行参处声明列即刻,而且该函数只能接受x行4列的数组
int multiple_arr(int arr[][4], int row) {
    int sum = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < (sizeof(arr[0]) / sizeof(int)); ++j) {
            sum += arr[i][j];
        }
    }
    return sum;
}



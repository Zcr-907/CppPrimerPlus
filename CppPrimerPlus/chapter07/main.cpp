#include <iostream>

// 函数声明: int arr[] 与int *arr是可以互相替换的
int para_is_arr_func(const int arr[], int size);

void update_arr_element(int *arr, int index, int update_val);

int main() {
    using namespace std;
    int int_arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "int_arr sum: " << endl << para_is_arr_func(int_arr, (sizeof(int_arr) / sizeof(int))) << endl;

    // 以下演示了后缀表达式的使用,以及说明了数组参数传递了地址=>可以通过地址修改原始数据的值
    // int_arr + 1表示数组第二个元素,通过函数再偏移一个元素,所以修改的就是第三个元素
    update_arr_element(int_arr + 1, 1, -1);
    int index = 0;
    for (int element: int_arr) {
        cout << (index++)+1 << " = " << element << "\t";
    }
    cout << endl;
}


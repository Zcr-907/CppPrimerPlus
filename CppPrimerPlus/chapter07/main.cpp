#include <iostream>

struct offset {
    int x;
    int y;
};

struct location {
    offset o1;
    double height;
};

void value_transfer_struct(location param);

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
        cout << (index++) + 1 << " = " << element << "\t";
    }
    cout << endl;


    // 按值传递结构,那么将深拷贝一个结构的值给被调函数,被调函数对parma的操作并不会影响到arg
    struct location location1 = {
            {1, 2}, 1.0
    };
    value_transfer_struct(location1);
    std::cout << location1.o1.x << std::endl;
}

void value_transfer_struct(location param) {
    param.o1.x = -1;
    std::cout << param.o1.x << std::endl;
}



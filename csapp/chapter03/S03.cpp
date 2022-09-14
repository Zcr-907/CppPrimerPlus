// Created by Zcr on 2022/9/14.
#include <iostream>

void test_00() {
    using namespace std;
    // 测试证明: 通过2个同类型的指针相减,可以得到2个指针间距离了X个类型单位的距离
    int arr[] = {1, 2, 3, 4, 5};
    int step = &arr[2] - &arr[1];
    cout << "arr[2] 与 arr[1] 距离了几个单位: " << step << endl;
    int *ip = &arr[2];

    // 测试证明: 通过指针加减常数,可以进行类似与数组的操作
    cout << "arr[2] 之后的第二个元素: " << *(2 + ip) << endl;


}



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

    int arr2[][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    cout << "sizeof(arr2[0]): " << sizeof(arr2[0]) << endl;

    // 测试证明: *arr2[1],其实在尝试获取arr2[1][0]的值,arr2[1],表示为第二个内层数组的首地址,取该地址所存储的值也就是4
    cout << "sizeof(*arr2[0]): " << sizeof(*arr2[1]) << endl;

    // 测试证明: 二者结果相同,都表示arr2[0][0]
    printf("%d\n", **arr2);
    printf("%d\n", *arr2[0]);

    // 多维数组的指针表示法
    int (*pt)[3];
    pt = (int[2][3]) {{1, 2, 3},
                      {4, 5, 6}};


}



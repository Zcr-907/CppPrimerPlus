#include <iostream>

using namespace std;

static const int length = 4;

void array_func() {
    cout << "-------> array_dev <-------" << endl;
    // 数组的声明: typeName arrayName[arraySize],其中arraySize必须为整形参数或者const值
    // 未完全初始化如a: 除了指定处初始化,其他元素初始化未0
    // 全未初始化如b: 那么所有的值都是内存所遗留的历史值
    int a[length] = {1};
    int b[3];
    // sizeof(array): elementSize * Size
    cout << "sizeOf a : " << sizeof(a) << endl;
    for (int i: a) {
        cout << i << endl;
    }
    cout << "-------> array_dev <-------" << endl;
}


#include <iostream>

using namespace std;

// 理解union: union的大小为union中最大属性的大小,union同一时间只能存储一个属性数据
//           但是所存储的这一个属性数据可以使用union所定义的不同属性类型进行使用,如下展示了int 和 char 的使用
struct product {
    int type: 1;    // 指定字段所占有的最大bit位
    union name {
        int int_val;
        char ch_val;
    } p_name;
};

void union_func() {
    cout << "-------> union_func <-------" << endl;
    product p1{};
    p1.type = 1;
    p1.p_name.int_val = 1;
    cout << "p1.type: " << p1.type << "\tp1.ch_val: " << p1.p_name.ch_val << "\tp1.int_val: " << p1.p_name.int_val
         << endl;

    cout << "-------> union_func <-------" << endl;


}


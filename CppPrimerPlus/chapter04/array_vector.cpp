#include <vector>
#include <array>
#include <iostream>

void array_vector_func() {
    using namespace std;

    int a1[] = {1, 2, 3, 4};
    vector<int> a2(4);
    a2[0] = 0;
    a2[1] = 0;
    a2[2] = 0;
    a2[3] = 0;

    array<int, 4> a3 = {1, 2, 3, 4};
    cout << "-------> array_vector_func <-------" << endl;

    cout << "a1[0]: " << a1[0] << "\t" << "&a1[0]" << &a1[0] << endl;
    cout << "a2[0]: " << a2[0] << "\t" << "&a2[0]" << &a2[0] << endl;
    cout << "a3[0]: " << a3[0] << "\t" << "&a3[0]" << &a3[0] << endl;


    // 以下证明数组的不安全性
    // 0.首先明确,数组与array是在栈上分配的,vector是在堆上分配的 => 也就是说通过栈上偏移是可以访问到栈上的元素
    // 1.&a1[0] - &a3[0]: 计算 a1和 a3 之间的偏移
    // 2.由于内存栈是从高向低分配空间的,并且a1声明在a2前 => 所以计算出负偏移
    // 3.此时就可以通过负偏移和a1定位到a3的位置
    // 4.结论上看a1确实改变了a3的值
    // 5.当然array使用[]也是不安全的,如果想安全的使用array,可以使用at(),通过损耗一些性能换取安全(边界检查)
    int difference = &a1[0] - &a3[0];
    cout << "a1 和 a2 之间相差了多少个int单位: " << difference << endl;
    int minus_difference = -difference;
    a1[difference * -1] = 7;
    cout << "a1[" << minus_difference << "]: " << a1[minus_difference] << "\t" << "&a1[" << minus_difference << "]"
         << &a1[minus_difference] << endl;
    cout << "a3[0]: " << a3[0] << "\t" << "&a3[0]" << &a3[0] << endl;
    a3[-1] = 1;
//    a3.at(-1) = 1;  // 运行时抛出异常

    char *p_char1 = "ABC";
    char *p_char2 = "ABC";
    char char_arr[] = "ABC";

    // char *: 对于字符指针,共用的是一个"ABC"字面量
    // char[]: 将字面量 "ABC" 拷贝一份复制数据副本,将这个副本的地址应用交给字符数组
    // 如果通过指针修改了字面量,那么所有引用该字面量的数据都会产生数据修改 => 但是p_char1[1]是被拒绝操作的,字面量的存储区域收到保护
    printf("p_char1: %p\n",p_char1);
    printf("p_char1: %p\n",p_char2);
    printf("p_char1: %p\n",char_arr);


    cout << "-------> array_vector_func <-------" << endl;

}

#include <iostream>

using namespace std;

int main() {
    int int_arr[] = {1, 2, 3};
    int i, j, temp;

    /**
     * 逗号表达式
     * int i, j, temp; => 此处逗号并不意味着逗号运算符,而是意味着声明分割
     * i++, j--        => 该处逗号意味着逗号运算符,且每个逗号都为一个顺序点(顺序点: 程序保证在该顺序点之前的所有副作用都已完成)
     */
    for (i = 0, j = (sizeof(int_arr) / sizeof(int)) - 1; j < i; i++, j--) {
        temp = int_arr[i];
        int_arr[i] = int_arr[j];
        int_arr[j] = temp;


    }

    for (int k = 0; k < (sizeof(int_arr) / sizeof(int)); ++k) {
        cout << "第" << k << "个数: " << int_arr[k];
        // ios_base::boolalpha => 将表达式的值按照Boolean类型输出
        cout.setf(ios_base::boolalpha);
        cout << "\t是否为偶数: " << (int_arr[k] % 2 == 0) << endl;
    }

    /**
     * 再次验证:
     * true: 字符指针共用的是相同字符串字面量       => p_char是 &p_char中存储的数据也就是"ABC"的地址
     * false: 数组会开辟一个空间存储该字面量的副本   => char_arr = &char_arr[0] 是字符数组的首元素地址
     */
    const char *p_char = "ABC";
    char char_arr[] = "ABC";
    cout << R"+*(p_char=="ABC": )+*" << (p_char == "ABC") << endl;
    cout << R"+*(char_arr=="ABC": )+*" << (char_arr == "ABC") << endl;

    // 基于范围的for循环
    for (char element : char_arr) {  // 类似java增强for循环,但是不能修改成员的值
        cout << "element: " << element << endl;
    }
    for (char &element : char_arr) { // &这种方式拓展了该类型循环类可以修改成员的方式
        element += 1;
    }
    cout << "every char add one value:" << char_arr << endl;


    /**
     * cin.get(ch): 将缓存区读到的字符存入ch,并且返回cin实例,如果需要将cin表示为bool的地方
     *              如果遇到了EOF,则该cin表示为false,否则为true
     */
    char ch;
    while (cin.get(ch)) {
        cout << ch;
    }
    cout << "EOF,Exit" << endl;

}

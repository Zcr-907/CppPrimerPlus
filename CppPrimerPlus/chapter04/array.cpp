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
    // 数组元素个数 = 数组Size / 元素Size
    short short_array[] = {1, 2, 3};
    short cpp_short_array[]{1, 2, 3};   // c++兼容的列表初始化方式
    cout << "short_array.length: " << sizeof(short_array) / sizeof(short) << endl;

    // 字符串的初始化方式;
    char str1[] = "i am string";
    char str_error[] = {'a', 'b', 'c'};
    char str2[] = {'A', 'B', 'C', '\0'};
    cout << "str1: " << str1 << endl;
    cout << "str_error: " << str_error << endl;    // 由于str_error的初始化声明中,并没有在结尾中使用'\0',所以cout不能够识别何时结束,直到遇到下一个'\0'
    cout << "str2: " << str2 << endl;

    // 为什么用print => cout会输出字符串表示,这里使用print输出单个字符进行表示
    // 在此处是证明str_errors所输出的abcA的A,并不是str2[0]的'A'
    cout << &str_error[3] << endl;
    printf("&str_error[3]=%p\tstr_error[3]=%c\t&str_error[4]=%d\n", &str_error[3], str_error[3], str_error[4]);
    printf("&str2[0]     =%p\tstr2[0]     =%c\n", &str2[0], str2[0]);

    // cin.get()获取单个字符
    // (cin >> year).get(); 为什么在末尾添加.get(),是为了消耗在输入year时留在输入队列中的换行符
    // cin.get(array,size); arg1:要存储的数组,arg2:要存储的字节数量。
    cout << "what year now?" << endl;
    int year;
    (cin >> year).get();
    cout << "what is your name" << endl;
    const int name_size = 15;
    char name[name_size];
    cin.get(name, name_size);
    cout << "year:" << year << endl;
    cout << "name:" << name << endl;


    cout << "-------> array_dev <-------" << endl;
}


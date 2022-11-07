#include <iostream>
#include <string>

void string_func() {
    using namespace std;
    cout << "-------> string_func <-------" << endl;
    // string来声明在头文件<string>中,对于cout,cin可以想使用char[]一样去使用,也可以使用char[]形式的下标索引去引用字符
    // string的优势: cin >> string时将自动调整string的长度
    //              可以将一个string对象赋值给另一个string对象,但是char[]就不行
    //              可以对2个string进行算术运输,str3=str1+str2 , str1+=str2
    string name;
    cout << "enter you name:";
    cin >> name;
    cout << "your enter name is " << name << endl;
    cout << "the " << name << " third word is:" << name[2] << endl;

    // 字符串的几种"字符串"字面量声明方式
    char str1[] = {"Hello i am str1"};
    char str2[]{"Hello i am str2"};
    // str1=str2;
    string str3 = {"str3"};
    string str4{"str4"};
    str3 = str4;
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    cout << str4 + str3 << endl;
    cout << "str3.size: " << str3.size() << endl;

    // raw: 原始字符串
    // 使得可以不使用转译符来使用一些字符,比如""
    // R"( 和 )" 总是成对出现
    // R"+*( 和 )+*" 总是成对出现,相比前者这是为了让字符串中使用()无歧义
    cout << R"(is a
            "test")" << endl;
    cout << R"+*("is" a "test2")+*" << endl;

    cout << "-------> string_func <-------" << endl;

}

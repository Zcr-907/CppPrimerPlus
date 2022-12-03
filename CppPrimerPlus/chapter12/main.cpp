#include <iostream>
#include "stringbad.h"

using namespace std;

void callme1(StringBad &rsb);

void callme2(StringBad rsb);

int main() {
    {

        StringBad dan("dan");// 0x6000039c4000 "dan"
        StringBad jiu("jiu");// 0x600002828010 "jiu"

        // 通过引用传递并不会造成什么问题
        callme1(dan);
        cout << "dan: " << dan << endl;

        // 当使用默认复制函数时就会产生如下问题
        // 但是通过传值调用就会产生一些无法预估的问题,原因如下
        // 传值时相当于执行 StringBad param=arg; => param=StringBad(const StringBad &); => 而这个复制构造函数并不知道要对num_strings进行操作
        // 在离开调用函数时,调用了对象的析构函数,对静态变量进行了操作,并且把原始对象new 出的str内存空间进行了delete[]
        // 这就造成了2个现象:
        //      1.静态变量减到了负数
        //      2.由于在堆中str内存空间被释放了,所以原内存地址上的内容将变得随机,不可预知
        //      3.当退出代码块时jiu调用析构函数再次释放str内存空间,这就导致2次释放相同的内存地址,会产生错误
        callme2(jiu);
        cout << "jiu: " << jiu << endl;

        // 当使用默认赋值运算符时就会产生如下问题
        // 使用默认赋值运算符产生的问题
        // StringBad jiao; 使用默认构造函数创建了jiao
        // jiao = jiu;     使用默认赋值运算符将jiu的每个成员属性赋值给jiao,这将会导致上述默认复制函数的问题
        StringBad jiao;
        jiao = jiu;
    }
}

void callme1(StringBad &rsb) {
    cout << "通过引用传递:\n";
    cout << "\"" << rsb << "\"\n";
}

void callme2(StringBad sb) {
    cout << "通过值传递:\n";
    cout << "\"" << sb << "\"\n";
}


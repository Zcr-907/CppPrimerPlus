#include <iostream>
#include "human.h"
#include "stacktp.h"

using namespace std;

int main() {
//    Man man;
//    man.subShow();

    // 由于Man12多重继承自Man1和Man2,其内部miShow()方法存在多个版本,所以需要使用限定修饰符来调用具体的版本
    Man12 man12_1;
    man12_1.Man1::miShow();

    cout << "------- 泛型类 -------" << endl;
    // 仅在程序包含模版并不能生成模版类,必须进行实例化
    Stack<int> intStack;
    Stack<string> strStack;
    intStack.push(1);
    intStack.push(2);
    strStack.push("sspTop");
    int ispTop;
    intStack.pop(ispTop);
    string sspTop;
    strStack.pop(sspTop);
    cout << "ispTop: " << ispTop << endl;
    cout << "sspTop: " << sspTop << endl;

    tpSize<int>();
    tpSize<double>();

    cout << "------- 泛型类 -------" << endl;
}


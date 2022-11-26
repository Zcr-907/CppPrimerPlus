#include "Stock.h"


int main() {
    cout << "-------> 类对象创建 <-------" << endl;

    // 理解以下不同的使用方式差别
    Stock sally;            // 为sally分配了内存空间(栈上),但是所指向的位置是未知的
    sally.show();

    auto *solly = new Stock;// 为solly分配了内存空间(堆上),分配的内存区块都进行了零值初始化
    (*solly).show();
    cout << "-------> 类对象创建 <-------" << endl;
    cout << "-------> 类对象使用 <-------" << endl;
    sally.acquire("NanoSmart", 20, 12.50);
    sally.show();
    sally.buy(15, 18.125);
    sally.show();
    sally.sell(400, 20.00);
    sally.show();
    sally.buy(300000, 40.125);
    sally.show();
    sally.sell(300000, 0.125);
    sally.show();
    cout << "-------> 类对象使用 <-------" << endl;

}

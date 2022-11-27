#include "Stock.h"


int main() {
    cout << "-------> 类对象创建 <-------" << endl;
    Stock ucg0;                                  // 当程序没有提供构造函数时,就会调用默认构造函数
    Stock ucg1("Ucg1.0");               // ucg2的简便方式
    Stock ucg2 = Stock("Ucg2.0");       // 为sally分配了内存空间(栈上),但是所指向的位置是未知的 => 后期使用了构造函数来初始化
    auto *ucg3 = new Stock("Ucg3.0");   // 为solly分配了内存空间(堆上),分配的内存区块都进行了零值初始化

    ucg0.show();                                 // 对象的值是遗留在内存上的历史值
    ucg1.show();                                 // 被构造函数初始化后的值
    ucg2.show();                                 // new时会将内存区域进行零值初始化
    (*ucg3).show();
    cout << "-------> 类对象创建 <-------" << endl;


    cout << "-------> 类对象使用 <-------" << endl;
    ucg2.acquire("NanoSmart", 20, 12.50);
    ucg2.show();
    ucg2.buy(15, 18.125);
    ucg2.show();
    ucg2.sell(400, 20.00);
    ucg2.show();
    ucg2.buy(300000, 40.125);
    ucg2.show();
    ucg2.sell(300000, 0.125);
    ucg2.show();
    cout << "-------> 类对象使用 <-------" << endl;

}

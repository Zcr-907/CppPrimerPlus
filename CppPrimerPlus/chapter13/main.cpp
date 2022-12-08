#include <iostream>
#include "tabtenn0.h"

using namespace std;

int main() {
    TableTennisPlayer p1("Lewis", "Lei", true);
    p1.name();
    if (p1.hasTable()) {
        cout << " has a table;" << endl;
    }
    p1.resetTable(false);
    cout << "After rest Table= " << p1.hasTable() << endl;

    cout << "------- 创建子类 -------" << endl;
    RatePlayer r1{10, "Jiao", "BaCao", true};
    r1.name();
    cout << " rating: " << r1.rating() << endl;
    RatePlayer r2(20, p1);
    r2.name();
    cout << " rating: " << r2.rating() << endl;
    cout << "------- 创建子类 -------" << endl;

    cout << "------- 子类与父类 -------" << endl;
    RatePlayer r3(3, "SubClass", "r3", false);
    // 基类指针可以在不进行显示类型转换的情况下指向子类对象
    // 但是子类指针不能指向基类对象
    TableTennisPlayer &p2 = r3;
    TableTennisPlayer *p3 = &r3;
    TableTennisPlayer p4("SuperClass", "p4", true);
    // 对于参数是基类的方法: 可以传递子类参数,也可以传递基类对象
    void show(TableTennisPlayer &p);
    show(p4);
    show(r3);

    // 可以通过子类对象来初始化基类对象: 以下初始化语句
    // => TableTennisPlayer(const TableTennisPlayer &p);            // 通过上述的引用兼容属性将子类向上转型为基类,然后调用了默认复制函数
    TableTennisPlayer p5(r3);
    // => TableTennisPlayer& operator=(const TableTennisPlayer &p); // 通过上述的引用兼容属性将子类向上转型为基类,然后调用了默认赋值运算符
    TableTennisPlayer p6 = r3;
    cout << "------- 子类与父类 -------" << endl;

    cout << "------- 虚方法 -------" << endl;
    // 可以在子类中重新申明并定义一个非虚name(),但是存在一个问题: 程序根据引用类型或者指针类型来选择方法版本,就不能多态的根据对象类型来选择方法版本
    TableTennisPlayer p7("SuperClass", "p7", false);
    p7.name();
    cout << endl;
    RatePlayer r4(4, "SubClass", "r4", false);
    TableTennisPlayer &p8 = r4;
    p8.name();
    cout << endl;
    r4.name();
    cout << endl;


    // 采用虚方法,程序将根据对象的实际类型来调用
    p7.toString();
    cout << endl;
    p8.toString();
    cout << endl;
    cout << "------- 虚方法 -------" << endl;


}

void show(TableTennisPlayer &p) {
    cout << "Name: ";
    p.name();
    cout << "  Has Table: ";

    if (p.hasTable()) {
        cout << "yes!" << endl;
    } else {
        cout << "no!" << endl;

    }
}

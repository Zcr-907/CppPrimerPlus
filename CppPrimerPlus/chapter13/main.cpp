#include <iostream>
#include "tabtenn0.h"
#include "abstract0.h"
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

    cout << "------- 静态联编和动态联编 -------" << endl;
    // 静态联编: 静态分派(重载方法)
    // 动态联编: 动态分派(通过虚方法重写父类方法)

    // 当函数为传值调用时,如果传入子类就将子类中的基类部分传递给函数
    void toUpper(TableTennisPlayer p);
    toUpper(r3);
    cout << "------- 静态联编和动态联编 -------" << endl;
    cout << "------- 虚函数实现原理 -------" << endl;

    // result: RatePlayer(_rating: 2	TableTennisPlayer(_firstName: none	_lastName: none	_hasTable: 0))
    // ManRatePlayer调用默认构造函数,默认构造函数调用之前会调用RatePlayer的默认构造函数,所以_rating=2
    // 虚函数实现原理:
    // 1.编译器为每个对象都新增一个虚方法表(一个指向函数地址数组的指针)
    // 2.每个子类对象都包含一个指向独立地址表的指针。如果子类重新定义了虚方法,那么虚方法表就保存新函数地址,否则保存原始版本的函数(最近重写版本)
    // 3.特殊的,如果基类声明 int m1(); 子类声明  int m1(int a); => 那么m1()将会被隐藏,子类中的m1(int a)并不会作为m1()的重载版本
    //         但是如果返回类型为基类引用或者指针,那么重写版本可以为子类引用或者指针
    ManRatePlayer m1;
    m1.toString();
    cout << endl;
    cout << "------- 虚函数实现原理 -------" << endl;

    cout << "------- protected -------" << endl;
    // 对于基类使用protected修饰的成员，子类中可以进行直接使用,但是其他作用域是不可见的
    RatePlayer r5;
    r5.setAge(5);
    cout << "rg.age: "<<r5.getAge() << endl;
    cout << "------- protected -------" << endl;

    cout << "------- 抽象基类 -------" << endl;
    // 抽象类只能作为基类,而不能被实例化
    // AbstractClass ac1;

    SubClassA subA1;
    subA1.show();
    cout << "------- 抽象基类 -------" << endl;

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

void toUpper(TableTennisPlayer p) {
    cout << "向上转型:";
    p.toString();
    cout << endl;
}

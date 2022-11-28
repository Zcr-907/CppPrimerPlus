#include "Stock.h"


int main() {
    cout << "-------> 类对象创建 <-------" << endl;
    static Stock ucg0;                           // 当程序没有提供构造函数时,就会调用默认构造函数
    Stock ucg1("Ucg1.0");               // ucg2的简便方式
    {
        Stock ucg2 = Stock("Ucg2.0");       // 为sally分配了内存空间(栈上),但是所指向的位置是未知的 => 后期使用了构造函数来初始化
        auto *ucg3 = new Stock("Ucg3.0");   // 为solly分配了内存空间(堆上),分配的内存区块都进行了零值初始化

        ucg0.show();                                 // 对象的值是遗留在内存上的历史值
        ucg1.show();                                 // 被构造函数初始化后的值
        ucg2.show();                                 // new时会将内存区域进行零值初始化
        (*ucg3).show();
        cout << "-------> 类对象创建 <-------" << endl;


        cout << "-------> 类对象使用 <-------" << endl;
        ucg2.buy(20, 12.50);
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

        cout << "-------> 对象的销毁 <-------" << endl;
        delete ucg3;
        cout << "-------> 对象的销毁 <-------" << endl;

        cout << "-------> 对象的赋值 <-------" << endl;
        // 将一个对象赋值给另一个对象是深拷贝,而不是Java中的浅拷贝(修改引用指针)
        ucg1.test_copy = 2;
        cout << "ucg1.test_copy: " << ucg1.test_copy << endl;
        ucg2 = ucg1;
        cout << "ucg2.test_copy: " << ucg2.test_copy << endl;
        ucg2.test_copy = 1;
        cout << "ucg1.test_copy: " << ucg1.test_copy << endl;
        cout << "ucg2.test_copy: " << ucg2.test_copy << endl;
        cout << "-------> 对象的赋值 <-------" << endl;

        cout << "-------> Test Something <-------" << endl;
        Stock ucg10 = Stock("Ucg10.0"); // 创建该对象
        ucg10 = Stock("Ucg10.1");       // 创建一个临时变量,将该临时变量赋值给ucg10,任何删除该零时变量,最后离开作用域时再调用ucg10的析构函数
        cout << "-------> Test Something <-------" << endl;

        cout << "-------> const成员方法 <-------" << endl;
        const Stock ucg11("Ucg11.0");
        ucg11.show();    // 因为方法被const修饰,保证了该方法不会修改对象属性,所以可以直接调用
        // ucg11.sell(); // 因为ucg12被const修饰,程序无法判断该方法是否会修改对象属性
        cout << "-------> const成员方法 <-------" << endl;

        cout << "-------> this指针 <-------" << endl;
        Stock ucg12("Ucg12.0", 1, 1.0);
        ucg12.test_copy = 12;
        Stock ucg13("Ucg13.0", 1, 1.1);
        ucg13.test_copy = 13;
        cout << ucg12.top_val(ucg13).test_copy << endl;
        cout << "-------> this指针 <-------" << endl;

        cout << "-------> 对象数组 <-------" << endl;
        Stock stocks[3];                    // 调用默认的构造方法
        cout << stocks[1].test_copy << endl;// 对象确实被创建了,因为公有字段被初始化了
        cout << "-------> 对象数组 <-------" << endl;

        cout << "-------> 类成员 <-------" << endl;
        cout << Stock::class_field << endl;
        cout << "-------> 类成员 <-------" << endl;

        cout << "-------> 作用域内枚举 <-------" << endl;
        // 因为枚举值相同所以无效
//        enum egg1 {small, middle, big};
//        enum egg2 {small, middle, big};
        // 使用class或者struct关键字可以声明作用域枚举,这将不会导致冲突
        enum class egg1 {
            small, middle, big
        };
        enum struct egg2 {
            small, middle, big
        };
        // 作用域枚举不支持隐式转换,必须通过显示的类型转换才能转为int
        cout << "egg1::small =>" << (int) egg1::small << endl;
        cout << "egg2::small =>" << (int) egg2::middle << endl;

        cout << "-------> 作用域内枚举 <-------" << endl;

    }
    /**
     * -------> 对象的销毁 <-------
     * Stock Class of Ucg3.0 deleting   // 程序调用delete时调用了析构函数
     * -------> 对象的销毁 <-------
     * Stock Class of Ucg2.0 deleting   // 内层代码块结束时调用
     * Stock Class of Ucg1.0 deleting   // main函数结束时调用
     * Stock Class of No_Name deleting  // 程序结束时调用
     */
    return 0;
}

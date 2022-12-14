#ifndef CPP_DEV_STOCK_H
#define CPP_DEV_STOCK_H
// ======================= 正文 =======================
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Stock {
// 私有访问权限: 如果不添加任何访问修饰符,那默认为private权限
private:
    string m_company;     // 公司名称
    long m_shares;        // 持有股票总数量
    double m_share_val;   // 每股股票价格
    double m_total_val;   // 股票总价格

    // 定义与类声明中的函数都将自动成为内联函数
    // 无论是在类中声明并定义函数
    // 还是在类中声明,类声明之外定义成员函数都可以通过inline关键字使其成为内联函数
    void set_tot();
    //  void set_tot() {
    //      m_total_val = (double) m_shares * m_share_val;
    //  }


// 公共访问权限
public:
    // 类成员
    static const int class_field = 2;

    int test_copy = 1;

    // 声明构造函数来进行初始化成员属性
    Stock();

    Stock(const string &company, long n = 0, double pr = 0.0);

    // 析构函数: 对象过期时将会自动调用 析构函数
    // 静态存储类对象: 例如静态外部,静态内部,代码块内的静态。随着程序的结束而调用。eg: ucg0
    // 自动存储类对象: 非静态存储类时,执行完作用域代码块时自动调用。eg: ucg1,ucg2
    // 动态存储类对象: new出来的对象,由delete时调用。eg: ucg3
    // 临时对象: 方法传参时创建的零时变量将在结束该对象的使用时调用析构函数
    ~Stock();

    void buy(long num, double price);

    void sell(long num, double price);

    void update(double price);

    // const成员函数保证函数定义内不会对成员属性进行更改
    void show() const;

    // 第一个const: 表示返回的Stock引用不可被修改
    //      => s1.top_val(s2)=s3;将不被允许
    //      => s3=s1.top_val(s2); s3=s4; 这是允许的,因为经过一次赋值操作s3并不是返回的引用类型对象,而是深拷贝覆值过的对象,所以它是可变的
    // 第二个const: 显示访问的对象s引用在方法内不可被修改
    // 第三个const: 隐式访问的当前调用对象不会通过该方法修改自身的属性
    const Stock &top_val(const Stock &s) const;
};

inline void Stock::set_tot() {
    m_total_val = (double) m_shares * m_share_val;
}
// ======================= 正文 =======================
#endif

#ifndef CPP_DEV_STOCK_H
#define CPP_DEV_STOCK_H
// ======================= 正文 =======================
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Stock {
// 私有访问权限,如果不添加任何访问修饰符,那默认为private权限
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
    void acquire(const string &co, long n, double pr);

    void buy(long num, double price);

    void sell(long num, double price);

    void update(double price);

    // 如果函数在类声明中定义了,那么其他位置就不可重定义
    void show() {
        cout << "Company: " << m_company
             << " m_shares: " << m_shares << endl
             << " share price: " << m_share_val
             << " total Worth: " << m_total_val << endl;
    }

    // 声明构造函数来进行初始化成员属性
    Stock(const string &company, long n = 0, double pr = 0.0);
    Stock(){}

};

inline void Stock::set_tot() {
    m_total_val = (double) m_shares * m_share_val;
}
// ======================= 正文 =======================
#endif

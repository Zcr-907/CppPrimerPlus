#include "Stock.h"
#include <iostream>

using namespace std;

// 默认构造函数
Stock::Stock() {
    cout << "Create Default Stock\n";
    m_company = "No_Name";
    m_shares = 0;
    m_share_val = 0.0;
    m_total_val = 0.0;
}

// 有参构造函数
Stock::Stock(const string &company, long n, double pr) {
    cout << "Create Stock That Company Name Is " << company << endl;
    m_company = company;
    if (n < 0) {
        cout << "Number of m_shares can't be negative;"
             << m_company << " m_shares set to 0.\n";
        m_shares = 0;
    } else {
        m_shares = n;
    }
    m_share_val = pr;
    set_tot();
}

// 析构函数
Stock::~Stock() {
    cout << "Stock Class of " << m_company << " deleting" << endl;
}


void Stock::buy(long num, double price) {
    if (num < 0) {
        cout << " Number of m_shares purchased can't be negative."
             << "Transaction is aborted.\n";
    } else {
        m_shares += num;
        m_share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price) {
    if (num < 0) {
        cout << " Number of m_shares purchased can't be negative."
             << "Transaction is aborted.\n";
    } else if (num > m_shares) {
        cout << "You Can't sell more than you have!"
             << "Transaction is aborted.\n";
    } else {
        m_shares -= num;
        m_share_val = price;
        set_tot();
    }
}

void Stock::update(double price) {
    m_share_val = price;
    set_tot();
}


void Stock::show() const {
    //    m_company = "";
    cout << "Company: " << m_company
         << " m_shares: " << m_shares << endl
         << " share price: " << m_share_val
         << " total Worth: " << m_total_val << endl;
}

const Stock &Stock::top_val(const Stock &s) const {
    // const Stock temp = *this; // 如果返回临时变量temp是存在风险的,因为离开函数时,temp就会被销毁,后续返回的该引用地址将有可能出现其他的情况
    // 每个成员函数都有一个this指针,它指向调用对象
    if (s.m_total_val > this->m_total_val) {
        return s;
    } else {
        return *this;
    }
}

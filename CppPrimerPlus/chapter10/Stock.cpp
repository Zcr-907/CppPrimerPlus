#include "Stock.h"
#include <iostream>

using namespace std;

void Stock::acquire(const string &co, long n, double pr) {
    m_company = co;
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

// 定义构造函数
Stock::Stock(const string &company, long n, double pr) {
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

//void Stock::show() {
//    cout << "Company: " << m_company
//         << " m_shares: " << m_shares << endl
//         << " share price: " << m_share_val
//         << " total Worth: " << m_total_val << endl;
//}
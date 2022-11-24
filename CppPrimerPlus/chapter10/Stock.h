#ifndef CPP_DEV_STOCK_H
#define CPP_DEV_STOCK_H
// ======================= 正文 =======================
#include <string>

using std::string;

class Stock {
private:
    string company;     // 公司名称
    long shares;        // 持有股票总数量
    double share_val;   // 每股股票价格
    double total_val;   // 股票总价格

    void set_tot() {
        total_val = (double) shares * share_val;
    }

public:
    void acquire(const string &co, long n, double pr);
    void buy(long num,double price);
    void sell(long num,double price);
    void update(double price);
    void show();
};
// ======================= 正文 =======================
#endif

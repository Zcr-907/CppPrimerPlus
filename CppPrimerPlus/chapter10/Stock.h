#ifndef CPP_DEV_STOCK_H
#define CPP_DEV_STOCK_H
// ======================= 正文 =======================
#include <string>

using std::string;

class Stock {
// 私有访问权限
private:
    string company;     // 公司名称
    long shares;        // 持有股票总数量
    double share_val;   // 每股股票价格
    double total_val;   // 股票总价格
    void set_tot() {
        total_val = (double) shares * share_val;
    }

// 公共访问权限
public:
    void acquire(const string &co, long n, double pr);

    void buy(long num, double price);

    void sell(long num, double price);

    void update(double price);

    void show();
};
// ======================= 正文 =======================
#endif

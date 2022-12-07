#include "tabtenn0.h"
#include <iostream>

using std::cout;

TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln, bool ht) : _firstName(fn), _lastName(ln),
                                                                                    _hasTable(ht) {}

void TableTennisPlayer::name() const {
    cout << _firstName << ", " << _lastName;
}

// >>>>>>> sub class >>>>>>>
// 在调用子类构造函数前,程序首先创建基类对象
// 如果省略: TableTennisPlayer(fn, ln, ht) 将调用基类默认的构造函数,就等价于如下方法:
// RatePlayer::RatePlayer(unsigned int r, const string &fn, const string &ln, bool ht){...}
// RatePlayer::RatePlayer(unsigned int r, const string &fn, const string &ln, bool ht): TableTennisPlayer(){...}
RatePlayer::RatePlayer(unsigned int r, const string &fn, const string &ln, bool ht) : TableTennisPlayer(fn, ln,ht) {
    _rating = r;
}

// 可以通过初始化成员列表的方式初始化基类和子类扩展的字段
RatePlayer::RatePlayer(unsigned int r, const TableTennisPlayer &tp) : TableTennisPlayer(tp),_rating(r){}


#ifndef CPP_DEV_TABTENN0_H
#define CPP_DEV_TABTENN0_H

#include <string>

using std::string;

class TableTennisPlayer {
private:
    string _firstName;
    string _lastName;
    bool _hasTable;
public:
    explicit TableTennisPlayer(const string &fn = "none", const string &ln = "none", bool ht = false);

    void name() const;

    bool hasTable() const { return _hasTable; };

    void resetTable(bool v) { _hasTable = v; };

    virtual void toString() const;
};

// >>>>>>> sub class >>>>>>>
// ":"指出RatePlayer的基类是TableTennisPlayer
class RatePlayer : public TableTennisPlayer {
private:
    unsigned int _rating; // 记录得分
public:
    // 限定该构造函数只能用于显示转换,禁止隐式转换(RatePlayer r0 = true;)
    explicit RatePlayer(unsigned int r = 2, const string &fn = "none", const string &ln = "none", bool ht = false);

    RatePlayer(unsigned int r, const TableTennisPlayer &tp);

    unsigned int rating() const { return _rating; }

    void resetRating(unsigned int r) {
        _rating = r;
    }

    void name() const;

    // 可以用virtual来标识这是一个虚方法,这里为了去除警告所以删除了
    void toString() const override;
};

class ManRatePlayer : public RatePlayer {

};

#endif //CPP_DEV_TABTENN0_H

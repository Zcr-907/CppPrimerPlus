// Created by Zcr on 2022/11/29.


#ifndef CPP_DEV_MYTIME0_H
#define CPP_DEV_MYTIME0_H

class Time {
private:
    int hours;
    int minutes;
public:
    Time();

    explicit Time(int h, int m = 0);

    int getHr();

    int getMin();

    void addMin(int m);

    void addHr(int h);

    void reset(int h = 0, int m = 0);

    void show() const;

    Time sum(const Time &t) const;

    // 运算符重载
    Time operator+(const Time &t) const;

    // 友元函数
    friend Time operator*(int m, Time &t);

    friend int fGetHr(Time &t);

    friend std::ostream &operator<<(std::ostream &os, Time &t);

    // 转换函数: 被转换对象就是自身,所以不需要入参,返回值是int,所以也不需要对返回值进行定义
    // 使用explicit拒绝隐式转换[ int a=Time{1} ],只能通过显式转换[ int a= (int)Time{1} ]
    explicit operator int();
};

#endif //CPP_DEV_MYTIME0_H

// Created by Zcr on 2022/11/29.


#ifndef CPP_DEV_MYTIME0_H
#define CPP_DEV_MYTIME0_H

class Time {
private:
    int hours;
    int minutes;
public:
    Time();

    Time(int h, int m = 0);

    void addMin(int m);

    void addHr(int h);

    void reset(int h = 0, int m = 0);

    void show() const;

    Time sum(const Time &t) const;

    // 运算符重载
    Time operator+(const Time &t) const;
};

#endif //CPP_DEV_MYTIME0_H

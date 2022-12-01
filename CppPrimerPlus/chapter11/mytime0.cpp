#include <iostream>
#include "mytime0.h"

Time::Time() {
    hours = minutes = 0;
}

Time::Time(int h, int m) {
    hours = h;
    minutes = m;
}

void Time::addMin(int m) {
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::addHr(int h) {
    hours += h;
}

void Time::reset(int h, int m) {
    hours = h;
    minutes = m;
}


void Time::show() const {
    std::cout << hours << " hours, " << minutes << " minutes";
}

Time Time::sum(const Time &t) const {
    Time sum;
    sum.minutes = this->minutes + t.minutes;
    sum.hours = this->hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time Time::operator+(const Time &t) const {
    Time sum;
    sum.minutes = this->minutes + t.minutes;
    sum.hours = this->hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

int Time::getHr() {
    return hours;
}

int Time::getMin() {
    return minutes;
}

// 定义友元函数: 虽然友元函数在类中声明,但它不是成员函数,但它与成员函数的访问权限相同
//             不要使用Time::限定符,也不要在定义中使用friend,可以直接使用对象的私有属性
Time operator*(int m, Time &t) {
    Time result;
    int total_min = t.hours * m * 60 + t.minutes * m;
    result.hours = total_min / 60;
    result.minutes = total_min % 60;
    return result;
}

int fGetHr(Time &t) {
    return t.hours;
}

std::ostream &operator<<(std::ostream &os, Time &t) {
    std::cout << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}

Time::operator int() {
    return hours * 60 + minutes;
}






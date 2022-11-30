#include <iostream>
#include "mytime0.h"

Time operator/(int m, Time &n);

int main() {
    Time playing;
    Time coding(6);
    Time fixing(12, 30);

    using std::cout;
    using std::endl;

    cout << "playing time = ";
    playing.show();
    cout << endl;

    cout << "coding time = ";
    coding.show();
    cout << endl;

    cout << "fixing time = ";
    fixing.show();
    cout << endl;

    Time sum = coding.sum(fixing);
    cout << "coding.sum(fixing) = ";
    sum.show();
    cout << endl;

    Time sum_op = coding + fixing;
    cout << "coding + fixing = ";
    sum_op.show();
    cout << endl;

    cout << "------- 重载运算符 -------" << endl;
    Time main_operator{1, 30};
    // 示意: 非成员函数也能重载运算符
    cout << "main_operator= ";
    main_operator.show();
    cout << endl << "2 / main_operator= ";
    (2 / main_operator).show();
    cout << endl << "------- 重载运算符 -------" << endl;

    cout << "------- 友元运算符 -------" << endl;
    Time ucg_friend(1, 30);
    // 通过友元函数来重载 * 运算符
    Time double_ucg_friend = 2 * ucg_friend;
    // 通过友元函数来重载 << 运算符: 必须是通过友元函数,因为如果不为友元函数的话,那么第一个操作数必须为Time
    cout << double_ucg_friend << endl;
    // 这只是举例可以定义任意的友元函数
    cout << "friend get double_ucg_friend hours= " << fGetHr(double_ucg_friend) << endl;
    cout << "------- 友元运算符 -------" << endl;

}

Time operator/(int m, Time &n) {
    int total_min = (n.getHr() * 60 + n.getMin()) / m;
    return {total_min / 60, total_min % 60};
}


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


    cout << "------- 转换函数 -------" << endl;
    //  在Time(int h, int m = 0)没有被explicit修饰的时候是可以将int赋值给Time对象,因为2个参数中第一个为int,第二个赋了默认值 => 等价Time a(1)
    //  这种情况适用与
    //  1.将int赋予Time对象
    //  2.将Time对象初始化为int值时
    //  3.函数的参数为Time对象时
    //  4.函数的返回值为Time镀锡时
    //  Time a=1;
    int change_time = (int)Time{1};
    cout << "change_time = {1} => change_time= " << change_time << endl;
    cout << "------- 转换函数 -------" << endl;
}

Time operator/(int m, Time &n) {
    int total_min = (n.getHr() * 60 + n.getMin()) / m;
    return Time{total_min / 60, total_min % 60};
}


#include <cstring>
#include "stringbad.h"

// 初始化静态类成员
int StringBad::num_strings = 0;

StringBad::StringBad(const char *s) {
    len = (int) std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
    std::cout << num_strings << " : \"" << str
              << "\" object created\n";
}

StringBad::StringBad(const StringBad &sb) {
    len = (int) std::strlen(sb.str);
    str = new char[len + 1];
    std::strcpy(str, sb.str);
    num_strings++;
    std::cout << num_strings << " : \"" << str
              << "\" object created\n";
}

StringBad::StringBad() {
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    num_strings++;
    std::cout << num_strings << " : \"" << str
              << "\" object created\n";
}

StringBad::~StringBad() {
    std::cout << "\"" << str << "\" object deleted, ";
    std::cout << --num_strings << " left\n";
    delete[] str;
}

std::ostream &operator<<(std::ostream &os, const StringBad &st) {
    os << st.str;
    return os;
}

StringBad &StringBad::operator=(const StringBad &sb) {
    // 如果是a=a;直接返回即可
    if (this == &sb) {
        return *this;
    }
    // 由于在使用赋值运算符之前已经为str分配了内存空间,为防止内存泄露,需要对之前分配的空间进行释放
    delete[] str;
    len = sb.len;
    str = new char[len + 1];
    std::strcpy(str, sb.str);
    return *this;
}

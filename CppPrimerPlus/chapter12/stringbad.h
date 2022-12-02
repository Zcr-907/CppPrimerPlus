#ifndef CPP_DEV_STRINGBAD_H
#define CPP_DEV_STRINGBAD_H

#include <iostream>

class StringBad {
private:
    // 字符串值
    char *str;
    // 字符串长度
    int len;
    // 创建该类对象的计数
    static int num_strings;

public:
    StringBad();

    StringBad(const char *s);

    ~StringBad();

    friend std::ostream &operator<<(std::ostream &os, const StringBad &st);
};

#endif

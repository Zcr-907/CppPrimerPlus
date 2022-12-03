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

    // 使用自定义复制构造函数,这样进行如下操作时就不会调度默认的复制函数
    // StringBad ditto(motto);
    // StringBad metoo=motto;           // 可能直接调用复制函数,也可能使用复制函数构建临时对象然后再将临时对象复值给该变量
    // StringBad also=StringBad(motto); // 可能直接调用复制函数,也可能使用复制函数构建临时对象然后再将临时对象复值给该变量
    // StringBad * pStringBad=new StringBad(motto);
    // 当调度按值传递的函数时也会调度复制函数
    StringBad(const StringBad &sb);

    StringBad(const char *s);

    ~StringBad();

    friend std::ostream &operator<<(std::ostream &os, const StringBad &st);

    // 自定义赋值运算符,防止使用默认运算符造成问题
    StringBad &operator=(const StringBad &sb);
};

#endif

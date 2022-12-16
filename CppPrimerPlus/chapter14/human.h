#ifndef CPP_DEV_HUMAN_H
#define CPP_DEV_HUMAN_H


class Human {
public:
    void show() const;
};

// 使用私有继承,子类将基类的公有方法,作为自己的私有方法,外部不可访问
class Man : private Human {
public:
    void subShow() const;
};


#endif //CPP_DEV_HUMAN_H



#ifndef CPP_DEV_ABSTRACT0_H
#define CPP_DEV_ABSTRACT0_H


class AbstractClass {
private:
    int _x;  // x坐标
    int _y;  // y坐标
public:
    explicit AbstractClass(int x = 0, int y = 0) : _x(x), _y(y) {}

    // 方法声明后增加=0,表示该函数为纯虚函数
    // 拥有至少一个纯虚函数的类为抽象类,抽象类只能作为基类而不能被初始化
    virtual void show() = 0;
};

class SubClassA : public AbstractClass {
public:
    void show() override;
    // virtual void show(); // 与上作用一致

};

#endif //CPP_DEV_ABSTRACT0_H

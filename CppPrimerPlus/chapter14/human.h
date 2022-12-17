#ifndef CPP_DEV_HUMAN_H
#define CPP_DEV_HUMAN_H


class Human {
public:
    void show() const;
};

// 使用私有继承,子类将基类的公有方法,作为自己的私有方法,外部不可访问
// 使用保护继承,子类将基类的公有/保护成员,作为子类的保护成员
class Man : private Human {
public:
    void subShow() const;
};

/**
 * Man1和Man2使用虚基类Human
 * 不实用虚基类: 将导致Man12包换2个Human对象的副本
 * 使用虚基类: 使得Man12仅有1个Human对象副本
 */
class Man1 : virtual public Human {
public :
    void miShow();
};

class Man2 : virtual public Human {
public :

    void miShow();
};

class Man12 : public Man1, public Man2 {

};


#endif //CPP_DEV_HUMAN_H

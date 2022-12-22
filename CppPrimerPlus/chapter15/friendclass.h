#ifndef CPP_DEV_FRIENDCLASS_H
#define CPP_DEV_FRIENDCLASS_H

#include <iostream>

using namespace std;

class Tv {
private:
    string _name;
public:
    // 声明了一个友元类,该友元类可以直接访问Tv的私有元素
    friend class Remote;

    Tv(string name) : _name(name) {}

};

class Remote {
public:
    void getTvName(const Tv &t) {
        // 访问到了tv的私有原属
        cout << t._name << endl;
    }
};

/**
 * RTTI
 */
class Grand {
    int _num;
public:
    explicit Grand(int num = 0) : _num(num) {}

    virtual void speak() const {
        cout << "i am a Grand" << endl;
    };
};

class Major : public Grand {
public:
    void speak() const override {
        cout << "i am a Major" << endl;
    };

    virtual void say() const {
        cout << "Major Say" << endl;
    }
};

class Minor : public Major {
public:
    void speak() const override {
        cout << "i am a Minor" << endl;
    };

    void say() const override {
        cout << "Minor Say" << endl;
    }
};

// >>>>>>> 前置声明 >>>>>>>
/**
 * 1.由于Tv1将Remote1::opsTv1()声明为友元方法,所以在Tv1声明之前应该至少存在Remote1::opsTv1()的声明
 * 2.Remote1::opsTv1()的声明至少需要存在Tv1类,所以在这之前前置声明了一个Tv1
 */
class Tv1;

class Remote1 {
public:
    void opsTv1(Tv1 &tv1, string name);
};


class Tv1 {
    friend void Remote1::opsTv1(Tv1 &tv1, string name);

private:
    string _name;

public:
    Tv1(string &name);

    void toString() const;
};

inline Tv1::Tv1(string &name) : _name(name) {}

inline void Tv1::toString() const {
    cout << _name << endl;
}

inline void Remote1::opsTv1(Tv1 &tv1, string name) {
    tv1._name = name;
}

#endif //CPP_DEV_FRIENDCLASS_H

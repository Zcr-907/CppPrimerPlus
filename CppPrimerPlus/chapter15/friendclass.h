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


#endif //CPP_DEV_FRIENDCLASS_H

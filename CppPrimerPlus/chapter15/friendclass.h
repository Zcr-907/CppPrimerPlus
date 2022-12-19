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


#endif //CPP_DEV_FRIENDCLASS_H

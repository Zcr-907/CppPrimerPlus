#ifndef CPP_DEV_FRIENDCLASS_H
#define CPP_DEV_FRIENDCLASS_H

#include <iostream>

using namespace std;

// =====================
// 友元类: 如下例子中,Tv类中声明了Remote为Tv的友元类,那么后续在Remote的作用域内就可以访问Tv的私有元素
// =====================
class Tv {
    // 声明Remote为Tv的友元类
    friend class Remote;

private:
    string _name;

public:

    explicit Tv(string &name);

};

class Remote {
private:
    string _name;
public:
    explicit Remote(string &name);

    void printTvName(const Tv &t) const;

};

inline Tv::Tv(string &name) : _name(name) {}

inline Remote::Remote(string &name) : _name(name) {}

// 由于Remote是Tv的友元类,所以Remote类的方法可以访问Tv实例的私有属性
inline void Remote::printTvName(const Tv &t) const {
    cout << _name << " Print: [" << t._name << "]" << endl;
}

// =====================
// 友元方法: 如果说B类只有一个方法会使用到A类的私有属性,那么将整个B类声明为A类的友元类显得不那么必要,可以将B类的那个方法声明为A类的友元方法
//          这样的话只有B类的那个指定的友元方法才可以访问A类的私有属性
// 前置声明: 由于A和B在声明的时候需要知道互相的存在
//          对于B而言由于方法声明只需要知道A类的存在。对于A而言,需要B的类声明(包括方法声明)。
//          所以B的完整声明需要在A的完整声明之前,A的前置声明需要在B的完整声明之前,整个声明过程如下
// =====================
// 前置声明
class Tv1;

class Remote1 {
public:
    // updateTv1Name()在Tv1的声明中被声明为友元方法,所以该方法可以操作Tv1的私有属性
    static void updateTv1Name(Tv1 &tv1, string &name);
};

class Tv1 {
    // 声明Remote1::updateTv1Name()为Tv1的友元方法
    friend void Remote1::updateTv1Name(Tv1 &tv1, string &name);

private:
    string _name;
public:
    explicit Tv1(string &name);

    void toString() const;
};

inline Tv1::Tv1(string &name) : _name(name) {}

inline void Tv1::toString() const {
    cout << "Tv1: " << _name << endl;
}

inline void Remote1::updateTv1Name(Tv1 &tv1, string &name) {
    tv1._name = name;
}

// =====================
// RTTI: 运行时类型识别
// =====================
class Grand {
public:
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

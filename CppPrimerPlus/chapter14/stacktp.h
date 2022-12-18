#ifndef CPP_DEV_STACKTP_H
#define CPP_DEV_STACKTP_H

#include <iostream>

using namespace std;

// 约束友元step1
template<typename T>
void tpSize();

template<class T>
class Stack {
private:
    enum {
        MAX = 10
    };
    T _items[MAX];
    int _top;
public:
    Stack();

    bool isEmpty();

    bool isFull();

    bool push(const T &item);

    bool pop(T &item);

    // 约束友元step2
    friend void tpSize<T>();
};

/**
 * 为什么此处将函数定义与函数声明放在一起? => 由于模版不是函数他们不能单独编译,所以需要将定义与声明放在一个实现文件中
 * @tparam T
 */
// template<class T>                 => class与typename等价
// template<class T1,class T2>       => 可以使用多个泛型
template<typename T>
Stack<T>::Stack() {
    _top = 0;
}

template<class T>
bool Stack<T>::isEmpty() {
    return _top == 0;
}

template<class T>
bool Stack<T>::isFull() {
    return _top == MAX;
}

template<class T>
bool Stack<T>::push(const T &item) {
    if (_top < MAX) {
        _items[_top++] = item;
        return true;
    }
    return false;
}

template<class T>
bool Stack<T>::pop(T &item) {
    if (_top > 0) {
        item = _items[--_top];
        return true;
    }
    return false;
}

// 约束友元step3
template<class T>
void tpSize() {
    cout << "tpSize: " << sizeof(Stack<T>) << endl;
}


#endif //CPP_DEV_STACKTP_H

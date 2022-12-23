#include "friendclass.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define DYNAMIC_CAST_LOOP 5
using namespace std;


Grand *getOneGrand();


int main() {
    cout << "------- 友元类 -------" << endl;
    string publicPartFriendClass = "FriendClass";
    string tv_1_name = publicPartFriendClass + "|tv_1";
    string remote_1_name = publicPartFriendClass + "|remote_1";

    Tv tv_1(tv_1_name);
    Remote remote_1(remote_1_name);
    remote_1.printTvName(tv_1);

    cout << "------- 友元方法,前置声明 -------" << endl;
    string publicPartFriendMethod = "FriendMethod";
    string tv1_1_name = publicPartFriendMethod + "|tv1_1";
    Tv1 tv1_1(tv1_1_name);
    Remote1 remote1_1;
    tv1_1.toString();
    string updateName = publicPartFriendMethod + "|updateName";
    remote1_1.updateTv1Name(tv1_1, updateName);
    tv1_1.toString();

    cout << "------- RTTI#dynamic_cast -------" << endl;
    srand(time(nullptr));
    int n = DYNAMIC_CAST_LOOP;
    while (n-- > 0) {
        Grand *pg = getOneGrand();
        cout << ">dynamic_cast#loop#" << n << "<" << endl;
        pg->speak();
        // 如果pg为Major及其子类那么就会返回一个Major*的指针引用,否则就会返回一个空指针
        if (dynamic_cast<Major *>(pg)) {
            dynamic_cast<Major *>(pg)->say();
        }
        delete pg;
    }

    cout << "------- RTTI#typeid -------" << endl;
    n = DYNAMIC_CAST_LOOP;
    while (n-- > 0) {
        Grand *pg = getOneGrand();
        cout << ">typeid#loop#" << n << "<" << endl;
        pg->speak();
        // pg的真实类型必须为Major,才会判断为True
        if (typeid(Major) == typeid(*pg)) {
            dynamic_cast<Major *>(pg)->say();
        }
        delete pg;
    }

    cout << "------- tryCatch -------" << endl;
    void tryCatch(int a, int b);
    tryCatch(1, 0);
}

void tryCatch(int a, int b) {
    try {
        if (b == 0) {
            throw "除数不能为0";
        }
        cout << a / b << endl;
    } catch (const char *message) {
        cout << message << endl;
    }
}

// 随机生成Grand继承树上的对象
Grand *getOneGrand() {
    int random = rand() % 3;
    switch (random) {
        case 0:
            return new Grand();
        case 1:
            return new Major();
        case 2:
            return new Minor();
        default:
            throw exception();
    }
}


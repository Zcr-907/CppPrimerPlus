#include <iostream>
#include "human.h"

int main() {
//    Man man;
//    man.subShow();

    // 由于Man12多重继承自Man1和Man2,其内部miShow()方法存在多个版本,所以需要使用限定修饰符来调用具体的版本
    Man12 man12_1;
    man12_1.Man1::miShow();
}


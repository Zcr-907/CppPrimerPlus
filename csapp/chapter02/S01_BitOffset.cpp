#include <iostream>

void lab01() {
    using namespace std; // 设置名称空间
    // 测试证明: << 左移运算符,会讲所有的高位依次剔除。例如10....111 <===> 0.....1110
    cout << "[有符号负数左移]: " << (0xBFFFFFFF << 1) << endl;

    // 测试证明: 无符号数与有符号数一起操作时,先将有符号数转为无符号数进行同一操作
    unsigned int uZero = 0;
    cout << "[uZero > -1]: " << (uZero > -1) << endl;

    // 测试证明: 无符号数与有符号数一起操作时,先将有符号数转为无符号数进行同一操作
    //          以下会陷入死循环
    unsigned int i = 0;
    for (int j = 0; j >= i; j--) {
        cout << j << endl;
    }

    /**
     * 问题1:
     *  (int a >> 0XFF): 保留低八位的值
     *  (char b>> 0XFF): 保留低八位的值,并且将char向上转型为int
     *                   目的是char无论表示的是负数还是正数,因为向上转型,当前值的补码表示为正数的补码
     *  (char) (1 & 0XFF): 问题描述 > char直接截断了int的第八位,&0XFF也是取出第八位,那么为什么不直接使用(char)int?
     *                     解释    >
     */
    int i_int = (char) (1 & 0XFF);
}



#include <iostream>
#include <cctype>

void fileIO_func();

int main() {

    fileIO_func();

    int i = 0;
    int j = 1;
    if (i++ >= 0 || i == j++) {
        // 逻辑或运算: 因为i++ >= 0=true,所以i==j++就不会被执行
        std::cout << " (i++ > -1 || i == ++j) >> j:" << j << std::endl;
    }

    // 指定枚举one的只为49,后续的枚举值依次递增1
    enum switch_case {
        one = 49, two, three, four, five, six
    };
    std::cout << "输入一个数字" << std::endl;
    char user_input;
    std::cin.get(user_input).get(); //  最后的get()是为了消耗输入时的回车
    while (isdigit(user_input)) {   // 判断输入的字符是否为数字
        switch (user_input) {
            case one:
                std::cout << "switch_case#one:" << one << std::endl;
                break;
            case two:
                std::cout << "switch_case#two:" << two << std::endl;
                break;
            case three:
                std::cout << "switch_case#three:" << three << std::endl;
                break;
            case four:  // 不添加break;程序就会执行接下去的case
                std::cout << "switch_case#four:" << four << std::endl;
            case five:
                std::cout << "switch_case#five:" << five << std::endl;
            case six:
                std::cout << "switch_case#six:" << six << std::endl;
            default:
                std::cout << "greater than six" << std::endl;
        }
        std::cout << "输入一个数字" << std::endl;
        std::cin.get(user_input).get();
    }
    std::cout << "非数字: " << user_input << "\n程序退出" << std::endl;


}


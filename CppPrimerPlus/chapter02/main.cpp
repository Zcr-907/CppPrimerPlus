#include <iostream> // C++新式风格头文件名
//#include <math.h>   // C旧式头文件名
//#include <cmath>    // 转换为C++新式风格的C库


// C++要求以int main()为开始
int main() {
    using namespace std;    // 名称空间: 在java中如何区别类名一致的类型呢 > 通过包名 > 名称空间起到的作用大抵相同

    /**
     * Show Input and Output
     */
    int num;
    cin >> num;
    for (int i = 0; i < num; ++i) {
        cout << "Hello Cpp!" << endl;
    }
}


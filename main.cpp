#include <iostream>

void test();

void (*pf)();

int main() {
    using namespace std;// C++的新标准,预处理中的头文件如果为不加.h后缀的形式就可以使用这种"声明名称空间的方式"
    cout << "Hello World";// 格式符重载(eg: &既可以表示为取地址,也可以表示为位AND操作)
    cout << endl;         // 光标换行



    using namespace std;
    pf = &test;
    printf("%p\n",&test);
    printf("%p\n",*pf);

}

void test() {
    printf(" func Pointer");
}

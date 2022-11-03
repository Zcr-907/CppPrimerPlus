#include <iostream>
#include <climits>  // 该头文件定义了符号常量来表示类型的限制

using namespace std;

void int_dev();

void char_dev();

int main() {
    // 函数内可以使用未被初始化的变量来初始化另一个变量,但这会导致2个变量的值都是未知的,它们的值等于当前内存单元由于之前操作所遗留下的值
    // C++可以使用={},{},=(),()来进行初始化,差别在()内不可以为空,但{}可以,{}为空时,变量初始化为零值
    int a = (1);
    int b;
    int c{1};
    cout << "Int a: " << a << endl;
    cout << "Int b: " << b << endl;
    // sizeof: 是运算符,并不是函数
    //         好的习惯是无论其中是变量还是类型名都加上括号(sizeof()),当然变量可以不加括号
    cout << "Sizeof Int: " << sizeof(a) << endl;
    cout << "Sizeof Int: " << sizeof(int) << endl;
    // 不同的物理机1Byte的实现并不一致,CHAR_BIT表示了当前物理机上1Byte的Bit数
    cout << "CHAR_BIT:" << CHAR_BIT << endl;

    // ================================================================================================================
    int_dev();
    char_dev();
}

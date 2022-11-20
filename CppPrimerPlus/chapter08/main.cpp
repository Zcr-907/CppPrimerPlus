#include <iostream>

using namespace std;

struct Offset {
    int x;
    int y;
};

struct Location {
    Offset o1;
    int height;
};

// 1.内联函数
// 声明一个内联函数
// 内联函数在程序执行时将二进制代码复制到程序调用处,以节省程序花在函数调用处的时间,但如果多处调用的话,内存开销也不小
inline int incr_int(int a) {
    return ++a;
}

// 2.默认参数
//   函数的默认参数实现通过函数声明实现,定义携带默认参数的函数时,必须从从右往左设置默认值( invalid eg:  int a=1, int b, int c = 3)
//   使用时: 从左往右进行赋值
//          print_3_int_can_default(1);         valid       a=1,b=2,c=3
//          print_3_int_can_default(1,12);      valid       a=1,b=12,c=3
//          print_3_int_can_default(1,12,13);   valid       a=1,b=12,c=13
//          print_3_int_can_default(1,,13);     invalid
void print_3_int_can_default(int a, int b = 2, int c = 3);

// 5.通用模版函数: 起到了类似Java中泛型的作用,
//   关键字"typename"是必须的,仅可以使用class替代,否则必须为typename。这2关键字(typename和class是等价的)
//   模版函数并不能缩短可执行函数,例如对于swap_two_val()而言,使用int和double时,最终将由2个独立的函数定义,就像以手工定义了这些函数一样
//   最终的代码不包括任何模版,近包含了为程序生成的实际函数 => 之所以使用模版函数是由于它生成的多个函数定义更简单更可靠(避免手动的copy,replace)
//                                                    对于#define也更符合程序生成 #define,#define会对任何(变量名等)也进行替换
//   模版函数同样可以使用函数重载(只要2个函数 特征指标不同)

//   对于以下方法的调用,当调用时,实参都能与之匹配时: 非模版函数>显示具体化模版函数>通用模版函数
//                           其他情况        : 根据实参类型按需调度
//  1)通用模版函数
template<class T>
void swap_two_val(T &, T &); // 等价template<typename T>  // 等价void swap_two_val(T &a, T &b);
//  2)非模版函数
void swap_two_val(char &, char &);

//  3)显示具体化模版函数
template<>
void swap_two_val<Offset>(Offset &, Offset &);

// 5.1实例化与具体化
// 1)隐式实例化: 当程序编译时,发现程序需要进行模版实例化时才会生成对应类型(按需)
//   显示实例化: 如下方式则在该声明处识别出要生成模版实例,而不需等编译判断是否需要生成
template void swap_two_val<int>(int &, int &);

// 2)显示具体化: 即告诉编译器不要使用函数模版进行实例化,而应该使用专门为Location类型显示的定义函数定义
//              显示具体化在template后添加<>,但显示实例化没有,如果在同一个编译单元使用同一种类型的显示实例化与显示具体化将会出错
template<>
void swap_two_val<Location>(Location &, Location &);

int main() {
    cout << "using inline func incr_int: " << incr_int(2) << endl;

    // 2.引用变量,在&符号出现在赋值表达式的左侧时,表示左侧变量名为右侧值的引用,修改左侧值 => 修改右侧值
    //   这为在函数传参时处指针以外多提供了一种使用引用的方式,这样修改这个值其实就是修改其原始值,而不是副本
    int a = 1;
    int b = 1;
    int &ref_a = a; // 声明引用变量时必须初始化,一旦建立便不可更改引用变量的管理关系
    ref_a++;
    cout << "使用引用变量修改a的值,a= : " << a << endl;
    ref_a = b;

    // 看起来ref_a=b=1,好像将ref_a和b关联起来,其实这等价与a=b
    // 查看&ref_a , &a ,&b会发现  &ref_a = &a != &b
    cout << "修改引用关系的关联对象,a= : " << a << endl;

    // 声明一个使用引用变量为参数的函数来修改引用变量的值
    void update_int_val(int &original, int update);
    update_int_val(a, 1001);
    cout << "使用引用变量参数的函数修改a的值,a= : " << a << endl;


    // 3.引用结构变量 引用类变量其实也一致的
    //   如果试图返回函数内的临时变量的引用,并在外部调用的话那会报错,因为程序内部变量会随着方法栈的出栈而销毁
    Location l1 = {
            {1, 2}, 3
    };
    void update_struct(Location &original);
    update_struct(l1);
    cout << "l1.o1.x: " << l1.o1.x << endl;
    cout << "l1.o1.y: " << l1.o1.y << endl;
    cout << "l1.height: " << l1.height << endl;


    print_3_int_can_default(1);
    print_3_int_can_default(1, 12);
    print_3_int_can_default(1, 12, 13);

    // 4.函数重载: 对于指针类型的参数与引用类型的参数,存在const匹配的优先级,其他的常规参数如果除const之外特产相同，那么编译将会出错，存在二义性
    void reload(const int &a);      // 左值匹配
    void reload(int &a);
    void reload(string a);          // 函数标识不同
    void reload(const int &&a);     // 右值匹配

    int reload_test = 1;
    reload(reload_test);
    reload(1);

    // 5.函数模版,起到了类似Java中泛型的作用
    int s_a = 1;
    int s_b = 2;
    swap_two_val(s_a, s_b);
    cout << "s_a=" << s_a << endl;
    cout << "s_b=" << s_b << endl;


}

template<typename T1, typename T2>
auto decltype_func(T1 x, T2 y) -> decltype(x + y) {
    // decltype(x + y) xy_type => 将xy_type定义为(x+y)的类型
    // typedef 为后续使用上述类型提供方便
    // auto: 可以理解为占位符,表示由后置返回类型(-> decltype(x + y))提供的类型
    typedef decltype(x + y) xy_type;
    xy_type z = x + y;
    return z;
}

template<typename T>
void swap_two_val(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

void swap_two_val(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

template<>
void swap_two_val<Offset>(Offset &a, Offset &b) {
    int temp_x = a.x;
    int temp_y = a.y;
    a.x = b.x;
    a.y = b.y;
    b.x = temp_x;
    b.y = temp_y;
}

void swap_two_val(Location &, Location &) {

}

void reload(const int &a) {
    cout << "const int &a" << endl;
}

void reload(int &a) {
    cout << "const int &a" << endl;
}

void reload(string a) {
    cout << "const string a" << endl;
}

void reload(const int &&a) {
    cout << "const int &&a" << endl;
}

void update_int_val(int &original, int update) {
    original = update;
}

void update_struct(Location &original) {
    original = {
            {4, 5}, 6
    };
}

void print_3_int_can_default(int a, int b, int c) {
    using namespace std;
    cout << "-------> print_3_int_can_default <-------" << endl;
    cout << "a= " << a << endl;
    cout << "b= " << b << endl;
    cout << "c= " << c << endl;
    cout << "-------> print_3_int_can_default <-------" << endl;
}



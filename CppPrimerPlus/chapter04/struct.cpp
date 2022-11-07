#include <iostream>
#include <string>

using namespace std;

struct Human {
    int num;
    string name;    // 为啥不使用char[],使用char就不能像h2那样简单的进行初始化赋值了
    int age;
    double height;
};

// 不建议: 变量尽可能声明在较小的作用域,避免误操作.将结构定义与变量声明区分开更易于阅读和理解
struct Human1 {
    int num;
    string name;
    int age;
    double height;
} human1a, human1b;

// 不建议: 将结构定义与变量初始化分开更为合理和优雅
struct Human2 {
    int num;
    string name;
    int age;
    double height;
} human2a = {
        1, "human2a", 22, 161.1
};

// 不建议: 这样human3a类型的变量就无法在创建了
struct {
    int num;
    string name;
    int age;
    double height;
} human3a = {
        1, "human2a", 22, 161.1
};

void struct_unc() {

    Human h0 = {0, "h0", 23, 173.5};
    Human h1{1, "h1", 21, 172.5};
    Human h2;
    h2.num = 2;
    h2.name = "h2";
    h2.age = 22;
    h2.height = 170.1;
    Human h3{3};

    cout << "-------> struct_unc <-------" << endl;
    cout << "num: " << h0.num << "\tname: " << h0.name << "\tage: " << h0.age << "\theight: " << h0.height << endl;
    cout << "num: " << h1.num << "\tname: " << h1.name << "\tage: " << h1.age << "\theight: " << h1.height << endl;
    cout << "num: " << h2.num << "\tname: " << h2.name << "\tage: " << h2.age << "\theight: " << h2.height << endl;
    cout << "num: " << h3.num << "\tname: " << h3.name << "\tage: " << h3.age << "\theight: " << h3.height << endl;


    // 证明"h5_b = h5_a": 与Java不同,这是深拷贝,不是将h5_a的引用赋给h5_b
    //                   无论采取如下何种方式赋值,当h5_b声明时就开辟了一块内存空间,而后的赋值操作,是将h5_a的属性值拷贝至h5_b属性的地址上
    //                   Human h5_b=h5_a; struct Human h5_b=h5_a;
    Human h5_a = {50, "h5a", 23, 173.5};
    Human h5_b{};
    h5_b = h5_a;
    cout << "&h5_a.num: " << &h5_a.num << "\th5_a.num: " << h5_a.num << "\t&h5_a.name: " << &h5_a.name
         << "\th5_a.name: " << h5_a.name << endl;
    cout << "&h5_b.num: " << &h5_b.num << "\th5_a.num: " << h5_b.num << "\t&h5_a.name: " << &h5_b.name
         << "\th5_b.name: " << h5_b.name << endl;


    cout << "-------> struct_unc <-------" << endl;

}


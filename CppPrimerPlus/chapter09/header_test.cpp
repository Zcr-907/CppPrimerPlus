#include <iostream>
#include "header_test.h"

using namespace std;
// 声明了一个静态持续性,链接性为外部的的静态变量
extern string static_external = "static_external";

string static_inner_test="static_inner_test";
void plus_HeaderStruct_h2_to_h1(HeaderStruct &h1, HeaderStruct h2) {
    h1.a = h1.a + h2.a;
    h1.b = h1.b + h2.b;
}

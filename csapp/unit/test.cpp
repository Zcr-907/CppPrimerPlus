#include <cstdio>

int main() {
    // 逗号表达式: 从左至右依次计算表达式,然后将最右侧的表达式值赋予变量
    int a = (a = 3 * 5, a * 4);
    printf("%d\n", a);
}

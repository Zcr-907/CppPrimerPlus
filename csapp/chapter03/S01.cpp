/**
 * 查看汇编代码
 * gcc -Og -S S01.cpp
 * gcc > gcc 编译器
 * -Og > debug级的编译优化,不过度优化
 * -S  > 仅仅完成第一阶段就停止: 也就是将源代码转为汇编代码
 */
 /**
  * disassemble 反汇编: 通过目标程序得出汇编代码
  * [方式一] objdump -d S01 > S01.d
  * [方式二] 安装gdb: brew install gdb
  *         $ gdb S01
  *         (gdb)  disassemble lab01(long, long, long*)
  */
long plus(long x, long y);
int main(){

}
void lab01(long x, long y, long *dest) {
    long t = plus(x, y);
    *dest = t;
}

long plus(long x, long y) {
    return x + y;
}


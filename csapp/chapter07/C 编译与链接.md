### C 编译与链接

#### 强符号与弱符号

- 链接器不允许定义2个同名的强符号
- 存在一个强符号与多个弱符号同名，那么选择强符号
- 存在多个同名弱符号,随机选择一个弱符号

#### 如何避免编译时的符号同名问题

- GCC-fno-common：遇到多重定义的全局符号时触发一个错误
- -Werror：任何的警告都变为错误

#### 为什么要使用静态链接库？

- 在链接器中定义对标准函数的支持 -> 导致链接器的构造异常复杂(C存在大量标准函数)

- 作为参数交给链接器生产可执行目标文件

  - gcc main.c /usr/lib/libc.o > 导致程序中存在大量不被使用到的函数(内存被消耗)
  - gcc main.c /usr/lib/print.o …. > 参数太多，容易出错且耗时

- 静态链接库

  - gcc main.c /usr/lib/libc.a

  - libc.a中的函数被编译成独立的模块,链接时将只复制被程序使用到的目标模块

    - 减少了内存的消耗，也不需要提供那么多的参数

- 链接器如何使用静态库来解析引用

  - 基本顺序：

    - 可重定义目标文件会被加入集合E(代表目标文件所需文件)，使用到但是未定义的符号放入集合U，前面输入文件中已定义的符号放入集合D
    - 对于静态库，尝试对集合U中的符号在库成员列表中寻找符号的定义，如果有成员m匹配符号成功，就将m加入到集合E，将U中的符号移至集合D。
    - 最后链接器发现集合U非空，就会产生undefined
    - \>>> 由此可知，使用链接器时对库文件的使用要留意参数顺序

  #### 思考为什么要进行内存对齐(内存寻址的优化，高速缓存模型的优化)

  * 从内存中读取数据的效率角度

  - ```
        > 计算机一次性从chunk中读取8字节的数据,如果不进行内存对齐,就会导致前4个字节在第一个chunk,后四个字节在第二个chunk这样要通过2次读取,才能获取完全的数据
        > 如果8字节数据进行内存对齐,这样就仅通过一次获取就能得到完整的数据
    ```

  - * 从高速缓存块的角度

  - ```
        > 为了兼容CPU与内存在执行速度上的差异,现在的计算机系统采取了多级高速缓存的内存模型
        > 离CPU越近，容量越小,速度越快,造价越贵
        > 数据按块存储在存储器中,数据块按照首地址取模运算存储在存储器中
    
        > 假设l3高速缓存的数据块大小为512bytes，共4个数据块 int x ,int y通过计算后分别存储在数据块1和数据块5中,且x,y是会被频繁使用到的数据
        > 根据时间局部性远离,int x,int y所处的数据块应长期驻留在高速缓存中。但是由于哈希取模之后，数据块1和数据块5频繁被互相置换
    ```
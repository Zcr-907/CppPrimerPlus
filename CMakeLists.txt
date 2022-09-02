# 指定最小 CMAKE 版本要求
cmake_minimum_required(VERSION 3.21)

# 设置项目名称,和所使用的语言
project(CppPrimerPlus C CXX)

# 设置变量: 使用c11标准来编译cpp
set(CMAKE_CXX_STANDARD 11)

# 设置变量: 变量名custom,变量值var1 var2 ==> 类比Makefile
set(custom var1 var2)

# 向终端输出用户自定义的信息
# STATUS: 前缀为"-"
# SEND_ERROR: 产生错误,生成过程被跳过
# FATAL_ERROR: 立即终止所有cmake过程
MESSAGE(STATUS "This is BINARY dir " ${CppPrimerPlus_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir " ${CppPrimerPlusSOURCE_DIR})

# 生成可执行文件: 可执行文件名=CppPrimerPlus,依赖文件为main.cpp
add_executable(CppPrimerPlus main.cpp)

#[[
    添加可执行文件 target, 类似与原来Makefile的:
-------------------- C Version --------------------
        main            : main.o dependency.o
        main.o          : main.c main.h
        dependency.o    : dependency.c dependency.h
--------------- C Plus Plus Version ---------------
        Chapter2            : chapter_2/Chapter2.obj chapter_2/S01_BitOffset.obj
        Chapter2.obj        : chapter_2/Chapter2.cpp
        S01_BitOffset.obj   : chapter_2/S01_BitOffset.cpp
    CMake会自动找到依赖的头文锦啊,因此不需要特别指定,
    当头文件修改的时候,会自动重新编译依赖它的目标文件

#]]
add_executable(Chapter2 chapter_2/Chapter2.cpp chapter_2/S01_BitOffset.cpp)
#[[
使用如下命令构建本项目:
    cmake -B build      # 生成构建目录
    cmake --build build # 执行构建
    ./build/Chapter2    # 运行Chapter2程序
#]]


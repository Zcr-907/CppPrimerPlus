# 指定最小 CMAKE 版本要求
cmake_minimum_required(VERSION 3.21)

# 设置项目名称
project(CppPrimerPlus)

set(CMAKE_CXX_STANDARD 11)
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


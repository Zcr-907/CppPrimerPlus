# 指定最小 CMAKE 版本要求
cmake_minimum_required(VERSION 3.21)

# 设置项目名称,和所使用的语言
project(CPP_DEV C CXX)

# 设置变量: 使用c11标准来编译cpp
set(CMAKE_CXX_STANDARD 11)

# 生成可执行文件: 可执行文件名=main,依赖文件为main.cpp
add_executable(main main.cpp)

# 指定子模块,文件生成至build/csapp内
ADD_SUBDIRECTORY(csapp csapp)

# ==================================================================================================================
#[[
使用如下命令构建本项目:
    cmake -B build      # 生成构建目录
    cmake --build build # 执行构建
    ./build/Chapter2    # 运行Chapter2程序
#]]

## 设置变量: 变量名custom,变量值var1 var2 ==> 类比Makefile
#set(custom var1 var2)

## 向终端输出用户自定义的信息
## STATUS: 前缀为"-"
## SEND_ERROR: 产生错误,生成过程被跳过
## FATAL_ERROR: 立即终止所有cmake过程
#MESSAGE(STATUS "This is BINARY dir " ${CppPrimerPlus_BINARY_DIR})
#MESSAGE(STATUS "This is SOURCE dir " ${CppPrimerPlusSOURCE_DIR})


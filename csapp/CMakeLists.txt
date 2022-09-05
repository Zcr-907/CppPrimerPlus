# 构建可执行文件
ADD_EXECUTABLE(chapter02 ./chapter02/Chapter2.cpp ./chapter02/S01_BitOffset.cpp ./chapter02/S02_ShowBytes.cpp)
# 添加: 子目录
# 子目录 > ./lib
# 生成的文件放在build/bin: 后续在该目录下执行Makefile就会生成库
ADD_SUBDIRECTORY(./lib bin)
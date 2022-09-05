# 构建可执行文件
ADD_EXECUTABLE(chapter02 ./chapter02/Chapter2.cpp ./chapter02/S01_BitOffset.cpp ./chapter02/S02_ShowBytes.cpp)
# 构建lib模块
ADD_SUBDIRECTORY(./lib)
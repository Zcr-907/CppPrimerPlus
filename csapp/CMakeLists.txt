# 构建可执行文件
ADD_EXECUTABLE(chapter02 ./chapter02/Chapter2.cpp ./chapter02/S01_BitOffset.cpp ./chapter02/S02_ShowBytes.cpp)
ADD_EXECUTABLE(chapter03_exc ./chapter03/Chapter3.cpp)

# 添加: 子目录
ADD_SUBDIRECTORY(./lib bin)
# 表示在/usr/local/include/hello目录下去找头文件
INCLUDE_DIRECTORIES(/usr/local/include/hello)
# 链接动态库
TARGET_LINK_LIBRARIES(chapter03_exc /usr/local/lib/libprintHello.dylib)
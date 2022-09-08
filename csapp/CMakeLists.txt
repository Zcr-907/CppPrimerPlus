# 构建可执行文件: chapter02_exc > target
#               ./chapter02/Chapter2.cpp ./chapter02/S01_BitOffset.cpp ./chapter02/S02_ShowBytes.cpp > 构建目标依赖项
ADD_EXECUTABLE(chapter02_exc ./chapter02/Chapter2.cpp ./chapter02/S01_BitOffset.cpp ./chapter02/S02_ShowBytes.cpp)
ADD_EXECUTABLE(chapter03_exc ./chapter03/Chapter3.cpp)

# 设置子模块
ADD_SUBDIRECTORY(./lib libBin)

# 添加头文件搜索路径: 默认从后插入
INCLUDE_DIRECTORIES(/usr/local/include/hello)
INCLUDE_DIRECTORIES(/usr/local/include/ShowBytesByType)

# 设置要链接的库文件的名称: chapter02_exc > 使用库文件的目标程序
#                       /usr/local/lib/libShowBytesByType_Share.dylib > 库文件绝对路径
TARGET_LINK_LIBRARIES(chapter02_exc /usr/local/lib/libShowBytesByType_Share.dylib)
TARGET_LINK_LIBRARIES(chapter03_exc /usr/local/lib/libprintHello.dylib)
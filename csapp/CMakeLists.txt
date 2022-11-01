# 构建可执行文件: chapter02_exc > target
#               ./chapter02/Chapter2.cpp ./chapter02/S01_BitOffset.cpp ./chapter02/S02_ShowBytes.cpp > 构建目标依赖项
ADD_EXECUTABLE(csapp_02_01exc ./chapter02/Chapter2.cpp ./chapter02/S01_BitOffset.cpp ./chapter02/S02_ShowBytes.cpp)
ADD_EXECUTABLE(csapp_03_01exc ./chapter03/Chapter3.cpp ./chapter03/S03.cpp)
ADD_EXECUTABLE(csapp_07_01exc ./chapter07/chapter07_01.cpp chapter07/chapter07_02.cpp)
ADD_EXECUTABLE(csapp_08_Fork ./chapter08/Fork.cpp)
ADD_EXECUTABLE(csapp_08_Recycle ./chapter08/RecycleChildProcess.cpp)
ADD_EXECUTABLE(csapp_09_01exc ./chapter09/main.cpp)

ADD_EXECUTABLE(unit_exec ./unit/test.cpp)

# 设置子模块
ADD_SUBDIRECTORY(./lib libBin)

# 添加头文件搜索路径: 默认从后插入
INCLUDE_DIRECTORIES(/usr/local/include/hello)
INCLUDE_DIRECTORIES(/usr/local/include/ShowBytesByType)

# 设置要链接的库文件的名称: chapter02_exc > 使用库文件的目标程序
#                       /usr/local/lib/libShowBytesByType_Share.dylib > 库文件绝对路径
TARGET_LINK_LIBRARIES(csapp_02_01exc /usr/local/lib/libShowBytesByType_Share.dylib)
TARGET_LINK_LIBRARIES(csapp_03_01exc /usr/local/lib/libprintHello.dylib)
# 构建: lib
# printHello_static > 生成lib的名称
# SHARED > 共享库 , STATIC > 静态库
# Hello.cpp Hello.h > 生成该库所需要的文件
ADD_LIBRARY(printHello_static STATIC Hello.cpp Hello.h)
# printHello_static > 重命名为printHello
SET_TARGET_PROPERTIES(printHello_static PROPERTIES OUTPUT_NAME "printHello")
# cmake在构建一个新的target的时候,会尝试清理其他使用这个名字的库,在创建printHello.so时就会尝试清理掉在创建printHello.a
SET_TARGET_PROPERTIES(printHello_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

ADD_LIBRARY(printHello_share SHARED Hello.cpp Hello.h)
SET_TARGET_PROPERTIES(printHello_share PROPERTIES OUTPUT_NAME "printHello")
SET_TARGET_PROPERTIES(printHello_share PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# 安装头文件: 安装位置见上级模块
INSTALL(FILES Hello.h DESTINATION include/hello)
# 安装库文件: 安装位置见上级模块
INSTALL(TARGETS printHello_share printHello_static LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)

# ====================================================================================================================
# 生成库: ShowBytesByType_Share
ADD_LIBRARY(ShowBytesByType_Share SHARED ShowBytesByType.cpp ShowBytesByType.h)
INSTALL(FILES ShowBytesByType.h DESTINATION include/ShowBytesByType)
INSTALL(TARGETS ShowBytesByType_Share LIBRARY DESTINATION lib)


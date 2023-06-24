cmake_minimum_required(VERSION 3.8) #对版本的要求

#项目名称
project(ddmqtt)

#类似于 #define
set(DDMQTT_LIB_SRC
    util/common.cpp
    thirdlib/log/tlog.cpp
    thirdlib/md5/md5.c
    thirdlib/base64/encode.c
    thirdlib/base64/buffer.c)

set(CMAKE_BUILD_TYPE "Debug")

#增加宏
add_definitions(-D_GNU_SOURCE)

#将指定的目录添加到编译器的头文件搜索路径之下，指定的目录被解释成当前源码路径的相对路径
include_directories(${CMAKE_SOURCE_DIR} thirdlib/log thirdlib/md5 thirdlib/base64)

#根据指定的代码路径生成指定的库，默认为静态
#add a library to the project using the specified source files
#add_library(<name> [STATIC | SHARED | MODULE]
#            [EXCLUDE_FROM_ALL]
#           [<source>...])
add_library(mqtt ${DDMQTT_LIB_SRC})

#添加需要链接的库文件目录
#CMAKE_BINARY_DIR:生成树的最顶层目录。这个变量永远不会改变它的值。
#The path to the top level of the build tree.
#This is the full path to the top level of the current CMake build tree. 
#For an in-source build, this would be the same as CMAKE_SOURCE_DIR.
link_directories(${CMAKE_BINARY_DIR})

#添加需要链接的库文件路径，注意这里是全路径
link_libraries(mqtt pthread)

#用指定的源文件来生成目标可执行文件
add_executable(broker broker.cpp)
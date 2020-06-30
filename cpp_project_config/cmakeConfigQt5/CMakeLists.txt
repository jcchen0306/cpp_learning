#此配置适用于qt5，功能是同使用qt图形界面和cmake管理的opencv库
#需要设置qt5的Qt5Config.cmake的路径 ，和opencv的OpenCVConfig.cmake的路径

#设置cmake版本号
cmake_minimum_required(VERSION 3.4.0)
 
#设置工程名称
project(HelloOpenCV)
 
#设置工程包含当前目录，非必须
set(CMAKE_INCLUDE_CURRENT_DIR ON) 
 
#设置自动生成moc文件，设置使用ui和rcc文件一定要设置
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

#这两行是设置opencv库的安装路径和查找该库
set(OpenCV_DIR "/home/jiacai_chen/software/opencv/opencv_install/lib/cmake/opencv4")
find_package(OpenCV REQUIRED)

#设置Qt库的安装路径和查找该库，最好每一个用到的库都要写，Qt也会根据依赖关系自动添加
set(Qt_DIR "/home/jiacai_chen/software/Qt5.14.0/5.14.0/gcc_64/lib/cmake/Qt5")
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

#查找当前文件夹中的所有源代码文件，也可以通过Set命令将所有文件设置为一个变量
FILE(GLOB SRC_FILES "src/*.cpp") 
#同理，查找当前文件夹中所有的头文件，这一行一般可以通过 include_directories 来自动在头文件路径中去查找所需的头文件
#但是使用了qt特性Q_OBJECT的头文件，必须要单独寻找出来，然后添加到add_executable指令的文件列表后面。
#不然会出现 undefined reference to `vtable for MainWindow' 的错误
FILE(GLOB HEAD_FILES "./include/*.h") 

#同理，查找当前文件夹中所有的ui文件
#此处的设置用处感觉不大，在使用到ui文件生成的头文件ui_***.h的源文件中，
#   include头文件ui_***.h时，要以这源文件和ui文件的 相对路径去引用。
#例如： #include "../ui/ui_mainwindow.h"
#其中所引用的ui文件在源文件的 ../ui/ 目录下
FILE(GLOB UI_FILES "ui/*.ui") 

#在要调用ui文件生成的头文件 的源文件中，include 指向 ui文件相对当前原文件的相对路径，
#把 UI文件直接当成对应的ui_****.h头文件引用即可,
#可以不使用如下指令qt5_wrap_ui
#qt5_wrap_ui(UI_HEADERS ${UI_FILES})

#添加资源文件
set(RCC_FILES qrc/spreadsheet.qrc)

include_directories(include
                    ${OpenCV_INCLUDE_DIRS} )

#add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEAD_FILES} ${RCC_FILES} ${UI_FILES})
add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEAD_FILES} ${RCC_FILES})
 
#添加Qt5依赖项
target_link_libraries(${PROJECT_NAME} Qt5::Widgets 
                                      Qt5::Core 
                                      Qt5::Gui 
                                      ${OpenCV_LIBS}
                     )

#https://doc.qt.io/qt-5/cmake-get-started.html#build-a-gui-executable


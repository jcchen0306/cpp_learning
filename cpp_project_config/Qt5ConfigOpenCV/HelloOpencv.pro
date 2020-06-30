#如果出现了编译链接opencv成功，成功生成了二进制可执行程序，但是命令行或者qt里头运行时，载入库失败，
#则要在home下的.bashrc 中设置对应库的路径到环境变量 LD_LIBRARY_PATH
#例如：export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/lql/software/opencv_install/lib

#理论上，生成了二进制可执行程序，可以在命令行运行 ldd ./HelloOpenCV 来查看编译时候链接的库的路径和版本
#运行时，这些编译时被链接的库路径要在环境变量 LD_LIBRARY_PATH 里头。

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HelloOpenCV
TEMPLATE = app

#这是调用OpenCV的第一种依赖解决方案。
#这一种方案，方便通过文件来制定详细的配置，在不同的环境下或者release,debug中调用相应的库。
#可以通过这种自己定义一个头文件和库文件依赖的文件pri，包含到pro配置的项目中，然后设置相应的路径OpenCVPath，传递到pri文件中使用
OpenCVPath = /home/jiacai_chen/software/opencv/opencv_install
include(pri/opencv.pri)



#这是调用OpenCV的第二种依赖解决方案。
#这一种方案比较直接，直接制定了头文件路径和要连接的库文件路径。
#设置要包含的头文件路径
#INCLUDEPATH += /home/jiacai_chen/software/opencv/opencv_install/include/opencv4/opencv2 \
#                /home/jiacai_chen/software/opencv/opencv_install/include/opencv4/
#设置要链接的库
#LIBS += -L /home/jiacai_chen/software/opencv/opencv_install/lib/libopencv_*.so

message($${INCLUDEPATH})
message($${LIBS})


#如果用了弃用的api函数，编译器会报警。
DEFINES += QT_DEPRECATED_WARNINGS

#自己定义的头文件所在的文件夹路径，一定要加到INCLUDEPATH，不然会出现头文件找不到。
INCLUDEPATH += ./include

SOURCES += \
        src/main.cpp \
        src/mainwindow.cpp \
    src/graphicsview.cpp \
    src/imgfile.cpp

#这里的设置和上面INCLUDEPATH感觉上有重复，但是跟使用到了qt特性Q_OBJECT的头文件，必须加到下面的HEADERS属性中。
#未使用到qt特性Q_OBJECT的头文件，可以不加
HEADERS += \
#    include/graphicsview.h \
#   include/imgfile.h  \
    include/mainwindow.h

FORMS += \
        ui/mainwindow.ui

RESOURCES     = qrc/spreadsheet.qrc




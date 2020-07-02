#include <QApplication>    //所有用到qt图形界面的项目必须用到此头文件，
                           //QApplication提供图形界面，信号与槽相关的单线程自循环运行环境
#include <QHBoxLayout>     //QHBoxLayout，他可以将一系列控件加入其布局中，然后将整个布局应用到窗口中
#include <QSlider>        //QSlider是一个滑动条控件
#include <QSpinBox>      //spinbox就是一个可输入、课点击上下三角进行增减的框。

int main(int argc, char *argv[])   //argc 运行可执行程序时带的参数数目；
                                   //argv是运行可执行程序时带的参数的字符串数组的首地址，是一个2级指针。
{
    QApplication app(argc, argv);   //每一个qt图形界面程序必须申明一个QApplication类的对象
                                    //该对象提供图形界面，信号与槽相关的单线程自循环运行环境
                                    //当图形界面上指定的控件被鼠标操作，就会产生一个事件event,
                                    //释放一个信号signal，如果有一个函数操作slot，被关联到这个signal上面
                                    //那么signal被发出，slot就会被执行。把signal和slot关联起来是用connect函数
                                    //每个图形界面控件，被鼠标操作时都可以发出signa
                                    //slot对应的函数操作可以是任何一个用户定义的函数
                                    //QApplication类对象的方法exec()被调用时，一个确保信号与槽之间的联系，
                                    //能够被实时触发和响应的单线程自循环运行环境就建立好了。

    QWidget *window = new QWidget;      //申明一个QWidget类对象
                                        //new是在堆上面申明一个对象，长期有效，返回该对象的首地址
                                        //该地址只能用该类的指针变量接受
    window->setWindowTitle("cjc Enter Your Age");  //调用 QWidget类对象的方法setWindowTitle()函数来设置显示在窗口标题栏上的文字

    QSpinBox *spinBox = new QSpinBox;        //申明一个QSpinBox类对象
                                             //new是在堆上面申明一个对象，长期有效，返回该对象的首地址
                                              //该地址只能用该类的指针变量接受
    QSlider *slider = new QSlider(Qt::Horizontal);  //创建一个水平方向的 QSlider
    spinBox->setRange(0, 130);              //设置spinBox的值范围
    slider->setRange(0, 130);               //设置slider的值范围

    QObject::connect(spinBox, SIGNAL(valueChanged(int)),slider, SLOT(setValue(int))); //spinBox的值发生变化时，slider值也跟着变化
    QObject::connect(slider, SIGNAL(valueChanged(int)),spinBox, SLOT(setValue(int))); //slider的值发生变化时，spinBox值也跟着变化


    spinBox->setValue(35);   //设定spinBox的初始值

    QVBoxLayout *layout = new QVBoxLayout;  //创建一个垂直平布局 QVBoxLayout为垂直方向排列控件，从上到下。这个对象相当一个容器
    layout->addWidget(spinBox);      //将spinBox控件加入到layout对象中，
    layout->addWidget(slider);       //接着将slider控件加入到layout对象中
    window->setLayout(layout);    //设定部件window的布局为layout

    window->show();            //显示窗体

    return app.exec();       //QApplication类对象的方法exec()被调用时，一个确保信号与槽之间的联系，
                             //能够被实时触发和响应的单线程自循环运行环境就建立好了。
}

#include <QApplication>  //所有用到qt图形界面的项目必须用到此头文件
                         //QApplication提供图形界面，信号与槽相关的多线程运行环境
#include "finddialog.h"  //包含finddialog.h头文件

int main(int argc, char *argv[])   //argc 运行可执行程序时带的参数数目；
                                   //argv是运行可执行程序时带的参数的字符串数组的首地址，是一个2级指针。
{
    QApplication app(argc, argv);    //每一个qt图形界面程序必须申明一个QApplication类的对象
                                     //该对象提供图形界面，信号与槽相关的多线程运行环境
                                     //当图形界面上指定的控件被鼠标操作，就会产生一个事件event,
                                     //释放一个信号signal，如果有一个函数操作slot，被关联到这个signal上面
                                     //那么signal被发出，slot就会被执行。把signal和slot关联起来是用connect函数
                                     //每个图形界面控件，被鼠标操作时都可以发出signa
                                     //slot对应的函数操作可以是任何一个用户定义的函数
                                     //QApplication类对象的方法exec()被调用时，一个确保信号与槽之间的联系，
                                     //能够被实时触发和响应的多线程运行环境就建立好了。
    FindDialog *dialog = new FindDialog;  //申明一个FindDialog类对象
    dialog->show();          //调用 FindDialog类对象的方法show()显示该控件
    return app.exec();       //QApplication类对象的方法exec()被调用时，一个确保信号与槽之间的联系，
                             //能够被实时触发和响应的多线程运行环境就建立好了。
}

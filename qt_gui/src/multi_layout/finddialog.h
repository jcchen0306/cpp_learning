#ifndef FINDDIALOG_H  //避免多重包含
#define FINDDIALOG_H

#include <QDialog>   //QDialog继承了QWidget

class QCheckBox;   //前置声明，告诉编译器类的存在，使编译更快些
class QLabel;
class QLineEdit;
class QPushButton;

class FindDialog : public QDialog  //声明FindDIalog 并且把他作为QDialog的子类
{
    Q_OBJECT   //对于定义了信号槽的类，类定义开始必须写宏Q_OBJECT

public:
    FindDialog(QWidget *parent = 0);    //parent 参数指定其父窗口组件，默认值为０，也就是空指针，没有父对象

signals:   //用户单击find时发出的两个信号signal关键字实际上是一个宏
    void findNext(const QString &str, Qt::CaseSensitivity cs);     //当用户点击find按钮，发射findNext信号
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);  //当用户点击find按钮，如果前向查询选中，发射findPrevious信号

private slots:         //声明私有槽，与signals一样
    void findClicked();
    void enableFindButton(const QString &text);

private:
    QLabel *label;          //申明一些控件类的指针变量，可以在实现信号槽的时候更好的访问它们
    QLineEdit *lineEdit;
    QCheckBox *caseCheckBox;
    QCheckBox *backwardCheckBox;
    QPushButton *findButton;
    QPushButton *closeButton;
};

#endif

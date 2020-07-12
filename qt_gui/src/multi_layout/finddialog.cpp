#include <QtGui> //QtGui中包含着QtCore和QtGui模块的所有类的定义，包含这个头文件就不用逐个包含所有类了

#include "finddialog.h"   //声明用于对话框实验的Qt类

FindDialog::FindDialog(QWidget *parent)   //将parent参数传递给父类的构造函数
    : QDialog(parent)
{
    label = new QLabel(tr("Find &what:"));  //tr()函数是把他们翻译成其他语言的标记
                                            //&表示快捷键，即"Alt + w"
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);           //设置了行编辑器作为标签的伙伴（buddy）
                                         //所谓“buddy”是指一个窗口部件，它可以在按下标签的快捷键时接受焦点（focus）
    caseCheckBox = new QCheckBox(tr("Match &case"));
    backwardCheckBox = new QCheckBox(tr("Search &backward"));

    findButton = new QPushButton(tr("&Find"));
    findButton->setDefault(true);   //setDefault（）让Find按钮成为对话框的默认按钮（default button）
                                    //default button 就是指当用户按下Enter健时能够按下对应的按钮
    findButton->setEnabled(false);   //默认禁止，显示灰色

    closeButton = new QPushButton(tr("Close"));

    connect(lineEdit, SIGNAL(textChanged(const QString &)), //当lineEdit(文本框)内容发生改变时，
            this, SLOT(enableFindButton(const QString &))); //私有槽enableFindButton(const QString &)会被调用
    connect(findButton, SIGNAL(clicked()),   //当findButton被点击，
            this, SLOT(findClicked()));      //私有槽findClicked()会被调用
    connect(closeButton, SIGNAL(clicked()),  //当closeButton被点击，
            this, SLOT(close()));            //对话框关闭，槽close()继承自QWidget，默认的功能是将控件隐藏(并非删除)

    QHBoxLayout *topLeftLayout = new QHBoxLayout;  //创建布局管理器，QHBoxLayout为横向，
    topLeftLayout->addWidget(label);     //给布局管理器添加控件
    topLeftLayout->addWidget(lineEdit);  //给布局管理器添加控件

    QVBoxLayout *leftLayout = new QVBoxLayout;  //创建布局管理器，QVBoxLayout为纵向
    leftLayout->addLayout(topLeftLayout);       //给布局管理器添加控件
    leftLayout->addWidget(caseCheckBox);        //给布局管理器添加控件
    leftLayout->addWidget(backwardCheckBox);    //给布局管理器添加控件

    QVBoxLayout *rightLayout = new QVBoxLayout;  //创建布局管理器，QVBoxLayout为纵向
    rightLayout->addWidget(findButton);          //给布局管理器添加控件
    rightLayout->addWidget(closeButton);         //给布局管理器添加控件
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout;   //创建布局管理器，QHBoxLayout为横向，
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);    //设置对话框的主布局

    setWindowTitle(tr("Find"));   //设置对话框标题
    setFixedHeight(sizeHint().height());  //设置对话框的大小，sizeHint()返回对话框的理想尺寸
}

void FindDialog::findClicked()   //当用户点击Find按钮，findClicked()槽被调用
{
    QString text = lineEdit->text();
    Qt::CaseSensitivity cs =
            caseCheckBox->isChecked() ? Qt::CaseSensitive  //CaseSensitivity枚举类型，如果caseCheckBox被选择，cs为CaseSensitive(1)
                                      : Qt::CaseInsensitive;  //否则为CaseInsensitive(0)
    if (backwardCheckBox->isChecked())  //发射findPrevious()或findNext()信号，emit关键字会被转成标准c++
    {
        emit findPrevious(text, cs);   //如果前向选择按钮被选中，则发射findPrevious()信号,否则发射另一个信号
    } else {
        emit findNext(text, cs);
    }
}

void FindDialog::enableFindButton(const QString &text)  //当文本框内容改变时，enableFindButton槽被调用
{
    findButton->setEnabled(!text.isEmpty());    //如果文本框非空，则findButton可用
}

# qt gui(图形用户界面）demo collection
1. helloQt:用qt显示一个标签(QLabel)类对象
2. button_connect_application:将button被点击的信号，connect连接到application的quit操作。
3. QWidget_QLayout:将2个控件装到一个布局对象QLayout中，然后将这个布局对象QLayout设置到一个窗口对象QWidget的显示内容上，这样就可以显示多个控件。
   带参数的connect，spinBox的值改变的时候，发射一个信号（包含值改变的信息和值是多少的信息），这些信息发送到slider,slider将值设置为接受到的这个值。
4. multi_layout: 用代码通过layout来嵌套布局。
5. ui_layout: 用qt creator的ui设计工具，来通过用鼠标拖动控件和布局设计界面。
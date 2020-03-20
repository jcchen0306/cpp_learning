class: 类型声明关键字，用来声明自定义的类，和struct差不多
class 里的变量：叫属性或者成员变量
class 里的函数：叫方法或者成员函数

自定义类范例：
头文件：
class myList
{

public:
    struct studentNode* head;
    int nodeNum;

    myList();   //构造函数,定义该类的对象的时候，自动调用。
    ~myList();  //析构函数，该类对象消失的时候，自动调用。
    void List_initialize(int num);//初始化一个链表
    void Add_list_back(int num,int startId);//给定一个链表的头节点指针，在该链表末端再加num个节点，id从startId开始
    void Delete_one_node(int idToDelete);//删除链表中的特定id的节点
    void Insert_one_node(int PositionToInsert,int InsertId); //再某个节点后面插入一个节点,
    void Print_all_node();//打印链表所有节点的id
    void inverseList();//反转链表
    void Delete_all_node();//删除所有节点
};

实现文件：
myList::myList()
{
    //函数实现
}

myList::~myList()
{
    //函数实现
}

void myList::List_initialize(int num)
{
    //函数实现
}

和c的区别：
(1) class 代替了 struct
(2) class 声明类内部的成员变量和成员函数时，要加上 public: (以后还有proteced和private)
(3) 成员函数在类的声明外实现的时候， 函数名前加上 类名:: , 例如 void myList::List_initialize(int num)，这个东西叫名空间。 在类声明里头的函数不加名空间，在类声明外头的函数要叫所属类的名空间。
(4) 类的声明里头的成员函数多了 构造函数 和 析构函数
(5) 构造函数可以随便自定义，不需要返回类型关键字。一般用来对类的成员变量成型初始化，在用类名声明一个 对象（类声明的变量)时自动调用。
(6) 析构函数可以随便自定义，不需要返回类型关键字。一般用来对类中成员函数malloc申请的内存进行释放清理，在一个 对象 生命周期结束，或者出了该对象的作用域时，自动调用。
(7)  class myList;                            myList      s;   //直接用自定义的class类型 声明的对象，在栈上面，相当于一个局部变量
       |         \                               |         \
   类声明关键字   |                      自定义的class类型   |
             自定义的class类型                    自定义的class类型声明的对象(变量)
(8) 类的new， delete，相当于c语言的malloc，和free。用法一般是先声明一个类指针，然后new一个类对象，new默认返回对象首地址。new出来的对象在堆(heap)上面，作用域是无限，声明周期直至delete。
    myList*  objectPointer;              //声明一个自定义类的指针变量
    objectPointer = new myList();        //new相当于malloc，在堆申请了一个对象的内存，返回了一个对象的首地址，必须用一个指针变量接收。new的时候默认调用了构造函数。
    delete objectPointer;                //new相当于free，后面接指针(指向一个对象的地址),delete时自动调用析构函数。
(9)类的高级操作：模板类，继承，多态（纯虚函数），重载。

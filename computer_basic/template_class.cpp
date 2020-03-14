//模板类的声明和实现在同一个文件，list.h

struct student   //申明结构体类型
{
    int studentId;
    char name[20];
    int gender;
    int gradeID;
    int classID;
    int age;
};

struct animal
{
    int age;
    int gender;
    int weight;
    int category;
};

struct myListNode      //申明结构体类型
{
    struct student oneStudent;       //模板类时，此处的节点结构体就可以作为模板参数，随便自定义，而不用改此处的源码
    //struct animal ani;
    int id;

    struct myListNode* next;
    struct myListNode* previous;
};




template<class T>     //先申明一个带类型模板参数的结构体
struct myListNode
{
    T value;
    int id;
    struct myListNode* next;
};


template<class T>         //再声明一个带类型模板参数的类
class myList
{
public:
    struct myListNode<T>* head;          //此处的T，用上面声明类时的模板参数，在实例化是接收到的类型，进行替代，得到一个具体的类型。

    myList();
    ~myList();
    void List_initialize(int num);
    void Add_list_back(int num,int startId);
    void Delete_one_node(int idToDelete);
    void Insert_one_node(int PositionToInsert,int InsertId);
    void Print_all_node();
    void inverseList();
    void Delete_all_node();
};

//实例化时，模板类的各个方法中的T的具体类型，来自class声明时的T形参接收的值
//模板class的声明 和 它的方法要在同一个文件中，例如都在同一个文件中。  这一点非常重要。
//这是因为模板类的方法，在模板类型参数未知时，不能编译
template<class T>              
myList<T>::myList()                     //此处的T，用上面声明类时的模板参数，在实例化是接收到的类型，进行替代，得到一个具体的类型。
{
    printf("helloworld");
}


template<class T>
myList<T>::~myList()                   //此处的T，用上面声明类时的模板参数，在实例化是接收到的类型，进行替代，得到一个具体的类型。
{
    printf("helloworld");
}

template<class T>
void myList<T>::List_initialize(int num)              //此处的T，用上面声明类时的模板参数，在实例化是接收到的类型，进行替代，得到一个具体的类型。
{

    struct myListNode<T>* p;                          //此处的T，用上面声明类时的模板参数，在实例化是接收到的类型，进行替代，得到一个具体的类型。
    head=(struct myListNode<T>*) malloc(sizeof(struct myListNode<T>));          //此处的T，用上面声明类时的模板参数，在实例化是接收到的类型，进行替代，得到一个具体的类型。
    p=head;
    p->id=0;
    for(int i=1;i<num;i++)
    {
        p->next=(struct myListNode<T>*) malloc(sizeof(struct myListNode<T>));    //此处的T，用上面声明类时的模板参数，在实例化是接收到的类型，进行替代，得到一个具体的类型。
        p->next->id=i;
        p=p->next;
    }
    p->next=0;
}


//测试main函数在另外一个独立的test.cpp文件
#include"list.h"
int main()
{
    myList<int> s;
    myList<struct animal> ss;     //使用了模板类，就可以不同内容的链表，主要的方法代码，最大限度的重用。
    myList<struct student> sss; 
    s.List_initialize(10);
    ss.List_initialize(10);
    sss.List_initialize(10);
    
    s.head->value=1;
    ss.head->value.category=0;
    sss.head->value.studentId=10;
}


//总结：
//模板类在编译之前进行推演，要把所有的模板参数都推演确定成具体的类型值，才能确定所需内存。
//模板按照最顶层的声明和模板参数，一步步的往定义内部推演。
//所有模板相关的类，函数，结构体，在使用的时候，都要带上   名称<模板参数值(一个具体的类型)>

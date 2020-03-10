#include"list.h"
//初始化链表，根据给定参数，建立一定数量的节点数
struct studentNode* List_initialize(int num)
{
    struct studentNode* head;
    struct studentNode* p;
    head=(struct studentNode*) malloc(sizeof(struct studentNode));
    head->oneStudent.id=0;
    p=head;
    for(int i=1;i<num;i++)
    {
        p->next=(struct studentNode*) malloc(sizeof(struct studentNode));
        p->next->oneStudent.id=i;
        p=p->next;
    }
    p->next=0;
    return head;
}
//给定一个链表的头节点指针，在该链表末端再加num个节点，id从startId开始
void Add_list_back(struct studentNode* head,int num,int startId)
{
    struct studentNode* p;
    p=head;
    for(;p->next!=0;p=p->next);//循环到末端p
    for(int i=0;i<num;i++)
    {
        p->next=(struct studentNode*) malloc(sizeof(struct studentNode));
        p->next->oneStudent.id=startId+i;
        p=p->next;
    }
    p->next=0;
}
//删除链表中的特定id的节点
void Delete_one_node(struct studentNode* head,int idToDelete)
{
    struct studentNode* p;
    struct studentNode* temp;
    p=head;
    for(;p!=0;p=p->next)
    {
        if(p->next->oneStudent.id==idToDelete)
        {
            temp=p->next;
            p->next=p->next->next;
            free(temp);
            break;
        }
    }
}

//再某个节点后面插入一个节点,
void Insert_one_node(struct studentNode* head,int PositionToInsert,int InsertId)
{
    struct studentNode* p;
    p=head;
    for (; p!=0; p=p->next)
    {
        if(p->oneStudent.id==PositionToInsert)
        {
            struct studentNode* temp;
            temp = p->next;
            p->next = (struct studentNode*) malloc(sizeof(struct studentNode));
            p->next->oneStudent.id=InsertId;
            p->next->next=temp;
            break;
        }
    }
}
//打印链表所有节点的id
void Print_all_node(struct studentNode* head)
{
    struct studentNode* p;
    p=head;
    for(;p!=0;p=p->next)
    {
        printf("print_node %d\n",p->oneStudent.id);
    }
}
//反转链表
void inverseList(struct studentNode** head)
{
    struct studentNode* p;
    struct studentNode* p1;
    int headflag;
    headflag=1;
    p=(*head)->next;
    p1=(*head)->next->next;
    for(;p!=0;)
    {
        if(headflag)
        {
            (*head)->next=0;
            headflag=0;
        }
        p->next=(*head);
        (*head)=p;
        p=p1;
        if(p1!=0)
        {
            p1=p1->next;
        }
    }
}
//删除所有节点
void Delete_all_node(struct studentNode** head)
{
    struct studentNode* p;
    struct studentNode* temp;
    p=(*head);
    for(;p!=0;)
    {
        printf("Delete node %d\n",p->oneStudent.id);
        temp=p;
        p=p->next;
        free(temp);
    }
    (*head)=0;
}




//以下是C++的代码
//初始化链表，根据给定参数，建立一定数量的节点数
void myList::List_initialize(int num)
{
    struct studentNode* p;

    if(head!=0)
    {
        Delete_all_node();
    }
    head=(struct studentNode*) malloc(sizeof(struct studentNode));
    head->oneStudent.id=0;
    p=head;
    for(int i=1;i<num;i++)
    {
        p->next=(struct studentNode*) malloc(sizeof(struct studentNode));
        p->next->oneStudent.id=i;
        p=p->next;
    }
    p->next=0;
}
//给定一个链表的头节点指针，在该链表末端再加num个节点，id从startId开始
void myList::Add_list_back(int num,int startId)
{
    struct studentNode* p;
    p=head;
    for(;p->next!=0;p=p->next);//循环到末端p
    for(int i=0;i<num;i++)
    {
        p->next=(struct studentNode*) malloc(sizeof(struct studentNode));
        p->next->oneStudent.id=startId+i;
        p=p->next;
    }
    p->next=0;
}
//删除链表中的特定id的节点
void myList::Delete_one_node(int idToDelete)
{
    struct studentNode* p;
    struct studentNode* temp;
    p=head;
    for(;p!=0;p=p->next)
    {
        if(p->next->oneStudent.id==idToDelete)
        {
            temp=p->next;
            p->next=p->next->next;
            free(temp);
            break;
        }
    }
}

//再某个节点后面插入一个节点,
void myList::Insert_one_node(int PositionToInsert,int InsertId)
{
    struct studentNode* p;
    p=head;
    for (; p!=0; p=p->next)
    {
        if(p->oneStudent.id==PositionToInsert)
        {
            struct studentNode* temp;
            temp = p->next;
            p->next = (struct studentNode*) malloc(sizeof(struct studentNode));
            p->next->oneStudent.id=InsertId;
            p->next->next=temp;
            break;
        }
    }
}
//打印链表所有节点的id
void myList::Print_all_node()
{
    struct studentNode* p;
    p=head;
    for(;p!=0;p=p->next)
    {
        printf("print_node %d\n",p->oneStudent.id);
    }
}
//反转链表
void myList::inverseList()
{
    struct studentNode* p;
    struct studentNode* p1;
    int headflag;
    headflag=1;
    p=head->next;
    p1=head->next->next;
    for(;p!=0;)
    {
        if(headflag)
        {
            head->next=0;
            headflag=0;
        }
        p->next=head;
        head=p;
        p=p1;
        if(p1!=0)
        {
            p1=p1->next;
        }
    }
}
//删除所有节点
void myList::Delete_all_node()
{
    struct studentNode* p;
    struct studentNode* temp;
    p=head;
    for(;p!=0;)
    {
        printf("Delete node %d\n",p->oneStudent.id);
        temp=p;
        p=p->next;
        free(temp);
    }
    head=0;
}

myList::myList()
{
    head=0;
    List_initialize(10);
    Print_all_node();
    printf("the object of myList is constructed\n");
}

myList::~myList()
{
    if(head!=0)
    {
        Delete_all_node();
    }
    printf("the object of myList is all deleted\n");
}

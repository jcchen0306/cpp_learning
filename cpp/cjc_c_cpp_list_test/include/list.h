#pragma once
#include<stdlib.h>
#include<stdio.h>

struct student   //申明结构体类型
{
    int id;
    char name[20];
    int gender;
    int gradeID;
    int classID;
    int age;
};

struct studentNode      //申明结构体类型
{
    struct student oneStudent;
    struct studentNode* next;
    struct studentNode* previous;
};

//初始化链表，根据给定参数，建立一定数量的节点数
struct studentNode* List_initialize(int num);

//给定一个链表的头节点指针，在该链表末端再加num个节点，id从startId开始
void Add_list_back(struct studentNode* head,int num,int startId);

//删除链表中的特定id的节点
void Delete_one_node(struct studentNode* head,int idToDelete);

//再某个节点后面插入一个节点,
void Insert_one_node(struct studentNode* head,int PositionToInsert,int InsertId);

//打印链表所有节点的id
void Print_all_node(struct studentNode* head);

//反转链表
void inverseList(struct studentNode** head);


//删除所有节点
void Delete_all_node(struct studentNode** head);



//c++版本
class myList
{

    struct studentNode* head;

public:
    myList();   //构造函数,定义该类的对象的时候，自动调用。
    ~myList();  //析构函数，该类对象消失的时候，自动调用。
    //初始化一个链表
    void List_initialize(int num);

    //给定一个链表的头节点指针，在该链表末端再加num个节点，id从startId开始
    void Add_list_back(int num,int startId);

    //删除链表中的特定id的节点
    void Delete_one_node(int idToDelete);

    //再某个节点后面插入一个节点,
    void Insert_one_node(int PositionToInsert,int InsertId);

    //打印链表所有节点的id
    void Print_all_node();

    //反转链表
    void inverseList();

    //删除所有节点
    void Delete_all_node();
};

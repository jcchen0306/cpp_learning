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




//以下是C++的面向对象思想及编程实现
//主要特点就是struct里头加了函数，用来表示行为。
//class 叫类，类的一个具体放到内存中的实体，叫对象
class myList
{
public:
    struct studentNode* head;
    int nodeNum;

    void List_initialize(int num);
    void Add_list_back(int num,int startId);
    void Delete_one_node(int idToDelete);
    void Insert_one_node(int PositionToInsert,int InsertId);
    void Print_all_node();
    void Delete_all_node();

    myList();
    ~myList();
};

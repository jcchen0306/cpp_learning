#pragma once
#include<stdlib.h>
#include<stdio.h>

struct student   //�����ṹ������
{
    int id;
    char name[20];
    int gender;
    int gradeID;
    int classID;
    int age;
};

struct studentNode      //�����ṹ������
{
    struct student oneStudent;
    struct studentNode* next;
    struct studentNode* previous;
};

//��ʼ���������ݸ�������������һ�������Ľڵ���
struct studentNode* List_initialize(int num);

//����һ�������ͷ�ڵ�ָ�룬�ڸ�����ĩ���ټ�num���ڵ㣬id��startId��ʼ
void Add_list_back(struct studentNode* head,int num,int startId);

//ɾ�������е��ض�id�Ľڵ�
void Delete_one_node(struct studentNode* head,int idToDelete);

//��ĳ���ڵ�������һ���ڵ�,
void Insert_one_node(struct studentNode* head,int PositionToInsert,int InsertId);

//��ӡ�������нڵ��id
void Print_all_node(struct studentNode* head);

//��ת����
void inverseList(struct studentNode** head);

//ɾ�����нڵ�
void Delete_all_node(struct studentNode** head);




//������C++���������˼�뼰���ʵ��
//��Ҫ�ص����struct��ͷ���˺�����������ʾ��Ϊ��
//class ���࣬���һ������ŵ��ڴ��е�ʵ�壬�ж���
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

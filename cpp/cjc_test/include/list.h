#include<stdlib.h>
#include<stdio.h>
struct student
{
    int id;
    int classID;
    int age;
};
struct teacher
{
    int name;
    int subject;
    int age;
};
struct studentNode
{
    struct student oneStudent;
    struct teacher oneTeacher;
    struct studentNode* next;
};
struct studentNode* list_initialize(int num);
void add_list_back(struct studentNode* head , int num ,int startId);
void delete_one_node(struct studentNode* head,int idToDelete);
void insert_one_node(struct studentNode* head,int PositionToInsert,int insertID);
void print_all_node(struct studentNode* head);
void delete_all_node(struct studentNode** head_p);

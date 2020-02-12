#include"list.h"
//初始化链表，根据给定参数，建立一定数量的节点数
struct studentNode* list_initialize(int num)
{
    struct studentNode* head;
    struct studentNode* p;
    head = (struct studentNode*) malloc(sizeof(struct studentNode));
    head->oneStudent.id=0;
    p=head;
    //这是是先生成一串节点
    for(int i=1;i<num;i++)
    {
        p->next=(struct studentNode*) malloc(sizeof(struct studentNode));
        p=p->next;
        p->oneStudent.id=i;
    }
    p->next=0;
    return head;

}
 //给定一个链表的头节点指针，在该链表末端再加num个节点，id从startId开始
void add_list_back(struct studentNode* head , int num ,int startId)
{
    struct studentNode* p;
    p=head;
    for(;p->next!=0;p=p->next);
    for(int i=0;i<num;i++)
    {
        p->next=(struct studentNode*) malloc(sizeof(struct studentNode));
        p=p->next;
        p->oneStudent.id=i+startId;
    }
    p->next=0;
}
//删除链表中的特定id的节点
void delete_one_node(struct studentNode* head,int idToDelete)
{
     struct studentNode* p;
     p= head;
     for(;p!=0;p=p->next)
     {
         if(p->next->oneStudent.id==idToDelete)
         {
             struct studentNode* temp;
             temp=p->next;
             p->next=p->next->next;
             free(temp);
             break;
         }
     }

}
//再某个节点后面插入一个节点,
void insert_one_node(struct studentNode* head,int PositionToInsert,int insertID)
{
    struct studentNode* p;
    p=head;
    for(;p!=0;p=p->next)
    {
        if(p->oneStudent.id==PositionToInsert)
        {
            struct studentNode* temp;
            temp=p->next;
            p->next=(struct studentNode*) malloc(sizeof(struct studentNode));
            p->next->oneStudent.id=insertID;
            p->next->next=temp;
            break;
        }

    }
}

//打印链表所有节点的id
void print_all_node(struct studentNode* head)
{
    struct studentNode* p;
    p=head;
    for(;p!=0;p=p->next)
    {
        printf("this node is %d\n",p->oneStudent.id);
    }
}
//删除所有节点
void delete_all_node(struct studentNode** head_p)
{
    struct studentNode *p;
    p=* head_p;
    for(;p!=0;)
    {
        printf("delete node is %d\n",p->oneStudent.id);
        p=p->next;
        free(*head_p);
        *head_p=p;
    }
}

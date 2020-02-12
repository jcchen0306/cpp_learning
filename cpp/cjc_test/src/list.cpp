#include"list.h"
//��ʼ���������ݸ�������������һ�������Ľڵ���
struct studentNode* list_initialize(int num)
{
    struct studentNode* head;
    struct studentNode* p;
    head = (struct studentNode*) malloc(sizeof(struct studentNode));
    head->oneStudent.id=0;
    p=head;
    //������������һ���ڵ�
    for(int i=1;i<num;i++)
    {
        p->next=(struct studentNode*) malloc(sizeof(struct studentNode));
        p=p->next;
        p->oneStudent.id=i;
    }
    p->next=0;
    return head;

}
 //����һ�������ͷ�ڵ�ָ�룬�ڸ�����ĩ���ټ�num���ڵ㣬id��startId��ʼ
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
//ɾ�������е��ض�id�Ľڵ�
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
//��ĳ���ڵ�������һ���ڵ�,
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

//��ӡ�������нڵ��id
void print_all_node(struct studentNode* head)
{
    struct studentNode* p;
    p=head;
    for(;p!=0;p=p->next)
    {
        printf("this node is %d\n",p->oneStudent.id);
    }
}
//ɾ�����нڵ�
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

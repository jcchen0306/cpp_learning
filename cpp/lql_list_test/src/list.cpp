#include"list.h"

//��ʼ���������ݸ�������������һ�������Ľڵ���
struct studentNode* List_initialize(int num)
{
    struct studentNode* head;
    struct studentNode* p;
    head = (struct studentNode*) malloc(sizeof(struct studentNode));       //�����ڴ�
    head->oneStudent.id = 0;

    p = head;
    //������������һ���ڵ�
    for (int i = 1; i < num; i++)
    {
        p->next = (struct studentNode*) malloc(sizeof(struct studentNode));
        p = p->next;
        p->oneStudent.id = i;
    }
    p->next=0;
    return head;
}

//����һ�������ͷ�ڵ�ָ�룬�ڸ�����ĩ���ټ�num���ڵ㣬id��startId��ʼ
void Add_list_back(struct studentNode* head,int num,int startId)
{
    struct studentNode* p;
    p=head;
    for(;p->next!=0;p=p->next);
    for (int i = 0; i < num; i++)
    {
        p->next = (struct studentNode*) malloc(sizeof(struct studentNode));
        p = p->next;
        p->oneStudent.id = i+startId;
    }
    p->next=0;
}

//ɾ�������е��ض�id�Ľڵ�
void Delete_one_node(struct studentNode* head,int idToDelete)
{
    struct studentNode* p;
    p = head;
    for (; p!= 0; p = p->next)
    {
        if(p->next->oneStudent.id==idToDelete)
        {
            struct studentNode* temp;
            temp = p->next;
            p->next=p->next->next;
            free(temp);
            break;
        }
    }
}

//��ĳ���ڵ�������һ���ڵ�,
void Insert_one_node(struct studentNode* head,int PositionToInsert,int InsertId)
{
    struct studentNode* p;
    p = head;
    for (; p!= 0; p = p->next)
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

//��ӡ�������нڵ��id
void Print_all_node(struct studentNode* head)
{
    struct studentNode* p;
    p = head;
    for (; p!= 0; p = p->next)
    {
        printf("new id of this node is %d\n", p->oneStudent.id);
    }
}

void inverseList(struct studentNode** head)
{
    struct studentNode* p1;
    struct studentNode* p2;
    int headFlag = 1;

    p1=(*head)->next;
    p2=(*head)->next->next;
    for(;p1!=0;)
    {
        if(headFlag)
        {
            headFlag=0;
            (*head)->next=0;
        }
        p1->next=(*head);

        (*head) =p1;
        p1 =p2;
        if(p2!=0)
            p2=p2->next;
    }
}

//ɾ�����нڵ�
void Delete_all_node(struct studentNode** head_p)
{
    struct studentNode* p;
    p = *head_p;
    for (; p!= 0;)
    {
        printf("delete node %d\n", (*head_p)->oneStudent.id);
        p=p->next;
        free(*head_p);
        *head_p=p;
    }
}


//������C++����ķ�����ʵ��
void myList::List_initialize(int num)
{
    struct studentNode* p;
    head = (struct studentNode*) malloc(sizeof(struct studentNode));
    nodeNum++;
    head->oneStudent.id = 0;

    p = head;
    for (int i = 1; i < num; i++)
    {
        p->next = (struct studentNode*) malloc(sizeof(struct studentNode));
        nodeNum++;
        p = p->next;
        p->oneStudent.id = i;
    }
    p->next=0;
}

void myList::Add_list_back(int num, int startId)
{
    struct studentNode* p;
    p=head;
    for(;p->next!=0;p=p->next);
    for (int i = 0; i < num; i++)
    {
        p->next = (struct studentNode*) malloc(sizeof(struct studentNode));
        nodeNum++;
        p = p->next;
        p->oneStudent.id = i+startId;
    }
    p->next=0;
}

void myList::Delete_one_node(int idToDelete)
{
    struct studentNode* p;
    p = head;
    for (; p!= 0; p = p->next)
    {
        if(p->next->oneStudent.id==idToDelete)
        {
            struct studentNode* temp;
            temp = p->next;
            p->next=p->next->next;
            free(temp);
            nodeNum--;
            break;
        }
    }
}

void myList::Insert_one_node(int PositionToInsert, int InsertId)
{
    struct studentNode* p;
    p = head;
    for (; p!= 0; p = p->next)
    {
        if(p->oneStudent.id==PositionToInsert)
        {
            struct studentNode* temp;
            temp = p->next;
            p->next = (struct studentNode*) malloc(sizeof(struct studentNode));
            nodeNum++;
            p->next->oneStudent.id=InsertId;
            p->next->next=temp;
            break;
        }
    }
}

void myList::Print_all_node()
{
    struct studentNode* p;
    p = head;
    for (; p!= 0; p = p->next)
    {
        printf("new id of this node is %d\n", p->oneStudent.id);
    }
}

void myList::Delete_all_node()
{
    struct studentNode* p;
    p = head;
    for (; p!= 0;)
    {
        printf("delete node %d\n", head->oneStudent.id);
        p=p->next;
        free(head);
        nodeNum--;
        head=p;
    }
}

myList::myList()
{
    head=0;
    nodeNum=0;
}

myList::~myList()
{
    if(head!=0)
    {
        Delete_all_node();
        nodeNum=0;
    }
}

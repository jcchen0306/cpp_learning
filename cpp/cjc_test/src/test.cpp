#include"list.h"
int main()
{
    struct studentNode* head;
    head=list_initialize(10);
    printf("the head address is %p\n",head);
    print_all_node(head);
    delete_one_node(head,3);
    printf("head address is %p\n",head);
    print_all_node(head);
    insert_one_node(head,2,9999);
    printf("head address is %p\n",head);
    print_all_node(head);
    add_list_back(head,20,1000);
    printf("head address is %p\n",head);
    print_all_node(head);
    printf("head address is %p\n",head);
    delete_all_node(&head);
    printf("head address is %p\n",head);
}

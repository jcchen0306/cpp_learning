#include"list.h"
int main()
{
    //c的函数式调用方法，结果变量要保存在函数外

    struct studentNode* head; //定义二个指针变量
    int num=0;
    head = List_initialize(100);
    num=num+100;
    Print_all_node(head);
    Delete_one_node(head,55);

    Print_all_node(head);
    Insert_one_node(head,54,6666);
    Print_all_node(head);

    Delete_all_node(&head);



    //C++对象的属性和行为调用方法
    //面向对象编程
   /* myList list[10];
    list[0].List_initialize(20);
    list[0].Print_all_node();
    printf("number of the node is :%d \n\n",list[0].nodeNum);

    list[0].Add_list_back(10,1000);
    list[0].Print_all_node();
    printf("number of the node is :%d \n\n",list[0].nodeNum);

    list[0].Delete_one_node(10);
    list[0].Print_all_node();
    printf("number of the node is :%d \n\n",list[0].nodeNum);

    list[0].Insert_one_node(9,9999);
    list[0].Print_all_node();
    printf("number of the node is :%d \n\n",list[0].nodeNum);

    list[0].Delete_all_node();
    printf("number of the node is :%d \n\n",list[0].nodeNum);
    */
}

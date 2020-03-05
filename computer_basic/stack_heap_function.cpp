#include<stdio.h>

int change(int p)
{
    p=101;
    printf("p的内存地址是%p\n",&p);
    printf("p的值是%p\n",p);
    return p+1;
}

int main()
{
    int a;
    int b;
    a=1;
    printf("a的内存地址是%p\n",&a);
    printf("b的内存地址是%p\n",&b);
    b=change(a);
    printf("a 的值是%d\n",a);
    printf("b 的值是%d\n",b);
}




int change(int* p)
{
    *p=101;
    printf("p的值是%p\n",p);
    printf("p的内存地址是%p\n",&p);
    printf("*p的值是%d\n",*p);
    return p;
}

int main()
{
    int a;
    int* b;
    a=1;
    printf("a的内存地址是%p\n",&a);
    printf("b的内存地址是%p\n",&b);
    b=change(&a);
    printf("a 的值是%d\n",a);
    printf("b 的值是%p\n",b);
    printf("*b 的值是%d\n",*b);
}




堆：用malloc申请的内存。作用域：全局可用。 生命周期：直到free
栈：其他非malloc申请的内存，作用域：局部可用 可以是一个函数也可以是{}以内的。生命周期：出了局部代码块就消失了

所以，变量最重要的3个概念： 一，内存空间的问题；二，作用域的问题；三，生命周期的问题。（和堆栈的概念相关，堆和栈的大小都是有限制的）

电影文件放硬盘；编程的变量才是在内存。



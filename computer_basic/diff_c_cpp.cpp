c: 面向过程的编程思想，主要是函数就是单纯用来做算法处理，从形参得到输入，从return，指针型形参的间址运算写操作，全局变量 可以返回计算结果。
   函数本身不能记下任何变量和计算结果

cpp: 面向对象的编程思想，将函数方法和变量，捆绑在一个class内部，当声明一个class的对象时，这个对象的方法可以读写它的成员变量，相当于一个对象，既有算法，
     也有变量，不需要用户对大量的计算结果另外申请内存来保存。这样变量也容易管理，函数的形参也变得简单。
     类名相当于一批变量的名空间，每个类的对象都会实例化出来一个属于自己对象名的名空间。
     这个对象名的名空间内部的变量，对于该对象的方法来说，相当于全局变量。所以对象的方法可以直接访问该对象的变量。
     面向对象编程，相当于一个对象的一批变量的名空间管理机制。

数据结构: 理论上来说，数组，栈，队列，链表，树，图，等属于数据结构理论，可以用任何计算机语言实现，不是专属于c语言

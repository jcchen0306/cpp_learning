//c++继承和多态   inheritance  polymorphism
//继承的主要目的是冗余的（相同或者类似）代码只保留一份，方便更改和重复利用
//多态的目的是，用一个父类的指针，指向不同的子类对象，用相同的函数接口名，就可以产生不同的行为

class animalClass
{
public:
    int gender;
    int weight;
    int age;
    char* name;

    animalClass();
    ~animalClass();
    void get_weight();
    virtual void makeSound();      //是虚函数而不是纯虚函数，就要该类的实现也要有
    virtual void eat()=0;          //纯虚函数，父类不实现该功能，但是要留一个接口给派生类，派生类在实例化时，
                                   //必须有该函数的该派生类的实现。供子类对象的地址给父类指针时，实现多态
};

animalClass::animalClass()       //基类的构造函数
{
    name = (char*) malloc(20*sizeof(char));
    weight=0;
}

animalClass::~animalClass()       //基类的析构函数
{
    free(name);
}

void animalClass::get_weight()       //普通基类函数，所有的子类都可以使用。实现多个类代码共享，避免重复开发和改动时的多处改动。
{
    printf("wight is %d",weight);
}

void animalClass::makeSound()      //虚函数的实现，为多态行为做准备。多态就是父类指针，指向父类对象，就调用父类函数，指向不同的子类，就调用不同的子类的函数。
{
    printf("hehhehe");
}


//派生类1
class dog : public animalClass
{
public:
    char* originPlace;
    void makeSound();                //子类中不需要重新实现的来自父类的函数，就不要声明，父类中已经实现的类可以直接调用。父类中该函数加了virtual
                                     //则派生类中该函数自带virtual，所有可加virtual关键字，提醒下一级子类，也可以不加。见谭浩强《C++程序设计(第二版)》p.401-402
    void eat();                      //父类中声明的纯虚函数，子类中必须要声明且实现。
    dog();
    ~dog();
};

void dog::makeSound()               //在类定义外实现虚函数，不需要加virtual；
{

    printf("wang wang wang \n");
}

void dog::eat()
{
    printf("eat bones\n");
}

dog::dog()
{
    originPlace = (char*) malloc(20*sizeof(char));
}

dog::~dog()
{
    free(originPlace);
}


//派生类2
class cat : public animalClass
{
public:
    char* color;
    void makeSound();                //子类中不需要重新实现的来自父类的函数，就不要声明，父类中已经实现的类可以直接调用。父类中该函数加了virtual
                                     //则派生类中该函数自带virtual，所有可加virtual关键字，提醒下一级子类，也可以不加。见谭浩强《C++程序设计(第二版)》p.401-402
    void eat();                      //父类中声明的纯虚函数，子类中必须要声明且实现。
    cat();
    ~cat();
};

void cat::makeSound()               //在类定义外实现虚函数，不需要加virtual；
{

    printf("miao miao miao \n");
}

void cat::eat()
{
    printf("eat fish\n");
}

cat::cat()
{
    color = (char*) malloc(20*sizeof(char));
}

cat::~cat()
{
    free(color);
}


//以下是测试函数
#include"list.h"

int main()
{
    animalClass* group[2];
    group[0] = new cat();
    group[1] = new dog();

    for(int i=0;i<2;i++)
    {
        group[i]->eat();
        group[i]->makeSound();
    }
}


//总结:
//虚函数的调用,执行函数时,选择父类的实现,还是子类的实现,原则是按照内存上的对象类型来选择: 内存上的对象是子类,就执行子类方法.内存上的对象是父类,就执行父类方法.
//内存上的对象类型,就是new出来啥,就是啥类型. 或者直接通过类的类型来定义的栈上的对象.
//非虚函数调用,执行函数时,按照对象地址所赋值到的指针类型的类选择函数. 例如,把一个子类的对象地址,给父类指针. 父类和子类有相同的方法,调用这个方法时,按照指针类型来定.所以执行的是父类的实现.

//虚函数调用哪个实现,看对象是哪个类型.
//非虚函数调用哪个实现,看指针是哪个类型. 

//某一个类,如果包含了一个虚函数方法,要么自己实现.要么=0.  相当于0也是一种实现,我们叫纯虚.


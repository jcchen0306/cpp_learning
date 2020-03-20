//这是注释的第一种方法，注释一行

/*
这是注释的第二种方法
可以注释多行
*/

/*
计算机基础知识：
#include<math.h>   pow(2, 3); //pow 在math.h 中定义的，用来算几次方，第一个参数是底数，第二个是指数。数学上用^
c语言规定标识符只能由字母，数字和下划线3种字符组成，且第一个字符必须为字母或下划线。
如：sum   averavg   _total  Class   lotus_1_2_3
十进制 满十进一 999 = 9*10^2 + 9*10^1 +9*10^0
8进制 满8进一 666 = 6*8^2 + 6*8^1 + 6*8^0
16进制 满16进一 F5A5 = 15*16^3 + 5*16^2 + 10*16^1+5*16^0     [0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F]
2进制 满2进一 10101 = 1*2^4 + 1*2^2 +1*2^0
一个字节 8个位 每个位是一个二进制位
一个字节最小的数为00000000，最大的数为11111111=1*2^7 + 1*2^6 + 1*2^5 + 1*2^4 + 1*2^3 + 1*2^2 + 1*2^1 + 1*2^0=255
正数：8位  1个字节 0000 0000 第一位为符号位 0为正 1为负

不想既定义加法的进位，也定义减法的借位，所以就把减法变成加法，用补码。
例如3-1，和3+99，在两位数的加法时，效果是不是一样的，都是等于2.那么可以认为，99是-1的加法替代码，叫补码。
这个过程中正数没有变，都是3，负数由-1变成了99
所以，补码总结如下：

正数的原码，反码，补码都相同，符号位为0，数值位绝对值

负数原码：符号位1 绝对值
负数反码：符号位1 绝对值取反（1变0,0变1）
负数补码：符号位1 绝对值取反（1变0,0变1）+1

举例：
-1的原码：1000  0001
-1的反码：1111  1110
-1的补码：1111 1110+1= 1111 1111

计算机加法，全部使用补码，正数补码+负数补码 = 和的补码

例如+1的补码，0000 0001
    -1的补码, 1111 1111
	加起来=   0000 0000

整数相除，结果是整数，按照去尾，去掉小数部分，例如：
2/5=0
6/4=1


小数相乘除(至少其中一个是小数)，结果是小数，一切正常，该怎么除怎么除。
5/3.0=1.666667

我们用C语言写的文本的代码（也叫源程序，或者源代码），经过visual studio的后台编译器，编译成机器可以识别的机器码（二进制码），最终是一个可以运行的exe程序。
人认识的程序（文本源代码），要换成机器可以认识的程序（二进制），这个转换过程叫做编译，转化的工具，叫做编译器。
找到机器能识别的二进制可执行程序exe，在这个文件夹鼠标右键单击，选择Git Bash Here，输入 ./可执行程序名字  ，然后按回车，就可以运行。
.代表当前文件夹，./test.exe  代表当前文件夹下的test.exe。
输入过程中可以按Tab键自动补全。

基本的命令行操作：
Windows下，按winkey+R，打开运行窗口，输入cmd，打开命令行窗口（黑色窗口）
命令行中的常用命令：
D:  ：就是进入D盘
cd ：change directory，就是要进入某一个文件夹
dir：directory ，列出当前文件夹下的所有文件和文件夹

.\test.exe : 就是运行当前文件夹下的程序test.exe

h 文件是header文件，头文件的意思，一般包函数声明，define等定义
cpp 文件是算法文件，主要是函数的实现，函数里头是大量的定义，if else，while，for，do

指针：
任何一个变量在内存中都有自己的位置。
这个位置就是一个地址，就是第几号位，4G 内存通常有2^32个字节，第几号位是从0 -  (2^32-1),用16进制，就是0000 0000 ~FFFF FFFF,这就是地址
int a; 定义一个变量，&a 就是变量a放在内存中的地址
int *p; 定义一个指针变量，用来存放一个int 变量的地址。赋值用 p = &a;
在非定义的时候：
*p=11; 把11放到p指向的地址中。（如果p=&a, 那么*p=11，其实就是a=11）*是对指针指向的内存单元进行赋值。
b=*p；把p指向的地址中的数，赋值给b。

指针赋值有2种
1）地址相关的运算 p=&a；（求址运算）
2）地址中存放的值相关的运算 *p=11； b=*p（间址运算读操作）*（p+1）=11(间址运算写操作)；（间接寻址运算，*就是寻找某个地址里头的值，简称间址运算）

函数形参为指针时，通过间址运算写操作，可以在子函数中改变指针指向的地址里头的值。

访问指针指向的连串存储单元里头的值，例如一个数组，a[10],a就是这个数组的首地址，可以赋值给一个指针
int* p;
p=a; //数组首地址赋值给指针
访问元素可以用
a[i], 或者   *(a+i)  /a为数组的首地址，a+i为数组偏移
p[i], 或者  *(p+i)=11；

定义数组不能用动态长度。

malloc是在内存的堆区域上面申请一定字节数的内存，返回的是这块内存的首地址，用指针接收（指针类型为无类型，void，要用来存储指定的数据类型，就要强制转换成指定的类型）

这个内存相当于全局变量，不用的时候要free。
malloc是一个内存动态操作。
malloc用法：
存储n个int型数时，(int*) malloc(n*sizeof(int));
存储m个double型数时，(double*) malloc(m*sizeof(double));

1定义字符数组  char string[]=" I love china"   //用%s格式申明输出string, 可以输出整个字符串。string的数组长度是由初始化字符串自己算出来的，最后一位为0
2定义字符变量  char *str="I love china"   //定义一个char*变量  把字符串第一个元素的地址赋值给变量str，str的数组长度是由初始化字符串自己算出来的，最后一位为0
3字符数组一定要有结束标志0，不管是打印还是作为返回值都要有0
4要返回一个字符数组 "china"
    char* str;
    str=(char*) malloc(sizeof(char)*6);
    *(char+5)=0;
    return str;

整数相关的技巧：
%用来求余数，求m的个位，就可以用m%10;
正整数除以正整数，结果是正整数，原则是去掉小数部分。m/10相当于丢掉个位，右移了一位。

结构体：
声明自定义数据类型
struct student
{
    int id;
	char name[20];
	int gender;
	int gradeID;
	int classID;
	int age;
};
定义变量：
struct student oneStu;
struct student multiStu[10];

把自定义的结构体类型声明简化
typedef struct
{
	int id;
	char name[20];
	int gender;
	int gradeID;
	int classID;
	int age;
}student;

student oneStu;
student multiStu[10];
结构体的优势：
1）变量组合在一起，捆绑，定义数组的工作量减少（原来可能要每一个属性定义一个数组，现在只需要定义一个结构体数组）
2）函数形参变得简单统一，结构体产生变化时，函数形参列表不发生变化。

堆区（heap）内存申请，用malloc，生命周期贯穿整个程序（就是说这个被申请的内存一直被占用，后面的申请，不能利用这块空间）
malloc申请的内存，当不需要再用的时候，用free可以把这块内存释放掉。用法就是free(p)，p是指向malloc申请内存成功时返回的内存首地址。

链表：
假设每个student结构体变量占100个字节。
该班开始有50个同学。
某天，该班上转入10个同学。
再过了几天，该班上转出5个同学。
该怎么保存这个班上的同学信息？

数组的问题：地址是连续，定义时，数组的长度就定了，后面不能改了。新加入的同学，只能再建一个数组。删掉同学，只能删掉信息，但是内存还占着。
1）循环遍历有难度，可能要遍历多个数组。最好遍历是一个循环能解决问题。
2）最好能释放不用的内存资源

链表就出现了
struct studentNode
{
	student oneStudent;
	struct studentNode* next;
};

struct studentNode* head,walker;
head = (struct studentNode*) malloc(sizeof(struct studentNode));
walker = head;
walker->next = (struct studentNode*) malloc(sizeof(struct studentNode));
//赋值结构体内容
walker=walker->next;
walker->next = (struct studentNode*) malloc(sizeof(struct studentNode));
//赋值结构体内容

->是访问结构体指针，指向的结构体内部的成员。
.是访问结构体的成员。


linux(ubuntu是一种linux发行版，Linux还有很多其他的发行版，例如debian，kubuntu，mint，raspbian，deepin，redhat)
CMakeLists.txt是项目管理文件。用来组织头文件，cpp源文件，以及要调用的库文件，最终通过编译器，编译成二进制文件，电脑可以执行的。
所有的cpp，h，CMakeLists.txt，都叫源代码的一部分。
我们的工具链，一般叫编程工具链，能投通过键盘输入，最终生产机器可以执行的程序，所用到的所有的软件。
工具链1： windows操作系统->visual studio 2019 编程软件 -> msvc编译器编译源代码 -> 命令行可运行的二进制文件。
工具链1-1： windows操作系统->qt 编程软件 -> msvc编译器编译源代码 -> 命令行可运行的二进制文件。
工具链2： ubuntu操作系统->qt编程软件 ->cmake(项目管理软件)解析项目管理文件CMakeLists.txt -> gcc编译器编译源代码 —> 命令行可运行的二进制文件。
时间上不能有多余的操作，空间上u盘和硬盘不能有多余的文件。
内存是用malloc申请的内存，硬盘是电脑里的储存文件。
重要文件更新改动后要保存，并复制到相应的目录，注意备份
内存是写源代码用malloc申请的字节，硬盘是电脑的储存文件。
删除上次编译生成的文件，鼠标右键打开命令行输入qt点回车，点击file点击open file or project，点击项目文件夹test，点击cmakelists.txt，编译并运行。
拷贝前找到项目编译生成的文件夹，例如build-test-Desktop_Qt_5_14_0_GCC_64bit-Debug文件夹打开，找到二进制可执行程序myTest，点击鼠标右键点击open in terminal，
用命令行运行./myTest，运行通过再拷贝并删除编译生成的文件。

文件类型 list.h 以h结尾的为头文件/以cpp结尾的为原文件，分别为显示文件和测试文件。
编程知识点12条
1项目管理文件
2编译加qt编程软件
3指针
4内存
5结构体
6函数
7循环
8判断
9条件
10数据类型
11数组
12CMakeLists.txt

八大数据结构
1数组
2链表
3堆
4树
5栈
6队列
7图
8散点表

链表：1初始化（建立n个节点node)
     2在末尾加n个节点
     3删除某一个节点
     4在某一个位置插入一个点
     5打印所有节点
     6清空所有节点
注：所有malloc的内存不用的时候要free.

声明的指针，一定要先赋值地址（一个自己声明的变量的地址或malloc申请的内存首地址），才能进行读写。
如果暂时不能赋一个有效的内存地址，就先赋值0，表示没有指向有效地址。

注意，自定义的头文件包含，要用"",例如，#include"my_function.h"

链表的节点内存单元，左上角内存的首地址，最下方表示一个指针，指向下一个节点的首地址。

首地址
  ---——————
     |data|
     |    |
     |    |
     ——————
     |next|
     ——————

一个结构体可以用来赋值给另一个结构体，就是所有的结构体成员一一赋值，

c语言中，函数调用时，要在被调函数（子函数）中更改调用函数（父函数）中传递的参数变量的值，那么形参必须是指针，父函数中调用子函数时，
传递变量的地址，子函数中对形参指针进行间接寻址运算，读和写，*p=100。
例如：
int swap(int* a, int* b)//这叫被调函数（子函数）
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int main()//这叫调用函数，（父函数）
{
    int a=1;
    int b=2;
    swap(&a,&b);
    //在这之后，a的值变成2，b的值变成1
}

多级指针。
主要窍门就是通过几次间接寻址运算，可以获取到一个指针所属类型的变量值。任何一个变量都在内存中有一定的字节来存储它的值，每个指针变量都有自己在内存中的位置（地址）
例如：
int a=1；
int* p; p=&a;   p是int型指针，指向一个int变量 a，通过一次间接寻址运算，可以拿到这个int的值，就是*p，所以p是一级指针。
int** p1; p1=&p;  p1指向一个一级指针， *p1 拿到的是 p,还是一个指针，需要在进行一次间接寻址运算，**p1, 拿到的才是int 的值，也就是a的值。所以p1是二级指针。
int*** p2; p2=&p1; *p2 拿到的是p1的存储的地址，**p2拿到的值p里头存储的地址， ***p2拿到的是p指向的整形数的值,也就是a的值。所以p2是三级指针。

网络基础：
1上网：所有电脑都有一个区域性身份编码IP，这个区域可以是全球，那么全球都以一个唯一的身份构(IP地址)成一个可互相访问的网络，这个网络叫广域网。这个区域也可以是一个城市 一栋楼 或一个公司，
这就叫局域网。

2构成网络的设备:路由器 和 交换机
(1)路由器 ----电信公司用的多，大型网络用的多。
(2）一般有多个路由器构成网络，确定连接路径。
(3）路由器有分配IP和路径选择算法。
(4）交换机一般局域网用的多，局域网一般只连接多台电脑构成相互可访问的局域网，没有远距离路由器计算功能，负责小范围交换。
(5) IP： 8位二进制 . 8位二进制 . 8位二进制 . 8位二进制  。 每个8位二进制表示范围是0~255。 全球通讯的两台电脑，必须有两个公网ip，就是全球唯一ip，全球唯一公网ip总数大概40亿。
    每个电脑可以在一个内网中，一个内网中最多可以有65535台电脑。
    两台电脑相互测试能否连接，先用ping ，例如 ping www.baidu.com， ping 192.168.0.7
    ping有响应，就表示两台电脑可以通过网络（局域网络）连接。
    windows上可以通过ipconfig/all 来查询本地的局域网ip地址；linux上可以通过ifconfig查询本地的局域网ip地址。
    一个局域网内部的两台电脑，可以通过ssh相互访问（尤其在linux上，要被访问的电脑先安装openssh-server)，访问指令是 ssh username@serverIP，就可以实现终端登录服务器。

(6)翻墙： 中国大陆为了防止国民访问反动势力的宣传网址，在中国出口路由上设置了路径屏蔽，例如国内想访问google的请求，会被路由器丢弃。我们就通过一个私密的连接，先连接到香港，新加坡等地的服务器上，在访问美国google。
   这种通过中间设备转发访问请求，就叫代理。

(7)网络架构：
                         router(路由器)               router(路由器)  ：连接广域网（全球网络）,进行路径选择（路由器算法)
                              \                      /
                               \                    /
                                \                  /
                                 \                /
                                  \              /
                                   router(路由器) ： 对内分配内网IP，对外进行路径选择（路由器算法)
                                       |
                                       |
                                       |
                                   switch(交换机）：连接多个电脑
                                       |
                      --------------------------------------
                      |           |             |           |

                    电脑1       电脑2           电脑3        电脑4


ubuntu18.04翻墙：
(1)设置：
   在系统的 setttings-> Network -> Network Proxy 选择 manual
   在http Proxy 填入 127.0.0.1， 后面端口中填入12333
   在Socks Host 填入 127.0.0.1， 后面端口中填入1080

(2)采用代理工具 electron-ssr-0.2.6, 运行 ./electron-ssr
(3)chrome 浏览器的代理插件选择 system proxy
(4)关闭翻墙，在系统的 setttings-> Network -> Network Proxy 选择 disabled；chrome 浏览器的代理插件选择 direct

标量： 无方向  体重  腰围  身高  金额
矢量： 有方向  位移  力   速度
矢量全部用坐标表示，起点与终点之差的量  有方向 有大小，但无作用点限制。

版本控制：
常见的版本控制软件有git， svn
我们以git作为主要版本控制软件。



git基本概念：

     工作区   --------->>    暂存区    -------------->>    版本库
             add（暂存）                 commit（提交）
工作区：就是眼睛可以看到的文件，以及对他们的修改，例如打开的一个git仓库的文件夹，这个文件夹里头的所有的文件，构成了工作区。
暂存区：位于仓库内的 .git 文件夹中，就是相当于记录了相对于上一次提交的对工作区的更改。
版本库：每一次提交都会有一个版本。所有的版本库信息都存在于 .git 文件夹中，可以用checkout指令，将 .git 文件夹中记录的某一个版本的所有文件，恢复到工作区。每个版本都有对应的commit编号。

1）在要创建git repository 的文件夹，运行 git init， 生成 .git 文件夹。 这样一个git 仓库就建立好了。
2）显示当前git repository维护的人员信息。 git config --list
3）添加文件或者修改文件，然后更新到暂存区。 git add . , .表示所有文件的改动都更新到暂存区，没有改动的，就不添加。
4）提交暂存区的改动，到版本库。 git commit -m "在这里写注释，表明这一次版本作了那些改动"。提交到版本库之后，会有一个版本号。
5）查看已经提交的版本历史。 git log。
6）查看当前工作区的更改和更新到暂存区的状态。 git status。
7）将某一次提交commit的文件版本，检出（复制）到工作区，就相当于把工作区的文件，编程某一次commit时的文件。 git checkout commit-id。checkout到之前的commit状态，不会删除后面以后的commit。
8）删除某一次commit后的commit。git reset --hard         丢弃工作区所有改动，版本库没有任何改动
                            git reset --hard HEAD^   回退到上一个版本，相当于丢掉了版本库中最新的一个版本。
                            git reset --hard HEAD^^ 回退到上上个版本，相当于丢掉了版本库中最新的两个版本。
                            git reset --hard HEAD~3      回滚到3个版本之前。相当于丢掉了版本库中最新的三个版本。
                            git reset --hard e9efa77  回退到 e9efa77  版本，相当于丢掉了版本库中e9efa77之后的所有版本。
   git reset --hard 很危险，他会把要回到的commit之后的所有改动全丢掉。
9）分支的概念：回到某一次commmit后，想在这次commit上接着写代码，做改动，但是又不想删除这次commit后的代码。那就从这个commit的地方，另外开一个分支，然后在这个分支上，做改动，不会影响原分支。

       checkout
       到此处
       建立新分支

   O---->O------>O------->O   master
         \
          \
          O------->O---->O    new-branch-name
          新分支，接着commit
    在某个commit处创建新分支。  git branch <new-branch-name>  <commit-id>

    切换到某一个分支。git checkout branch-name。


10）给远程库 https://github.com/xxx/LearnGit.git 添加一个别名origin到本地。准备用git网盘存储代码。
     git remote add origin https://github.com/xxx/LearnGit.git
11）给远程库起了本库的别名origin之后，可以用git push将当前所在仓库的某一个分支推送到云端服务器。 git push origin master

12）将服务器端的代码，拷贝到本地。 git clone https://github.com/xxx/LearnGit.git

13) git log中显示的 HEAD，指向某一个分支的某一次提交。

14）github 官方推荐的push 流程 (第一次创建github远程仓库的push到远程的流程)
echo "# cjc-test" >> README.md
git init
git add README.md
git commit -m "first commit"
git remote add origin git@github.com:jcchen0306/cjc-test.git
git push -u origin master


15) 将本地已有仓库，push到远程已有仓库流程

git add .
git commit -m "这里是本次版本的改动说明"
git push github_origin master


(16) git日常工作使用中的重点功能，合并！
合并情景一： 某人开发一个软件，写好了基本代码之后，要添加多个功能，由于精力有限，每次只能把精力放在一个分支上，
           那就在基本代码的版本上，建立多个分支，每个分支写一个功能，功能测试成功后，合并到master分支。
           一般不能在master分支上面写代码。

合并情景二： 某个项目经理，建立了一个产品基础代码。然后工作组有多个人在这个代码作为依赖，在此基础上写代码。
           那就让每个员工，在此基础版本上，建立自己的开发主分支，再在自己的开发主分支的基础上，建立自己的功能开发分支，
           功能开发分支通过后，先合并到自己的开发主分支。自己的所有开发功能完成后，进行最终合并自己的开发主分支，并将
           自己的开发主分支请求合并到经理的主分支。

建立新分支：
第一种简单方案：先checkout 到制定提交，直接修改，然后 git add .
                                              git commit -m "本次提交说明"
                                              git checkout master    //随便checkout到另个分支，master是默认存在的
                                              然后就有提示，要建立分支
                                              git branch <new-branch-name> <commit-id>
             这叫先斩后奏。先改并且提交，再补建分支。

第二种方案：  那就是先建立新分支，在切换到新分支的某个提交，在此基础上更改，并提交。
           在某个提交上直接创建分支： git branch -a    //先看总共有多少分支
                                 git checkout <branch-name>       //切换到某一个分支
                                 git log         //看一下当前分支有哪些提交
                                 git checkout <commit-id>         //切换到某一个提交
                                 git branch <new-branch-name>     //在当前分支的地方，建立一个新分支
                                 git checkout <new-branch-name>    //切换到刚刚建立的新分支，进行操作
                                 操作完了，就提交，然后去别的分支，干别的活。

建立了新分支，干完了活，功能开发成功，就要合并到主分支。

git checkout <自己的开发主分支或者master>
git merge  <merged-branch-name> //当前所处分支，在自己的开发主分支或者master，将<merged-branch-name>合并到当前所处分支。


如果有conflict（冲突）存在，那是因为两个要合并的分支，对同一个文件的同一个区域进行了修改。
git不知道保留哪个。
那就进去那个文件，手动更改。
手动修改的法则是：

冲突区域：（相当于把两个版本的都保存了）
<<<<<< HEAD
*&^^&&
=======
#@*&^^
>>>>>>> merged-branch-name

=======上面的（*&^^&&）是   自己的开发主分支或者master  分支中的内容
=======下面的（#@*&^^）是   merged-branch-name   分支的内容

那就把这个冲突区域 手动更改，随便改成哪一个，或者其他的。相信两个分支中的一个，或者都不相信，重新更改。
改完了之后，要重新提交：  git add .
                      git commit -m "合并冲突解决"

查看所有分支： git branch -a

合并完后，合并主分支中间就没有线条抽头，那就删除多余的被合并分支的编号： git branch -d  <branch-name>

查看当前分支的提交（可视化图形）： git log --graph

(17) 如果已经推送到远程库，而本地撤消了某个提交，可以强制push到远程库。
    git reset --hard HEAD^
    git push github_origin master --force


(18) git使用重要原则：
     1) 要使用 git log          //显示当前分支的提交记录
              git log --graph  //用图形形式显示当前分支记录
              git status       //显示当前分支和工作区状态
              git branch -a    //显示所有的分支
        越频繁越好。

     2）工作区的改动，要么提交  git add .
                            git commit -m "版本提交说明"
                   要么撤销  git reset --hard   //删除工作区所有的未提交的改动
        完成工作区的两大要求后，才能checkout（此种工作模式是最简单的，不需要用到git stash）

     3） 不是在某条分支最后一个节点提交改动后（此时就会有分叉），一定要先对该提交建立新分支，才能checkout 到其他分支。

     4） 合并完后，要删除多余的被合并分支的编号。  git branch -d <branch-name>





(19) git 使用的高级操作

git stash：

情景一： 在提交A的基础上，对工作区有改动，在不想继续提交的基础上，要切换到其他分支工作，能够保留改动，以后再回到A时，能够恢复对工作区的改动，继续工作。

情景二： 某工程师在对工作去有一定的改动后，发现自己处于错误的分支，想把此改动建立在其他分支的基础上。

git stash：能够将所有未提交的修改（工作区和暂存区）保存至堆栈中，用于后续恢复当前工作目录。
git stash save：作用等同于git stash，区别是可以加一些注释
git stash list：查看当前stash中的内容
git stash pop：将当前stash中的内容弹出，并应用到当前分支对应的工作目录上。注：该命令将堆栈中最近保存的内容删除（栈是先进后出）
               如果从stash中恢复的内容和当前目录中的内容发生了冲突，也就是说，恢复的内容和当前目录修改了同一行的数据，那么会提示报错，需要解决冲突，可以通过创建新的分支来解决冲突。
git stash apply：将堆栈中的内容应用到当前目录，不同于git stash pop，该命令不会将内容从堆栈中删除，也就说该命令能够将堆栈的内容多次应用到工作目录中，适应于多个分支的情况。
                堆栈中的内容并没有删除。可以使用git stash apply + stash名字（如stash@{1}）指定恢复哪个stash到当前的工作目录。
git stash clear：清除堆栈中的所有 内容
git stash show：查看堆栈中最新保存的stash和当前目录的差异。


git reset三种模式区别：
        --hard： 重置位置的同时，直接将 working Tree工作目录、 index 暂存区及 repository 都重置成目标Reset节点的內容,所以效果看起来等同于清空暂存区和工作区。
        --soft： 重置位置的同时，保留working Tree工作目录和index暂存区的内容，只让repository中的内容和 reset 目标节点保持一致，因此原节点和reset节点之间的
                【差异变更集】会放入index暂存区中(Staged files)。所以效果看起来就是工作目录的内容不变，暂存区原有的内容也不变，只是原节点和Reset节点之间的所有差异都会放到暂存区中。
--mixed（默认）： 重置位置的同时，只保留Working Tree工作目录的內容，但会将 Index暂存区 和 Repository 中的內容更改和reset目标节点一致，因此原节点和Reset节点之间的
                【差异变更集】会放入Working Tree工作目录中。所以效果看起来就是原节点和Reset节点之间的所有差异都会放到工作目录中。


git diff的三种模式：
         git diff：当工作区有改动，临时区为空，diff的对比是“工作区与最后一次commit提交的仓库的共同文件”；当工作区有改动，临时区不为空，
                  diff对比的是“工作区与暂存区的共同文件”。
git diff --cached
git diff --staged：显示暂存区(已add但未commit文件)和最后一次commit(HEAD)之间的所有不相同文件的增删改
    git diff HEAD：显示工作目录(已track但未add文件)和暂存区(已add但未commit文件)与最后一次commit之间的的所有不相同文件的增删改

(20) windows 10下使用git gui for win 的git bash 来使用git，以及git pull的使用。
     git bash的明亮行显示中文的设置：
     terminal内右键单击->options->text->font(选consolas，12pt);locale(选zh_CN);Character set(选UTF-8)
     windows 10端要先复制unbuntu下对应在github添加的密钥组(两个文件id_rsa和id_rsa.pub)到 C:\Users\Jiacai_Chen\.ssh路径下
     然后下载代码：
     git clone git@github.com:jcchen0306/cpp_learning.git

     设置远程库本地别名：
     git remote remove origin
     git remote add github_origin git@github.com:jcchen0306/cpp_learning.git

     设置本地用户信息：
     git config --global user.name "jcchen0306"
     git config --global user.email "2574533980@qq.com"

     windows端下修改代码，并提交，然后push到远程端，到ubuntu下pull远程端的master分支。
     git pull github_origin master //pull远程端的master分支，相当于 git fetch 和git merge。

     等价于：
     git fetch github_origin master //从远程主机的master分支拉取最新内容，取回更新后，会返回一个FETCH_HEAD ，指的是某个branch在服务器上的最新状态
     git merge FETCH_HEAD          //将拉取下来的最新内容合并到当前所在的分支中

(21) windows和linux下常用软件和所属公司
     Microsoft(微软)：全球最大，最早的软件公司
                    Office(办公套件）:
                                    word: 文档，文字排版软件
                                    Excel: 表格，报表处理软件
                                    PowerPoint: ppt，报告，汇报展示软件
                                    visio: 流程图，矢量图处理软件
                    操作系统：
                            windows xp: 2000年左右的操作系统
                            windows 7 : 2010年左右的操作系统
                            windows 10: 2015年左右开始的操作系统

                    软件开发：
                            visual studio: windows系统上的最好的软件开发工具，简称集成开发环境（integrated development environment，缩写IDE），目前最新版本是
                                           2019。分社区办（community，免费） 和 企业版（enterprise，收费）。可以用来写c/c++、python、c#、Android等语言的项目
                            visual studio code: 开源的软件开发工具，2017年左右开始的，免费，正在高速成长。可以支持远程登录开发。

     Nokia(诺基亚)：全球知名的嵌入式设备开发商，尤其是手机。以及嵌入式设备上的图形软件系统，以Qt图形系统为主要产品。
                  软件开发:
                         Qt: Qt图形库，和Qt c/c++ 集成开发环境（IDE）。不自带编译器和调试器。社区版不收费，企业版收费。（linux下相同）

     Adobe: 全球最大的多媒体处理软件供应商，所有软件全部收费。
            Adobe Acrobat DC：pdf编辑软件
            Adobe Dreamweaver: 网页设计软件
            Adobe Illustrator: 矢量图设计软件
            Adobe Lightroom: 单反相机原始格式数据处理软件（如.nef格式）
            Adobe photoshop: 位图处理软件
            Adobe premiere Pro: 视频处理软件

     anaconda: 免费，python虚拟环境管理软件 （linux下相同）

     pycharm: python开发软件（社区版不收费，企业版收费），不带python解释器。 （linux下相同）

     eclipse java：java常用的开发软件，不带java虚拟机，分标准版（standard edition，SE）和企业版（enterprise edition，EE）,不收费。（linux下相同）

     MyEclipse：java网页项目全栈开发工具，收费。（linux下相同）

     freefileSync: 文件同步软件，免费。（linux下相同）

     git：版本控制软件，免费。（linux下相同）

     Git for Windows：windows下的git版本图形化工具。

     wps: 中国金山软件公司开发的办公套件。个人版不收费，特殊服务收费。（linux下相同）
          word： 文档处理，相当于Microsoft的word
          presentation： 汇报展示，相当于Microsoft的 PowerPoint
          spread sheet: 表格，相当于Microsoft的 Excel
          pdf: pdf 阅读

     MobaXterm：windows下的远程工具。

     cmake：c/c++项目管理工具，用来解析CMakeLists.txt，解析项目头文件和库文件依赖。开源，不收费。（linux下相同）

     cmake-gui：c/c++项目管理工具，用来解析CMakeLists.txt，解析项目头文件和库文件依赖，图形化配置项目参数。开源，不收费。（linux下相同）
               windows下还可以将CMakeLists.txt项目转化为visual studio的 .sln 项目。

     notepad++: windows下的txt文档编辑软件，功能比windows自带的文本编辑器强大。开源，免费。

     google chrome: google 公司的浏览器软件，比windows自带的IE和edge好用。免费。（linux下相同）
*/
//一元二次方程求根，通过指针返回实数解
/*
#include<stdio.h>
#include<my_function.h>
int main()
{
	double x[100];
	int flag;
	x[0] = 0;
	x[1] = 0;
	flag = findRootOfSecondPoly(3, 4, 1, x);
	if (!flag)
		printf("两个实根是%lf, %lf\n", x[0], x[1]);
	else
		printf("没有实根\n");

	printf("x[99]: %lf\n", x[99]);
	return 0;
}
*/

/*
//注意，自定义的头文件包含，要用"",例如，#include"my_function.h"
#include<stdio.h>
#include"my_function.h"
int main()
{
	double array[10] = { 100,2,3,4,15,6,57,8,9,10 };
	sort(array, 10, 0);
	for (int i = 0; i < 10; i++)
		printf("%lf ", array[i]);
	printf("\n");
	return 0;
}
*/
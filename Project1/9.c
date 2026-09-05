/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stddef.h>
struct student {
	char name[20];
	int age;
}Stu = { "张三",19 };
// 匿名结构体类型
struct {
	char name[20];
	int age;
}x = { "张三",19 };
// 利用typedef关键字将结构体类型重命名为S
typedef struct {
	char name[20];
	int age;
}S;
struct {
	char name[20];
	int age;
}*p;
typedef struct Node {
	int data;
	struct Node* next;
}Node;
struct X {
	char c;// 1字节
	int x;// 4字节
	double d;// 8字节
};
struct Y {
	char c;// 1字节
	double d;// 8字节
	int y;// 4字节
};
#pragma pack(4)
struct Z {
	char c;// 1字节
	struct Y y1;// 24字节
	int z;// 4字节
};
#pragma pack()
struct A {
	int a;
	int b;
	int c;
	int d;
};
struct B {
	int a : 5;
	int b : 10;
	int : 0;
	// :0表示强制换行，会清空当前的剩余位，下个位段成员将将分配到新的存储单元
	int c : 15;
	int d : 20;
};
struct C {
	char a : 2;
	char b : 3;
	char c : 4;
	char d : 5;
};

int main() {

	// 结构体指针->成员名
	struct student s1 = { "李四", 20 };
	printf("%s %d\n", s1.name, s1.age);
	printf("%s %d\n", Stu.name, Stu.age);
	// 使用结构体变量名.成员名的方式直接访问结构体成员
	struct student* p1 = &s1, * p2 = &Stu;
	printf("%s %d\n", (*p1).name, (*p1).age);
	// 与指针变量使用方式类似，先取地址然后解引用操作访问结构体成员
	printf("%s %d\n", p2->name, p2->age);
	// 使用结构体指针->成员名的方式间接访问结构体成员

	// 结构体的特殊声明
	struct y = { "李四", 20 };
	printf("%s %d\n", y.name, y.age);
	printf("%s %d\n", x.name, x.age);
	// 匿名结构体类型只能使用一次，不能再定义其他变量
	S s2 = { "王五", 21 };
	printf("%s %d\n", s2.name, s2.age);
	// 但对于typedef重命名的结构体类型，可以定义多个变量
	p = &x;
	printf("%s %d\n", p->name, p->age);
	// 两个匿名结构体类型的成员变量即便完全相同，也会被编译器认为是不同的类型

	// 结构体的内存对齐
	printf("%zu\n", sizeof(struct X));
	// 按理来说，结构体X的大小应该是 1+4+8=13 字节，但实际上？
	printf("%zu\n", sizeof(struct Y));
	// 按理来说，结构体Y的成员变量与结构体X的相同，那两个应该是相同大小，但实际上？

	// offsetof宏，用于计算结构体成员相对于结构体首地址的偏移量
	printf("%zu ", offsetof(struct X, c));
	printf("%zu ", offsetof(struct X, x));
	printf("%zu\n", offsetof(struct X, d));
	printf("\n");
	printf("%zu ", offsetof(struct Y, c));
	printf("%zu ", offsetof(struct Y, d));
	printf("%zu\n", offsetof(struct Y, y));

	// #pragma pack(n)指令，用于设置结构体的内存对齐方式，n表示对齐的字节数
	printf("%zu\n", sizeof(struct Z));

	// 位段与结构体的区别
	printf("%zu\n", sizeof(struct A));
	printf("%zu\n", sizeof(struct B));

	// 位段成员在内存中的存储方式
	struct C c1 = { 0 };
	c1.a = 2;
	c1.b = 5;
	c1.c = 9;
	c1.d = 19;

	// 位段成员的赋值
	struct C c2 = { 0 };
	//scanf("%d", &c2.a);
	// 由于位段成员可能几个共用一个字节，所以每个位段成员没有自己的地址，
	// 那就不能对位段成员使用&操作符，也就无法通过scanf函数直接给位段成员赋值
	int a = 0;
	scanf("%d", &a);
	c2.a = a;
	// 借助中间变量就可以正常给位段成员赋值

	return 0;
}
*/
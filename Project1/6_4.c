/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
		 //int* arr == arr[]
void test1(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", *(arr + i));
					//*(arr+i) == arr[i]
	}
	printf("\n");
}
		 //int (*arr)[5] == arr[][5]
void test2(int (*arr)[5], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", *(*(arr + i) + j));
						//*(*(arr+i)+j) == arr[i][j]
		}
		printf("\n");
	}
}
void test() {
	printf("hehe\n");
}
int add(int x, int y) {
	return x + y;
}
int sub(int x, int y) {
	return x - y;
}
int mul(int x, int y) {
	return x * y;
}
int div(int x, int y) {
	return x / y;
}
typedef unsigned long long ull;	// typedef 原数据类型 新命名;
typedef int (*PA)[5];
typedef void (*PFf)();
typedef int (*PF)(int, int);

int main() {
	
	// 字符指针变量
	char ch = 'w';
	char* pc = &ch;
	printf("%p\n", pc);
	printf("%c\n", *pc);
	const char* ps = "abcdef";
	//字符串"abcdef"是常量字符串，当我们将其赋值给指针变量ps时，
	//实际上获取的是这个字符串的首字符地址，也就是字符a的地址
	printf("%c\n", *ps);
	//我们可以通过查看指针解引用操作后获得的字符是否是a来判断
	printf("%s\n", ps);
	//如果想要打印整个字符串就使用%s的格式，且此时ps不做解引用操作
	//*ps = 'w';
	
	// 字符指针变量与数组首地址的比较
	char str1[] = "Hello C";
	char str2[] = "Hello C";
	char* str3 = "Hello C";
	char* str4 = "Hello C";
	if (str1 == str2)
		printf("Yes!\n");
	else
		printf("No!\n");
	if (str3 == str4)
		printf("Yes!\n");
	else
		printf("No!\n");

	// 数组指针变量
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int* p[10] = &arr;
	printf("%p\n", p);
	// p = &arr，此时arr理解为整个数组，整个数组的起始地址就是&arr[0]
	printf("%p\n", p + 1);
	// 由于arr作为整个数组,在偏移时一次会跨过一个数组长度，所以p+1 = &arr[10]
	printf("%p\n", *p);
	// *p = arr，解引用后获得的是数组的首地址，也就是&arr[0]
	printf("%p\n", *p + 1);
	// 解引用后arr表示的是数组的首地址，在偏移时一次会跨过一个类型长度，所以*p+1 = &arr[1]

	// 二维数组传参的本质也是传递了数组的首地址，但此时是数组指针变量
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	test1(arr1, sz);
	int arr2[3][5] = { {1,2,3,4},{5,6,7},{8,9} };
	int n = sizeof(arr2) / sizeof(arr2[0]);
	int m = sizeof(arr2[0]) / sizeof(arr2[0][0]);
	test2(arr2, n, m);

	// 函数指针变量
	void (*p1)() = &test;
	void (*p2)() = test;
	printf("%p\n", p1);
	printf("%p\n", p1 + 1);
	printf("%p\n", p2);
	printf("%p\n", p2 + 1);
	printf("%p\n", *p1);
	printf("%p\n", *p2);

	// 使用函数指针变量调用函数
	int a = 10, b = 20;
	int c = add(a, b);
	int (*p)() = add;
	int d = (*p)(a, b);
	//int d = p(a, b);
	printf("c=%d\n", c);
	printf("d=%d\n", d);

	// typedef 关键字的使用方法
	unsigned long long n = 1e10 + 8;
	ull m = 2e10 - 7;
	int arr[5] = { 1,2,3,4,5 };
	int (*p1)[5] = &arr;
	PA p2 = &arr;
	printf("p1=%p\n", p1);
	printf("p2=%p\n", p2);
	void (*p3)() = test;
	PFf p4 = test;
	printf("p3=%p\n", p3);
	printf("p4=%p\n", p4);

	// 函数指针数组
	PF arr[4] = { add,sub,mul,div };
	
	return 0;
}
*/
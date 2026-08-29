/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//已知在x86环境下，下面这个结构体大小为20个字节
struct test {
	int num;
	char* name;
	short date;
	char ch[2];
	short base[4];
}*p = (struct test*)0x100000;

int main() {

	// sizeof 与 strlen 的区别
	int a = 10;
	printf("%zu\n", sizeof(a));
	int arr[5] = { 1,2,3,4,5 };
	printf("%zu\n", sizeof(arr));
	char arr1[4] = { 'a','b','c','d' };
	char arr2[] = "abcd";
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	printf("%d\n", sizeof(arr1));
	// arr1数组四个元素，每个元素都是char类型，总共占据4字节大小的内存空间，
	printf("%d\n", sizeof(arr2));
	// arr2数组看上去也是四个元素，但字符串末尾有隐藏的'\0'，所以占据5字节大小的内存空间，
	printf("%d\n", len1);
	// 利用strlen函数求arr1数组的字符个数，由于此时数组中没有'\0'存在，就会越界访问，
	printf("%d\n", len2);
	// 利用strlen函数求arr2数组的字符个数，碰到末尾隐藏的'\0'后停止，所以字符个数为4

	// sizeof 与指针
	int arr[] = { 1,2,3,4,5 };
	printf("%d\n", sizeof(arr));
	printf("%d\n", sizeof(*&arr));
	printf("%d\n", sizeof(&arr));
	printf("%d\n", sizeof(arr + 1));
	printf("%d\n", sizeof(&arr + 1));
	printf("%d\n", sizeof(*arr));
	printf("%d\n", sizeof(arr[1]));
	printf("%d\n", sizeof(arr[1] + 1));

	int arr[3][4] = { {1,2,3},{4,5},{6} };
	printf("%d\n", sizeof(arr));
	printf("%d\n", sizeof(arr[1]));
	printf("%d\n", sizeof(arr[1][1]));
	printf("%d\n", sizeof(arr+1));
	printf("%d\n", sizeof(arr[1]+1));
	printf("%d\n", sizeof(arr[1][1]+1));
	printf("%d\n", sizeof(&arr + 1));
	printf("%d\n", sizeof(&arr[1] + 1));
	printf("%d\n", sizeof(&arr[1][1] + 1));
	printf("%d\n", sizeof(*arr + 1));
	printf("%d\n", sizeof(*arr[1] + 1));
	printf("%d\n", sizeof(*(arr + 1)));
	printf("%d\n", sizeof(*(arr[1] + 1)));

	// strlen 与指针
	char arr[] = "abcdef";
	printf("%d\n", strlen(arr));
	printf("%d\n", strlen(*&arr));
	printf("%d\n", strlen(&arr));
	printf("%d\n", strlen(arr + 1));
	printf("%d\n", strlen(&arr + 1));
	printf("%d\n", strlen(&arr[1] + 1));
	//printf("%d\n", strlen(*arr));
	//printf("%d\n", strlen(arr[1]));
	//printf("%d\n", strlen(arr[1] + 1));
	//*(arr + 1) == arr[1] == 'b' == 98
	//strlen接收的是地址，当我们把98这个值作为地址传入时，在x86的32位环境下，
	//strlen最开始的起始地址就是0x00000062，此时strlen成了野指针，程序也就出错了

	char* p = "abcdef";
	printf("%d\n", strlen(p));
	printf("%d\n", strlen(*&p));
	printf("%d\n", strlen(&p));
	printf("%d\n", strlen(p + 1));
	printf("%d\n", strlen(&p + 1));
	printf("%d\n", strlen(&p[1] + 1));
	//printf("%d\n", strlen(*p));
	//这里程序依旧会报错，报错原因就不再重复了，和之前是一样的

	// 与指针有关的一系列题目
	int arr[5] = { 1,2,3,4,5 };
	int* p = (int*)(&arr + 1);
	printf("%d %d\n", *(arr + 1), *(p - 1));

	printf("%p\n", p + 0x1);
	printf("%p\n", (unsigned long long)p + 0x1);
	printf("%p\n", (unsigned int*)p + 0x1);

	int arr[3][2] = { (1,2),(3,4),(5,6) };
	int* p = arr[0];
	printf("%d\n", p[2]);

	// 在x86环境下运行
	int arr[5][5] = { 0 };
	int(*p)[4];
	p = arr;
	printf("%p %d\n", &p[4][2] - &arr[4][2], &p[4][2] - &arr[4][2]);

	int arr[2][3] = { 1,2,3,4,5,6 };
	int* p1 = (int*)(&arr + 1);
	int* p2 = (int*)(*(arr + 1));
	printf("%d %d\n", *(p1 - 1), *(p2 - 1));

	char* arr[] = { "Hello","C","and","C++" };
	char** ps = arr;
	ps++;
	printf("%s\n", *ps);

	char* c[] = { "one","two","three","four" };
	char** pc[] = { c + 3,c + 2,c + 1,c };
	char*** ppc = pc;
	printf("%s\n", **++ppc);
	printf("%s\n", *-- * ++ppc + 2);
	printf("%s\n", *ppc[-2] + 3);
	printf("%s\n", ppc[-1][-1] + 1);

	return 0;
}
*/
//-4的原码：1000 0000 0000 0000 0000 0000 0000 0100
//-4的反码：1111 1111 1111 1111 1111 1111 1111 1011
//-4的补码：1111 1111 1111 1111 1111 1111 1111 1100
//			  F    F    F    F    F    F    F    C
//%d 打印时是转原码形式输出，且是十进制形式，那就是 -4
//%p 打印时是按补码形式输出，且是十六进制形式，那就是 FFFFFFFC


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	/*	取地址操作符&与解引用操作符*
	int a = 10;
	int* p1 = &a;
	printf("%p\n", p1);
	printf("%p\n", &a);
	printf("%d\n", *p1);
	printf("%d\n", a);
	int *p2 = &a;
	*p2 = 20;
	printf("%p\n", p2);
	printf("%p\n", &a);
	printf("%d\n", *p2);
	printf("%d\n", a);
	*/
	/*	指针变量大小测试
	printf("%zu\n", sizeof(char*));
	printf("%zu\n", sizeof(int*));
	printf("%zu\n", sizeof(long long*));
	printf("%zu\n", sizeof(float*));
	printf("%zu\n", sizeof(double*));
	*/
	/*	指针变量对解引用操作的影响
	int a = 0x1234678;
	char* p = &a;
	*p = 0;
	*/
	/*	指针变量对地址偏移的影响
	int a = 0x12345678;
	int* p1 = &a;
	printf("p1原本=%p\n", p1);
	p1 += 1;
	printf("p1偏移=%p\n", p1);
	printf("\n");
	char* p2 = &a;
	printf("p2原本=%p\n", p2);
	p2 += 1;
	printf("p2偏移=%p\n", p2);
	*/
	/*	void* 指针
	int a = 0x12345678;
	//char* p = &a;
	void* p = &a;
	*p = 0;
	p += 1;
	*/
	return 0;
}


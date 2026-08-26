/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int Strlen(char* p) {
	char* s = p;
	while (*p != '\0')//while(*p) '\0'的ASCII值为0 
	{
		p++;
	}
	int len = p - s;
	return len;
}

int main() {

	// 取地址操作符&与解引用操作符*
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
	
	// 指针变量大小测试
	printf("%zu\n", sizeof(char*));
	printf("%zu\n", sizeof(int*));
	printf("%zu\n", sizeof(long long*));
	printf("%zu\n", sizeof(float*));
	printf("%zu\n", sizeof(double*));
	
	// 指针变量对解引用操作的影响
	int a = 0x1234678;
	char* p = &a;
	*p = 0;
	
	// 指针变量对地址偏移的影响
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
	
	// void* 指针
	int a = 0x12345678;
	//char* p = &a;
	void* p = &a;
	*p = 0;
	p += 1;
	
	char a = 0;
	scanf("%c", &a);
	printf("%c\n", a);
	char arr[10] = { '\0' };
	scanf("%s", arr);
	printf("%s\n", arr);

	// 指针与整数相加减
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int* p = arr;
	for (int i = 0; i < 10; i++) {
		printf("%d ", *p);
		p++;
	}
	printf("\n");
	p = arr;
	for (int i = 0; i < 10; i++) {
		printf("%d ", *(p + i));
	}
	printf("\n");
	
	// 指针与指针相减
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int* p1 = arr;
	int* p2 = &arr[9];
	printf("%d\n", p2 - p1);
	char ch[5] = { 'a','b','c','d','e' };
	char* p3 = ch;
	printf("%d\n", p3 - p1);
	
	// 模拟 strlen 函数
	char arr[] = "abcdef";
	int len1 = strlen(arr);
	printf("%d\n", len1);
	int len2 = Strlen(arr);
	printf("%d\n", len2);
	
	// 指针的关系运算
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,0 };
	for (int* p1 = arr1; p1 < &arr1[10]; p1++) {
		printf("%d ", *p1);
	}
	printf("\n");
	int arr2[] = { 1,2,3,4,5,6 };
	int n = sizeof(arr2) / sizeof(arr2[0]);
	int* p2 = arr2;
	while (p2 < arr2 + n) {
		printf("%d ", *p2);
		p2++;
	}
	printf("\n");
	
	return 0;
}
*/

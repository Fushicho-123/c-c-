
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int test() {
	int num = 10;
	return &num;
}
int main() {
	// const 修饰的变量为常变量，虽然常变量无法被修改，但本质上仍然是变量
	const int a = 10;
	//a = 100;
	int arr1[10] = { 0 };
	//int arr2[a] = { 0 };
	// const 修饰指针变量放在 * 左侧时，修饰的是指针变量指向的内容，
	// 此时指针变量指向的内容无法被修改，但指针变量指向的对象可以改变
	// const 修饰指针变量放在 * 右侧时，修饰的是指针变量本身，
	// 此时指针变量指向的对象无法被修改，但指针变量指向的内容可以改变
	const int* const p = &a;
	//*p = 100;
	printf("%d\n", a);
	int b = 20;
	//p = &b;
	printf("%p\n", p);
	/*
	// 指针没有初始化
	int a = 10;
	int* p = &a;
	*p = 20;
	int* p;
	*p = 20;
	
	// 指针越界访问
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int* p = arr;
	for (int i = 0; i <= 10; i++) {
		*p = 1;
		printf("%d ", *p);
		p++;
	}
	
	// 指针指向的空间被释放
	int* p = test();
	printf("haha\n");
	printf("%d\n", *p);
	*/

	return 0;
}

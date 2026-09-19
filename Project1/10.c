/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
void test(int** ptr) {
	for (int i = 0; i < 10; i++) {
		*(*ptr + i) = i + 1;
	}
	free(*ptr);
}
void test1(void) {
	int* p = (int*)malloc(40);
	if (p == NULL) {
		perror("error");
		return -1;
	}
	for (int i = 0; i < 10; i++) {
		*(p + i) = i + 1;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", p[i]);
	}

}
void getspace(void** p) {
	*p = (char*)malloc(100);
}
void* getspace1(void* p) {
	p = (char*)malloc(100);
	return p;
}
void print() {
	char* pc = NULL;
	getspace(&pc);
	if (pc == NULL) {
		perror("error");
		return -1;
	}
	strcpy(pc, "Hello");
	printf(pc);
	free(pc);
	pc = NULL;
}
void* init(void) {
	static char arr[] = "ABCDE";
	return arr;
}
void* init1(void* p) {
	p = (char*)malloc(100);
	for (int i = 0; i < 5; i++) {
		*((char*)p + i) = 'A' + i;
	}
	return p;
}
void print1() {
	char* pc = NULL;
	pc = init();
	if (pc == NULL) {
		perror("error");
		return -1;
	}
	printf("haha\n");
	printf(pc);
}
void print2() {
	char* pc = NULL;
	pc = init1(pc);
	if (pc == NULL) {
		perror("error");
		return -1;
	}
	printf("haha\n");
	for (int i = 0; i < 5; i++) {
		printf("%c", pc[i]);
	}
	free(pc);
	pc = NULL;
}
void print3() {
	char* pc = (char*)malloc(100);
	strcpy(pc, "Hello");
	free(pc);
	pc = NULL;
	if (pc != NULL) {
		strcat(pc, "World");
		printf(pc);
	}
}
struct test {
	int n;
	int arr[];// 柔性数组
};
struct test1 {
	int n;
	int* arr;
};

int main() {

	// malloc 函数
	// int arr[5] = { 1,2,3,4,5 };
	// 以往创建数组是在栈区上开辟一块固定大小的内存空间
	int* p = (int*)malloc(20);
	if (p == NULL) {
		perror("error");
		// 输出错误信息
	}
	else {
		for (int i = 0; i < 5; i++) {
			*(p + i) = i + 1;
		}
	}
	for (int i = 0; i < 5; i++) {
		printf("%d ", p[i]);
	}
	printf("\n");
	free(p);
	p = NULL;

	// calloc 函数
	int* p = (int*)calloc(5, 4);
	if (p == NULL) {
		perror("error");
		// 输出错误信息
	}
	else {
		for (int i = 0; i < 5; i++) {
			*(p + i) = i + 1;
		}
	}
	for (int i = 0; i < 5; i++) {
		printf("%d ", p[i]);
	}
	printf("\n");
	free(p);
	p = NULL;

	// realloc 函数
	int* p = (int*)realloc(NULL, 20);
	if (p == NULL) {
		perror("error");
		// 输出错误信息
	}
	else {
		for (int i = 0; i < 5; i++) {
			*(p + i) = i + 1;
		}
	}
	for (int i = 0; i < 5; i++) {
		printf("%d ", p[i]);
	}
	printf("\n");
	int* np = (int*)realloc(p, 40);
	if (np == NULL) {
		perror("error");
	}
	else {
		for (int i = 5; i < 10; i++) {
			*(np + i) = i + 1;
		}
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", np[i]);
	}
	printf("\n");
	free(np);
	np = NULL;

	// 未经检查对NULL指针解引用操作
	int* p = (int*)malloc(20 * INT_MAX);
	for (int i = 0; i < 10; i++) {
		*(p + i) = i + 1;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", p[i]);
	}
	free(p);
	p = NULL;

	// 在动态内存空间中越界访问
	int* p = (int*)malloc(40);
	if (p == NULL) {
		perror("error");
		return -1;
	}
	for (int i = 0; i < 10; i++) {
		*(p + i) = i + 1;
	}
	for (int i = 0; i <= 10; i++) {
		printf("%d ", p[i]);
	}
	free(p);
	p = NULL;

	// 访问已被释放的动态内存空间
	int* p = (int*)malloc(40);
	if (p == NULL) {
		perror("error");
		return -1;
	}
	test(&p);
	for (int i = 0; i < 10; i++) {
		printf("%d ", p[i]);
	}

	// 忘记释放开辟的动态内存空间
	test1();

	// 多次释放同一块动态内存空间
	int* p = malloc(20);
	if (p == NULL) {
		perror("error");
		return -1;
	}
	int* np = realloc(p, 40);
	if (np == NULL) {
		perror("error");
		return -1;
	}
	for (int i = 0; i < 10; i++) {
		*(np + i) = i + 1;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", np[i]);
	}
	free(np);
	np = NULL;
	free(p);
	p = NULL;

	// 只释放开辟的动态内存空间的部分
	// 或释放的不是开辟的动态内存空间
	int* p = malloc(20);
	if (p == NULL) {
		perror("error");
		return -1;
	}
	int* np = realloc(p, 40);
	if (np == NULL) {
		perror("error");
		return -1;
	}
	for (int i = 0; i < 10; i++) {
		*(np + i) = i + 1;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", np[i]);
	}
	np++;
	free(np);
	np = NULL;

	// 对栈区空间使用free函数
	int arr[5] = { 0 };
	int* p = arr;
	for (int i = 0; i < 5; i++) {
		*(p + i) = i + 1;
	}
	for (int i = 0; i < 5; i++) {
		printf("%d ", p[i]);
	}
	free(p);
	p = NULL;

	// 行参与实参关系
	print();

	// 野指针处理
	// static修饰局部数组使其生命周期与全局数组一样
	print1();
	// 动态管理下不主动使用free函数释放空间，与全局变量类似
	print2();
	// 用完动态管理及时使用free函数释放空间并将指针置空
	print3();

	// 柔性数组的使用
	struct test T = { 0 };
	printf("%zu\n", sizeof(T));
	struct test* p = (struct test*)malloc(sizeof(T) + 5 * sizeof(int));
	if (p == NULL) {
		perror("error");
		return -1;
	}
	p->n = 100;
	for (int i = 0; i < 5; i++) {
		p->arr[i] = i + 1;
	}
	struct test* np = (struct test*)realloc(p, sizeof(T) + 10 * sizeof(int));
	if (np == NULL) {
		perror("error");
		return -1;
	}
	p = np;
	np = NULL;
	for (int i = 5; i < 10; i++) {
		p->arr[i] = i + 1;
	}
	free(p);
	p = NULL;

	// 使用指针实现类柔性数组的效果
	struct test1 T = { 0 };
	struct test1* p = (struct test1*)malloc(sizeof(T));
	if (p == NULL) {
		perror("error");
		return -1;
	}
	p->n = 100;
	int* np = (int*)malloc(5 * sizeof(int));
	if (np == NULL) {
		perror("error");
		return -1;
	}
	p->arr = np;
	np = NULL;
	for (int i = 0; i < 5; i++) {
		p->arr[i] = i + 1;
	}
	int* np1 = (int*)malloc(10 * sizeof(int));
	if (np1 == NULL) {
		perror("error");
		return -1;
	}
	p->arr = np1;
	np1 = NULL;
	for (int i = 5; i < 10; i++) {
		p->arr[i] = i + 1;
	}
	free(p->arr);
	p->arr = NULL;
	free(p);
	p = NULL;

	return 0;
}
*/

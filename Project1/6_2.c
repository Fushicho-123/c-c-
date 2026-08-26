/*
#define NDEBUG
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
int test() {
	int num = 10;
	return &num;
}
size_t Strlen(const char* p) {
	const char* s = p;
	assert(p != NULL);
	while (*p != '\0') {
		p++;
	}
	return p - s;
}
void swap1(int x, int y) {
	int z = x;
	x = y;
	y = z;
}
void swap2(int* p1, int* p2) {
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
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

	// 指针没有初始化
	int a = 10;
	int* p1 = &a;
	*p1 = 20;
	int* p1;
	*p1 = 20;

	// 指针越界访问
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int* p2 = arr;
	for (int i = 0; i <= 10; i++) {
		*p2 = 1;
		printf("%d ", *p2);
		p2++;
	}

	// 指针指向的空间被释放
	int* p3 = test();
	printf("haha\n");
	printf("%d\n", *p3);
	
	// 使用 NULL 初始化指针
	int a = 10;
	int* p1 = &a;
	int* p2 = NULL;
	
	// 使用 NULL 指针防止越界
	int* p = NULL;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	p = arr;
	for (int i = 0; i <= 10; i++) {
		if (p >= arr + n)
			p = NULL;
		if (p != NULL) {
			*p = 1;
			printf("%d ", *p);
			p++;
		}
	}
	
	// assert 断言
	int* p = NULL;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	p = arr;
	for (int i = 0; i < 10; i++) {
		if (p >= arr + n)
			p = NULL;
		assert(p != NULL);
		*p = 1;
		printf("%d ", *p);
		p++;
	}
	
	// 使用 const 与 assert 改进 Strlen 函数
	char arr[] = "abcdefg";
	size_t len = Strlen(arr);
	printf("%zu\n", len);

	// 传值调用与传址调用
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);
	printf("交换前：a=%d，b=%d\n", a, b);
	swap1(a, b);
	printf("传值调用交换后：a=%d，b=%d\n", a, b);
	swap2(&a, &b);
	printf("传址调用交换后：a=%d，b=%d\n", a, b);

	return 0;
}
*/


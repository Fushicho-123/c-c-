/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void test(int arr[], int n) {
	//int n = sizeof(arr) / sizeof(arr[0]);
	//printf("在函数内求：%d\n", n);
	for (int i = 0; i < n; i++) {
		printf("%d ", *(arr + i));
	}
}
void mppx(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int flag = 1;
		for (int j = 0; j < n - i; j++) {
			if (arr[j] > arr[j + 1]) {
				flag = 0;
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
		if (flag)
			break;
		printf("第%d次排序：", i);
		for (int k = 0; k < n; k++) {
			printf("%d ", arr[k]);
		}
		printf("\n");
	}
}

int main() {
	
	// 数组名 arr 的不同理解，sizeof 与 &arr 要理解为整个数组
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	printf("&arr[0] =%p\n", &arr[0]);
	printf("arr[0]  =%d\n", arr[0]);
	printf("arr     =%p\n", arr);
	printf("*arr    =%d\n", *arr);
	printf("sizeof(arr)                  =%zu\n", sizeof(arr));
	printf("sizeof(arr) / sizeof(arr[0]) =%d\n", sizeof(arr) / sizeof(arr[0]));
	printf("&arr    =%p\n", &arr);
	printf("&arr[0]    =%p\n", &arr[0]);
	printf("&arr[0] +1 =%p\n", &arr[0] + 1);
	printf("arr +1     =%p\n", arr + 1);
	printf("&arr +1    =%p\n", &arr + 1);
	printf("&arr[9]    =%p\n", &arr[9]);

	// 数组访问的书写形式
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//int* p = arr;
	for (int i = 0; i < n; i++) {
		printf("%d ", i[arr]);
	}
	// arr[i] == *(arr+i) == *(p+i)
	// *(arr+i) == *(i+arr)
	// arr[i] == i[arr]
	
	// 一维数组传参的本质就是传递了数组的首地址
	int arr[5] = { 1,2,3,4,5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("在函数外求：%d\n", n);
	test(arr, n);

	// 冒泡排序：数组内相邻元素两两比较
	int arr[10] = { 0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("排序前的数组：");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	mppx(arr, n);
	printf("排序后的数组：");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	// 二级指针
	int a = 10;
	int* pa = &a;// 一级指针
	int** paa = &pa;// 二级指针
	printf("pa    =%p\n", pa);
	printf("paa   =%p\n", paa);
	printf("*paa  =%p\n", *paa);
	printf("**paa =%d\n", **paa);
	// *paa == pa，*pa == a ==> **paa == a

	// 利用指针模拟二维数组
	int arr1[5] = { 1,2,3 };
	int arr2[5] = { 4,5,6,7 };
	int arr3[5] = { 8 };
	int* arr[3] = { arr1,arr2,arr3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int m = sizeof(arr1) / sizeof(arr1[0]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", arr[i][j]);
			// *(arr+i) == arr1，*(arr1+j) == 1 ==> *(*(arr+i)+j)
			// arr[i] == *(arr+i) ==> arr[i] == arr1
			// arr1[j] == *(arr1+j) ==> arr[i][j]
		}
		printf("\n");
	}

	return 0;
}
*/

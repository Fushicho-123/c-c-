/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int(*CMP)(void*, void*);
int cmp_int(void* p1, void* p2) {
	//	return (*(int*)p1 - *(int*)p2);
	//  直接做差通常没有问题，但对于临界情况会出问题，比如一个极大的数减去一个极小的数
	//	为了避免上述情况产生，我们也可以采用下面这样的书写方式
	if (*(int*)p1 > *(int*)p2)
		return 1;
	else if (*(int*)p1 < *(int*)p2)
		return -1;
	else
		return 0;

}
void swap(void* p1, void* p2, size_t w) {
	for (int i = 0; i < w; i++) {
		char tmp = *((char*)p1 + i);
		*((char*)p1 + i) = *((char*)p2 + i);
		*((char*)p2 + i) = tmp;
	}
}
void Qsort(void* arr, size_t n, size_t w, CMP cmp) {
	for (int i = 1; i < n; i++) {
		int flag = 1;
		for (int j = 0; j < n - i; j++) {
			if (cmp((char*)arr + j * w, (char*)arr + (j + 1) * w) > 0) {
				flag = 0;
				swap((char*)arr + j * w, (char*)arr + (j + 1) * w, w);
			}
		}
		if (flag)
			break;
	}
}

int main() {

	// qsort 函数的研究与模拟
	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int w = sizeof(arr[0]);
	printf("排序前：");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	Qsort(arr, n, w, cmp_int);
	printf("排序后：");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
*/

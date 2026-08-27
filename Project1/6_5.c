
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int(*CMP)(void*, void*);
int cmp_int(void* p1, void* p2) {
	return (*(int*)p1 - *(int*)p2);
}
void Qsort(void* arr, size_t n, size_t w, CMP cmp) {
	for (int i = 1; i < n; i++) {
		int flag = 1;
		for (int j = 0; j < n - i; j++) {
			if (cmp((int*)arr + j, (int*)arr + (j + 1)) > 0) {
				flag = 0;
				int tmp = *((int*)arr + j);
				*((int*)arr + j) = *((int*)arr + (j + 1));
				*((int*)arr + (j + 1)) = tmp;
			}
		}
		if (flag)
			break;
	}
}
int main() {
	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int w = sizeof(arr[0]);
	printf("≈≈–Ú«∞£∫");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	Qsort(arr, n, w, cmp_int);
	printf("≈≈–Ú∫Û£∫");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}


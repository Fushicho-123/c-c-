
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "clean.h"
void menu() {
	printf("*--*--*--*--*--*--*\n");
	printf("*- 1.add   2.sub -*\n");
	printf("*- 3.mul   4.div -*\n");
	printf("*- 0.exit        -*\n");
	printf("*--*--*--*--*--*--*\n");
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
int cal(int(*p)(int, int)) {
	int x = 0, y = 0;
	printf("请输入两个操作数：");
	scanf("%d %d", &x, &y);
	CleanBur();
	int z = p(x, y);
	printf("计算结果是%d\n", z);
}
/*
int main() {
	int sz = 0;
	do {
		menu();
		printf("请选择操作：");
		scanf("%d", &sz);
		CleanBur();
		switch (sz) {
		case 1:
			cal(add);
			break;
		case 2:
			cal(sub);
			break;
		case 3:
			cal(mul);
			break;
		case 4:
			cal(div);
			break;
		case 0:
			printf("欢迎下次使用\n");
			break;
		default:
			printf("无对应操作选项，请重新选择！\n");
			break;
		}
	} while (sz);
	return 0;
}
*/
/*
typedef int (*PF)(int, int);
int main() {
	PF arr[5] = { NULL,add,sub,mul,div };
	int sz = 0;
	int x = 0, y = 0;
	do {
		menu();
		printf("请选择操作：");
		scanf("%d", &sz);
		CleanBur();
		if (sz > 0 && sz < 5) {
			printf("请输入两个操作数：");
			scanf("%d %d", &x, &y);
			CleanBur();
			int z = arr[sz](x, y);
			printf("计算结果是%d\n", z);
		}
		else if (sz == 0) {
			printf("欢迎下次使用\n");
		}
		else {
			printf("无对应操作选项，请重新选择！\n");
		}
	} while (sz);
	return 0;
}
*/
/*
int main() {
	int sz = 0;
	int x = 0, y = 0;
	do {
		menu();
		printf("请选择操作：");
		scanf("%d", &sz);
		CleanBur();
		switch (sz) {
		case 1: {
			printf("请输入两个操作数：");
			scanf("%d %d", &x, &y);
			CleanBur();
			int z = add(x, y);
			printf("计算结果是%d\n", z);
			break;
		}
		case 2: {
			printf("请输入两个操作数：");
			scanf("%d %d", &x, &y);
			CleanBur();
			int z = sub(x, y);
			printf("计算结果是%d\n", z);
			break;
		}
		case 3: {
			printf("请输入两个操作数：");
			scanf("%d %d", &x, &y);
			CleanBur();
			int z = mul(x, y);
			printf("计算结果是%d\n", z);
			break;
		}
		case 4: {
			printf("请输入两个操作数：");
			scanf("%d %d", &x, &y);
			CleanBur();
			int z = div(x, y);
			printf("计算结果是%d\n", z);
			break;
		}
		case 0: {
			printf("欢迎下次使用\n");
			break;
		}
		default: {
			printf("无对应操作选项，请重新选择！\n");
			break;
		}
		}
	} while (sz);
	return 0;
}
*/
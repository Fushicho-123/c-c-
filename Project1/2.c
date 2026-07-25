
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(){
	//if else 语句
	int year = 0;
	scanf("%d", &year);
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
		printf("%d年是闰年\n", year);
	else
		printf("%d年不是闰年\n", year);
	int sz = 0;
	scanf("%d", &sz);
	if (sz > 0)
		if (sz % 2 == 1)
			printf("haha\n");
		else
			printf("hehe\n");
	//else永远与自己最近的一个if进行匹配

	int i = 0, a = 0, b = 2, c = 3, d = 4;
	i = a++ && ++b && d++;
	printf("%d %d %d %d %d\n", i, a, b, c, d);
	//&&运算符当两侧都为真时结果才为真，当左侧为假时直接短路结束运算
	//||运算符两侧有一侧为真结果就为真，当左侧为真时直接短路结束运算

	//switch 语句
	int sz = 0;
	scanf("%d", &sz);
	switch (sz %= 3) {
		case 0:
			printf("余数为0\n");
			break;
		case 1:
			printf("余数为1\n");
			break;
		case 2:
			printf("余数为2\n");
			break;
		default:
			printf("没有结果\n");
			break;
	}
	//case语句如果没有break，结果将从符合条件的语句开始一直执行到结束

	//while 语句
	int i = 0;
	while (i <= 10) {
		i++;
		if (i == 5)
			continue;
		printf("%d ", i);
	}
	printf("\n");

	//for 语句
	int sum = 0;
	for (int i = 3; i <= 100; i += 3)
		sum+=i;
	printf("%d", sum);
	for (int i = 101; i < 200; i+=2) {
		int flag = 1;
		for (int j = 2; j*j <= i; j++) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}
		if (flag)
			printf("%d是质数\n", i);
	}
	//for(循环初始化;循环继续条件;循环步进条件)，三个条件并非必须，可以视情况省略

	//break用于跳出整个循环，直接终止循环，在有多层循环时一个break只能跳出自己所在这一层循环
	//continue用于跳出本次循环，下一个循环继续直到结束，continue无法用于switch语句

	//goto 语句
	int i = 0, j = 0, k = 0;
	for (i = 1; i <= 10; i++) {
		for (j = i; j <= 20; j++) {
			for (k = j; k <= 30; k++) {
				if (k == i + j)
					goto next;
			}
		}
	}
next:
	printf("%d = %d + %d\n", k, i, j);
	//goto语句可以直接跳转到对应标记位置执行后续语句，
	//在有多层循环时利用goto语句可以快速从内层循环跳出来
	return 0;
}

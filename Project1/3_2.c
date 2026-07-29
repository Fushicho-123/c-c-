/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"sub.h"//自定义库函数的头文件使用""，可以调用自定义库里面的所有相关函数
extern int add(int x, int y);//extern引用外部函数

int main(){

	extern int A1;//extern引用外部变量
	int A2 = 30;
	int A3 = add(A1, A2);
	printf("%d\n", A3);
	int A4 = sub(A1, A2);
	printf("%d\n", A4);
	return 0;
}
*/
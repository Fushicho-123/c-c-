/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<windows.h>
//自定义函数:
//返回值类型 函数名(参数){	函数头
//	函数体
//}
void arrfz(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		arr[i] = 1;
	}
}
int is_run(int year) {
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
		return 1;
	else
		return 0;
}
int get_days(int year, int month) {
	int arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int day = arr[month];
	if (is_run(year) && month == 2)//函数的嵌套调用
		day += 1;
	return day;
}
int add(int x, int y) {
	return x + y;
}
int mul(int x, int y) {
	return x * y;
}
int factorial(int n) {
	if (n == 0)
		return 1;
	return factorial(n - 1) * n;
}
int fbnq1(int n) {
	if (n <= 2)
		return 1;
	return fbnq1(n - 1) + fbnq1(n - 2);
}
int fbnq2(int n) {
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2) {
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
int sum(int n) {
	static int sum = 1;
	//局部变量的生命周期原本与其作用域相同，离开作用域范围，变量被销毁，生命周期结束，
	//static修饰后将局部变量的生命周期变得与全局变量相同，生命周期是整个程序，但作用域仍旧不变
	sum *= n;
	return sum;
}
int A1 = 10;
static int A2 = 10;
//全局变量具有外部链接属性，被static修饰后变为内部链接属性，仅在当下源文件内可被使用

int main(){

	// 一维数组
	int arr1[5] = { 1,2,3,4,5 };//完全初始化，为数组里每一个元素都赋上初值
	int arr2[5] = { 1 };//部分初始化，仅给数组里一部分元素赋上初值
	int arr3[] = { 1,2,3 };//若不定义数组长度，则数组大小由赋值多少决定
	// 二维数组
	int arr4[3][4] = { 1,2,3,4,2,4,6,8,3,5,7,9 };//完全初始化，为数组里每一个元素都赋上初值
	int arr5[3][4] = { {1,2},{3,4},{5,6} };//部分初始化，仅给数组里一部分元素赋上初值
	int arr6[][4] = { 1,2,3,4,5,6 };
	//二维数组可以忽略行数但不能忽略列数，赋值多少依据列数自动分配到具体行数上

	char Arr1[] = { "Hello World !!!" };
	char Arr2[] = { "###############" };
	int len = sizeof(Arr1) / sizeof(Arr1[0]) - 1;
	int s = 0, e = len-1;
	printf("%s\n", Arr2);
	while (s <= e) {
		Sleep(1000);//windows指令,让程序在休息1000ms之后继续执行
		Arr2[s] = Arr1[s];
		Arr2[e] = Arr1[e];
		printf("%s\n", Arr2);
		s++;
		e--;
	}
	
	int n = 0;
	scanf("%d", &n);
	int Arr3[n];//变长数组，根据输入的变量大小来决定数组的容量大小
	for (int i = 0; i < n; i++)
		scanf("%d", &Arr3[i]);
	int num = 0;
	scanf("%d", &num);
	int l = 0;
	int r = sizeof(Arr3) / sizeof(Arr3[0]) - 1;
	int flag = 0;
	//二分查找，仅适用于有序数组
	while (l <= r) {
		//int m = (l + r) / 2;
		int m = l + (r - l) / 2;//可以避免在较大数字运算下的数据溢出
		if (Arr3[m] > num)
			r = m - 1;
		else if (Arr3[m] < num)
			l = m + 1;
		else
		{
			flag = 1;
			printf("%d是数组中的第%d个元素\n", num, m + 1);
			break;
		}
	}
	if(!flag)
		printf("%d不是该数组中的元素\n", num);

	int arr[10];
	int len1 = sizeof(arr) / sizeof(arr[0]);
	arrfz(arr, len1);//自定义函数的调用
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
	
	int year = 0, month = 0, day = 0;
	scanf("%d %d", &year, &month);
	day = get_days(year, month);
	printf("%d年的%d月有%d天\n", year, month, day);

	int x = 0, y = 0, z = 0;
	scanf("%d %d %d", &x, &y, &z);
	int jg = mul(add(x, y), z);//函数的链式访问
	printf("%d\n",jg );
	
	int sum1 = 0;
	for (int i = 0; i <= 10; i++) {
		if (i == 0)
			sum1 = 1;
		else
			sum1 *= i;
	}
	printf("%d\n", sum1);
	int sum2 = factorial(10);//函数递归
	printf("%d\n", sum2);
	int m = 0; 
	scanf("%d", &m);
	//函数递归与循环的比较
	int jg1 = fbnq1(m);
	printf("%d\n", jg1);
	int jg2 = fbnq2(m);
	printf("%d\n", jg2);
	//当函数递归层数较多时，会大大增加程序的运行时间，严重时可能引发栈溢出的报错情况
	//但函数递归相比循环往往更易发现运行逻辑，具体使用函数递归还是循环需要视情况而定
	for (int i = 1; i <= 5; i++) {
		printf("%d ", sum(i));
	}
	printf("\n");
	return 0;
}
*/
/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int cnt = 1;

int main() {

	//limits.h储存了整数类型的取值范围，float.h储存了浮点数类型的取值范围

	size_t len;//size_t为无符号整数类型，作为sizeof的返回值类型
	short a1 = 5;
	int a2 = 7;
	printf("%zu\n", sizeof(a1 = a1 + a2));
	printf("%zu\n", sizeof(a2 = a1 - a2));
	//%zu用于打印sizeof的返回结果，sizeof不会计算表达式的结果，只会输出对应类型的字节长度

	int num = 2;
	//cnt为全局变量，num为局部变量，一般常用局部变量
	if (num == 2) {
		int num = 4;
		printf("%d\n", num);//存在多个同名局部变量时，最近优先
	}

	int b1 = 76, b2 = 13;
	int c1 = b1 / b2;//正常情况下/运算符只做整除运算
	printf("%d\n", c1);
	float c2 = b1 * 1.0 / b2;//当存在一位及以上浮点数时，计算结果为浮点型
	printf("%f\n", c2);

	//%运算符多用于获取数字的最后一位
	int sz = 1627;
	while (sz > 0) {
		int mw = sz % 10;
		sz /= 10;
		printf("%d ", mw);
	}
	printf("\n");

	printf("%d\n", 11 % -5);// 1
	printf("%d\n", -11 % 5);// -1
	printf("%d\n", -11 % -5);// -1
	//存在负数时，取模结果取决于被除数的正负性

	int a = 1;
	int b = a++;//后置++:b=a,a+=1,先赋值后自增
	int c = ++a;//前置++:a+=1,c=a,先自增后赋值
	printf("%d %d %d\n", a, b, c);
	//--同理

	printf("%5d,%-5d\n", 123,456);
	//%[n]类型，通过n控制最小位宽，默认右对齐在数据最前面补空格，-将对齐方式改为左对齐
	printf("%.2f\n", 3.1415f);
	//%.[m]类型，通过m控制小数精度，数据默认double双精度类型，数据末尾加f可以将数据转为float单精度类型
	printf("%+d\n", 10);//%+类型可让数据输出时带上正号

	//%s读取的字符串末尾会自动加上'\0'作为字符串的结束标志
	char ch1;
	scanf("%c",&ch1);//除了%c以外，其余的占位符都会自动忽略起首的空白字符
	printf("---%c---\n",ch1);
	char ch2;
	scanf(" %c", &ch2);// %c表示跳过零个或多个空白字符
	printf("---%c---\n", ch2);
	char arr[100];
	scanf("%s", arr);
	//scanf读取时会从上一次遗留的字符开始读完缓存，或遇到第一个不符合条件的字符结束
	printf("---%s---\n", arr);
	char arr1[100];
	scanf("%s",arr1);
	//scanf在读取一长串带空格的字符串时只从第一个非空白字符开始到第一个空白字符结束
	printf("%s\n", arr1);
	printf("%s\n", "hello world");
	char arr2[10];
	scanf("%5s", arr2);//%[n]s为最多读取n宽度个字符
	printf("%.3s\n", arr2);//%.[m]s为最多输出m宽度个字符
	int year = 0, month = 0, day = 0;
	scanf("%d%*c%d%*c%d", &year, &month, &day);
	//%*类型在读取后直接丢弃不存入变量，该方法的使用可避免因为输入格式问题导致的数据获取失败
	printf("%d %d %d", year, month, day);

	int js1 = 0, js2 = 0;
	while (scanf("%d %d", &js1, &js2) != EOF) {
		int js = js1 + js2;
		printf("%d\n", js);
	}
	// scanf的返回值为成功获取到的变量个数
	// EOF = end of file，是文件结束的标志，其返回值通常是-1
	// 可用于多组输入时的连续读入，在vs中需要连续三次ctrl+z+enter来结束输入

	printf("%d ", printf("%d ", 12));
	// printf的返回值为屏幕上打印的字符个数

	return 0;
}
*/
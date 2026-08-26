/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	
	// 字符指针变量
	char ch = 'w';
	char* pc = &ch;
	printf("%p\n", pc);
	printf("%c\n", *pc);
	const char* ps = "abcdef";
	//字符串"abcdef"是常量字符串，当我们将其赋值给指针变量ps时，
	//实际上获取的是这个字符串的首字符地址，也就是字符a的地址
	printf("%c\n", *ps);
	//我们可以通过查看指针解引用操作后获得的字符是否是a来判断
	printf("%s\n", ps);
	//如果想要打印整个字符串就使用%s的格式，且此时ps不做解引用操作
	//*ps = 'w';
	
	// 字符指针变量与数组首地址的比较
	char str1[] = "Hello C";
	char str2[] = "Hello C";
	char* str3 = "Hello C";
	char* str4 = "Hello C";
	if (str1 == str2)
		printf("Yes!\n");
	else
		printf("No!\n");
	if (str3 == str4)
		printf("Yes!\n");
	else
		printf("No!\n");

	return 0;
}
*/


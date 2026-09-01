/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
// strlen, strcpy, strcat, strcmp 在使用前都要引用 string.h 头文件
// strncpy, strncat, strncmp 在使用前也都要引用 string.h 头文件
#include <errno.h>
size_t Strlen(char* p) {
	if (*p == '\0')
		return 0;
	p++;
	return 1 + Strlen(p);
}
char* Strcpy(char* p2, const char* p1) {
	assert(p2 != NULL && p1 != NULL);
	char* tmp = p2;
	while (*p2++ = *p1++);
	// *p2++ -> p=p2, *p, p2++
	// 也就是先获取p2这个地址进行解引用操作，然后p2++向后偏移一个单位
	// 那把这个表达式作为while循环的判断语句时，
	// 每次拷贝结束都会判断刚刚拷贝字符的ASCII值是否为0，
	// 因为我们讲过，字符在储存时存的都是ASCII值，而'\0'的ASCII值为0，
	// 那在完成字符'\0'的拷贝后，整个循环就会终止
	return tmp;
}
char* Strncpy(char* p2, const char* p1, int n) {
	assert(p2 != NULL && p1 != NULL);
	char* tmp = p2;
	while ((n--) && (*p2++ = *p1++));
	// 判断规定长度是否大于源头字符串长度
	// 如果小于就只循环n次
	while ((n--) > 0)
		*p2++ = '\0';
	// 如果大于则通过补'\0'的方式循环完剩余次数
	return tmp;
}
char* Strcat(char* p2, const char* p1) {
	assert(p2 != NULL && p1 != NULL);
	char* tmp = p2;
	// strcat 函数与 strcpy 函数类似，也是对字符串内容做修改，
	// 只是 strcpy 函数的字符串拷贝是从目标字符串的首地址开始，
	// 而 strcat 函数的字符串拼接应从目标字符串的最后一个字符，也就是'\0'开始
	while (*p2 != '\0') {
		p2++;
	}
	// 用来找到目标字符串'\0'字符的位置
	while (*p2++ = *p1++);
	// 用来实现字符赋值操作
	return tmp;
}
char* Strncat(char* p2, const char* p1, int n) {
	assert(p2 != NULL && p1 != NULL);
	char* tmp = p2;
	while (*p2 != '\0') {
		p2++;
	}
	while ((n--) && (*p2++ = *p1++));
	*p2 = '\0';
	// 无论拼接结果如何都会在末尾补'\0'字符
	return tmp;
}
int Strcmp(const char* p1, const char* p2) {
	assert(p1 != NULL && p2 != NULL);
	while (*p1 == *p2) {
		if (*p1 == '\0')
			return 0;
		p1++;
		p2++;
	}
	return (*p1 - *p2);
}
int Strncmp(const char* p1, const char* p2, int n) {
	assert(p1 != NULL && p2 != NULL);
	while ((n--) && (*p1 == *p2)) {
		if (*p1 == '\0')
			return 0;
		p1++;
		p2++;
	}
	return (*p1 - *p2);
}
char* Strstr(const char* p1, const char* p2) {
	assert(p1 != NULL && p2 != NULL);
	const char* pc = p1;
	const char* tp1 = NULL;
	const char* tp2 = NULL;
	while (*pc != '\0') {
		tp1 = pc;
		tp2 = p2;
		while (*tp1 != '\0' && *tp2 != '\0' && *tp1 == *tp2) {
			tp1++;
			tp2++;
		}
		if (*tp2 == '\0')
			return pc;
		if (*tp1 == '\0')
			return NULL;
		pc++;
	}
	return NULL;
}

int main() {
	
	// 字符分类函数
	char c = 'A';
	int n = isupper(c);
	// 判断这个字符是否是大写字符类型
	int m = islower(c);
	// 判断这个字符是否是小写字符类型
	printf("%d %d\n", n, m);
	//如果结果为真则返回一个非零值，不是固定的1；
    //如果结果为假则返回0

	// 字符转换函数
	char c1 = 'E';
	printf("c1 = %c\n", c1);
	printf("c1 = %c\n", tolower(c1));
	char c2 = 'f';
	printf("c2 = %c\n", c2);
	printf("c2 = %c\n", toupper(c2));

	// 字符串的大小写转换
	char arr[] = "This Is An Apple";
	int len = strlen(arr);
	for (int i = 0; i < len; i++) {
		if (isupper(arr[i])) {
			arr[i] = tolower(arr[i]);
		}
	}
	for (int i = 0; i < len; i++) {
		printf("%c", arr[i]);
	}
	printf("\n");

	// strlen 函数的返回值类型 size_t 为无符号整型
	char arr1[] = "abcd";
	char arr2[] = "abcdef";
	size_t len1 = strlen(arr1);// 4
	size_t len2 = strlen(arr2);// 6
	if (len1 - len2 > 0) {
		printf("len1 比 len2 长\n");
		// 4 - 6 == -2
        // 本应该走 else 语句的，但由于 strlen 函数的返回值类型为 size_t，
        // 所以 -2 被当做是无符号整型数据时，表示的是一个极大的数
	}
	else {
		printf("len1 比 len2 短\n");
	}

	// strlen 函数的模拟 (递归实现)
	char arr[] = "abcdef";
	size_t len = Strlen(arr);
	printf("%zu\n", len);

	// strcpy 函数
	char arr1[] = "abcdef";
	char arr2[20] = "----------";
	*arr2 = *arr1;
	printf("%s\n", arr2);

	char arr1[] = "abcdef";
	char arr2[20] = "----------";
	strcpy(arr2, arr1);
	// char* strcpy(char* p2,char* p1);
	// char* strcpy(char* p2, char* p1);
    // strcpy 函数的作用是拷贝字符串，会从源头字符串的首地址开始拷贝，到源头字符串的'\0'结束
    // 其中 p2 为目标字符串的首地址，p1 为源头字符串的首地址
    // strcpy 函数的返回值类型为 char*, 返回的是目标字符串的首地址
	printf("%s\n", arr2);

	// strcpy 函数的模拟
	char arr1[] = "abcdef";
	char arr2[20] = "----------";
	Strcpy(arr2, arr1);
	printf("%s\n", arr2);

	// strncpy 函数
	char arr1[] = "abcd";
	char arr2[20] = "----------";
	strncpy(arr2, arr1, 3);
	// 拷贝长度小于源头字符串长度时只会拷贝部分，
	// 且'\0'字符不会随其他字符一起被拷贝过来
	printf("%s\n", arr2);

	char arr1[] = "abcd";
	char arr2[20] = "----------";
	strncpy(arr2, arr1, 6);
	// 拷贝长度大于源头字符串长度时就会拷贝全部，
	// 且会通过在末尾补'\0'字符的方式凑齐所需长度
	printf("%s\n", arr2);

	// strncpy 函数的模拟
	char arr1[] = "abcd";
	char arr2[20] = "----------";
	Strncpy(arr2, arr1, 3);
	printf("%s\n", arr2);
	Strncpy(arr2, arr1, 6);
	printf("%s\n", arr2);

	// strcat 函数
	char arr1[] = "abcdef";
	char arr2[20] = "----------";
	strcat(arr2, arr1);
	printf("%s\n", arr2);

	// strcat 函数的模拟
	char arr1[] = "abcdef";
	char arr2[20] = "----------";
	Strcat(arr2, arr1);
	printf("%s\n", arr2);

	// strncat 函数
	char arr1[] = "abc";
	char arr2[20] = "-----\0-----";
	strncat(arr2, arr1, 2);
	// 拼接长度小于源头字符串长度时只会拼接部分，
	// 且会在拼接结束后自动补上'\0'字符
	printf("%s\n", arr2);

	char arr1[] = "abc";
	char arr2[20] = "-----\0-----";
	strncat(arr2, arr1, 5);
	// 拼接长度大于源头字符串长度时就会拼接全部，
	// 且不会通过在末尾补'\0'字符的方式凑齐所需长度
	printf("%s\n", arr2);

	// strncat 函数的模拟
	char arr1[] = "abc";
	char arr2[20] = "-----\0-----";
	Strncat(arr2, arr1, 2);
	printf("%s\n", arr2);
	Strncat(arr2, arr1, 5);
	printf("%s\n", arr2);

	// strcmp 函数
	char arr1[] = "abcdef";
	char arr2[] = "bcd";
	char arr3[] = "abcd";
	char arr4[] = "bcd\0ef";
	printf("%d\n", strcmp(arr1, arr2));
	printf("%d\n", strcmp(arr1, arr3));
	printf("%d\n", strcmp(arr2, arr4));

	// strcmp 函数的模拟
	char arr1[] = "abcdef";
	char arr2[] = "bcd";
	char arr3[] = "abcd";
	char arr4[] = "bcd\0ef";
	printf("%d\n", Strcmp(arr1, arr2));
	printf("%d\n", Strcmp(arr1, arr3));
	printf("%d\n", Strcmp(arr2, arr4));

	// strncmp 函数
	char arr1[] = "aabcdegc";
	char arr2[] = "aabcdcgh";
	int n = strncmp(arr1, arr2, 4);
	int m = strncmp(arr1, arr2, 7);
	printf("%d %d\n", n, m);

	// strncmp 函数的模拟
	char arr1[] = "aabcdegc";
	char arr2[] = "aabcdcgh";
	int n = Strncmp(arr1, arr2, 4);
	int m = Strncmp(arr1, arr2, 7);
	printf("%d %d\n", n, m);

	// strstr 函数
	char arr1[] = "aabdevgcccd";
	char arr2[] = "abc";
	char arr3[] = "ccd";
	char arr4[] = "evgcccdbc";
	char arr5[] = "";
	char* p1 = strstr(arr1, arr2);
	// char* strstr(char* p1,char* p2);
	// strstr函数用于查找p2字符串在p1字符串中第一次出现的位置，
	// 也就是可以判断p2是否为p1的子串，并找到p2最开始出现的位置，
	// strstr函数的返回值类型为char*指针类型，
	// 返回的是p2在p1中第一次出现位置的指针或是NULL指针，
	// NULL指针表明在p1中没有找到p2，
	// strstr函数的参数有两个，第一个指针指向被查找的母串的首地址，
	// 第二个指针指向要查找的子串的首地址
	printf("%p\n", p1);
	char* p2 = strstr(arr1, arr3);
	printf("%p\n", p2);
	char* p3 = strstr(arr1, arr4);
	printf("%p\n", p3);
	char* p4 = strstr(arr1, arr5);
	printf("%p\n", p4);

	// strstr 函数的模拟
	char arr1[] = "aabdevgcccd";
	char arr2[] = "abc";
	char arr3[] = "ccd";
	char arr4[] = "evgcccdbc";
	char arr5[] = "";
	char* p1 = Strstr(arr1, arr2);
	printf("%p\n", p1);
	char* p2 = Strstr(arr1, arr3);
	printf("%p\n", p2);
	char* p3 = Strstr(arr1, arr4);
	printf("%p\n", p3);
	char* p4 = Strstr(arr1, arr5);
	printf("%p\n", p4);

	// strtok 函数
	char arr1[] = "1123@qq.com//or//1123@163.com";// 要分割的字符串
	char arr2[] = "@/";// 分隔符的集合
	char arr3[50] = { '\0'};
	strcpy(arr3, arr1);
	char* p = strtok(arr3, arr2);
	// 首次调用时需要传入要分割的字符串的首地址
	printf("%s\n", p);
	while (p != NULL) {
		p = strtok(NULL, arr2);
		// 后续调用时只要传入NULL指针，表示分割的是同一个字符串
		printf("%s\n", p);
	}

	char arr1[] = "1123@qq.com//or//1123@163.com";// 要分割的字符串
	char arr2[] = "@/";// 分隔符的集合
	char arr3[50] = { '\0' };
	strcpy(arr3, arr1);
	for (char* p = strtok(arr3, arr2); p != NULL; p = strtok(NULL, arr2)) {
		printf("%s\n", p);
		// char* strtok(char* p1,char* p2);
		// strtok函数可基于分隔符集合对字符串做分割操作，将一个大字符串分割为几个小字符串
		// 返回值有两种：
		// 成功完成分割操作后返回当前子串的首地址；无法再做分割操作时返回NULL指针
		// 参数有两个：
		// 第一个为要分割的字符串的首地址，只有在首次调用时使用，
		// 后续调用直接传入NULL指针，表示分割的是同一个字符串，不然就是从头开始重新分割字符串
		// 第二个为分隔符集合的首地址，strtok函数只会对在集合中的分隔符做替换操作
	}

	// strerror 函数
	FILE* pf = fopen("data.txt", "r");
	// 打开文件操作，"r"表示以只读的方式打开文件
	// 此时文件必须已存在，不然就会打开文件失败并返回NULL指针
	// 此时就是使用标准库函数时发生错误，对应的会在errno变量里存入一个错误码
	char* per = strerror(errno);
	// char* strerror(int errno);
	// 返回值为错误码对应错误信息字符串的首地址
	// 参数为要转换信息的错误码
	printf("%d: %s\n", errno, per);

	// perror 函数
	FILE* pf = fopen("data.txt", "r");
	// 打开文件操作，"r"表示以只读的方式打开文件
	// 此时文件必须已存在，不然就会打开文件失败并返回NULL指针
	// 此时就是使用标准库函数时发生错误，对应的会在errno变量里存入一个错误码
	perror("error");
	// perror == printf + strerror
	// perror函数会自动读取errno变量中存放的错误码，并转为错误信息字符串打印输出
	// perror函数的参数是一个字符串，当字符串为空串也就是没有内容时，会直接打印输出错误信息字符串
	// 但当字符串不为空串时，最后的打印输出格式就是 xxx(字符串内容): xxxxx(错误信息字符串内容)
	// 会先打印完字符串的内容，然后加上一个冒号与一个空格，然后再打印输出错误信息字符串的内容

	return 0;
}
*/

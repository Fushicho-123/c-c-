/*
#define _CRT_SECURE_NO_WARNINGS
#define DEV 1E-7 
// 宏定义一个误差区间，这里使用科学计数法，
// 1E-7表示1乘以10的-7次方，也就是0.0000001
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>
// math.h头文件下有一个fabs函数，可用于计算浮点数的绝对值，
// 如果要计算整数的绝对值，需要使用stdlib.h头文件下的abs函数
void* Memcpy(void* p1, void* p2, size_t n) {
	assert(p1 && p2);
	void* tmp = p1;
	for (int i = 0; i < n; i++) {
		*(char*)p1 = *(char*)p2;
		p1 = (char*)p1 + 1;
		p2 = (char*)p2 + 1;
	}
	return tmp;
}
void* Memmove(void* p1, void* p2, size_t n) {
	assert(p1 && p2);
	if (p1 < p2) {
		for (int i = 0; i < n; i++) {
			*((char*)p1 + i) = *((char*)p2 + i);
		}
	}
	else {
		for (int i = n - 1; i >= 0; i--) {
			*((char*)p1 + i) = *((char*)p2 + i);
		}
	}
	return p1;
}
void* Memset(void* p, int v, size_t n) {
	assert(p);
	for (int i = 0; i < n; i++) {
		*((char*)p + i) = (unsigned char)v;
	}
	return p;
}

int main() {

	// memcpy 函数
	// void* memcpy(void* p1,void* p2,size_t n);
	// memcpy函数是从p2所指向的内存地址开始，拷贝n个字节到p1所指向的内存地址中，且memcpy函数只能拷贝不重叠的内存
	// memcpy函数的返回值是目标空间的首地址，也就是p1所指向的内存地址
	// memcpy函数的参数有三个，分别是目标空间的首地址p1，源空间的首地址p2，以及要拷贝的字节数n
	// memcpy函数虽然做的是内存拷贝，但使用前也要包含头文件string.h

	int arr1[20] = { 1,2,1,2,3,1,2,3,4,1,2,3,4,5,1,2,3,4,5,6 };
	int arr2[20] = { 0 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	memcpy(arr2, arr1, 20);
	// 20是memcpy函数进行拷贝操作时要拷贝的字节数，
	// 而int类型数组一个元素的大小为4字节，
	// 所以这里实际上只拷贝了arr1数组中的前五个元素，
	// 而不是将整个arr1数组都拷贝到arr2数组里
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr2[i]);
	}
	printf("\n");

	// memcpy 函数的模拟
	int arr1[20] = { 1,2,1,2,3,1,2,3,4,1,2,3,4,5,1,2,3,4,5,6 };
	int arr2[20] = { 0 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	Memcpy(arr2, arr1, 20);
	// 20是memcpy函数进行拷贝操作时要拷贝的字节数，
	// 而int类型数组一个元素的大小为4字节，
	// 所以这里实际上只拷贝了arr1数组中的前五个元素，
	// 而不是将整个arr1数组都拷贝到arr2数组里
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr2[i]);
	}
	printf("\n");

	int arr1[20] = { 1,2,1,2,3,1,2,3,4,1,2,3,4,5,1,2,3,4,5,6 };
	int arr2[20] = { 0 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	memcpy(arr1 + 4, arr1, 20);
	// 20是memcpy函数进行拷贝操作时要拷贝的字节数，
	// 而int类型数组一个元素的大小为4字节，
	// 所以这里实际上只拷贝了arr1数组中的前五个元素，
	// 而不是将整个arr1数组都拷贝到arr2数组里
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");

	int arr1[20] = { 1,2,1,2,3,1,2,3,4,1,2,3,4,5,1,2,3,4,5,6 };
	int arr2[20] = { 0 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	Memcpy(arr1 + 4, arr1, 20);
	// 20是memcpy函数进行拷贝操作时要拷贝的字节数，
	// 而int类型数组一个元素的大小为4字节，
	// 所以这里实际上只拷贝了arr1数组中的前五个元素，
	// 而不是将整个arr1数组都拷贝到arr2数组里
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");

	// memmove 函数
	int arr1[20] = { 1,2,1,2,3,1,2,3,4,1,2,3,4,5,1,2,3,4,5,6 };
	int arr2[20] = { 0 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	memmove(arr1 + 4, arr1, 20);
	// memmove函数与memcpy函数类似，都是对内存进行拷贝操作，
	// 所以两个函数的返回值类型与参数个数均相同，
	// 唯一的区别就是memmove函数可以拷贝重叠的内存，而memcpy函数不可以
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");

	// memmove 函数的模拟
	int arr1[20] = { 1,2,1,2,3,1,2,3,4,1,2,3,4,5,1,2,3,4,5,6 };
	int arr2[20] = { 0 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	Memmove(arr1 + 4, arr1, 20);
	// memmove函数与memcpy函数类似，都是对内存进行拷贝操作，
	// 所以两个函数的返回值类型与参数个数均相同，
	// 唯一的区别就是memmove函数可以拷贝重叠的内存，而memcpy函数不可以
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");

	int arr1[20] = { 1,2,1,2,3,1,2,3,4,1,2,3,4,5,1,2,3,4,5,6 };
	int arr2[20] = { 0 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	memmove(arr1, arr1 + 4, 20);
	// memmove函数与memcpy函数类似，都是对内存进行拷贝操作，
	// 所以两个函数的返回值类型与参数个数均相同，
	// 唯一的区别就是memmove函数可以拷贝重叠的内存，而memcpy函数不可以
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");

	int arr1[20] = { 1,2,1,2,3,1,2,3,4,1,2,3,4,5,1,2,3,4,5,6 };
	int arr2[20] = { 0 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	Memmove(arr1, arr1 + 4, 20);
	// memmove函数与memcpy函数类似，都是对内存进行拷贝操作，
	// 所以两个函数的返回值类型与参数个数均相同，
	// 唯一的区别就是memmove函数可以拷贝重叠的内存，而memcpy函数不可以
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");

	int arr1[20] = { 1,2,1,2,3,1,2,3,4,1,2,3,4,5,1,2,3,4,5,6 };
	int arr2[20] = { 0 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	memmove(arr2, arr1, 20);
	// memmove函数与memcpy函数类似，都是对内存进行拷贝操作，
	// 所以两个函数的返回值类型与参数个数均相同，
	// 唯一的区别就是memmove函数可以拷贝重叠的内存，而memcpy函数不可以
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr2[i]);
	}
	printf("\n");

	int arr1[20] = { 1,2,1,2,3,1,2,3,4,1,2,3,4,5,1,2,3,4,5,6 };
	int arr2[20] = { 0 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	Memmove(arr2, arr1, 20);
	// memmove函数与memcpy函数类似，都是对内存进行拷贝操作，
	// 所以两个函数的返回值类型与参数个数均相同，
	// 唯一的区别就是memmove函数可以拷贝重叠的内存，而memcpy函数不可以
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr2[i]);
	}
	printf("\n");

	// memset 函数的错误用法
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	memset(arr, 1, sizeof(arr));
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	// memset 函数的正确用法
	int arr[10] = { 1,1,2,2,3,3,4,4,5,5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	memset(arr, 0, sizeof(arr));
	// void* memset(void* p,int v,size_t n);
	// memset函数是从p所指向的内存地址开始将n个字节全部设置为v值，可用来初始化一片内存空间的值
	// memset函数的返回值是目标空间的首地址，也就是p所指向的内存地址
	// memset函数的参数有三个，分别是目标空间的首地址p，要设置的值v，以及要设置的字节数n
	// 关于值v，memset函数会将其转换为unsigned char类型，然后以字节为单位进行设置操作
	// memset函数虽然做的是内存初始化，但使用前也要包含头文件string.h
	for (int i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	// memcmp 函数
	int arr1[9] = { 1,2,3,257,3,4,3,4,5 };
	int arr2[7] = { 1,2,3,1,2,3,4 };
	int c1 = memcmp(arr1, arr2, 8);
	int c2 = memcmp(arr1, arr2, 13);
	int c3 = memcmp(arr1, arr2, 14);
	// int memcmp(const void* p1, const void* p2, size_t n);
	// memcmp函数是从p1所指向的内存地址开始，依次比较p1与p2内存地址中前n个字节的内容，
	// memcmp函数的返回值是一个整数，若返回值为0，则表示两片内存空间的内容完全相同
	// 若返回值大于0，则表示p1所指向的内存空间大于p2所指向的内存空间
	// 若返回值小于0，则表示p1所指向的内存空间小于p2所指向的内存空间
	// memcmp函数的参数有三个，分别是要比较的两片内存空间的首地址p1与p2，以及要比较的字节数n
	printf("%d %d %d\n", c1, c2, c3);

	// 大小端存储
	int x = 1;
	if (*(char*)&x == 1) {
		printf("小端存储\n");
	}
	else {
		printf("大端存储\n");
	}

	// x86环境下运行
	int arr[4] = { 1,2,3,4 };
	int* p1 = (int*)(&arr + 1);
	int* p2 = (int*)((int)arr + 1);
	printf("%x %x\n", p1[-1], *p2);
	// %x格式是以十六进制形式打印无符号整数

	// 数位截断与整型提升
	char a = -1;
	signed char b = -1;
	unsigned char c = -1;
	printf("%d %d %d\n", a, b, c);
	// -1的十六进制补码：FFFFFF FF
	// char a默认是有符号char，与signed char b相同，
	// 当int类型的-1赋给a和b时发生数位截断，a和b中存的是 FF，
	// 最后打印输出时发生整型提升，按符号位填充得到 FFFFFFFF，
	// 所得的是-1的补码，所以输出-1
	// unsigned char c是无符号char，
	// 当-1赋给c时同样发生数位截断，c中存的也是 FF，
	// 但c发生整型提升时由于是无符号，按0填充得到 000000FF，
	// 所得的是255的补码，所以输出255

	char c = -128;
	printf("%u\n", c);
	// %u格式是以十进制形式打印无符号整数
	// -128的8位二进制表示数是10000000，
	// 关于原因我们前面也讲过了，不再重复，
	// 所以-128的十六进制补码：FFFFFF 80
	// 赋给c时数位截断，c中存的是 80，
	// 最后打印输出时整型提升，转变为 FFFFFF80，
	// 这个十六进制数以无符号十进制形式表示时，
	// 就是我们所见的那个极大的数

	char arr[1000] = { 0 };
	// 看似是-1,-2,-3...-128,-129...-1000，但char类型取值范围是-128~127，-129一定会发生数位截断，
	// 所以实际是-1,-2,-3...-128,127...-8
	// strlen函数在统计字符个数时会从字符串的首地址开始，依次判断每个字符的ASCII值是否为0，直到遇到'\0'为止
	// 所以当strlen函数在统计到第256个时就会停止，因为此时的值实际上就是0
	// 而strlen函数的返回值类型为size_t，是无符号整型，所以最后的结果就是255
	for (int i = 0; i < 1000; i++) {
		arr[i] = -1 - i;
	}
	printf("%d\n", strlen(arr));

	for (unsigned int i = 5; i >= 0; i--) {
		printf("%u\n", i);
	}
	// 如果是int类型的i，那么当i==0时，i--后就会变为-1，此时循环结束，
	// 但现在的i是unsigned int类型，当i==0时，i--后所变的-1由于不存在符号位，
	// 就会变为一个极大的数，此时永远满足表达式i>=0，循环就会一直进行下去

	// 浮点数的存储
	int x = 9;
	float* p = (float*)&x;
	printf("%d %f\n", x, *p);
	// 9 == 1001
	// 所以9这个整数在存储时：00000000 00000000 00000000 00001001
	// 当我们以浮点数形式读取时：0 00000000 00000000000000000001001
	// S = 0, E = 1 - 127 = -126，M = 00000000000000000001001
	// 这样最后结果就是一个接近于0的极小浮点数，而float精度只有六位有效数字，只能输出0.000000
	*p = 9.0;
	printf("%d %f\n", x, *p);
	// 9.0 == (-1)^0 * 1.001 * 2^3
	// S = 0, E = 3 + 127 = 130 = 10000010, M = 00100000000000000000000
	// 所以9.0这个浮点数在存储时：0 10000010 00100000000000000000000
	// 当我们以整数形式读取时：01000001 00010000 00000000 00000000
	// 这样最后结果就是一个极大的整数，最终输出 1091567616

	float x = 0.1, y = 0.2;
	if (x + y == 0.3) {
		printf("==\n");
	}
	else {
		printf("!=\n");
		// 结果是!=，0.1，0.2和0.3都是浮点数，而这三个浮点数在计算机中都无法精确保存
	}

	float x = 0.1, y = 0.2;
	if (fabs(x + y - 0.3) <= DEV) {
		printf("==\n");
		// 结果是==，利用fabs计算差值的绝对值，在设定的可接受误差范围内比较，就能避免浮点数精度问题
	}
	else {
		printf("!=\n");
	}

	return 0;
}
*/


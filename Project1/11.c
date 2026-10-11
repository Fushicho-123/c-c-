/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
struct student {
	char name[20];
	int age;
	float score;
};

int main() {

	// 引子：使用文件的原因
	int n = 0;
	int arr[5] = { 0 };
	scanf("%d", &n);
	if (n == 1) {
		for (int i = 0; i < 5; i++) {
			scanf("%d", &arr[i]);
		}
	}
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	// 二进制文件
	int n = 1234;
	FILE* pf = fopen("test.txt", "wb");
	fwrite(&n, 4, 1, pf);
	fclose(pf);
	pf = NULL;

	// 向文件写入字符
	// 打开文件
	// FILE* pf = fopen("E:/VScode/c_study/Fushicho-123/test.txt", "r");
	// FILE* pf = fopen("../../test.txt", "r");
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL) {
		perror("error");
		return -1;
	}
	printf("打开成功\n");
	// 读写文件（写）
	fputc('a', pf);
	fputc('b', pf);
	fputc('c', pf);
	// 关闭文件
	int flag = fclose(pf);
	if (flag != 0) {
		perror("error");
		return -1;
	}
	pf = NULL;
	printf("关闭成功\n");

	// 向标准输出流stdout写入字符
	for (int i = 'a'; i <= 'z'; i++) {
		fputc(i, stdout);
	}

	// 从文件读取字符
	// 打开文件
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		perror("error");
		return -1;
	}
	printf("打开成功\n");
	// 读写文件（读）
	int ch = 0;
	while ((ch = fgetc(pf)) != EOF) {
		printf("%c\n", ch);
	}
	// 关闭文件
	int flag = fclose(pf);
	if (flag != 0) {
		perror("error");
		return -1;
	}
	pf = NULL;
	printf("关闭成功\n");
	
	// 从标准输入流stdin读取字符
	int ch = 0;
	while ((ch = fgetc(stdin)) != EOF) {
		printf("%c\n", ch);
	}

	// feof函数与ferror函数的使用
	// 打开文件
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		perror("error");
		return -1;
	}
	printf("打开成功\n");
	// 读写文件（读）
	for (int i = 0; i < 5; i++) {
		int ch = fgetc(pf);
		if (ch == EOF) {
			if (feof(pf)) {
				printf("遇到文件末尾\n");
			}
			else if (ferror(pf)) {
				printf("发生读写错误\n");
			}
			break;
		}
		printf("%c\n", ch);
	}
	// 关闭文件
	int flag = fclose(pf);
	if (flag != 0) {
		perror("error");
		return -1;
	}
	pf = NULL;
	printf("关闭成功\n");

	// 向文件写入字符串
	// 打开文件
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL) {
		perror("error");
		return -1;
	}
	printf("打开成功\n");
	// 读写文件（写）
	fputs("Hello", pf);
	fputs("World", pf);
	// 关闭文件
	int flag = fclose(pf);
	if (flag != 0) {
		perror("error");
		return -1;
	}
	pf = NULL;
	printf("关闭成功\n");

	// 从文件读取字符串
	// 打开文件
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		perror("error");
		return -1;
	}
	printf("打开成功\n");
	// 读写文件（读）
	char arr[] = "----------";
	while ((fgets(arr, 10, pf)) != NULL) {
		printf("%s\n", arr);
	}
	// 关闭文件
	int flag = fclose(pf);
	if (flag != 0) {
		perror("error");
		return -1;
	}
	pf = NULL;
	printf("关闭成功\n");

	// 向文件写入格式化数据
	struct student s1 = { 0 };
	// 打开文件
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL) {
		perror("error");
		return -1;
	}
	printf("打开成功\n");
	// 读写文件（写）
	scanf("%s %d %f", &s1.name, &s1.age, &s1.score);
	fprintf(pf, "%s %d %.2f\n", s1.name, s1.age, s1.score);
	// 关闭文件
	int flag = fclose(pf);
	if (flag != 0) {
		perror("error");
		return -1;
	}
	pf = NULL;
	printf("关闭成功\n");

	// 从文件读取格式化数据
	struct student s1 = { 0 };
	// 打开文件
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		perror("error");
		return -1;
	}
	printf("打开成功\n");
	// 读写文件（读）
	fscanf(pf, "%s %d %d", &s1.name, &s1.age, &s1.score);
	printf("%s %d %.2f\n", s1.name, s1.age, s1.score);
	// 关闭文件
	int flag = fclose(pf);
	if (flag != 0) {
		perror("error");
		return -1;
	}
	pf = NULL;
	printf("关闭成功\n");

	// sprintf函数
	struct student s1 = { "qyh",20,80 };
	char arr[20] = { 0 };
	int n = sprintf(arr, "%s %d %.1f", s1.name, s1.age, s1.score);
	printf("%d\n", n);

	// sscanf函数
	struct student s1 = { 0 };
	char arr[20] = "abc 12.3";
	int n = sscanf(arr, "%s %d %f", &s1.name, &s1.age, &s1.score);
	printf("%d\n", n);
	printf("%s %d %.1f\n", s1.name, s1.age, s1.score);

	struct student s1 = { 0 };
	char arr[20] = "abc 12.3";
	int n = sscanf(arr, "%d %f", &s1.age, &s1.score);
	printf("%d\n", n);
	printf("%d %.1f\n", s1.age, s1.score);

	struct student s1 = { 0 };
	char arr[20] = " ";
	int n = sscanf(arr, "%d %f", &s1.age, &s1.score);
	printf("%d\n", n);
	printf("%d %.1f\n", s1.age, s1.score);

	// 以内存块的形式向文件写入数据
	struct student s1 = { "qyh",20,80 };
	// 打开文件
	FILE* pf = fopen("test.txt", "wb");
	if (pf == NULL) {
		perror("error");
		return -1;
	}
	printf("打开成功\n");
	// 读写文件（写）
	fwrite(&s1, sizeof(struct student), 1, pf);
	// 关闭文件
	int flag = fclose(pf);
	if (flag != 0) {
		perror("error");
		return -1;
	}
	pf = NULL;
	printf("关闭成功\n");

	// 以内存块的形式从文件读取数据
	struct student s1 = { 0 };
	// 打开文件
	FILE* pf = fopen("test.txt", "rb");
	if (pf == NULL) {
		perror("error");
		return -1;
	}
	printf("打开成功\n");
	// 读写文件（读）
	fread(&s1, sizeof(struct student), 1, pf);
	printf("%s %d %.1f\n", s1.name, s1.age, s1.score);
	// 关闭文件
	int flag = fclose(pf);
	if (flag != 0) {
		perror("error");
		return -1;
	}
	pf = NULL;
	printf("关闭成功\n");

	// fseek函数的使用
	// 打开文件
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		perror("error");
		return -1;
	}
	printf("打开成功\n");
	// 读写文件（读）
	int ch = 0;
	ch = fgetc(pf);
	printf("%c\n", ch);
	fseek(pf, 2, SEEK_CUR);
	ch = fgetc(pf);
	printf("%c\n", ch);
	fseek(pf, -4, SEEK_END);
	ch = fgetc(pf);
	printf("%c\n", ch);
	fseek(pf, 2, SEEK_CUR);
	ch = fgetc(pf);
	printf("%c\n", ch);
	fseek(pf, 3, SEEK_SET);
	ch = fgetc(pf);
	printf("%c\n", ch);
	fseek(pf, 1, SEEK_CUR);
	ch = fgetc(pf);
	printf("%c\n", ch);
	// 关闭文件
	int flag = fclose(pf);
	if (flag != 0) {
		perror("error");
		return -1;
	}
	pf = NULL;
	printf("关闭成功\n");

	// ftell函数的使用
	// 打开文件
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		perror("error");
		return -1;
	}
	printf("打开成功\n");
	// 读写文件（读）
	int ch = 0;
	ch = fgetc(pf);
	printf("%c\n", ch);
	long int pos = ftell(pf);
	fseek(pf, -5, SEEK_END);
	ch = fgetc(pf);
	printf("%c\n", ch);
	fseek(pf, pos, SEEK_SET);
	ch = fgetc(pf);
	printf("%c\n", ch);
	// 关闭文件
	int flag = fclose(pf);
	if (flag != 0) {
		perror("error");
		return -1;
	}
	pf = NULL;
	printf("关闭成功\n");

	// rewind函数的使用
	// 打开文件
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL) {
		perror("error");
		return -1;
	}
	printf("打开成功\n");
	// 读写文件（读）
	int ch = 0;
	ch = fgetc(pf);
	printf("%c\n", ch);
	long int pos = ftell(pf);
	fseek(pf, -5, SEEK_END);
	ch = fgetc(pf);
	printf("%c\n", ch);
	fseek(pf, pos, SEEK_SET);
	ch = fgetc(pf);
	printf("%c\n", ch);
	fseek(pf, 0, SEEK_SET);
	ch = fgetc(pf);
	printf("%c\n", ch);
	fseek(pf, 3, SEEK_CUR);
	ch = fgetc(pf);
	printf("%c\n", ch);
	rewind(pf);
	ch = fgetc(pf);
	printf("%c\n", ch);
	// 关闭文件
	int flag = fclose(pf);
	if (flag != 0) {
		perror("error");
		return -1;
	}
	pf = NULL;
	printf("关闭成功\n");

	// 缓冲区证明与fflush函数使用
	// 打开文件
	FILE* pf = fopen("test.txt", "w");
	if (pf == NULL) {
		perror("error");
		return -1;
	}
	printf("打开成功\n");
	// 读写文件（写）
	fputs("Hello World", pf);
	printf("已将数据写入缓冲区\n");
	Sleep(10000);
	printf("系统已经过10秒睡眠\n");
	fflush(pf);
	printf("已强制刷新缓冲区\n");
	Sleep(10000);
	printf("系统已经过10秒睡眠\n");
	// 关闭文件
	int flag = fclose(pf);
	if (flag != 0) {
		perror("error");
		return -1;
	}
	pf = NULL;
	printf("关闭成功\n");

	// r+/w+/a+
	// 打开文件
	FILE* pf = fopen("test.txt", "w+");
	if (pf == NULL) {
		perror("error");
		return -1;
	}
	printf("打开成功\n");
	// 读写文件（写）
	fputs("Hello World", pf);
	fseek(pf, -1, SEEK_CUR);
	int ch = fgetc(pf);
	printf("%c\n", ch);
	fseek(pf, 5, SEEK_SET);
	fputs("hi", pf);
	fseek(pf, 1, SEEK_CUR);
	ch = fgetc(pf);
	printf("%c\n", ch);
	// 关闭文件
	int flag = fclose(pf);
	if (flag != 0) {
		perror("error");
		return -1;
	}
	pf = NULL;
	printf("关闭成功\n");

	return 0;
}
*/
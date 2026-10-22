/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "ADD.h"
#include "ADD.h"
#include "ADD.h"
#define MAX 10
#define LL long long
#define PRINT printf("现在时间是 %s %s\n", \
                     __DATE__, __TIME__)
#define SQA(x) ((x) * (x))
#define CMP(x, y) ((x) > (y) ? (x) : (y))
#define MALLOC(type, num) (type *)malloc(num * sizeof(type))
int cmp(int x, int y)
{
    return x > y ? x : y;
}
#define OUTPUT(num,type) printf(#num"的值是"type"\n",num)
int Add_Int(int x, int y) {
    return x + y;
}
float Add_Float(float x, float y) {
    return x + y;
}
// 通过宏定义构建参数模板
#define ADD(type) type add_##type(type x,type y){\
                        return x+y;\
                        }
ADD(int)
ADD(float)
#define M 10
#define N 20
#define __DEBUG__

int main()
{

    // 编译链接测试
    int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    for (int index = 0; index < 10; index++)
    {
        array[index] = (index + 4) * (2 + 6);
        printf("%d ", array[index]);
    }

    int a = 10;
    int b = 20;
    int c = Add(a, b);
    printf("%d + %d = %d\n", a, b, c);

    // 预定义符号
    printf("%s\n", __FILE__);
    printf("%d\n", __LINE__);
    printf("%s\n", __DATE__);
    printf("%s\n", __TIME__);
    printf("%d\n", __STDC__);

    // #define定义常量
    LL arr[MAX] = { 1,2,3,4,5,6,7,8,9,10 };
    for (LL i = 0; i < MAX; i++)
    {
        arr[i] = i*2;
        printf("%lld ", arr[i]);
    }
    printf("\n");
    PRINT;

    // #define定义宏
    int a = 8;
    int b = 18;
    int n = SQA(b + 2) / SQA(a + 2);
    printf("%d\n", n);

    // 带副作用的宏参数
    int a = 10;
    int b = a + 1;
    printf("b=%d a=%d\n", b, a);
    int c = ++a;
    printf("c=%d a=%d\n", c, a);

    // 宏与函数的比较
    int a = MAX;
    int b = 20;
    int max = CMP(MAX, ++b);
    printf("MAX=%d a=%d b=%d\n", max, a, b);

    int a = 10;
    int b = 20;
    int max = cmp(++a, ++b);
    printf("max=%d a=%d b=%d\n", max, a, b);

    int* p1 = (int*)malloc(10 * sizeof(int));
    int* p2 = MALLOC(int, 10);

    // #的使用
    printf("Hello World\n");
    printf("Hello ""World\n");
    int a = 5;
    printf("a的值是%d\n", a);
    OUTPUT(a, "%d");
    float b = 3.14;
    printf("b的值是%f\n", b);
    OUTPUT(b, "%f");

    // ##的使用
    int c1 = add_int(10, 20);
    printf("c1=%d\n", c1);
    float c2 = add_float(3.14, 5.12);
    printf("c2=%.2f\n", c2);

    // #undef的使用
      printf("M=%d N=%d\n", M, N);
#undef M
    int M = N * 2;
    printf("M=%d N=%d\n", M, N);
#define M 100
#undef N
    int N = M / 4;
    printf("M=%d N=%d\n", M, N);

    // 命令行定义
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;
    }
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 条件编译指令
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    int c = add_int(a++, b++);
    printf("c=%d\n", c);
//#if !defined(__DEBUG__)
#ifndef __DEBUG__
    printf("a=%d b=%d\n", a, b);
#endif

    int flag = 1;
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    int c = add_int(a++, b++);
    printf("c=%d\n", c);
#if __DEBUG__==1
    printf("a=%d b=%d\n", a, b);
#endif

    #if __DEBUG__<=3
    printf("haha\n");
#elif __DEBUG__>3&&__DEBUG__<7
    printf("hehe\n");
#else 
    printf("xixi\n");
#endif

    return 0;
}
*/
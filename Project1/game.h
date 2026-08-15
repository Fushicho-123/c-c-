#define _CRT_SECURE_NO_WARNINGS
#define CJROW 9
#define CJCOL 9
#define CJNUM 10
#define ZJROW 16
#define ZJCOL 16
#define ZJNUM 40
#define GJROW 16
#define GJCOL 30
#define GJNUM 99

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitArr(char arr[][110], int r, int l, char c);

void SetLandMine(char bottom[][110], int r, int l, int num);

void PrintArr(char arr[][110], int r, int l);

int CheckLandMine(char bottom[][110], int x, int y);

int CountLandMine(char bottom[][110], int x, int y);

int FindLandMine(char top[][110], char bottom[][110], int x, int y, int r, int l);

void SearchLandMine(char top[][110], char bottom[][110], int x, int y, int r, int l);

int SignLandMine(char top[][110], char bottom[][110], int x, int y, int r, int l, int num, int mnum);

int CancelSign(char top[][110], char bottom[][110], int x, int y, int r, int l, int num);

int LimitSign(char top[][110], int r, int l);

int Select1(char top[][110], char bottom[][110], int r, int l);

int Select2(char top[][110], char bottom[][110], int r, int l, int num, int mnum);

int Select3(char top[][110], char bottom[][110], int r, int l, int num);

void CleanBur();
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
void menu() {
	printf("*--*--*--*--*--*--*--*\n");
	printf("*---- 1.开始游戏 ----*\n");
	printf("*--------------------*\n");
	printf("*---- 0.结束游戏 ----*\n");
	printf("*--*--*--*--*--*--*--*\n");
}
void menu_select() {
	printf("*--*--*--*--*--*--*--*\n");
	printf("*---- 1.排雷 --------*\n");
	printf("*---- 2.标记 --------*\n");
	printf("*---- 3.取消标记 ----*\n");
	printf("*--*--*--*--*--*--*--*\n");
}
void menu_hard() {
	printf("*--*--*--*--*--*--*--*\n");
	printf("*----- 1.基础   -----*\n");
	printf("*----- 2.中级   -----*\n");
	printf("*----- 3.专家   -----*\n");
	printf("*----- 4.自定义 -----*\n");
	printf("*--*--*--*--*--*--*--*\n");
}
void game() {
	char bottom[110][110] = { '0' };
	char top[110][110] = { '0' };
	int xz = 0;
	do {
		menu_hard();
		printf("请选择操作：");
		scanf("%d", &xz);
		CleanBur();
		int oldtime = time(NULL);
		switch (xz) {
		case 1: {
			InitArr(bottom, CJROW + 2, CJCOL + 2, '0');
			SetLandMine(bottom, CJROW, CJCOL, CJNUM);
			InitArr(top, CJROW + 2, CJCOL + 2, '*');
			//PrintArr(bottom, CJROW, CJCOL);
			PrintArr(top, CJROW, CJCOL);
			int sz1 = 0, num = CJNUM;
			int Mnum = CJNUM;
			do {
				menu_select();
				printf("请选择操作：");
				scanf("%d", &sz1);
				CleanBur();
				switch (sz1) {
				case 1: {
					int flag = Select1(top, bottom, CJROW, CJCOL);
					int newtime = time(NULL);
					if (flag == 1) {
						printf("本局游戏所用时间(秒)：%d\n", newtime - oldtime);
						sz1 = 0;
					}
					else {
						printf("本局游戏已用时间(秒)：%d\n", newtime - oldtime);
					}
					break;
				}
				case 2: {
					num = Select2(top, bottom, CJROW, CJCOL, num, Mnum);
					//printf("还有%d颗雷\n", num);
					int newtime = time(NULL);
					if (num == 0) {
						printf("非常棒，排雷成功，已排出所有雷点！\n");
						printf("本局游戏所用时间(秒)：%d\n", newtime - oldtime);
					}
					else {
						printf("本局游戏已用时间(秒)：%d\n", newtime - oldtime);
					}
					break;
				}
				case 3: {
					num = Select3(top, bottom, CJROW, CJCOL, num);
					//printf("还有%d颗雷\n", num);
					int newtime = time(NULL);
					printf("本局游戏已用时间(秒)：%d\n", newtime - oldtime);
					break;
				}
				default:
					printf("无对应操作选项，请重新选择！\n");
					break;
				}
			} while (sz1);
			xz = 0;
			break;
		}
		case 2: {
			InitArr(bottom, ZJROW + 2, ZJCOL + 2, '0');
			SetLandMine(bottom, ZJROW, ZJCOL, ZJNUM);
			InitArr(top, ZJROW + 2, ZJCOL + 2, '*');
			//PrintArr(bottom, ZJROW, ZJCOL);
			PrintArr(top, ZJROW, ZJCOL);
			int sz1 = 0, num = ZJNUM;
			int Mnum = ZJNUM;
			do {
				menu_select();
				printf("请选择操作：");
				scanf("%d", &sz1);
				CleanBur();
				switch (sz1) {
				case 1: {
					int flag = Select1(top, bottom, ZJROW, ZJCOL);
					int newtime = time(NULL);
					if (flag == 1) {
						printf("本局游戏所用时间(秒)：%d\n", newtime - oldtime);
						sz1 = 0;
					}
					else {
						printf("本局游戏已用时间(秒)：%d\n", newtime - oldtime);
					}
					break;
				}
				case 2: {
					num = Select2(top, bottom, ZJROW, ZJCOL, num, Mnum);
					//printf("还有%d颗雷\n", num);
					int newtime = time(NULL);
					if (num == 0) {
						printf("非常棒，排雷成功，已排出所有雷点！\n");
						printf("本局游戏所用时间(秒)：%d\n", newtime - oldtime);
					}
					else {
						printf("本局游戏已用时间(秒)：%d\n", newtime - oldtime);
					}
					break;
				}
				case 3: {
					num = Select3(top, bottom, ZJROW, ZJCOL, num);
					//printf("还有%d颗雷\n", num);
					int newtime = time(NULL);
					printf("本局游戏已用时间(秒)：%d\n", newtime - oldtime);
					break;
				}
				default:
					printf("无对应操作选项，请重新选择！\n");
					break;
				}
			} while (sz1);
			xz = 0;
			break;
		}
		case 3: {
			InitArr(bottom, GJROW + 2, GJCOL + 2, '0');
			SetLandMine(bottom, GJROW, GJCOL, GJNUM);
			InitArr(top, GJROW + 2, GJCOL + 2, '*');
			//PrintArr(bottom, GJROW, GJCOL);
			PrintArr(top, GJROW, GJCOL);
			int sz1 = 0, num = GJNUM;
			int Mnum = GJNUM;
			do {
				menu_select();
				printf("请选择操作：");
				scanf("%d", &sz1);
				CleanBur();
				switch (sz1) {
				case 1: {
					int flag = Select1(top, bottom, GJROW, GJCOL);
					int newtime = time(NULL);
					if (flag == 1) {
						printf("本局游戏所用时间(秒)：%d\n", newtime - oldtime);
						sz1 = 0;
					}
					else {
						printf("本局游戏已用时间(秒)：%d\n", newtime - oldtime);
					}
					break;
				}
				case 2: {
					num = Select2(top, bottom, GJROW, GJCOL, num, Mnum);
					//printf("还有%d颗雷\n", num);
					int newtime = time(NULL);
					if (num == 0) {
						printf("非常棒，排雷成功，已排出所有雷点！\n");
						printf("本局游戏所用时间(秒)：%d\n", newtime - oldtime);
					}
					else {
						printf("本局游戏已用时间(秒)：%d\n", newtime - oldtime);
					}
					break;
				}
				case 3: {
					num = Select3(top, bottom, GJROW, GJCOL, num);
					//printf("还有%d颗雷\n", num);
					int newtime = time(NULL);
					printf("本局游戏已用时间(秒)：%d\n", newtime - oldtime);
					break;
				}
				default:
					printf("无对应操作选项，请重新选择！\n");
					break;
				}
			} while (sz1);
			xz = 0;
			break;
		}
		case 4: {
			int r = 0, l = 0, n = 0;
			printf("请输入要设置的雷盘大小(行，列)与雷的数量(颗)：");
			scanf("%d %d %d", &r, &l, &n);
			InitArr(bottom, r + 2, l + 2, '0');
			SetLandMine(bottom, r, l, n);
			InitArr(top, r + 2, l + 2, '*');
			//PrintArr(bottom, r, l);
			PrintArr(top, r, l);
			int sz1 = 0, num = n;
			int Mnum = n;
			do {
				menu_select();
				printf("请选择操作：");
				scanf("%d", &sz1);
				CleanBur();
				switch (sz1) {
				case 1: {
					int flag = Select1(top, bottom, r, l);
					int newtime = time(NULL);
					if (flag == 1) {
						printf("本局游戏所用时间(秒)：%d\n", newtime - oldtime);
						sz1 = 0;
					}
					else {
						printf("本局游戏已用时间(秒)：%d\n", newtime - oldtime);
					}
					break;
				}
				case 2: {

					num = Select2(top, bottom, r, l, num, Mnum);
					//printf("还有%d颗雷\n", num);
					int newtime = time(NULL);
					if (num == 0) {
						printf("非常棒，排雷成功，已排出所有雷点！\n");
						printf("本局游戏所用时间(秒)：%d\n", newtime - oldtime);
					}
					else {
						printf("本局游戏已用时间(秒)：%d\n", newtime - oldtime);
					}
					break;
				}
				case 3: {
					num = Select3(top, bottom, r, l, num);
					//printf("还有%d颗雷\n", num);
					int newtime = time(NULL);
					printf("本局游戏已用时间(秒)：%d\n", newtime - oldtime);
					break;
				}
				default:
					printf("无对应操作选项，请重新选择！\n");
					break;
				}
			} while (sz1);
			xz = 0;
			break;
		}
		default:
			printf("无对应操作选项，请重新选择！\n");
			break;
		}
	}while (xz);
}

int main() {
	srand((unsigned)time(NULL));
	int sz = 0;
	do {
		menu();
		printf("请选择操作：");
		scanf("%d", &sz);
		CleanBur();
		switch (sz) {
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束，欢迎下次游玩！\n");
			break;
		default:
			printf("无对应操作选项，请重新选择！\n");
			break;
		}
	} while (sz);
	return 0;
}

//srand函数与rand函数的头文件是 stdlib.h，
//time函数的头文件是 time.h
//srand(参数);
//srand为随机种子，参数的不同使得每一次所获取的随机数不同，默认参数为1
//time(参数);
//time为时间戳，当参数为NULL时以当下时间与1970年1月1日0时0分的时间差为结果传值，
//另一种传参方式是使用指针的形式，这里不用，感兴趣的小萌新自研
//time函数的返回值类型为time_t，作为srand参数时要先强制类型转化为unsigned
//利用时间戳不断改变参数，使得srand随机种子的参数不再是默认的1，从而实现实时的伪随机
//rand();
//rand函数无参数，返回一个随机整数
//常见的使用形式：int N=a+rand()%(b-a+1); 
//可用于表示取值范围在[a,b]之间的一个随机数


/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int sum = 0;
void game() {
	int bomb = rand() % 100 + 1;
	//通用形式：结果=a+rand()%(b-a+1); 可用于表示取值范围在[a,b]之间的一个随机数
	printf("炸弹已埋好了（1-100层里的某一层），快去拆炸弹吧！\n");
	int guess = 0;
	int num = 0;
	int score = 0;
	int flag = 1;
	for (int i = 10; i > 0;i--) {
		printf("请输入你要去往的层数（仅数字），还剩余%d次：\n",i);
		scanf("%d", &guess);
		num = guess;
		if (guess == bomb) {
			flag = 0;
			score += 20;
			printf("成功找到并拆除了炸弹，得分+20！\n");
			break;
		}
		if (abs(guess - bomb) <= 5) {
			score += 3;
			printf("近了近了，炸弹就在附近，得分+3！\n");
		}
		else if (abs(guess - bomb) <= 15) {
			score += 2;
			printf("已经慢慢靠近炸弹了，得分+2！\n");
		}
		else if (abs(guess - bomb) <= 30) {
			score += 1;
			printf("炸弹离得还是有点远，得分+1！\n");
		}
		else {
			printf("炸弹离得还挺远的，得分+0！\n");
		}
	}
	if (flag) {
		if (abs(num - bomb) <= 5) {
			score = 0;
			printf("BOM！真男人就要直面爆炸,得分清零！\n");
		}
		else if (abs(num - bomb) <= 10) {
			score = 0;
			printf("BOM！炸弹的余波直接将你哄睡着了，得分清零！\n");
		}
		else if (abs(num - bomb) <= 12) {
			score += 5;
			printf("精准控制！炸弹的余波在你身后停止，得分+5！\n");
		}
		else if (abs(num - bomb) <= 15) {
			score += 3;
			printf("准度欠佳，炸弹的余波在你身后停止，得分+3！\n");
		}
		else if (abs(num - bomb) <= 20) {
			score += 2;
			printf("马马虎虎，但好歹没被炸弹的余波波及，得分+2！\n");
		}
		else {
			printf("胆小如鼠，但好歹没被炸弹的余波波及，得分+0！\n");
		}
	}
	printf("本轮游戏结束，最终得分为%d！\n", score);
	sum += score;
}
int main(){
	sum = 0;
	int input = 0;
	srand((unsigned int)time(NULL));
	//srand为随机种子，参数的不同使得每一次所获取的随机数不同
	//time为时间戳，以当下时间与1970年1月1日0时0分的时间差为结果传值
	//利用时间戳不断改变参数，使得srand随机种子的参数不再是默认的1，从而实现实时的伪随机
	do {
		printf("--------------------\n");
		printf("--- 1.start game ---\n");
		printf("---- 0.end game ----\n");
		printf("--------------------\n");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("欢迎下次来玩，本次游戏总得分为%d！\n", sum);
			break;
		default:
			printf("请输入正确的游戏选项！\n");
			break;
		}
	} while (input);
	return 0;
}
*/
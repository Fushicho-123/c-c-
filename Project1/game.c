#include "game.h"
void InitArr(char arr[][110], int r, int l, char c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < l; j++)
			arr[i][j] = c;
	}
}

void SetLandMine(char bottom[][110], int r, int l, int num) {
	while (num) {
		int x = rand() % r + 1;
		int y = rand() % l + 1;
		if (bottom[x][y] == '0') {
			bottom[x][y] = '1';
			num--;
		}
	}
}

void PrintArr(char arr[][110], int r, int l) {
	system("cls");
	for (int i = 0; i <= r; i++) {
		printf("%2d ", i);
		for (int j = 1; j <= l; j++) {
			if (i == 0)
				printf("%2d ", j);
			else
				printf("%2c ", arr[i][j]);
		}
		printf("\n");
	}
}

int CheckLandMine(char bottom[][110], int x, int y) {
	if (bottom[x][y] == '1')
		return 1;
	return 0;
}

int CountLandMine(char bottom[][110], int x, int y) {
	int num = 0;
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++)
			num += (bottom[i][j] - '0');
	}
	return num;
}

int FindLandMine(char top[][110], char bottom[][110], int x, int y, int r, int l) {
	if (CheckLandMine(bottom, x, y) == 1) {
		printf("很遗憾，排雷失败，这个是雷点！\n");
		PrintArr(bottom, r, l);
		return 1;
	}
	else {
		SearchLandMine(top, bottom, x, y, r, l);
		PrintArr(top, r, l);
		return 0;
	}
}

void SearchLandMine(char top[][110], char bottom[][110], int x, int y, int r, int l) {
	if (x<1 || x>r || y<1 || y>l) //碰到边界后停止递归
		return;
	if (top[x][y] != '*') //碰到已经排查过的点也停止递归
		return;
	int cnt = CountLandMine(bottom, x, y);
	top[x][y] = cnt + '0';
	if (cnt == 0) { //只有当一个点周围不存在任何雷点时，按四个方向依次递归
		SearchLandMine(top, bottom, x - 1, y, r, l); //向上递归
		SearchLandMine(top, bottom, x + 1, y, r, l); //向下递归
		SearchLandMine(top, bottom, x, y - 1, r, l); //向左递归
		SearchLandMine(top, bottom, x, y + 1, r, l); //向右递归
	}
	return; //当格子周围有雷时，统计雷点数量并停止递归
}

int SignLandMine(char top[][110], char bottom[][110], int x, int y, int r, int l,int num,int mnum) {
	int used = LimitSign(top, r, l);
	if (used < mnum) {
		top[x][y] = 'F';
		used++;
		if (bottom[x][y] == '1') {
			num--;
		}
		printf("本局游戏共有%d颗雷，%d个标记，已使用%d个标记，还剩余%d个标记\n", mnum, mnum, used, mnum - used);
	}
	else {
		printf("无多余的标记可用，请先移除其他位置的标记！\n");
	}
	PrintArr(top, r, l);
	return num;
}

int CancelSign(char top[][110], char bottom[][110], int x, int y, int r, int l,int num) {
	top[x][y] = '*';
	if (bottom[x][y] == '1') {
		num++;
	}
	PrintArr(top, r, l);
	return num;
}

int LimitSign(char top[][110], int r, int l) {
	int fnum = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= l; j++) {
			if (top[i][j] == 'F')
				fnum++;
		}
	}
	return fnum;
}

int Select1(char top[][110], char bottom[][110], int r, int l) {
	int x = 0, y = 0, n = 1;
	while (n) {
		printf("请输入要排雷的坐标(行，列)：");
		scanf("%d %d", &x, &y);
		if (x > 0 && y > 0 && x < r + 2 && y < l + 2) {
			n = 0;
			int flag = FindLandMine(top, bottom, x, y, r, l);
			if (flag == 1)
				return 1;
		}
		else {
			printf("输入的坐标不合法，请重新输入！\n");
		}
	}
	return 0;
}

int Select2(char top[][110], char bottom[][110], int r, int l, int num, int mnum) {
	int x = 0, y = 0, n = 1;
	while (n) {
		printf("请输入要标记的位置(行，列)：");
		scanf("%d %d", &x, &y);
		if (x<1 || x>r || y<1 || y>l) {
			printf("标记位置不合法，请重新输入！\n");
		}
		else if (top[x][y] != '*') {
			printf("无法标记已排查过的位置，请重新输入！\n");
		}
		else {
			num = SignLandMine(top, bottom, x, y, r, l, num, mnum);
			n = 0;
		}
	}
	return num;
}

int Select3(char top[][110], char bottom[][110], int r, int l,int num) {
	int x = 0, y = 0, n = 1;
	while (n) {
		printf("请输入要取消标记的位置(行，列)：");
		scanf("%d %d", &x, &y);
		if (x<1 || x>r || y<1 || y>l) {
			printf("取消标记位置不合法，请重新输入！\n");
		}
		else if (top[x][y] != 'F') {
			printf("该位置不是原有标记位置，请重新输入！\n");
		}
		else {
			num = CancelSign(top, bottom, x, y, r, l, num);
			n = 0;
		}
	}
	return num;
}


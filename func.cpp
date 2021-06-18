#include"convention.h"
#include"func.h"
#include<Windows.h>
#include<iostream>
//胜利的宣告
void win(int user) {
	std::cout << "User " << user << " win!!!" << std::endl << "Congratuations!!!" << std::endl;
	system("pause");
	exit(0);
}
//打印棋盘
void printBoard(int** board) {
	system("cls");
	//棋盘边的小数字
	printf("①②③④⑤⑥⑦⑧⑨⑩1112131415\n");

	for (int i = 0; i < BOARD_LENTH; i++) {
		for (int j = 0; j < BOARD_LENTH; j++) {
			switch (board[i][j]) {
			case 2:std::cout << "□"; break;
			case 1:

				std::cout << "●";
				break;
			case 0:
				//变红色
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
					FOREGROUND_RED);
				std::cout << "●"; 
				//变回去
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
					FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				
				break;

			}
		}
		//棋盘边的小数字
		std::cout << i+1<<std::endl;
	}
	//棋盘边的小数字
	printf("①②③④⑤⑥⑦⑧⑨⑩1112131415\n");
}
//落子可行性检测
bool check(int** board,int x, int y) {
	if (board[x][y] == EMPTY) {
		for (int i = max(0, x - 1); i < min(BOARD_LENTH, x + 2); i++) {
			for (int j = max(0, y - 1); j < min(BOARD_LENTH, y + 2); j++)
				if (board[i][j] != EMPTY) {
					return true;
					
				}
		}

	}
	return false;
}
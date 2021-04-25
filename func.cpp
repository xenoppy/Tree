#include"node.h"
#include"func.h"
#include<iostream>
bool judge(int** board,int user) {
	//横向检查
	for (int i = 0; i < BOARD_LENTH; i++) {
		int j = 0, sum = 0;
		while (j < BOARD_LENTH) {
			if (board[i][j] == user) {
				sum = sum + 1;
			}
			else {
				sum = 0;
			}
			if (sum == 5)return true;
			j++;
		}
	}
	//纵向检查
	for (int i = 0; i < BOARD_LENTH; i++) {
		int j = 0, sum = 0;
		while (j < BOARD_LENTH) {
			if (board[j][i] == user) {
				sum = sum + 1;
			}
			else {
				sum = 0;
			}
			if (sum == 5)return true;
			j++;
		}
	}
	//斜方向检查（右下
	for (int i = 0; i <BOARD_LENTH * 2-1; i++) {
		int j = 0, sum = 0;
		while (j < BOARD_LENTH&&i-j<BOARD_LENTH) {
			if (board[j][i - j] == user) {
				sum = sum + 1;
			}
			else {
				sum = 0;
			}
			if (sum == 5)return true;
			j++;
		}
	}
	//斜方向检查（右上
	for (int i = 1-BOARD_LENTH; i <= BOARD_LENTH-1; i++) {
		int j = 0, sum = 0;
		while (j < BOARD_LENTH&&j+i<BOARD_LENTH) {
			if (board[j][i+j] == user) {
				sum = sum + 1;
			}
			else {
				sum = 0;
			}
			if (sum == 5)return true;
			j++;
		}
		return false;
	}
}
void win(int user) {
	std::cout << "User " << user << " win!!!" << std::endl << "Congratuations!!!" << std::endl;
}

void printBoard(int** board) {
	system("cls");
	for (int i = 0; i < BOARD_LENTH; i++) {
		for (int j = 0; j < BOARD_LENTH; j++) {
			switch (board[i][j]) {
			case 0:std::cout << "□"; break;
			case 1:std::cout << "●"; break;
			case 2:std::cout << "○"; break;

			}
		}
		std::cout << std::endl;
	}
	system("pause");
}
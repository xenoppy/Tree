#include"node.h"
#include"func.h"
#include<iostream>
int max(int x, int y) {
	if (x > y)return x;
	else return y;
}
int min(int x, int y) {
	if (x < y)return x;
	else return y;
}
bool judge(int** board,int user,int x,int y) {
	int sum1, sum2, score = 0, a[5] = { 0,0,0,0,0 };
	//横向检查
	sum1 = 0;
	sum2 = 0;
	for (int i = x; i > max(0, x - 5); i--) {
		if (board[i][y] == user) {
			sum1=sum1+1;
		}
		else break;
	}
	for (int i = x; i < min(BOARD_LENTH, x + 5); i++) {
		if (board[i][y] == user) {
			sum2=sum2 + 1;
		}
		else break;
	}
	if ((sum1 + sum2) > 5) return true;
	//纵向检查
	sum1 = 0;
	sum2 = 0;
	for (int i = y; i > max(-1, y - 5); i--) {
		if (board[x][i] == user) {
			sum1++;
		}
		else break;
	}
	for (int i = y; i < min(BOARD_LENTH+1, y + 5); i++) {
		if (board[x][i] == user) {
			sum2++;
		}
		else break;
	}
	if ((sum1 + sum2) > 5) return true;
	//左上右下检查
	sum1 = 0;
	sum2 = 0;
	for (int i = 0; i > -5; i--) {
		if ((x + i) >= 0 && (y + i) >= 0) {
			if (board[x + i][y + i] == user) {
				sum1++;
			}
			else break;
		}
		else break;
	}
	for (int i = 0; i < 5; i++) {
		if ((x + i) < BOARD_LENTH && (y + i) < BOARD_LENTH) {
			if (board[x + i][y + i] == user) {
				sum2++;
			}
			else break;
		}
		else break;
	}
	if ((sum1 + sum2) > 5) return true;
	//右上左下检查
	sum1 = 0;
	sum2 = 0;
	for (int i = 0; i > -5; i--) {
		if ((x + i) >= 0 && (y - i) >= 0) {
			if (board[x + i][y - i] == user) {
				sum1++;
			}
			else break;
		}
		else break;
	}
	for (int i = 0; i < 5; i++) {
		if ((x + i) < BOARD_LENTH && (y - i) < BOARD_LENTH) {
			if (board[x + i][y - i] == user) {
				sum2++;
			}
			else break;
		}
		else break;
	}
	if ((sum1 + sum2) > 5) return true;
	return false;
	
}
void win(int user) {
	std::cout << "User " << user << " win!!!" << std::endl << "Congratuations!!!" << std::endl;
	system("pause");
}

void printBoard(int** board) {
	system("cls");
	for (int i = 0; i < BOARD_LENTH; i++) {
		for (int j = 0; j < BOARD_LENTH; j++) {
			switch (board[i][j]) {
			case 2:std::cout << "□"; break;
			case 1:std::cout << "●"; break;
			case 0:std::cout << "○"; break;

			}
		}
		std::cout << std::endl;
	}
	system("pause");
}
//int** copy(int** from) {
//	int** goal = InitializeBoard();
//	for (int i = 0; i < BOARD_LENTH; i++) {
//		for (int j = 0; j < BOARD_LENTH; j++) {
//			goal[i][j] = from[i][j];
//		}
//	}
//	return goal;
//}
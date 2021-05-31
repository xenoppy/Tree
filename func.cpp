#include"node.h"
#include"func.h"
#include<Windows.h>
#include<iostream>
bool judge(int** board,int user,int x,int y) {

	return true;
	//int sum1, sum2, score = 0, a[5] = { 0,0,0,0,0 };
	////横向检查
	//sum1 = 0;
	//sum2 = 0;
	//for (int i = x; i > max(0, x - 5); i--) {
	//	if (board[i][y] == user) {
	//		sum1=sum1+1;
	//	}
	//	else break;
	//}
	//for (int i = x; i < min(BOARD_LENTH, x + 5); i++) {
	//	if (board[i][y] == user) {
	//		sum2=sum2 + 1;
	//	}
	//	else break;
	//}
	//if ((sum1 + sum2) > 5) return true;
	////纵向检查
	//sum1 = 0;
	//sum2 = 0;
	//for (int i = y; i > max(-1, y - 5); i--) {
	//	if (board[x][i] == user) {
	//		sum1++;
	//	}
	//	else break;
	//}
	//for (int i = y; i < min(BOARD_LENTH+1, y + 5); i++) {
	//	if (board[x][i] == user) {
	//		sum2++;
	//	}
	//	else break;
	//}
	//if ((sum1 + sum2) > 5) return true;
	////左上右下检查
	//sum1 = 0;
	//sum2 = 0;
	//for (int i = 0; i > -5; i--) {
	//	if ((x + i) >= 0 && (y + i) >= 0) {
	//		if (board[x + i][y + i] == user) {
	//			sum1++;
	//		}
	//		else break;
	//	}
	//	else break;
	//}
	//for (int i = 0; i < 5; i++) {
	//	if ((x + i) < BOARD_LENTH && (y + i) < BOARD_LENTH) {
	//		if (board[x + i][y + i] == user) {
	//			sum2++;
	//		}
	//		else break;
	//	}
	//	else break;
	//}
	//if ((sum1 + sum2) > 5) return true;
	////右上左下检查
	//sum1 = 0;
	//sum2 = 0;
	//for (int i = 0; i > -5; i--) {
	//	if ((x + i) >= 0 && (y - i) >= 0) {
	//		if (board[x + i][y - i] == user) {
	//			sum1++;
	//		}
	//		else break;
	//	}
	//	else break;
	//}
	//for (int i = 0; i < 5; i++) {
	//	if ((x + i) < BOARD_LENTH && (y - i) < BOARD_LENTH) {
	//		if (board[x + i][y - i] == user) {
	//			sum2++;
	//		}
	//		else break;
	//	}
	//	else break;
	//}
	//if ((sum1 + sum2) > 5) return true;
	//return false;
	
}
void win(int user) {
	std::cout << "User " << user << " win!!!" << std::endl << "Congratuations!!!" << std::endl;
	system("pause");
	exit(0);
}

void printBoard(int** board) {
	system("cls");
	printf("①②③④⑤⑥⑦⑧⑨⑩1112131415\n");

	for (int i = 0; i < BOARD_LENTH; i++) {
		for (int j = 0; j < BOARD_LENTH; j++) {
			switch (board[i][j]) {
			case 2:std::cout << "□"; break;
			case 1:

				std::cout << "●";
				break;
			case 0:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
					FOREGROUND_RED);

				std::cout << "●"; 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
					FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				break;

			}
		}
		std::cout << i+1<<std::endl;
	}
	printf("①②③④⑤⑥⑦⑧⑨⑩1112131415\n");
}
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
//int** copy(int** from) {
//	int** goal = InitializeBoard();
//	for (int i = 0; i < BOARD_LENTH; i++) {
//		for (int j = 0; j < BOARD_LENTH; j++) {
//			goal[i][j] = from[i][j];
//		}
//	}
//	return goal;
//}
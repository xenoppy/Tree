#include<iostream>
#include"algorithm.h"
#include"func.h"
#include"node.h"
void evaluate(int** board,int user,int x,int y,int* temp) {
	int sum1,sum2,score=0,a[5] = { 0,0,0,0,0 };
	//横向检查
	sum1 = 0;
	sum2 = 0;
	for (int i = x; i >max(-1,x-5) ; i--) {
		if (board[i][y] == user) {
			sum1++;
		}
		else break;
	}
	for (int i = x; i <min(BOARD_LENTH, x +5); i++) {
		if (board[i][y] == user) {
			sum2++;
		}
		else break;
	}
	score = score +pow(10, (sum1 + sum2-2));
	//纵向检查
	sum1 = 0;
	sum2 = 0;
	for (int i = y; i > max(-1, y - 5); i--) {
		if (board[x][i] == user) {
			sum1++;
		}
		else break;
	}
	for (int i =y; i < min(BOARD_LENTH, y + 5); i++) {
		if (board[x][i] == user) {
			sum2++;
		}
		else break;
	}
	score = score +pow(10, (sum1 + sum2 - 2));
	//左上右下检查
	sum1 = 0;
	sum2 = 0;
	for (int i = 0; i >-5; i--) {
		if ((x + i) >= 0 && (y + i) >= 0) {
			if (board[x + i][y + i] == user) {
				sum1++;
			}
			else break;
		}
		else break;
	}
	for (int i = 0; i <5; i++) {
		if ((x + i) < BOARD_LENTH && (y + i)<BOARD_LENTH) {
			if (board[x + i][y + i] == user) {
				sum2++;
			}
			else break;
		}
		else break;
	}
	score = score +pow(10, (sum1 + sum2 -2));
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
	score = score +pow(10, (sum1 + sum2 - 2));
	////纵向检查
	//for (int i = 0; i < BOARD_LENTH; i++) {
	//	int j = 0, sum = 0;
	//	while (j < BOARD_LENTH) {
	//		if (board[j][i] == user) {
	//			sum = sum + 1;
	//			if (sum > 4)score = +1000000;
	//			else a[sum - 1]++;
	//		}
	//		else {
	//			sum = 0;
	//		}
	//		j++;
	//	}
	//}
	////斜方向检查（右下
	//for (int i = 0; i < BOARD_LENTH * 2 - 1; i++) {
	//	int j = 0, sum = 0;
	//	while (j >= 0 && i - j >= 0 && j < BOARD_LENTH && i - j < BOARD_LENTH) {
	//		if (board[j][i - j] == user) {
	//			sum = sum + 1;
	//			if (sum > 4)score = +1000000;
	//			else a[sum - 1]++;
	//		}
	//		else {
	//			sum = 0;
	//		}
	//		j++;
	//	}
	//}
	////斜方向检查（右上
	//for (int i = 1 - BOARD_LENTH; i <= BOARD_LENTH - 1; i++) {
	//	int j = 0, sum = 0;
	//	while (i + j >= 0 && j < BOARD_LENTH && j + i < BOARD_LENTH) {
	//		if (board[j][i + j] == user) {
	//			sum = sum + 1;
	//			if (sum > 4)score = +1000000;
	//			else a[sum - 1]++;
	//		}
	//		else {
	//			sum = 0;
	//		}
	//		j++;
	//	}
	//}
	//int k = 1;
	//for (int i = 0; i < 5; i++) {
	//	score = score+ k * a[i];
	//	k = k * 10;
	//}
	//score = score * (user * 2 - 1);
	* temp = (*temp) + (user*2-1)*score;
}
int search(int ** Board, int user, int times,int* temp) {
	int max_score = -2147483647*(1- user * 2 ),save;
	int** preBoard;
	int** finBoard=copy(Board);
		
	if (times == 0) {
		//找到该层的极值
		for (int i = 0; i < BOARD_LENTH; i++) {
			for (int j = 0; j < BOARD_LENTH; j++) {
				preBoard = copy(Board);
				if (preBoard[i][j] == EMPTY) {
					int t = *temp;
					preBoard[i][j] = user;
					evaluate(preBoard, user, i, j, &t);
					if (t*(user*2-1) > max_score) {
						max_score = t;
					}
				freeBoard(preBoard);
				}
			}
		}
		freeBoard(finBoard);
		return max_score;
	}
	else {
		//找到该层的极值
		for (int i = 0; i < BOARD_LENTH; i++) {
			for (int j = 0; j < BOARD_LENTH; j++) {
				preBoard = copy(Board);
				if (preBoard[i][j] == EMPTY) {
					int t = *temp;
					preBoard[i][j] = user;
					save = search(preBoard, 1-user, times - 1, &t);
					if (save*(user*2-1) > max_score) {
						max_score = save;
						finBoard = copy(preBoard);
					}
				}
				freeBoard(preBoard);
			}
		}
//		printBoard(finBoard);
		freeBoard(finBoard);
		return save;
	}
	return 0;
}
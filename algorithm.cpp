#include<iostream>
#include"algorithm.h"
#include"func.h"
#include"node.h"
void evaluate(int** board,int user,int x,int y,int* temp) {
	int sum1,sum2,score=0,a[6] = { 0,10,100,1000,10000,100000 };
	////横向检查
	//sum1 = 0;
	//sum2 = 0;
	//int minus;
	//minus = 0;
	//for (int i = x; i >max(-1,x-5) ; i--) {
	//	if (board[i][y] == user) {
	//		sum1++;
	//		if (i == 0) {
	//			minus = minus + 1;
	//			break;
	//		}
	//	}
	//	else if (board[i][y] == 1-user) {
	//		minus=1+minus;
	//		break;
	//	}
	//	else break;
	//}
	//for (int i = x; i <min(BOARD_LENTH, x +5); i++) {
	//	if (board[i][y] == user) {
	//		sum2++; 
	//		if (i == BOARD_LENTH - 1) {
	//			minus = minus + 1;
	//			break;
	//		}
	//	}
	//	else if (board[i][y] ==1-user ) {
	//		minus = 1 + minus;
	//		break;
	//	}
	//	else break;
	//}
	//if (sum1 + sum2 == 6)sum1 = sum1 + 5;
	//if (minus == 2)minus = minus + 3; 
	//score = score + pow(10, (sum1 + sum2-minus - 2));
	//minus = 0;
	////纵向检查
	//sum1 = 0;
	//sum2 = 0;
	//for (int i = y; i > max(-1, y - 5); i--) {
	//	if (board[x][i] == user) {
	//		sum1++; 
	//		if (i == 0) {
	//			minus = minus + 1;
	//			break;
	//		}
	//	}
	//	else if (board[x][i] == 1-user) {
	//		minus=minus+1;
	//		break;
	//	}
	//	else break;
	//}
	//for (int i =y; i < min(BOARD_LENTH, y + 5); i++) {
	//	if (board[x][i] == user) {
	//		sum2++;
	//		if (i == BOARD_LENTH - 1) {
	//			minus = minus + 1;
	//			break;
	//		}
	//	}
	//	else if (board[x][i] == 1 - user) {
	//		minus = minus + 1;
	//		break;
	//	}
	//	else break;
	//}
	//if (sum1 + sum2 == 6)sum1 = sum1 + 5;
	//if (minus == 2)minus = minus + 3; 
	//score = score + pow(10, (sum1 + sum2 - minus - 2));
	//minus = 0;
	////左上右下检查
	//sum1 = 0;
	//sum2 = 0;
	//for (int i = 0; i >-5; i--) {
	//	if ((x + i) >= 0 && (y + i) >= 0) {
	//		if (board[x + i][y + i] == user) {
	//			sum1++;
	//			if (x + i == 0 || y + i == 0) {
	//				minus = minus + 1;
	//				break;
	//			}
	//		}
	//		else if (board[x + i][y + i] ==1-user ) {
	//			minus=minus+1;
	//			break;
	//		}
	//		else break;
	//	}
	//	else break;
	//}
	//for (int i = 0; i <5; i++) {
	//	if ((x + i) < BOARD_LENTH && (y + i)<BOARD_LENTH) {
	//		if (board[x + i][y + i] == user) {
	//			sum2++;
	//			if (x + i == BOARD_LENTH-1 || y + i == BOARD_LENTH - 1) {
	//				minus = minus + 1;
	//				break;
	//			}
	//		}
	//		else if (board[x + i][y + i] == 1-user ) {
	//			minus=minus+1;
	//			break;
	//		}
	//		else break;
	//	}
	//	else break;
	//}
	//if (sum1 + sum2 == 6)sum1 = sum1 + 5;
	//if (minus == 2)minus = minus + 3; 
	//score = score + pow(10, (sum1 + sum2 - minus - 2));
	//minus = 0;
	////右上左下检查
	//sum1 = 0;
	//sum2 = 0;
	//for (int i = 0; i > -5; i--) {
	//	if ((x + i) >= 0 && (y - i) >= 0) {
	//		if (board[x + i][y - i] == user) {
	//			sum1++;
	//			if (x + i ==0 || y - i == 0) {
	//				minus = minus + 1;
	//				break;
	//			}
	//		}
	//		else if (board[x + i][y + i] == 1 - user ) {
	//			minus = minus + 1;
	//			break;
	//		}
	//		else break;
	//	}
	//	else break;
	//}
	//for (int i = 0; i < 5; i++) {
	//	if ((x + i) < BOARD_LENTH && (y - i) < BOARD_LENTH) {
	//		if (board[x + i][y - i] == user) {
	//			sum2++;
	//			if (x + i == BOARD_LENTH - 1 || y - i == BOARD_LENTH - 1) {
	//				minus = minus + 1;
	//				break;
	//			}
	//		}
	//		else if (board[x + i][y + i] == 1 - user ) {
	//			minus = minus + 1;
	//			break;
	//		}
	//		else break;
	//	}
	//	else break;
	//}
	//if (sum1 + sum2 == 6)sum1 = sum1 + 5;
	//if (minus == 2)minus = minus + 3;
	//score = score + pow(10, (sum1 + sum2 - minus - 2));
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
	//横向检查
	
	//有问题：关于连成五子的情况这里判断会过于麻烦了
	if (judge(board, 0, x, y)) {
		*temp = -1000000000;
		return;
	}
	if (judge(board, 1, x, y)) {
		*temp = 1000000000;
	return;
	}
	//横向
	for (int i = 0; i < BOARD_LENTH; i++) {

		sum1 = -1;
		sum2 = -1;
		for (int j = 0; j < BOARD_LENTH; j++) {
			if (board[i][j] == EMPTY) {
				if (sum1 > -1)score = score - a[sum1];
				if (sum2 > -1)score = score + a[sum2];
				sum1 = 0;
				sum2 = 0;
			}
			else if (board[i][j] == 0) {
				sum1 = sum1 + 1;
				sum2 = sum2 - 1;
				if (sum2 > -1)score = score + a[sum2];
				sum2 = -1;
			}
			else {
				sum1 = sum1 - 1;
				sum2 = sum2 + 1;
				if (sum1 > -1)score = score - a[sum1];
				sum1 = -1;
			}
			if (j == BOARD_LENTH - 1) {
				sum1 = sum1 - 1;
				sum2 = sum2 - 1;
				if (sum1 > -1)score = score - a[sum1];
				if (sum2 > -1)score = score + a[sum2];
			}
		}
	}
	//纵向
	for (int j = 0; j < BOARD_LENTH; j++) {

		sum1 = -1;
		sum2 = -1;
		for (int i = 0; i < BOARD_LENTH; i++) {
			if (board[i][j] == EMPTY) {
				if (sum1 > -1)score = score - a[sum1];
				if (sum2 > -1)score = score + a[sum2];
				sum1 = 0;
				sum2 = 0;
			}
			else if (board[i][j] == 0) {
				sum1 = sum1 + 1;
				sum2 = sum2 - 1;
				if (sum2 > -1)score = score + a[sum2];
				sum2 = -1;
			}
			else {
				sum1 = sum1 - 1;
				sum2 = sum2 + 1;
				if (sum1 > -1)score = score - a[sum1];
				sum1 = -1;
			}
			if (j == BOARD_LENTH - 1) {
				sum1 = sum1 - 1;
				sum2 = sum2 - 1;
				if (sum1 > -1)score = score - a[sum1];
				if (sum2 > -1)score = score + a[sum2];
			}
		}
	}
	//
	* temp = score;
}
int search(int ** Board, int user, int times,int* temp) {
	int max_score = -2147483647,save;
	//int saveBoard[17][17];
	////保存
	//for (int i= 0; i < BOARD_LENTH; i++) {
	//	for (int j = 0; j < BOARD_LENTH; j++) {
	//		saveBoard[i][j] = Board[i][j];
	//	}
	//}
		
	if (times == 0) {
		//找到该层的极值
		for (int i = 0; i < BOARD_LENTH; i++) {
			for (int j = 0; j < BOARD_LENTH; j++) {
				if (Board[i][j] == EMPTY) {
					int t = *temp;
					Board[i][j] = user;
					evaluate(Board, user, i, j, &t);
					if (t*(user*2-1) > max_score) {
						max_score = t;
					}

					//复原
					Board[i][j] = EMPTY;
				}
			}
		}
		
		return max_score;
	}
	else {
		//找到该层的极值
		for (int i = 0; i < BOARD_LENTH; i++) {
			for (int j = 0; j < BOARD_LENTH; j++) {
				if (Board[i][j] == EMPTY) {
					int t = *temp;
					Board[i][j] = user;
					save = search(Board, 1-user, times - 1, &t);
					if (save*(user*2-1) > max_score) {
						max_score = save;
					}
					//复原
					Board[i][j] = EMPTY;
				}
			}
		}
		
		return max_score;
	}
	return 0;
}
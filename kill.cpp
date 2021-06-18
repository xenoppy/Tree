#include"kill.h"
#include"convention.h"
#include"func.h"
#include"algorithm.h"
#include<iostream>
#include<Windows.h>
//算杀搜索树
int KillSearch(int** Board, int user,int time, int* temp, int extre) {
	int max_score = -2147483647, save;
	bool killornot = false;
	if (time > 0) {
		for (int i = 0; i < BOARD_LENTH; i++) {
			for (int j = 0; j < BOARD_LENTH; j++) {
				if (check(Board, i, j)) {
					if (checkKill(Board, user, i, j)) {
						killornot = true;
						//在i，j处落子
						int t = *temp;
						Board[i][j] = user;
						//搜索树未抵达底层
						save = KillSearch(Board, 1 - user, time - 1, &t, max_score * (user * 2 - 1));

						if (save * (user * 2 - 1) > max_score) {
							max_score = save * (user * 2 - 1);
						}
						//复原
						Board[i][j] = EMPTY;
						if (max_score > extre * (2 * user - 1)) {
							return extre;
						}

					}
				}
			}
		}
	}
	if (not killornot) {
		//搜索树抵达底层
		int t;
		evaluate(Board, user, 0, 0, &t);
		return t;
	}
	return 0;
}
//检查是否有棋可杀
bool checkKill(int** board, int user, int x, int y) {
	int sum1, sum2, minus1, minus2, score = 0, a[6] = { 1,10,100,1000,1000000,10000000000000 };
	//横向检查
	sum1 = 0;
	sum2 = 0;
	int minus;
	minus = 0;
	for (int i = x; i >max(-1,x-5) ; i--) {
		if (board[i][y] == user) {
			sum1++;
			if (i == 0) {
				minus = minus + 1;
				break;
			}
		}
		else if (board[i][y] == 1-user) {
			minus=1+minus;
			break;
		}
		else break;
	}
	for (int i = x; i <min(BOARD_LENTH, x +5); i++) {
		if (board[i][y] == user) {
			sum2++; 
			if (i == BOARD_LENTH - 1) {
				minus = minus + 1;
				break;
			}
		}
		else if (board[i][y] ==1-user ) {
			minus = 1 + minus;
			break;
		}
		else break;
	}
	if (sum1 + sum2 > 4 && minus < 2)return true;
	minus = 0;
	//纵向检查
	sum1 = 0;
	sum2 = 0;
	for (int i = y; i > max(-1, y - 5); i--) {
		if (board[x][i] == user) {
			sum1++; 
			if (i == 0) {
				minus = minus + 1;
				break;
			}
		}
		else if (board[x][i] == 1-user) {
			minus=minus+1;
			break;
		}
		else break;
	}
	for (int i =y; i < min(BOARD_LENTH, y + 5); i++) {
		if (board[x][i] == user) {
			sum2++;
			if (i == BOARD_LENTH - 1) {
				minus = minus + 1;
				break;
			}
		}
		else if (board[x][i] == 1 - user) {
			minus = minus + 1;
			break;
		}
		else break;
	}
	if (sum1 + sum2 > 4 && minus < 2)return true;
	minus = 0;
	//左上右下检查
	sum1 = 0;
	sum2 = 0;
	for (int i = 0; i >-5; i--) {
		if ((x + i) >= 0 && (y + i) >= 0) {
			if (board[x + i][y + i] == user) {
				sum1++;
				if (x + i == 0 || y + i == 0) {
					minus = minus + 1;
					break;
				}
			}
			else if (board[x + i][y + i] ==1-user ) {
				minus=minus+1;
				break;
			}
			else break;
		}
		else break;
	}
	for (int i = 0; i <5; i++) {
		if ((x + i) < BOARD_LENTH && (y + i)<BOARD_LENTH) {
			if (board[x + i][y + i] == user) {
				sum2++;
				if (x + i == BOARD_LENTH-1 || y + i == BOARD_LENTH - 1) {
					minus = minus + 1;
					break;
				}
			}
			else if (board[x + i][y + i] == 1-user ) {
				minus=minus+1;
				break;
			}
			else break;
		}
		else break;
	}
	if (sum1 + sum2 > 4 && minus < 2)return true;
	minus = 0;
	//右上左下检查
	sum1 = 0;
	sum2 = 0;
	for (int i = 0; i > -5; i--) {
		if ((x + i) >= 0 && (y - i) >= 0) {
			if (board[x + i][y - i] == user) {
				sum1++;
				if (x + i ==0 || y - i == 0) {
					minus = minus + 1;
					break;
				}
			}
			else if (board[x + i][y + i] == 1 - user ) {
				minus = minus + 1;
				break;
			}
			else break;
		}
		else break;
	}
	for (int i = 0; i < 5; i++) {
		if ((x + i) < BOARD_LENTH && (y - i) < BOARD_LENTH) {
			if (board[x + i][y - i] == user) {
				sum2++;
				if (x + i == BOARD_LENTH - 1 || y - i == BOARD_LENTH - 1) {
					minus = minus + 1;
					break;
				}
			}
			else if (board[x + i][y + i] == 1 - user ) {
				minus = minus + 1;
				break;
			}
			else break;
		}
		else break;
	}
	if (sum1 + sum2 > 4 && minus < 2)return true;
	minus = 0;


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

	/*有问题：关于连成五子的情况这里判断会过于麻烦了
	/*if (judge(board, 0, x, y)) {
		*temp = -1000000000;
		return;
	}
	if (judge(board, 1, x, y)) {
		*temp = 1000000000;
	return;
	}*/
	//横向
	/*for (int i = 0; i < BOARD_LENTH; i++) {
		minus1 = 1;
		minus2 = 1;
		sum1 = 0;
		sum2 = 0;
		for (int j = 0; j < BOARD_LENTH; j++) {
			if (board[i][j] == EMPTY) {
				if (sum1 - minus1 > -1)score = score - 1.1 * a[sum1 - minus1];
				if (sum2 - minus2 > -1)score = score + a[sum2 - minus2];
				//检查是否胜利
				if (sum1 == 5) {
					*temp = -10000000000000;
					return;
				}
				else if (sum2 == 5) {
					*temp = 10000000000000;
					return;
				}
				sum1 = 0;
				sum2 = 0;
				minus1 = 0;
				minus2 = 0;
			}
			else if (board[i][j] == 0) {
				sum1 = sum1 + 1;
				minus2 = minus2 + 1;
				if (sum2 - minus2 > -1)score = score + a[sum2 - minus2];

				//检查是否胜利
				if (sum1 == 5) {
					*temp = -10000000000000;
					return;
				}
				else if (sum2 == 5) {
					*temp = 10000000000000;
					return;
				}
				sum2 = 0;
				minus2 = 1;
			}
			else {
				minus1 = minus1 + 1;
				sum2 = sum2 + 1;
				if (sum1 - minus1 > -1)score = score - 1.1 * a[sum1 - minus1];
				//检查是否胜利
				if (sum1 == 5) {
					*temp = -10000000000000;
					return;
				}
				else if (sum2 == 5) {
					*temp = 10000000000000;
					return;
				}
				sum1 = 0;
				minus1 = 1;
			}
		}
		minus1 = minus1 + 1;
		minus2 = minus2 + 1;
		if (sum1 == 5) {
			*temp = -10000000000000;
			return;
		}
		else if (sum2 == 5) {
			*temp = 10000000000000;
			return;
		}
		else {
			if (sum1 - minus1 > -1)score = score - 1.1 * a[sum1 - minus1];
			if (sum2 - minus2 > -1)score = score + a[sum2 - minus2];
		}
	}

	//纵向
	for (int j = 0; j < BOARD_LENTH; j++) {
		minus1 = 1;
		minus2 = 1;
		sum1 = 0;
		sum2 = 0;
		for (int i = 0; i < BOARD_LENTH; i++) {
			if (board[i][j] == EMPTY) {
				if (sum1 - minus1 > -1)score = score - 1.1 * a[sum1 - minus1];
				if (sum2 - minus2 > -1)score = score + a[sum2 - minus2];
				//检查是否胜利
				if (sum1 == 5) {
					*temp = -10000000000000;
					return;
				}
				else if (sum2 == 5) {
					*temp = 10000000000000;
					return;
				}
				sum1 = 0;
				sum2 = 0;
				minus1 = 0;
				minus2 = 0;
			}
			else if (board[i][j] == 0) {
				sum1 = sum1 + 1;
				minus2 = minus2 + 1;
				if (sum2 - minus2 > -1)score = score + a[sum2 - minus2];

				//检查是否胜利
				if (sum1 == 5) {
					*temp = -10000000000000;
					return;
				}
				else if (sum2 == 5) {
					*temp = 10000000000000;
					return;
				}
				sum2 = 0;
				minus2 = 1;
			}
			else {
				minus1 = minus1 + 1;
				sum2 = sum2 + 1;
				if (sum1 - minus1 > -1)score = score - 1.1 * a[sum1 - minus1];
				//检查是否胜利
				if (sum1 == 5) {
					*temp = -10000000000000;
					return;
				}
				else if (sum2 == 5) {
					*temp = 10000000000000;
					return;
				}
				sum1 = 0;
				minus1 = 1;
			}
		}
		minus1 = minus1 + 1;
		minus2 = minus2 + 1;
		if (sum1 == 5) {
			*temp = -10000000000000;
			return;
		}
		else if (sum2 == 5) {
			*temp = 10000000000000;
			return;
		}
		else {
			if (sum1 - minus1 > -1)score = score - a[sum1 - minus1];
			if (sum2 - minus2 > -1)score = score + a[sum2 - minus2];
		}
	}

	//左下右上
	for (int i = 0; i < BOARD_LENTH * 2 - 1; i++) {
		int j = 0;
		minus1 = 1;
		minus2 = 1;
		sum1 = 0;
		sum2 = 0;

		while (j >= 0 && i - j >= 0 && j < BOARD_LENTH && i - j < BOARD_LENTH) {
			if (board[j][i - j] == EMPTY) {
				if (sum1 - minus1 > -1)score = score - a[sum1 - minus1];
				if (sum2 - minus2 > -1)score = score + a[sum2 - minus2];
				//检查是否胜利
				if (sum1 == 5) {
					*temp = -10000000000000;
					return;
				}
				else if (sum2 == 5) {
					*temp = 10000000000000;
					return;
				}
				sum1 = 0;
				sum2 = 0;
				minus1 = 0;
				minus2 = 0;
			}
			else if (board[j][i - j] == 0) {
				sum1 = sum1 + 1;
				minus2 = minus2 + 1;
				if (sum2 - minus2 > -1)score = score + a[sum2 - minus2];

				//检查是否胜利
				if (sum1 == 5) {
					*temp = -10000000000000;
					return;
				}
				else if (sum2 == 5) {
					*temp = 10000000000000;
					return;
				}
				sum2 = 0;
				minus2 = 1;
			}
			else {
				minus1 = minus1 + 1;
				sum2 = sum2 + 1;
				if (sum1 - minus1 > -1)score = score - 1.1 * a[sum1 - minus1];
				//检查是否胜利
				if (sum1 == 5) {
					*temp = -10000000000000;
					return;
				}
				else if (sum2 == 5) {
					*temp = 10000000000000;
					return;
				}
				sum1 = 0;
				minus1 = 1;
			}
			j++;
		}
		//检查最后边界
		minus1 = minus1 + 1;
		minus2 = minus2 + 1;
		if (sum1 == 5) {
			*temp = -10000000000000;
			return;
		}
		else if (sum2 == 5) {
			*temp = 10000000000000;
			return;
		}
		else {
			if (sum1 - minus1 > -1)score = score - 1.1 * a[sum1 - minus1];
			if (sum2 - minus2 > -1)score = score + a[sum2 - minus2];
		}
	}


	//左上右下
	for (int i = 1 - BOARD_LENTH; i <= BOARD_LENTH - 1; i++) {
		int j = 0;
		minus1 = 1;
		minus2 = 1;
		sum1 = 0;
		sum2 = 0;

		while (i + j >= 0 && j < BOARD_LENTH && j + i < BOARD_LENTH) {
			if (board[j][i + j] == EMPTY) {
				if (sum1 - minus1 > -1)score = score - a[sum1 - minus1];
				if (sum2 - minus2 > -1)score = score + a[sum2 - minus2];
				//检查是否胜利
				if (sum1 == 5) {
					*temp = -10000000000000;
					return;
				}
				else if (sum2 == 5) {
					*temp = 10000000000000;
					return;
				}
				sum1 = 0;
				sum2 = 0;
				minus1 = 0;
				minus2 = 0;
			}
			else if (board[j][i + j] == 0) {
				sum1 = sum1 + 1;
				minus2 = minus2 + 1;
				if (sum2 - minus2 > -1)score = score + a[sum2 - minus2];

				//检查是否胜利
				if (sum1 == 5) {
					*temp = -10000000000000;
					return;
				}
				else if (sum2 == 5) {
					*temp = 10000000000000;
					return;
				}
				sum2 = 0;
				minus2 = 1;
			}
			else {
				minus1 = minus1 + 1;
				sum2 = sum2 + 1;
				if (sum1 - minus1 > -1)score = score - a[sum1 - minus1];
				//检查是否胜利
				if (sum1 == 5) {
					*temp = -10000000000000;
					return;
				}
				else if (sum2 == 5) {
					*temp = 10000000000000;
					return;
				}
				sum1 = 0;
				minus1 = 1;
			}
			j++;
		}
		//检查最后边界
		minus1 = minus1 + 1;
		minus2 = minus2 + 1;
		if (sum1 == 5) {
			*temp = -10000000000000;
			return;
		}
		else if (sum2 == 5) {
			*temp = 10000000000000;
			return;
		}
		else {
			if (sum1 - minus1 > -1)score = score - 1.1 * a[sum1 - minus1];
			if (sum2 - minus2 > -1)score = score + a[sum2 - minus2];
		}
		if (i != 0) {
			j = BOARD_LENTH - 1;
			minus1 = 1;
			minus2 = 1;
			sum1 = 0;
			sum2 = 0;
			while (i + j >= 0 && j < BOARD_LENTH && j + i < BOARD_LENTH) {
				if (board[j][i + j] == EMPTY) {
					if (sum1 - minus1 > -1)score = score - 1.001 * a[sum1 - minus1];
					if (sum2 - minus2 > -1)score = score + a[sum2 - minus2];
					//检查是否胜利
					if (sum1 == 5) {
						*temp = -10000000000000;
						return;
					}
					else if (sum2 == 5) {
						*temp = 10000000000000;
						return;
					}
					sum1 = 0;
					sum2 = 0;
					minus1 = 0;
					minus2 = 0;
				}
				else if (board[j][i + j] == 0) {
					sum1 = sum1 + 1;
					minus2 = minus2 + 1;
					if (sum2 - minus2 > -1)score = score + a[sum2 - minus2];

					//检查是否胜利
					if (sum1 == 5) {
						*temp = -10000000000000;
						return;
					}
					else if (sum2 == 5) {
						*temp = 10000000000000;
						return;
					}
					sum2 = 0;
					minus2 = 1;
				}
				else {
					minus1 = minus1 + 1;
					sum2 = sum2 + 1;
					if (sum1 - minus1 > -1)score = score - 1.1 * a[sum1 - minus1];
					//检查是否胜利
					if (sum1 == 5) {
						*temp = -10000000000000;
						return;
					}
					else if (sum2 == 5) {
						*temp = 10000000000000;
						return;
					}
					sum1 = 0;
					minus1 = 1;
				}
				j--;
			}
			//检查最后边界
			minus1 = minus1 + 1;
			minus2 = minus2 + 1;
			if (sum1 == 5) {
				*temp = -10000000000000;
				return;
			}
			else if (sum2 == 5) {
				*temp = 10000000000000;
				return;
			}
			else {
				if (sum1 - minus1 > -1)score = score - 1.1 * a[sum1 - minus1];
				if (sum2 - minus2 > -1)score = score + a[sum2 - minus2];
			}
		}

	}

	*temp = score;*/
return false;
}

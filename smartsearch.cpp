#include "smartsearch.h"
#include "func.h"
#include "convention.h"
#include "func.h"

int smartevaluate(int** board, int x, int y,int user) {
	int sum1, sum2, minus1, minus2, score = 0, a[6] = { 1,10,100,1000,1000000,10000000000000 };
	//横向检查
	sum1 = 0;
	sum2 = 0;
	int minus;
	minus = 0;
	for (int i = x; i > max(-1, x - 5); i--) {
		if (board[i][y] == user) {
			sum1++;
			if (i == 0) {
				minus = minus + 1;
				break;
			}
		}
		else if (board[i][y] == 1 - user) {
			minus = 1 + minus;
			break;
		}
		else break;
	}
	for (int i = x; i < min(BOARD_LENTH, x + 5); i++) {
		if (board[i][y] == user) {
			sum2++;
			if (i == BOARD_LENTH - 1) {
				minus = minus + 1;
				break;
			}
		}
		else if (board[i][y] == 1 - user) {
			minus = 1 + minus;
			break;
		}
		else break;
	}
	if (sum1 + sum2 > 4 && minus < 2) score=score+sum1+sum2-minus;
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
		else if (board[x][i] == 1 - user) {
			minus = minus + 1;
			break;
		}
		else break;
	}
	for (int i = y; i < min(BOARD_LENTH, y + 5); i++) {
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
	if (sum1 + sum2 > 4 && minus < 2)score=score+sum1+sum2-minus;
	minus = 0;
	//左上右下检查
	sum1 = 0;
	sum2 = 0;
	for (int i = 0; i > -5; i--) {
		if ((x + i) >= 0 && (y + i) >= 0) {
			if (board[x + i][y + i] == user) {
				sum1++;
				if (x + i == 0 || y + i == 0) {
					minus = minus + 1;
					break;
				}
			}
			else if (board[x + i][y + i] == 1 - user) {
				minus = minus + 1;
				break;
			}
			else break;
		}
		else break;
	}
	for (int i = 0; i < 5; i++) {
		if ((x + i) < BOARD_LENTH && (y + i) < BOARD_LENTH) {
			if (board[x + i][y + i] == user) {
				sum2++;
				if (x + i == BOARD_LENTH - 1 || y + i == BOARD_LENTH - 1) {
					minus = minus + 1;
					break;
				}
			}
			else if (board[x + i][y + i] == 1 - user) {
				minus = minus + 1;
				break;
			}
			else break;
		}
		else break;
	}
	if (sum1 + sum2 > 4 && minus < 2)score=score+sum1+sum2-minus;
	minus = 0;
	//右上左下检查
	sum1 = 0;
	sum2 = 0;
	for (int i = 0; i > -5; i--) {
		if ((x + i) >= 0 && (y - i) >= 0) {
			if (board[x + i][y - i] == user) {
				sum1++;
				if (x + i == 0 || y - i == 0) {
					minus = minus + 1;
					break;
				}
			}
			else if (board[x + i][y + i] == 1 - user) {
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
			else if (board[x + i][y + i] == 1 - user) {
				minus = minus + 1;
				break;
			}
			else break;
		}
		else break;
	}
	if (sum1 + sum2 > 4 && minus < 2)score=score+sum1+sum2-minus;
	return score;
}
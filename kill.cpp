#include"kill.h"
#include"convention.h"
#include"func.h"
#include"algorithm.h"
#include<iostream>
int KillSearch(int** Board, int user, int times, int* temp, int extre) {
	int max_score = -2147483647, save;
	if (times == 1) {
		//找到该层的极值
		for (int i = 0; i < BOARD_LENTH; i++) {
			for (int j = 0; j < BOARD_LENTH; j++) {
				if (check(Board, i, j)) {
					int t = *temp;
					Board[i][j] = user;
					evaluate(Board, user, i, j, &t);
					if (t * (user * 2 - 1) > max_score) {
						max_score = t * (user * 2 - 1);
					}

					//复原
					Board[i][j] = EMPTY;
				}
			}
		}

		return max_score * (user * 2 - 1);
	}
	else {
		//找到该层的极值
		for (int i = 0; i < BOARD_LENTH; i++) {
			for (int j = 0; j < BOARD_LENTH; j++) {
				if (check(Board, i, j)) {
					int t = *temp;
					Board[i][j] = user;
					save = search(Board, 1 - user, times - 1, &t, max_score * (user * 2 - 1));
					if (times == DEPTH - 1) {//阿尔法贝塔剪枝
						if (abs(save) > 1000000) {
							if (save * (user * 2 - 1) > 1000000 * (user * 2 - 1))return 100000000 * (user * 2 - 1);

						}
					}
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

		return max_score * (user * 2 - 1);
	}
	return 0;
}
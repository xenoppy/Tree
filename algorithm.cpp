#include<iostream>
#include"algorithm.h"
#include"kill.h"
#include"func.h"
#include"convention.h"
void initialize(int* sum1, int* sum2, int* minus1, int* minus2) {
	*minus1 = 1;
	*minus2 = 1;
	*sum1 = 0;
	*sum2 = 0;

}
bool checkwin(int* sum1,int* sum2,int* temp) {
	if (*sum1 == 5) {
		*temp = -10000000000000;
		return true;
	}
	else if (*sum2 == 5) {
		*temp = 10000000000000;
		return true;
	}
}
void empty(int* sum1, int* sum2, int* minus1, int* minus2, int* score, int* temp, int* a) {
	if (*sum1 - *minus1 > -1)*score = *score - 1.1 * a[sum1 - minus1];
	if (*sum2 - *minus2 > -1)*score = *score + a[sum2 - minus2];

}
void emptyback(int* sum1, int* sum2, int* minus1, int* minus2, int* score, int* temp, int* a) {

	*sum1 = 0;
	*sum2 = 0;
	*minus1 = 0;
	*minus2 = 0;
}

void white(int* sum1, int* sum2, int* minus1, int* minus2, int* score, int* temp, int* a) {
	*sum1 = *sum1 + 1;
	*minus2 = *minus2 + 1;
	if (*sum2 - *minus2 > -1)*score = *score + a[sum2 - minus2];
}
void whiteback(int* sum1, int* sum2, int* minus1, int* minus2, int* score, int* temp, int* a) {

	*sum2 = 0;
	*minus2 = 1;
}

void black(int* sum1, int* sum2, int* minus1, int* minus2, int* score, int* temp, int* a) {
	*minus1 = *minus1 + 1;
	*sum2 = *sum2 + 1;
	if (*sum1 - *minus1 > -1)*score = *score - 1.1 * a[sum1 - minus1];

}
void blackback(int* sum1, int* sum2, int* minus1, int* minus2, int* score, int* temp, int* a) {


	*sum1 = 0;
	*minus1 = 1;
}
void evaluate(int** board,int user,int x,int y,int* temp) {
	int sum1,sum2,minus1,minus2,score=0,a[6] = { 1,10,100,1000,1000000,10000000000000 };
	initialize(&sum1, &sum2, &minus1, &minus2);
	//横向
	for (int i = 0; i < BOARD_LENTH; i++) {
		
		for (int j = 0; j < BOARD_LENTH; j++) {
			if (board[i][j] == EMPTY) {
				empty(&sum1, &sum2, &minus1, &minus2, &score, temp, a);
				if (checkwin(&sum1, &sum2,  temp))return;
				emptyback(&sum1, &sum2, &minus1, &minus2, &score, temp, a);
			}
			else if (board[i][j] == WHITE) {
				white(&sum1, &sum2, &minus1, &minus2, &score, temp, a);
				//检查是否胜利
				if (checkwin(&sum1, &sum2,  temp))return;
				whiteback(&sum1, &sum2, &minus1, &minus2, &score, temp, a);
				
	
				
			}
			else {//黑棋				
				black(&sum1, &sum2, &minus1, &minus2, &score, temp, a);
				//检查是否胜利
				if (checkwin(&sum1, &sum2,  temp))return;
				blackback(&sum1, &sum2, &minus1, &minus2, &score, temp, a);

			}
		}
		//抵达边界
		minus1 ++ ;
		minus2 ++ ;
		if (checkwin(&sum1, &sum2, temp)) {
			return;
		}
		else {//结账
			if (sum1 - minus1 > -1)score = score - 1.1 * a[sum1 - minus1];
			if (sum2 - minus2 > -1)score = score + a[sum2 - minus2];
		}
	}
	
	//纵向
	for (int j = 0; j < BOARD_LENTH; j++) {
		initialize(&sum1, &sum2, &minus1, &minus2);
		for (int i = 0; i < BOARD_LENTH; i++) {
			if (board[i][j] == EMPTY) {
				empty(&sum1, &sum2, &minus1, &minus2, &score, temp, a);
				if (checkwin(&sum1, &sum2, temp))return;
				emptyback(&sum1, &sum2, &minus1, &minus2, &score, temp, a);
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
		//抵达边界
		minus1++;
		minus2++;
		if (checkwin(&sum1, &sum2, temp)) {
			return;
		}
		else {//结账
			if (sum1 - minus1 > -1)score = score - 1.1 * a[sum1 - minus1];
			if (sum2 - minus2 > -1)score = score + a[sum2 - minus2];
		}
	}
	
	//左下右上
	for (int i = 0; i < BOARD_LENTH * 2 - 1; i++) {
		initialize(&sum1, &sum2, &minus1, &minus2);
		int j = 0;
		

		while (j >= 0 && i - j >= 0 && j < BOARD_LENTH && i - j < BOARD_LENTH) {
			if (board[j][i - j] == EMPTY) {
				empty(&sum1, &sum2, &minus1, &minus2, &score, temp, a);
				if (checkwin(&sum1, &sum2,  temp))return;
				emptyback(&sum1, &sum2, &minus1, &minus2, &score, temp, a);
			}
			else if (board[j][i - j] == WHITE) {
				white(&sum1, &sum2, &minus1, &minus2, &score, temp, a);
				//检查是否胜利
				if (checkwin(&sum1, &sum2, temp))return;
				whiteback(&sum1, &sum2, &minus1, &minus2, &score, temp, a);

			}
			else {//黑棋								
				black(&sum1, &sum2, &minus1, &minus2, &score, temp, a);
				//检查是否胜利
				if (checkwin(&sum1, &sum2,  temp))return;
				blackback(&sum1, &sum2, &minus1, &minus2, &score, temp, a);

			}
			j++;
		}
		//抵达边界
		minus1++;
		minus2++;
		if (checkwin(&sum1, &sum2, temp)) {
			return;
		}
		else {//结账
			if (sum1 - minus1 > -1)score = score - 1.1 * a[sum1 - minus1];
			if (sum2 - minus2 > -1)score = score + a[sum2 - minus2];
		}
	}


	//左上右下
	//该情况需要用两个while去遍历所有路径
	for (int i = 1 - BOARD_LENTH; i <= BOARD_LENTH - 1; i++) {
		initialize(&sum1, &sum2, &minus1, &minus2);
		int j = 0;
		while (i + j >= 0 && j < BOARD_LENTH && j + i < BOARD_LENTH) {
			if (board[j][i + j] == EMPTY) {
				empty(&sum1, &sum2, &minus1, &minus2, &score, temp, a);
				if (checkwin(&sum1, &sum2,  temp))return;
				emptyback(&sum1, &sum2, &minus1, &minus2, &score, temp, a);
			}
			else if (board[j][i + j] == WHITE) {
				white(&sum1, &sum2, &minus1, &minus2, &score, temp, a);
				//检查是否胜利
				if (checkwin(&sum1, &sum2,  temp))return;
				whiteback(&sum1, &sum2, &minus1, &minus2, &score, temp, a);

			}
			else {
				//黑棋				
				black(&sum1, &sum2, &minus1, &minus2, &score, temp, a);
				//检查是否胜利
				if (checkwin(&sum1, &sum2,  temp))return;
				blackback(&sum1, &sum2, &minus1, &minus2, &score, temp, a);

			}
			j++;
		}
		//抵达边界
		minus1++;
		minus2++;
		if (checkwin(&sum1, &sum2, temp)) {
			return;
		}
		else {//结账
			if (sum1 - minus1 > -1)score = score - 1.1 * a[sum1 - minus1];
			if (sum2 - minus2 > -1)score = score + a[sum2 - minus2];
		}

		if (i != 0) {
			initialize(&sum1, &sum2, &minus1, &minus2);
			j = BOARD_LENTH - 1;
			while (i + j >= 0 && j < BOARD_LENTH && j + i < BOARD_LENTH) {
				if (board[j][i + j] == EMPTY) {
					empty(&sum1, &sum2, &minus1, &minus2, &score, temp, a);
					if (checkwin(&sum1, &sum2, temp))return;
					emptyback(&sum1, &sum2, &minus1, &minus2, &score, temp, a);
				}
				else if (board[j][i + j] == WHITE) {
					white(&sum1, &sum2, &minus1, &minus2, &score, temp, a);
					//检查是否胜利
					if (checkwin(&sum1, &sum2, temp))return;
					whiteback(&sum1, &sum2, &minus1, &minus2, &score, temp, a);

				}
				else {//黑棋				
					black(&sum1, &sum2, &minus1, &minus2, &score, temp, a);
					//检查是否胜利
					if (checkwin(&sum1, &sum2,  temp))return;
					blackback(&sum1, &sum2, &minus1, &minus2, &score, temp, a);

				}
				j--;
			}
			//抵达边界
			minus1++;
			minus2++;
			if (checkwin(&sum1, &sum2, temp)) {
				return;
			}
			else {//结账
				if (sum1 - minus1 > -1)score = score - 1.1 * a[sum1 - minus1];
				if (sum2 - minus2 > -1)score = score + a[sum2 - minus2];
			}
		}

	}

	* temp = score;
	return;
}
int search(int ** Board, int user, int times,int* temp,int extre) {
	int max_score = -2147483647,save;


	int t = *temp;
		//找到该层的极值
	KillSearch(Board, user, times + 4, &t, max_score * (user * 2 - 1));//算杀
	for (int i = 0; i < BOARD_LENTH; i++) {
		for (int j = 0; j < BOARD_LENTH; j++) {
			if (check(Board, i, j)) {
				//在i，j处落子
				t = *temp;
				Board[i][j] = user;
				if (times == 1) {
					//搜索树抵达底层
					evaluate(Board, user, i, j, &t);
					if (t * (user * 2 - 1) > max_score) {
						max_score = t * (user * 2 - 1);
					}
					//复原
					Board[i][j] = EMPTY;
				}
				else {
					//搜索树未抵达底层
					save = search(Board, 1 - user, times - 1, &t, max_score * (user * 2 - 1));
					/*if (times == DEPTH - 1) {//阿尔法贝塔剪枝
						if (abs(save) > 1000000) {
							if (save * (user * 2 - 1) > 1000000 * (user * 2 - 1))return 100000000 * (user * 2 - 1);

						}
					}*/
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

	if (times == 1)return max_score * (user * 2 - 1);
	else return max_score * (user * 2 - 1);
	return 0;
}
	
#include<iostream>
#include"algorithm.h"
#include"func.h"
#include"node.h"
int evaluate(int** board,int user) {
	int score=0,a[5] = { 0,0,0,0,0 };
	//横向检查
	for (int i = 0; i < BOARD_LENTH; i++) {
		int j = 0, sum = 0;
		while (j < BOARD_LENTH) {
			if (board[i][j] == user) {
				sum = sum + 1;
				if (sum > 4)score = +1000000;
				else a[sum - 1]++;
			}
			else {
				sum = 0;
			}
			j++;
		}
	}
	//纵向检查
	for (int i = 0; i < BOARD_LENTH; i++) {
		int j = 0, sum = 0;
		while (j < BOARD_LENTH) {
			if (board[j][i] == user) {
				sum = sum + 1;
				if (sum > 4)score = +1000000;
				else a[sum - 1]++;
			}
			else {
				sum = 0;
			}
			j++;
		}
	}
	//斜方向检查（右下
	for (int i = 0; i < BOARD_LENTH * 2 - 1; i++) {
		int j = 0, sum = 0;
		while (j >= 0 && i - j >= 0 && j < BOARD_LENTH && i - j < BOARD_LENTH) {
			if (board[j][i - j] == user) {
				sum = sum + 1;
				if (sum > 4)score = +1000000;
				else a[sum - 1]++;
			}
			else {
				sum = 0;
			}
			j++;
		}
	}
	//斜方向检查（右上
	for (int i = 1 - BOARD_LENTH; i <= BOARD_LENTH - 1; i++) {
		int j = 0, sum = 0;
		while (i + j >= 0 && j < BOARD_LENTH && j + i < BOARD_LENTH) {
			if (board[j][i + j] == user) {
				sum = sum + 1;
				if (sum > 4)score = +1000000;
				else a[sum - 1]++;
			}
			else {
				sum = 0;
			}
			j++;
		}
	}
	int k = 1;
	for (int i = 0; i < 5; i++) {
		score = score+ k * a[i];
		k = k * 10;
	}
	score = score * (user * 2 - 1);
	return score;
}
int search(int ** Board, int user, int times) {
	int max_score = -2147483647;
	int** preBoard = InitializeBoard();
	int** finBoard = InitializeBoard();
	for (int i = 0; i < BOARD_LENTH; i++) {
		for (int j = 0; j < BOARD_LENTH; j++) {
			preBoard = copy(Board);
			if (preBoard[i][j] == EMPTY) {
				preBoard[i][j] = user;
				int t = (user * 2 - 1) * (evaluate(preBoard, 1) + evaluate(preBoard, 0));
				if (t > max_score) {
					max_score = t;
					finBoard = copy(preBoard);
				}
			}			
		}
	}
		
	if (times == 1) {
		return (user * 2 - 1) * max_score;
	}
	else {
		return search(finBoard, 1 - user, times - 1);
	}
	return 0;
}
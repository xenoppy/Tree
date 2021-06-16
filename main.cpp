#include<iostream>
#include"convention.h"
#include"algorithm.h"
#include"put_in.h"
#include"func.h"
using namespace std;
int main() {
	int** board = InitializeBoard();//初始化棋盘
	int temp = 0, whether_First;
	//temp为对全局的评估分数
	evaluate(board, 1, 0, 0, &temp);
	cout << "电脑执先手？Y(1)/N(2)" << endl;
	cin >> whether_First;
	//替电脑下第一步棋
	if (whether_First == 1) {
		board[6][6] = 1;
	}
	printBoard(board);

	//开始对弈
	while (1) {

		User1In(board, &temp);
		printBoard(board);
		//cout << endl << temp << endl;//调试用
		User2In(board, &temp);

		printBoard(board);
	}
	return 0;
}
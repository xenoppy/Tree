#include<iostream>
#include"node.h"
#include"algorithm.h"
#include"put_in.h"
#include"func.h"
using namespace std;
int main() {
	int** board = InitializeBoard();//��ʼ������
	int temp=0;
	evaluate(board, 1, 0, 0, &temp);
	cout << "����ִ���֣�Y(1)/N(2)" << endl;
	int whether_First;
	cin >> whether_First;
	if (whether_First == 1) {
		board[6][6] = 1;
	}
	printBoard(board);
	while (1) {
		
		User1In(board,&temp);
		printBoard(board);
	//	cout << endl << temp << endl;
		User2In(board, &temp);

		printBoard(board);
	//	cout << endl << temp << endl;
	}
	return 0;
}
#include<iostream>
#include"convention.h"
#include"algorithm.h"
#include"put_in.h"
#include"func.h"
using namespace std;
int main() {
	//��ʼ������
	int** board = InitializeBoard();
	int temp = 0, whether_First;
	//tempΪ��ȫ�ֵ���������
	cout << "����ִ���֣�Y(1)/N(2)" << endl;
	cin >> whether_First;
	//������µ�һ����
	if (whether_First == 1) {
		board[6][6] = 1;
	}
	evaluate(board, &temp);
	printBoard(board);

	//��ʼ����
	while (1) {

		cout << endl << temp << endl;//������
		User1In(board, &temp);
		printBoard(board);
		cout << endl << temp << endl;//������
		User2In(board, &temp);

		printBoard(board);
	}
	return 0;
}
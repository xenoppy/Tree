#include<iostream>
#include"convention.h"
#include"algorithm.h"
#include"put_in.h"
#include"func.h"
using namespace std;
int main() {
	int** board = InitializeBoard();//��ʼ������
	int temp = 0, whether_First;
	//tempΪ��ȫ�ֵ���������
	evaluate(board, 1, 0, 0, &temp);
	cout << "����ִ���֣�Y(1)/N(2)" << endl;
	cin >> whether_First;
	//������µ�һ����
	if (whether_First == 1) {
		board[6][6] = 1;
	}
	printBoard(board);

	//��ʼ����
	while (1) {

		User1In(board, &temp);
		printBoard(board);
		//cout << endl << temp << endl;//������
		User2In(board, &temp);

		printBoard(board);
	}
	return 0;
}
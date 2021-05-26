#include<iostream>
#include"node.h"
#include"algorithm.h"
#include"put_in.h"
#include"func.h"
using namespace std;
int main() {
	int** board = InitializeBoard();//≥ı ºªØ∆Â≈Ã
	board[6][6] = 1;
	printBoard(board);
	int temp=0;
	while (1) {
		User1In(board,&temp);
		printBoard(board);
		cout << endl << temp << endl;
		User2In(board, &temp);

		printBoard(board);
		cout << endl << temp << endl;
	}
	return 0;
}
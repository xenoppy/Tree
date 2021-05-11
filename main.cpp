#include<iostream>
#include"node.h"
#include"algorithm.h"
#include"put_in.h"
#include"func.h"
using namespace std;
int main() {
	int** board = InitializeBoard();//≥ı ºªØ∆Â≈Ã
	printBoard(board);
	while (1) {
		User1In(board);
		printBoard(board);
		if (judge(board, 1)){ 
			win(1);
			break;
		}
		cout << endl << evaluate(board,0) << endl;
		User2In(board);
		printBoard(board);
		if (judge(board, 2)) {
			win(2);
			break;
		}
	}
	return 0;
}
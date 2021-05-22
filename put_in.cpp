#include"put_in.h"
#include"algorithm.h"
#include"node.h"
#include"func.h"
void User1In(int** board,int* temp) {
	GetFromKey(board, 0,temp);
	
}
void User2In(int** board, int* temp) {
	//GetFromAI(board,1);
	GetFromKey(board, 1,temp);
}
//¥”º¸≈Ã¥¶ ‰»Î
void GetFromKey(int** board,int user,int *temp){
	std::cout << "User" << user << " please put in:" << std::endl;
	int x, y;
	std::cin >> x >> y;
	if (board[x-1][y-1] == EMPTY) {
		board[x-1][y-1] = user;
	}
	evaluate(board, user, x-1, y-1, temp);
	printBoard(board);
	if (judge(board, user,x-1,y-1)) {
		win(0);
	}

}
void GetFromAI(int** Board, int user,int* temp) {
	for (int i = 0; i < BOARD_LENTH; i++) {
		for (int j = 0; j < BOARD_LENTH; j++) {

		}
	}
}
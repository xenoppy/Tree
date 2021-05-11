#include"put_in.h"
#include"algorithm.h"
#include"node.h"
void User1In(int** board) {
	GetFromKey(board, 0);
	
}
void User2In(int** board) {
	GetFromAI(board,1);

}
//¥”º¸≈Ã¥¶ ‰»Î
void GetFromKey(int** board,int user){
	std::cout << "User" << user << " please put in:" << std::endl;
	int x, y;
	std::cin >> x >> y;
	if (board[x-1][y-1] == EMPTY) {
		board[x-1][y-1] = user;
	}

}
void GetFromAI(int** Board, int user) {
	int x, y, max_score = -2147483647;
	for (int i = 0; i < BOARD_LENTH; i++) {
		for (int j = 0; j < BOARD_LENTH; j++) {
			int** preBoard = Board;
			if (preBoard[i][j] == EMPTY) {
				preBoard[i][j] = user;
				int t = (user * 2 - 1) * search(preBoard, 1 - user, 1);
				if (t > max_score){
					max_score = t;
					x = i;
					y = j;
				}
			}
			else break;
		}
	}
//	Board[x][y] = user;
}
#include"put_in.h"
#include"algorithm.h"
#include"node.h"
#include"func.h"
void User1In(int** board,int* temp) {
	GetFromKey(board, 0,temp);
	
}
void User2In(int** board, int* temp) {
	//GetFromAI(board,1,temp);
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
	int max_score = -2139062143 * (user * 2 - 1),x,y,t=*temp;
	for (int i = 0; i < BOARD_LENTH; i++) {
		for (int j = 0; j < BOARD_LENTH; j++) {
			if (Board[i][j] == EMPTY) {
				int** preBoard = copy(Board);
				preBoard[i][j] = user;
				int save =  search(preBoard, 1-user, DEPTH - 1, &t);
				if ((user * 2 - 1) *save > max_score) {
					x = i;
					y = j;
					max_score = save;
				}
			}
		}
	}
	Board[x][y] = user;
	evaluate(Board, user, x, y, temp);
}
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
//从键盘处输入
void GetFromKey(int** board,int user,int *temp){
	std::cout << "User" << user << " please put in:" << std::endl;
	int x, y;
	std::cin >> x >> y;
	if (board[x-1][y-1] == EMPTY) {
		board[x-1][y-1] = user;
	}
	evaluate(board, user, x-1, y-1, temp);
	if (judge(board, user,x-1,y-1)) {
		win(0);
	}

}
void GetFromAI(int** Board, int user,int* temp) {
	int max_score = -2139062143,x=0,y=0,t=*temp;
	//int saveBoard[17][17];
	////保存
	//for (int i = 0; i < BOARD_LENTH; i++) {
	//	for (int j = 0; j < BOARD_LENTH; j++) {
	//		saveBoard[i][j] = Board[i][j];
	//	}
	//}
	for (int i = 0; i < BOARD_LENTH; i++) {
		for (int j = 0; j < BOARD_LENTH; j++) {
			if (Board[i][j] == EMPTY) {
				Board[i][j] = user;
				int save =  search(Board, 1-user, DEPTH - 1, &t);
				if ((user * 2 - 1) *save > max_score) {
					x = i;
					y = j;
					max_score = save;					
				}
				//复原
				Board[i][j] = EMPTY;
			}
		}
	}
	
	Board[x][y] = user;
	evaluate(Board, user, x, y, temp); 
	if (judge(Board, user, x, y)) {
		win(0);
	}
}
#include"put_in.h"
#include"node.h"
void User1In(int** board) {
	GetFromKey(board, 1);
	
}
void User2In(int** board) {
	GetFromKey(board,2);

}
//¥”º¸≈Ã¥¶ ‰»Î
void GetFromKey(int** board,int user){
	std::cout << "User" << user << " please put in:" << std::endl;
	int x, y;
	std::cin >> x >> y;
	if (board[x][y] == EMPTY) {
		board[x][y] = user;
	}

}

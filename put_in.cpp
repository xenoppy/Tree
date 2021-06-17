#include"put_in.h"
#include"algorithm.h"
#include"smartsearch.h"
#include"convention.h"
#include"func.h"
#include <time.h>
void User1In(int** board, int* temp) {
	GetFromKey(board, 0, temp);

}
void User2In(int** board, int* temp) {
	clock_t t;
	t = clock();
	GetFromAI(board, 1, temp);
	t = clock() - t;
	std::cout << "time is " << t << std::endl;
	system("pause");
	//GetFromKey(board, 1,temp);
}
//从键盘处输入
void GetFromKey(int** board, int user, int* temp) {
	std::cout << "User" << user << " please put in:" << std::endl;
	int x, y;
	std::cin >> x >> y;
	if (board[x - 1][y - 1] == EMPTY) {
		board[x - 1][y - 1] = user;
	}
	evaluate(board, user, x - 1, y - 1, temp);
	if (*temp > 100000000) {
		printBoard(board);
		win(1);
	}
	else if (*temp < -100000000) {
		printBoard(board); win(0);
	}

}
void GetFromAI(int** Board, int user, int* temp) {
	nodevector Nodevector;
	Nodevector.initialize(Board,user);
	Nodevector.sort();
	int x = 0, y = 0, t = *temp;
	double max_score = -INT_MAX;
	int extre = max_score * (user * 2 - 1);
	//int saveBoard[17][17];
	////保存
	//for (int i = 0; i < BOARD_LENTH; i++) {
	//	for (int j = 0; j < BOARD_LENTH; j++) {
	//		saveBoard[i][j] = Board[i][j];
	//	}
	//}
	for (std::vector<node*>::iterator i = Nodevector.Nodevector.begin(); i != Nodevector.Nodevector.end(); i++) {
		if (check(Board, (*i)->x, (*i)->y)) {
			Board[(*i)->x][(*i)->y] = user;
			int tempp = t;
			evaluate(Board, user, 0, 0, &tempp);
			if (abs(tempp) > 10000000) {
				x = (*i)->x;
				y = (*i)->y;
				break;
			}
			int save = search(Board, 1 - user, DEPTH - 1, &t, (int)max_score);
			if ((user * 2 - 1) * save > (user * 2 - 1) * max_score) {
				x = (*i)->x;
				y = (*i)->y;
				max_score = save;
			}

			//复原
			Board[(*i)->x][(*i)->y] = EMPTY;
		}

	}
	Nodevector.end();
	Board[x][y] = user;
	evaluate(Board, user, x, y, temp);
	if (*temp > 100000000000) {
		win(1);
	}
	else if (*temp < -100000000000)win(0);

}
#pragma once
#define BOARD_LENTH 10
#define EMPTY 2
#define BLACK 1
#define WHITE 0
#define DEPTH 2

#include<vector>
class Node {
public:
	Node();
	std::vector<Node*>children;
	int n,quality;
	void createchild();
	void addQuality();
	void addN();
};
void InitializeTree();
int** InitializeBoard();
void freeBoard(int **a);
#pragma once
#define BOARD_LENTH 17
#define EMPTY 0
#define BLACK 1
#define WHITE 2

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
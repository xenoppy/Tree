#include"node.h"
#include<iostream>
using namespace std;
int** InitializeBoard() {
	int** a = (int**)malloc(sizeof(int*) * BOARD_LENTH);
	for (int i = 0; i < BOARD_LENTH; i++) {
		a[i] = (int*)malloc(sizeof(int) * BOARD_LENTH);
	}
	for (int i = 0; i < BOARD_LENTH; i++) {
		for (int j = 0; j < BOARD_LENTH; j++) {
			a[i][j] = EMPTY;
		}
	}
	return a;
}
//void freeBoard(int** a) {
//	for (int i = 0; i < BOARD_LENTH; i++) {
//		free(a[i]);
//	}
//	free(a);
//}
void Node::createchild() {
	Node* p =new Node();
	p->n = 0;
	p->quality = 0;
	children.push_back(p);
}
Node::Node(){
	n = 0;
	quality = 0;
}
void Node::addN() {
	n++;
}
void Node::addQuality() {
	quality++;
}
void InitializeTree() {

}
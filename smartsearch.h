#pragma once
#include"convention.h"
#include"func.h"
#include<vector>
#include<Windows.h>
int smartevaluate(int** Board, int x, int y,int user);
class node{
public:
	node(int a, int b) { x = a; y = b; score = 0; }
	int score, x, y;
};
class nodevector{
public:
	std::vector<node*>Nodevector;
	std::vector<node*>SortedNodevector;
	void NodePush(int x, int y) {
		Nodevector.push_back(new node(x, y));
	}
	void sort(int user) {
		for (std::vector<node*>::iterator i = Nodevector.begin(); i != Nodevector.end(); i++) {
			int max = -MAXINT;
			std::vector<node*>::iterator temp;
			for (std::vector<node*>::iterator j = Nodevector.begin(); j != Nodevector.end(); j++) {
				if ((*j)->score * (user * 2 - 1) > max) {
					max = (*j)->score * (user * 2 - 1);
					temp = j;
				}
			}
			SortedNodevector.push_back(new node((*temp)->x, (*temp)->y));
		}
	}
	void initialize(int** Board,int user) {
		Nodevector.clear();
		SortedNodevector.clear();
		for (int i = 0; i < BOARD_LENTH; i++) {
			for (int j = 0; j < BOARD_LENTH; j++) {
				if (check(Board, i, j))Nodevector.push_back(new node(i, j));
			}
		}
		for (std::vector<node*>::iterator i = Nodevector.begin(); i != Nodevector.end(); i++) {
			(*i)->score = smartevaluate(Board, (*i)->x, (*i)->y,user);//ÕÍ≥…π¿÷µ
		}

	}
	void end() {
		Nodevector.clear();
		SortedNodevector.clear();

	}
};

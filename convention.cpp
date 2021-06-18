#include"convention.h"
#include<iostream>
using namespace std;
//≥ı ºªØ∆Â≈Ã
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
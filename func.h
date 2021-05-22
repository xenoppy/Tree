#pragma once
int max(int x, int y);
int min(int x, int y);
bool judge(int** board,int user,int x,int y);
void win(int user);
void printBoard(int** board);
int** copy(int** from);
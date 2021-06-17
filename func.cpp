#include "convention.h"
#include "func.h"
#include <Windows.h>
#include <iostream>

void win(int user)
{
  std::cout << "User " << user << " win!!!" << std::endl
            << "Congratuations!!!" << std::endl;
  system("pause");
  exit(0);
}

void printBoard(int **board)
{
  system("cls");
  printf("�٢ڢۢܢݢޢߢ���1112131415\n");

  for (int i = 0; i < BOARD_LENTH; i++)
  {
    for (int j = 0; j < BOARD_LENTH; j++)
    {
      switch (board[i][j])
      {
      case 2:
        std::cout << "��";
        break;
      case 1:

        std::cout << "��";
        break;
      case 0:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
                                                                     FOREGROUND_RED);
        //��ɫ
        std::cout << "��";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
                                                                     FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        break;
      }
    }
    std::cout << i + 1 << std::endl;
  }
  printf("�٢ڢۢܢݢޢߢ���1112131415\n");
}
bool check(int **board, int x, int y)
{
  if (board[x][y] == EMPTY)
  {
    for (int i = max(0, x - 1); i < min(BOARD_LENTH, x + 2); i++)
    {
      for (int j = max(0, y - 1); j < min(BOARD_LENTH, y + 2); j++)
        if (board[i][j] != EMPTY)
        {
          return true;
        }
    }
  }
  return false;
}
//int** copy(int** from) {
//	int** goal = InitializeBoard();
//	for (int i = 0; i < BOARD_LENTH; i++) {
//		for (int j = 0; j < BOARD_LENTH; j++) {
//			goal[i][j] = from[i][j];
//		}
//	}
//	return goal;
//}
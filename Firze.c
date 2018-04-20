/*
 * Firze.c
 *
 *  Created on: 13 нояб. 2017 г.
 *      Author: Valera
 */
#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
#include <conio.h>
#define N 8
#define M 8
// Доска для ферзей.
// 0 - клетка пустая
// число - номер ферзя
int board[N][M];
int SearchSolution(int n);
int CheckBoard();
int CheckQueen(int x, int y, int n);
void Print(int n, int m, int a[N][M]);
void Zero(int n, int m, int a[N][M]);
void Pause(int key);
int checkMove(int x, int y);

int main1()
{
Zero(N, M, board);
SearchSolution(1);
printf("\n\n");
Print(N, M, board);
//getch();
return 0;
}

int SearchSolution(int n)
{
	// Если проверка доски возвращает 0, то эта расстановка не подходит
	if (n>1)
			if (CheckBoard(n-1) == 0) return 0;
	// 9 ферзя не ставим. Решение найдено
	if (n == 60) return 1 ;
	int row;
	int col;
	for(row = 0; row < N; row++)
		for(col = 0; col < M; col++)
			{
				if (board[row][col]==0)
						{
							// Расширяем test_solution
								board[row][col]=n;
							// Рекурсивно проверяем, ведет ли это к решению.
								if (SearchSolution(n+1)) return 1 ;
							// Если мы дошли до этой строки, данное частичное решение
							// не приводит к полному.
								board[row][col]=0;
						} else Print(N, M, board);
			}
	return 0;
}

//Проверка всей доски
int CheckBoard(int n)
{
int i, j;
for(i = 0; i < N; i++)
	for(j = 0; j < M; j++)
		if (board[i][j] == n)
		{
			if (CheckQueen(i, j, n) == 0) return 0;
			else
				{
				if (checkMove(i,j) == 0) return 0;
				}
		}
return 1;
}

int checkMove(int x, int y) {
	int i, j;
		for(i = 0; i < N; i++)
			for(j = 0; j < M; j++)
				if (board[i][j] == 0) {
					if (abs(x- i) == 2 && abs(y - j) == 1)  return 1;
					if (abs(x- i) == 1 && abs(y - j) == 2)  return 1;
				}
	return 0;
}

//Проверка определённого ферзя
int CheckQueen(int x, int y, int n)
{
	int i, j;
	for(i = 0; i < N; i++)
		for(j = 0; j < M; j++)
			// Если нашли предыдущую фигуру
			if (board[i][j] == n-1)
					{
					// Лежат где то рядом
						if (abs(x- i) == 2 && abs(y - j) == 1)  return 1;
						if (abs(x- i) == 1 && abs(y - j) == 2)  return 1;
					}
	// Если дошли до сюда, то не нашли предыдущую фигуру
	return 0 ;
}

//Выводим доску на экран
void Print(int n, int m, int a[N][M])
{
int i, j;
	for(i = 0; i < n; i++)
		{
		for(j = 0; j < m; j++)
			printf("%4d", a[i][j]);
		printf("\n");
		}
}


void Zero(int n, int m, int a[N][M])
{
	int i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			a[i][j] = 0;
}

void Pause(int key)
{
	int i;
	if (key == 1 )
		getch();
	else
		for (i = 0; i < 100000000; i++);
}


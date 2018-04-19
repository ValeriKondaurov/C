/*
 * HW.c
 *
 *  Created on: 10 нояб. 2017 г.
 *      Author: Valera Kondaurov
 */


#include <stdio.h>
#define N 8
#define M 8
int i1=0;
int map [N][M];
void Print2(int a[N][M]);
void ReadMap();
int calcrec (int S, int E);

void ReadMap() {
	FILE *file;
	file = fopen("map.txt", "r");
	int i,j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++) {
			fflush(stdout);
			fscanf(file, "%d", &map[i][j]);
			}
		}
	fclose(file);
}


void Print2 (int a[N][M])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			printf("%6d", a[i][j]);
		printf("\n");
	}
	printf("\n");
}

int CheckField (int Map, int A) {
	if (Map || !A) return 0;
	return 1;
}
//4. Реализовать задачу о калькулятор с помощью рекурсии
int calcrec (int S, int E) {
   if (S > E) return 0;
   if (S == E) return 1;
   if (E%2==0) return calcrec(S,E/2)+calcrec(S,E-1);
	else return calcrec(S,E-1);

}

void mapClear() {
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			map[i][j] = 0;
}





int main(int argc, char *argv[])
{
	/*1.Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и
		нахождение количество маршрутов. 1 - препятские 0  - доступное поле
*/
	ReadMap();
	int A[N][M];
	int i, j;
	A[0][0] = CheckField (map[0][0], 1);;
	for (j = 1; j < M; j++)
		A[0][j] = CheckField (map[0][j],  A[0][j-1]);
	for (i = 1; i < N; i++)
	{
		  A[i][0] = CheckField (map[i][0],  A[i-1][0]);
		for (j = 1; j < M; j++)
			A[i][j] = (CheckField (map[i][j], 1)? A[i][j - 1] + A[i - 1][j]: 0);
	}
	Print2(A);


	//4. Реализовать задачу о калькулятор с помощью рекурсии
	int Start, End;
	printf ("Введите число вход  ");
	fflush(stdout);
	scanf("%d", &Start);
	printf ("Введите число выхода  ");
	fflush(stdout);
	scanf("%d", &End);
	printf("От %3d  до %3d есть %d путей   \n", Start, End, calcrec(Start, End));


	return 0;

}

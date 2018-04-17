/*
 * HW.c
 *
 *  Created on: 8 ����. 2017 �.
 *      Author: Valera Kondaurov
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ���������� ������������ ������ �������

#define MaxN 20
int Count=0;

int a[MaxN];          // ������ ������ ������������� �������
int N;

void ReadData(int* a) {
	FILE *in;
	in = fopen("data.txt", "r");
	fflush(stdout);
	fscanf(in, "%d", &N);
	int i;
	for (i = 0; i < N; i++)
	{
		fflush(stdout);
		fscanf(in, "%d", &a[i]);
	}
	fclose(in);
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;

}

// ������������� ������
void print()
{
	int i;
	for (i = 0; i < N; i++)
		printf("%6d", a[i]);
	printf("\n");
}

int Compare(int a, int b)
{
	if (a > b) return 1;
	if (a < b) return -1;
	return 0;
}
/*1.
 * ����������� �������������� ����������� ����������. �������� ���������� ��������
��������� ���������������� � �� ���������������� ���������. �������� �������
����������, ������� ���������� ���������� ��������.
 */

int BubbleSort()
{

	int i,j;
	int flag = 0;
	for (i = 0; i < N && !flag; i++)
	{
		flag = 1;

		for (j = 0; j < N - 1; j++)
		{
			Count++;
			if (Compare(a[j],a[j+1])==1)
			{
				swap(&a[j], &a[j + 1]);
				flag = 0;
			}
		}
	}
	return Count;
}

int BubbleSortOptim()
{

	int i,j;
	int flag = 0;
	for (i = 0; i < N && !flag; i++)
	{
		flag = 1;

		for (j = 0; j < N - 1 -i; j++)
		{
			Count++;
			if (Compare(a[j],a[j+1])==1)
			{
				swap(&a[j], &a[j + 1]);
				flag = 0;
			}
		}
	}
	return Count;
}

// 2.����������� ��������� ����������
int ShakeSort()
{

	int i,j;
	int flag = 0;
	for (i = 0; i < N && !flag; i++)
	{
		flag = 1;
		for (j = i; j < N - 1-i; j++)
		{
			Count++;
			if (Compare(a[j],a[j+1])==1)
			{
				swap(&a[j], &a[j + 1]);
				flag = 0;
				print();
			}
		}
		printf("\n");
		for (j = N-1-i; j >i ; j--)
		{
			Count++;
			if (Compare(a[j],a[j-1])==-1)
			{
				swap(&a[j], &a[j -1]);
				flag = 0;
				print();
			}
		}
		printf("\n");
	}
	return Count;
}

/*3. ����������� �������� �������� ������ � ���� �������, ������� ����������
��������������� ������. ������� ���������� ������ ���������� �������� ��� -1 , ����
������� �� ������.
*/
int BinarySearch(int value)
{
	int L = 0, R = N - 1;
	int m = L + (R - L) / 2;
	while (L <= R && a[m] != value)
	{
		if (a[m] < value)
			L = m + 1;
		else
			R = m - 1;
		m = L + (R - L) / 2;
	}
	if (a[m] == value)
		return m;
	else
		return -1;

}

int main(int argc, char *argv[]) {

	ReadData(a);
	puts("Array before sort");
	print(N, a);
	BubbleSort();
	puts ("Array after Bubble Sort");
	print(N, a);
	printf("Count operation:%d \n", Count);
	ReadData(a);
	Count = 0;
	BubbleSortOptim();
	puts ("\n Array after Bubble Sort optimization");
	print(N, a);
	printf("Count operation:%d \n", Count);
	ReadData(a);
	Count = 0;
	ShakeSort();
	puts ("\n Array after Shake Sort optimization");
	print(N, a);
	printf("Count operation:%d \n", Count);

	int value;
	printf("Input value for search:");
	fflush(stdout);
	scanf("%i", &value);
	int indexV = BinarySearch(value);
	if (indexV>0)
		printf ("Value found. Index %d", indexV);
	 else
		printf ("Value not found");

	return 0;
}


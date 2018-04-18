/*
 * HW.c
 *
 *  Created on: 3 ����. 2017 �.
 *      Author: Valera
 */

#include <stdio.h>
#include <stdlib.h>


void decadeToBinary ();
int decadeToBinaryCalc (int a);
void mySqrt ();
int mySqrtwoRec(int a, int b);
int mySqrtRec(int a, int b);
int mySqrtRec2(int a, int b);

int main () {
	decadeToBinary ();
	mySqrt();
	return 0;
}


//1. ����������� ������� �������� �� 10 ������� � �������� ��������� ��������.
void decadeToBinary () {
	int decnum;
	printf ("������� ���������� ����� ");
	fflush(stdout);
	scanf ("%d", &decnum);
	printf("����� %d � �������� ������� %d \n", decnum, decadeToBinaryCalc (decnum));

}

int decadeToBinaryCalc (int a) {
	if (a == 1) return 1;
	return decadeToBinaryCalc (a/2)*10+a%2;
}

/*2. ����������� ������� ���������� ����� a � ������� b:

a. ��� ��������;
b. ����������;
c. *����������, ��������� �������� �������� �������.*/

void mySqrt () {
	int a,b;
	printf ("������� ����� ");
	fflush(stdout);
	scanf ("%d", &a);
	printf ("������� ������� ��� ���������� ");
	fflush(stdout);
	scanf ("%d", &b);
	printf("����� %d ��������� � ������� %d (��� ��������) %d \n", a, b, mySqrtwoRec(a,b));
	printf("����� %d ��������� � ������� %d (� ���������) %d \n", a, b, mySqrtRec(a,b));
	printf("����� %d ��������� � ������� %d (� ��������� � ���������) %d \n", a, b, mySqrtRec(a,b));

}

int mySqrtwoRec(int a, int b) {
	int i, asqrt=1;
	for (i=0;i<b;i++) {
		asqrt *= a;
	}
	return asqrt;
}

int mySqrtRec(int a, int b) {
	if (b ==1) return a;
	return a*mySqrtRec(a, b-1);
}

int mySqrtRec2(int a, int b) {
	if (b ==0) return 1;
	if (b ==1) return a*mySqrtRec2(a, b-2);
	return a*a*mySqrtRec2(a, b-2);

}




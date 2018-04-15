/*
 * HW.c
 *
 *  Created on: 1 Nov. 2017 ã.
 *      Author: Kondaurov Valeriy
 */

#include <stdio.h>

float I (int massa, int high) {

	return (massa/(float)(high*high));
}

void findmax (int n, int* m) {
	printf("%d    %d \n", n, *m);
	if (n>*m) *m = n;

}

int main () {
/*
1. Enter the weight and height of the person. 
Calculate and display body mass index according to the formula I=m/(h*h);
where m-body weight in kilograms, h-height in meters.
*/
/*	int m, h;
	printf ("Enter the weight of the subject in kilograms ");
	fflush(stdout);
	scanf ("%d",&m);
	printf ("Enter height in meters ");
	fflush(stdout);
	scanf ("%d",&h);
	printf ("And weight is %d and weight is %d body mass index %f \n", m, h, I(m,h));
*/
	/*
2. Find the maximum of four numbers. Arrays don't use.
	*/

/*	int max,i,num;
	i=1;
	printf ("Enter %d number", i);
	fflush(stdout);
	scanf ("%d", &max);
	while (i<4) {
		i++;
		printf ("Enter %d number", i);
		fflush(stdout);
		scanf ("%d", &num);
		findmax(num, &max);
	}
	printf ("Maximum number %d", max);
*/
/*
 * 	3. Write a program to exchange the values of two integer variables:
 
* a. using the third variable;
 
* b. * without using a third variable.
 */
	int x1,x2,x;
	printf ("Enter first number ");
	fflush(stdout);
	scanf ("%d",&x1);
	printf ("Enter second number ");
	fflush(stdout);
	scanf ("%d",&x2);
	printf ("Was: %d    %d \n", x1, x2);
	//variables:
  a.
	x = x1;
	x1 = x2;
	x2 = x;
	printf ("Result à: %d    %d \n", x1, x2);
	//variables: b
	x1 = x1 ^ x2;
	x2 = x1 ^ x2;
	x1 = x1 ^ x2;
	printf ("Result b: %d    %d \n", x1, x2);
	return 0;
}



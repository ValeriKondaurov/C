/*
 * HW5.c
 *
 *  Created on: 15 нояб. 2017 г.
 *      Author: Valera Kondaurov
 */



#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define T int
// Опишем структуру узла списка
struct TNode
{
	T value;
	struct TNode *next;
};
typedef struct TNode NNode;

struct Stack
{
	NNode *head;
	int size;
	int maxSize;
};

struct Stack Stack;
struct Stack Stack1;

struct TDblNode {
	char sim;
	int type;
	struct TDblNode *next;
	struct TDblNode *prev;
};
typedef struct TDblNode Node;

struct DblList
{
	Node *head, *tail, *current;
};
struct DblList List;

//1. Реализовать перевод из 10 в 2 систему счисления с использованием стека.
void push(T value)
{
	if (Stack.size >= Stack.maxSize) {
			printf("Error stack size");
			return;
}
NNode *tmp = (NNode*) malloc(sizeof(NNode));
tmp->value = value;
tmp->next = Stack.head;
Stack.head = tmp;
Stack.size++;
}

T pop() {
if (Stack.size == 0)
	{
		printf("Stack is empty");
		return '\0';
	}
	NNode* next = NULL;
	T value;
	value = Stack.head->value;
	next = Stack.head;
	Stack.head = Stack.head->next;
	free(next);
	Stack.size--;
	return value;
}
void PrintStack()
{
	NNode *current = Stack.head;
	while(current != NULL)
	{
		printf("%d", current->value);
		current = current->next;
	}
}
void PrintStack1()
{
	NNode *current = Stack1.head;
	printf("Stack11111   ");
	while(current != NULL)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("END \n");
}

void PrintStackPop()
{
	NNode *current = Stack.head;
	while(current != NULL)
	{
		printf("%d", pop());
		current = Stack.head;
	}
	printf("\n");
}

void copySteak () {
	Stack1.maxSize = 100;
	Stack1.head = NULL;
	NNode *tmp = Stack.head;
	printf("\n STAEK1 - %d \n", tmp->value);
	while (tmp !=NULL) {
		printf("%d", tmp->value);

		Stack1.head=tmp;
		printf("     %d\n", Stack1.head->value);
		tmp = tmp->next;
	}

}

//3. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной.
//Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.

Node* Init(char* a, int t) {
	Node *temp;
	// Выделение памяти под корень списка
	temp = (Node*) malloc(sizeof(Node));
	// Перенос строки
	temp->sim= *a;
	temp->type = t;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}


Node* AddElem(Node *current, char *a, int t){
	Node *temp, *p;
	temp = (Node*) malloc(sizeof(Node));
	p = current->next;
	current->next = temp;
	temp->sim = *a;
	temp->type = t;
	temp->next = p;
	temp->prev = current;
	if (p!=NULL)
		p->prev = temp;
	current = temp;
	return current;
}


void ListPrint(){
	Node *p = List.head;
	do {
		if (p == List.current)
			printf("#");
		printf("%c (%d)", p->sim,p->type );
		p = p->next;
	}
	while(p!=NULL);
	printf("\n");
}



void ListPrintTail(){
	Node *p = List.tail;
	do {
		if (p == List.current)
			printf("#");
		printf("%c (%d)", p->sim,p->type );
		p = p->prev;
	}

while(p!=NULL);
	printf("\n");
}

int checkChar (char s) {
	switch (s) {
			case ('['): return -3;
			case ('{'): return -2;
			case ('('): return -1;
			case (')'): return 1;
			case ('}'): return 2;
			case (']'): return 3;
			default: return 0;
	}
}



int main(int argc, char *argv[])
{
Stack.maxSize = 100;
Stack.head = NULL;
int num = 60;
printf ("Число %d в двоичной системе ", num);
while (num>0) {
	push(num%2);
	num/=2;
}
printf ("1");
copySteak();
printf ("2");
PrintStack();
printf ("3");
PrintStack1();

char formula[50] ="[2/{5*(4+7)}]";
int i, type, len=0;
List.head = Init(&formula[len], checkChar(formula[len]));
List.current = List.head;
List.tail = List.head;
while (formula[len] != '\0') {
	len++;
	type= checkChar(formula[len]);
	if (type!=0) {
			List.current = AddElem(List.current, &formula[len], type);
			List.tail = List.current;
	}
}


i=0;
Node *tail = List.tail;
Node *head = List.head;
while (tail!=head->prev && i==0) {
	if (tail->type<0 || tail->type + head->type != 0) i = 1;
		tail = tail->prev;
		head = head->next;

}

printf("В формуле %s последовательность скобок %sправильная \n",  formula, ((i)?"не":""));
return 0;
}

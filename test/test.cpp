// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define LEN 5
char queue[LEN];
int head, tail;
int queue_push(char ch);
char queue_pop();
void init();
int _tmain(int argc, _TCHAR* argv[])
{
	char ch;
	init();
	queue_push('a');
	queue_push('b');
	queue_push('c');
	queue_push('d');
	
	ch = queue_pop();
	printf("%c\n", ch);
	ch = queue_pop();
	printf("%c\n", ch);
	ch = queue_pop();
	printf("%c\n", ch);
	ch = queue_pop();
	printf("%c\n", ch);

	queue_push('d');
	queue_push('b');
	queue_push('a');
	ch = queue_pop();
	printf("%c\n", ch);
	ch = queue_pop();
	printf("%c\n", ch);
	ch = queue_pop();
	printf("%c\n", ch);

	return 0;
}

void init(){
	head = 0; tail = 0;
}
int queue_push(char ch){
	assert((tail+1)% 5 != head);
	queue[tail++] = ch;
	return tail;
}
char queue_pop(){
	char ch;
	assert(head != tail);
	ch = queue[head];
	head = (head + 1) % 5;
	return ch;
}
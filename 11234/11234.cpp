#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXNUM 10010
typedef struct _node{
	char op;
	struct _node *left;
	struct _node *right;
}Node;


Node *node_list;
Node *stack[MAXNUM];
Node *queue[MAXNUM];
int stack_head = 0;
int queue_head = 0;
int queue_tail = 0;
int node_head = 0;
void init();
void stack_push(Node *);
Node* stack_pop();

void queue_push(Node *item){
	queue[queue_tail++] = item;
}
Node* queue_pop(){
	Node* item = queue[queue_head];
	queue_head = (queue_head + 1) % MAXNUM;
	return item;
}
int main(int argc, char* argv[]){
	int t, i;
	char buff[MAXNUM];
#ifndef ONLINE_JUDGE
	freopen("11234.in", "r", stdin);
#endif
	node_list = (Node*)calloc(MAXNUM, sizeof(Node));
	scanf("%d\n", &t);
	while(t--){
		init();
		gets(buff);
		for(node_head=0; node_head<strlen(buff); node_head++){
			node_list[node_head].op = buff[node_head];
			if(islower(buff[node_head])){
				node_list[node_head].left = NULL;
				node_list[node_head].right = NULL;
			}else{
				Node *tmp = stack_pop();
				node_list[node_head].right = tmp;
				tmp = stack_pop();
				node_list[node_head].left = tmp;
			}
			stack_push(&node_list[node_head]);
		}
		queue_head = 0;
		queue_tail = 0;
		
		queue_push(stack[stack_head - 1]);
		i = 0;
		while(queue_head != queue_tail){
			Node *tmp = queue_pop();
			if(tmp->left) queue_push(tmp->left);

			if(tmp->right)queue_push(tmp->right);
			buff[i++] = tmp->op;
		}
		while(i--)
			putchar(buff[i]);
		printf("\n");
	}

	free(node_list);
	return 0;
}
void init(){
	memset(node_list, 0, sizeof(Node)*MAXNUM);
	stack_head = 0;
	node_head = 0;
}
void stack_push(Node *node){
	stack[stack_head++] = node;
}
Node* stack_pop(){
	return stack[--stack_head];
}

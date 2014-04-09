#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <math.h>

#define LEN 18192
typedef struct _node{
	char type; /*p means parent, f means black, e means empty*/
	int childindex;
	struct _node* c0;
	struct _node* c1;
	struct _node* c2;
	struct _node* c3;
}Node;
int si = 0;

Node* stack[LEN];
void push(Node *node){
	stack[si++] = node;
}
void pop(){
	if(si>0)
		si--;
}
Node* top(){
	return stack[si-1];
}
int isempty(){
	return (si == 0)?1:0;
}

void insert_child(Node *n1, Node *n2){
	switch(n1->childindex){
	case 0:
		n1->c0 = n2;
		break;
	case 1:
		n1->c1 = n2;
		break;
	case 2:
		n1->c2 = n2;
		break;
	default:
		n1->c3 = n2;
	}
	n1->childindex++;
	return;
}

Node* build_tree(char *buff){
	char *p = buff;
	Node *node, *t;
	memset(stack, 0, sizeof(stack));
	si = 0;
	while(*p){
		node = (Node*)calloc(1, sizeof(Node));
		if(*p == 'p'){
			node->type = 'p';
			node->childindex = 0;
			if(!isempty()){
				t = top();
				insert_child(t, node);
			}
			push(node);
		}else{ /*node is e or f*/
			node->type = *p;
			if(isempty()){
				push(node);
				break;
			}
			t = top();
			insert_child(t,node);
			while(1){
				t = top();
				if(t->childindex == 4 && si>1)
					pop();
				else
					break;
			}
		}
		p++;
	}
	return stack[0];
}
void trav(Node *root){
	if(root == NULL)
		return ;
	printf("%c", root->type);
	trav(root->c0);
	trav(root->c1);
	trav(root->c2);
	trav(root->c3);
}

void freetree(Node *tree){
	if(!tree)return;
	freetree(tree->c0);
	freetree(tree->c1);
	freetree(tree->c2);
	freetree(tree->c3);
	free(tree);
}

Node* combine(Node **n1, Node **n2){
	Node *t;
	if(*n1==NULL && *n2==NULL)return NULL;
	else if(*n1 == NULL && *n2 != NULL) return *n2;
	else if(*n1 != NULL && *n2 == NULL) return *n1;

	if((*n1)->type == 'p' && (*n2)->type == 'p'){
		(*n1)->c0 = combine(&(*n1)->c0, &(*n2)->c0);
		(*n1)->c1 = combine(&(*n1)->c1, &(*n2)->c1);
		(*n1)->c2 = combine(&(*n1)->c2, &(*n2)->c2);
		(*n1)->c3 = combine(&(*n1)->c3, &(*n2)->c3);
		(*n2)->c0 = NULL;
		(*n2)->c1 = NULL;
		(*n2)->c2 = NULL;
		(*n2)->c3 = NULL;
		return *n1;
	}
	else if((*n1)->type == 'p' && (*n2)->type == 'e'){
		freetree(*n2);
		*n2 = NULL;
		return *n1;
	}
	else if((*n1)->type == 'p' && (*n2)->type == 'f'){
		freetree(*n1);
		*n1 = NULL;
		return *n2;
	}
	else if((*n1)->type == 'e' && (*n2)->type == 'p'){
		freetree(*n1);
		*n1 = NULL;
		return *n2;
	}
	else if((*n1)->type == 'e' && (*n2)->type == 'e'){
		freetree(*n2);
		*n2 = NULL;
		return *n1;
	}
	else if((*n1)->type == 'e' && (*n2)->type == 'f'){
		freetree(*n1);
		*n1 = NULL;
		return *n2;
	}
	else if((*n1)->type == 'f' && (*n2)->type == 'p'){
		freetree(*n2);
		*n2 = NULL;
		return *n1;
	}
	else if((*n1)->type == 'f' && (*n2)->type == 'e'){
		freetree(*n2);
		*n2 = NULL;
		return *n1;
	}
	else { /*if(n1->type == 'f' && n2->type == 'f') */
		freetree(*n2);
		*n2 = NULL;
		return *n1;
	}
}

int getsum(Node *root, int level){
	int div = (int)pow(4.0, level);
	if(root->type == 'e')
		return 0;
	else if(root->type == 'f')
		return 1024 / div;
	else{
		return getsum(root->c0, level+1)+getsum(root->c1, level+1)
			+getsum(root->c2, level+1)+getsum(root->c3, level+1);
	}
}
int main(int argc, char* argv[]){
	int group;
	char buff[LEN];
	size_t len;
	Node *root1, *root2;
#ifndef ONLINE_JUDGE
	freopen("297.in", "r", stdin);
#endif
	scanf("%d\n", &group);
	while(group-- >0){
		/*  1. Get tree one */
		fgets(buff, LEN, stdin);
		len = strlen(buff);
		if(buff[len-1] == '\n'){
			buff[len-1] = '\0';
			len--;
		}
		root1 = build_tree(buff);

		/*  2. Get tree two */
		fgets(buff, LEN, stdin);
		len = strlen(buff);
		if(buff[len-1] == '\n'){
			buff[len-1] = '\0';
			len -- ;
		}
		root2 = build_tree(buff);
		/* combine two trees */
		root1 = combine(&root1, &root2);
		printf("There are %d black pixels.\n", getsum(root1, 0));
		/*freetree(root1);
		freetree(root2);*/
	}
	return 0;
}
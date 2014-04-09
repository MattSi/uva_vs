#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define LEN 10000
#define MAX 210000000
int in_trav[LEN];
int post_trav[LEN];

typedef struct _node{
	int value;
	struct _node *parent;
	struct _node *left;
	struct _node *right;
}Node;

Node* child[LEN];
int childindex = 0;
void init(){
	memset(in_trav, 0, sizeof(in_trav));
	memset(post_trav, 0, sizeof(post_trav));
}

Node* build_tree(int ilow, int ihigh, int plow, int phigh);

void mid_trav(Node *root){
	if(!root)return;
	mid_trav(root->left);
	printf("%4d", root->value);
	mid_trav(root->right);
}

void cleanup(Node *root){
	if(!root)return;
	cleanup(root->left);
	cleanup(root->right);
	free(root);
}
int main(int argc, char* argv[]){
	int index, value, i,minvalue = MAX, minnode, mv;
	char ch;
	Node *root, *tn;
#ifndef ONLINE_JUDGE
	freopen("548.in", "r", stdin);
#endif
	init();
	index = 0;
	childindex = 0;

	while(scanf("%d%c", &value, &ch) >0){
		if( ch != '\n' && ch !='\r')
			in_trav[index++] = value;
		else{
			in_trav[index++] = value;
			for(i=0; i<index; i++){
				scanf("%d%c", &value, &ch);
				post_trav[i] = value;
			}
			root = build_tree(0, index-1, 0, index-1);
			
			/*mid_trav(root);
			printf("\n");*/
			for(i=0; i<childindex; i++){
				mv = 0; 
				tn = child[i];
				while(tn){
					mv += tn->value;
					tn = tn->parent;
				}
				if(mv < minvalue){
					minvalue = mv;
					minnode = child[i]->value;
				}else if(mv == minvalue){
					if(child[i]->value < minnode)
						minnode = child[i]->value;
				}
				
			}
			printf("%d\n", minnode);
			index = 0;
			childindex = 0;
			minvalue = MAX;
			cleanup(root);
			root = NULL;
			tn = NULL;
			init();
		}
	}
	return 0;
}

Node* build_tree(int ilow, int ihigh, int plow, int phigh){
	int i;
	Node *root = (Node*)calloc(1, sizeof(Node));

	/* get root value*/
	root->value = post_trav[phigh];
	for(i=ilow; i<ihigh; i++)
		if(in_trav[i] == root->value)
			break;
	if(i == ilow)
		root->left = NULL;
	else{
		root->left = build_tree(ilow, i-1, plow, plow+i-1-ilow);
		root->left->parent = root;
	}
	if(i == ihigh)
		root->right = NULL;
	else{
		root->right = build_tree(i+1, ihigh, i+phigh-ihigh, phigh-1);
		root->right->parent = root;
	}
	if(!root->left && !root->right)
		child[childindex++] = root;
	return root;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

#define LEN 10000

typedef struct _node{
	int value;
	struct _node *parent;
	struct _node *left;
	struct _node *right;
}Node;

Node *leaf[LEN];
int leaf_index = 0;
Node* get_tree(){
	int ch, i;
	char va[16];
	Node *root;

	/* read tree head*/
	while((ch=getchar()) != '(');
	/* build a new tree node */
	root = (Node*) calloc(1, sizeof(Node));
	while(1){
		ch = getchar();
		if( ch == ')'){
			free(root);
			return NULL;
		}else if(isdigit(ch) || ch=='-'){
			ungetc(ch, stdin);
			break;
		}
	}

	/* read node value */
	i = 0;
	while(1){
		ch = getchar();
		if(isdigit(ch) || ch == '-'){
			va[i++] = ch;
		}else{
			ungetc(ch, stdin);
			va[i] = '\0';
			root->value = atoi(va);
			break;
		}
	}

	/* read left tree */
	root->left = get_tree();
	if(root->left != NULL)
		root->left->parent = root;

	/* read right tree */
	root->right = get_tree();
	if(root->right != NULL)
		root->right->parent = root;

	/* check leaf node */
	if(!root->left && !root->right)
		leaf[leaf_index++] = root;

	/* get the last ')' char */
	while((ch=getchar()) != ')');
	return root;
}

int check_leaf_value(int value){
	int i, sum;
	Node *node;
	for(i=0; i<leaf_index; i++){
		sum = 0;
		node = leaf[i];
		while(node){
			sum += node->value;
			node = node->parent;
		}
		if(sum == value)
			return 1;
	}
	return 0;
}

void free_nodes(Node *root){
	if(!root) return;
	free_nodes(root->left);
	free_nodes(root->right);
	free(root);
}

int main(int argc, char* argv[]){
	Node *root;
	int value;
#ifndef ONLINE_JUDGE
	freopen("112.in", "r", stdin);
#endif
	while(scanf("%d", &value) > 0){
		leaf_index = 0;
		root = get_tree();
		if(check_leaf_value(value))
			printf("yes\n");
		else
			printf("no\n");
		free_nodes(root);
	}
	return 0;
}

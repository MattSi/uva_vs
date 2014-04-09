#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 8192*2
int var_array[26];
int var_array2[26];
int fei;
typedef struct _node{
	int value;
	int type; /* 0 means value, 1 means operation*/
	char op;
	struct _node *left;
	struct _node *right;
}Node;


int getvalue(char *buff, int *i){
	char op = 0x0;
	char val = 0x0;
	char ch;
	int value = 0;
	while( (ch = *(buff+*i) )!= '\0'){
		if(ch == ' ' || ch == '\t'){
			(*i)++;
			continue;
		}
		if(ch == '+' || ch=='-'){
			if(val == 0x0){
				op = ch;
				(*i)+=2;
				continue;
			}
			else{
				if( *(buff + (*i)+1) == ch){
					if( ch == '+'){
						value = var_array[val - 'a'] ++;
						var_array2[val-'a'] = 1;
					}
					else{
						value = var_array[val - 'a'] --;
						var_array2[val-'a'] = 1;
					}
					(*i)+=2;
					return value;
				}
				else{
					var_array2[val-'a'] = 1;
					return var_array[val-'a'];
				}
			}
		}
		else if(isalpha(ch)){
			if(op != 0x0){
				/* got ++value, return*/
				if(op == '+'){
					value = ++var_array[ch - 'a'];
					var_array2[ch-'a'] = 1;
				}else{
					value = --var_array[ch - 'a'];
					var_array2[ch-'a'] = 1;
				}
				(*i)++;
				return value;
			}
			else{
				val = ch;
				var_array2[val-'a'] = 1;
			}
		}
		(*i)++;	
	}
	var_array2[val-'a'] = 1;
	return var_array[val-'a'];
}

char getop(char *buff, int *i){
	char ch;
	while( (ch = *(buff+*i) )!= '\0'){
		if(ch == ' ' || ch == '\t'){
			(*i)++;
			continue;
		}
		if(ch == '-' || ch=='+'){
			(*i)++;
			return ch;
		}
	}
	return 0;
}

Node* build_tree(char *buff){
	int i = 0;
	int value;
	char op;
	Node *node1, *operation, *node2;
	value = getvalue(buff, &i);
	node1 = (Node*)calloc(1, sizeof(Node));
	node1->value = value;
	node1->type = 0;
	while(*(buff+i) != '\0'){
		op = getop(buff, &i);
		operation = (Node*)calloc(1, sizeof(Node));
		operation->op = op;
		operation->type = 1;
		value = getvalue(buff, &i);
		node2 = (Node*)calloc(1, sizeof(Node));
		node2->value = value;
		node2->type = 0;
		
		operation->left = node1;
		operation->right = node2;
		node1 = operation;
		node2 = NULL;
	}
	return node1;
}

int compute(Node *root){
	if(root == NULL)return 0;
	else if(root->left == NULL && root->right == NULL)
		return root->value;
	if(root->op == '+'){
		return compute(root->left) + compute(root->right);
	}else{
		return compute(root->left) - compute(root->right);
	}
}
void init(){
	int i;
	for(i=0; i<26;i++){
		var_array[i] = i+1;
		var_array2[i] = 0;
	}
}

void destroy(Node *root){
}
int main(int argc, char* argv[]){
	char exp[LEN];
	Node *root;
	size_t len;
	int value, i;
#ifndef ONLINE_JUDGE
	freopen("327.in", "r", stdin);
#endif
	while(fgets(exp, LEN, stdin) != NULL){
		len = strlen(exp);
		if(exp[len-1] == '\n'){
			exp[len-1] = '\0';
			len--;
		}
		init();
		root = build_tree(exp);
		value = compute(root);
		printf("Expression: %s\n", exp);
		printf("    value = %d\n", value);
		for(i=0; i<26; i++){
			if(var_array2[i] >0){
				printf("    %c = %d\n", 'a'+i, var_array[i]);
			}
		}
	}
	return 0;
}
#include <stdio.h>
#include <string.h>

#define LENGTH 256
int firsti[LENGTH],secondi[LENGTH], intmax[LENGTH];
char cop;

void my_atoi(char str[], int len, int inti[]);
int cmp_int(int a[], int b[]);
void add_int(int a[], int b[]);
void mul_int(int a[], int b[]);
int main(int argc, char* argv[]){
	char first[LENGTH], second[LENGTH], line[LENGTH*2];
	char op[10];
	char *max = "2147483647";
#ifndef ONLINE_JUDGE
	freopen("465.in", "r", stdin);
#endif
	my_atoi(max, strlen(max), intmax);
	while(fgets(line, LENGTH*2, stdin) != NULL){
		size_t len = strlen(line);
		if(line[len-1] == '\n')line[len-1] = '\0';
		sscanf(line, "%s%s%s", first, op, second);
		my_atoi(first, strlen(first), firsti);
		my_atoi(second, strlen(second), secondi);
		int r1 = cmp_int(firsti, intmax);
		int r2 = cmp_int(secondi, intmax);
		printf("%s\n", line);
		if(r1 > 0) printf("first number too big\n");
		if(r2 > 0) printf("second number too big\n");

		if(strcmp(op, "+") == 0)
			add_int(firsti, secondi);
		else
			mul_int(firsti, secondi);
		if(cmp_int(firsti, intmax) > 0)
				printf("result too big\n");
		memset(first, 0, sizeof(first));
		memset(second, 0, sizeof(second));
		memset(firsti, 0, sizeof(firsti));
		memset(secondi, 0, sizeof(secondi));
		
	}
	return 0;
}
void add_int(int a[], int b[]){
	int flow = 0, bal;
	for(int i=0; i<LENGTH; i++){
		bal = a[i] + b[i] + flow;
		a[i] = bal % 10;
		flow = bal / 10;
	}
}
void mul_int(int a[], int b[]){
	int prod[LENGTH];
	int i, j, subt, c;
	memset(prod, 0, sizeof(prod));
	for(i=0; i<LENGTH; i++){
		c = 0;
		for(j=0; j<LENGTH; j++){
			if(i+j<LENGTH){
				subt = a[i] * b[j] + c + prod[j+i];			
				prod[j+i] = subt % 10;
				c = subt / 10;
			}else
				break;
		}
	}
	for(i=0; i<LENGTH; i++)
		a[i] = prod[i];
}
void my_atoi(char str[], int len, int inti[]){
	for(int i=0; i<len; i++)
		inti[i] = str[len-1-i] - '0';		
}
int cmp_int(int a[], int b[]){
	int i, j;
	for(i=LENGTH-1; i>=0; i--)
		if(a[i] != 0) break;
	for(j=LENGTH-1; j>=0; j--)
		if(b[j] != 0) break;
	if(i>j)return 1;
	else if(i<j) return -1;
	for(int k=i; k>=0; k--){
		if(a[k] > b[k]) return 1;
		else if(a[k] < b[k]) return -1;
	}
	return 0;
}
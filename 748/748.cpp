#include <stdio.h>


#define LENGTH 256
int prod[LENGTH];

int formatfloat(char *str);
int main(){
#ifndef ONLINE_JUDGE
	freopen("748.in", "r", stdin);
#endif
	char f[12];
	int n;
	while(scanf("%s%d", f, &n) != EOF){
		printf("%s\t\t%d\n", f, n);
	}
	return 0;
}
int formatfloat(char *str, int a[]){
	return 0;
}
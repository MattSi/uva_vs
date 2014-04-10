#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 2048
int main(int argc, char* argv[]){
	int number, i, times, val;
	char str[LEN], path[LEN];
	size_t len;
#ifndef ONLINE_JUDGE
	freopen("712.in", "r", stdin);
#endif
	i = 1;
	while(1){
		scanf("%d\n", &number);
		if(number==0)break;
		fgets(str, LEN, stdin); /* read x1, x2, x3*/
		gets(str);/*, LEN, stdin); /* read values*/
		/*
		len = strlen(str);
		if(str[len-1] == '\n'){
			str[len-1] = '\0';
		}
		*/
		printf("S-Tree #%d:\n", i++);
		scanf("%d\n", &times);
		while(times-- > 0){
			gets(path);/*, LEN, stdin);
			len = strlen(path);
			if(path[len-1] == '\n')
				path[len-1] = '\0';
				*/
			val = strtol(path, NULL, 2);
			printf("%c", str[val]);
		}
		printf("\n\n");

	}
	return 0;
}
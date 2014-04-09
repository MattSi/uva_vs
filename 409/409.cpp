#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 32
int comp(const void *arg1, const void *arg2){
	char *a = (char*)arg1;
	char *b = (char*)arg2;
	return strcmp(a,b);
}
int main(int argc, char*argv[]){
	int k, e, i, c, j, inword, index, max, casenumber=0;
	char keys[25][LENGTH];
	char exec[25][LENGTH * 3];
	char exeupp[LENGTH];
	int  exelen[25];
#ifndef ONLINE_JUDGE
	freopen("409.in", "r", stdin);
#endif
	while(scanf("%d%d", &k, &e) != EOF){
		for(i=0; i<k; i++)
			scanf("%s\n", keys[i]);
		qsort(keys, k, sizeof(keys[0]), comp);
		memset(exelen, 0, sizeof(exelen));
		max=0;
		for(i=0; i<e; i++){
			//for each line, get every word from the line.
			inword = 0;
			index=0;
			memset(exeupp, 0, sizeof(exeupp));
			memset(exec[i], 0, sizeof(exec[i]));
			j=0;		
			while(1){
				c = getchar();
				exec[i][j++] = c;
				if(isalpha(c)){
					exeupp[index++]= tolower(c);
					inword=1;
				}else if(c == '\n' || c == EOF){
					if(inword){
						//check...
						if(bsearch(exeupp, keys, k, sizeof(keys[0]), comp)){
							exelen[i]++;
							if(exelen[i] > max)
								max = exelen[i];
						}
					}
					exec[i][j]='\0';
					break;
				}else{
					if(inword){
						//check...
						if(bsearch(exeupp, keys, k, sizeof(keys[0]), comp)){
							exelen[i]++;
							if(exelen[i] > max)
								max = exelen[i];
						}
						inword = 0;
						index = 0;
						memset(exeupp, 0, sizeof(exeupp));
					}
				}
			}
		}
		printf("Excuse Set #%d\n", ++casenumber);
		for(i=0; i<e; i++){
			if(exelen[i] == max)
				printf("%s", exec[i]);
		}
		printf("\n");
	}
	return 0;
}
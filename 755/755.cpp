#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 100500
#define COL 300
char number[LENGTH][COL];

int map[256];
void init(){
	memset(map, -1, sizeof(map));
	map[48]=0;
	map[49]=1;
	map[50]=2;
	map[51]=3;
	map[52]=4;
	map[53]=5;
	map[54]=6;
	map[55]=7;
	map[56]=8;
	map[57]=9;
	map[65]=2;
	map[66]=2;
	map[67]=2;
	map[68]=3;
	map[69]=3;
	map[70]=3;
	map[71]=4;
	map[72]=4;
	map[73]=4;
	map[74]=5;
	map[75]=5;
	map[76]=5;
	map[77]=6;
	map[78]=6;
	map[79]=6;
	map[80]=7;
	map[81]=-1;
	map[82]=7;
	map[83]=7;
	map[84]=8;
	map[85]=8;
	map[86]=8;
	map[87]=9;
	map[88]=9;
	map[89]=9;
	map[90]=-1;
}
int comp(const void *arg1, const void *arg2){
	char *a = (char*)arg1;
	char *b = (char*)arg2;
	return  strcmp(a,b);
}
void output(int phones){
	int i, j, record, flag=0;
	for(i=0, j=i+1, record = 1; i<phones; ){
		while(   j<phones && strcmp(number[i], number[j])==0){
			j++;
			record++;
		}
		if(record > 1){
			printf("%c%c%c%c%c%c%c%c %d\n", number[i][0],
				number[i][1],
				number[i][2],
				'-',
				number[i][3],
				number[i][4],
				number[i][5],
				number[i][6],
				record);
			record = 1;
			flag=1;
		}		
		i = j;
		j = i + 1;
	}
	if(!flag){
		printf("No duplicates.\n");
	}else{
		
	}
}
int main(int argc, char* argv[]){
	int dataset, phones;
	char draft[COL];
#ifndef ONLINE_JUDGE
	freopen("755.in", "r", stdin);
#endif
	init();
	scanf("%d\n", &dataset);
	while(dataset){
		scanf("%d\n", &phones);
		memset(number, 0, sizeof(number));
		int index = 0, j;
		for(int k = 0; k<phones; k++){
			fgets(draft, COL, stdin);
			size_t len = strlen(draft);
			j = 0;
			for(int i=0; i<len; i++)
				if(map[draft[i]] >=0)
					number[index][j++]= map[draft[i]] + '0';
			index++;
		}
		qsort(number, phones, sizeof(number[0]), comp);
		output(phones);		
		printf("\n");
		dataset--;
	}
	return 0;
}
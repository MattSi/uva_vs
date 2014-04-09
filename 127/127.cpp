#include <stdio.h>
#include <string.h>

#define CARDS 52

int randmap[128] = {0};
 
typedef struct _heap{
	int number;
	int card[CARDS + 1];
}Heap;
Heap heap[CARDS];


int read_group();
int play();
int find(int current, int position);
int main(int argc, char *argv[]){
#ifndef ONLINE_JUDGE
	freopen("127.in", "r", stdin);
#endif
	randmap[65] = 10;
	randmap[50] = 20;
	randmap[51] = 30;
	randmap[52] = 40;
	randmap[53] = 50;
	randmap[54] = 60;
	randmap[55] = 70;
	randmap[56] = 80;
	randmap[57] = 90;
	randmap[84] = 100;
	randmap[74] = 110;
	randmap[81] = 120;
	randmap[75] = 130;

	while(read_group()){
		while(1){
			if(!play())break;
		}
		int result = 0;
		for(int i=0; i<CARDS; i++)
			if(heap[i].number) result++;
		if(result > 1)printf("%d piles remaining:", result);
		else printf("1 pile remaining:");
		for(int i=0; i<CARDS; i++)
			if(heap[i].number)
				printf(" %d", heap[i].number);
		printf("\n");
	}
	return 0;
}
int play(){
	int  i;
	int rank, suit, rank_tmp = 0, suit_tmp = 0;
	for(i=0; i<CARDS; i++){
		if(heap[i].number == 0)continue;
		suit = heap[i].card[heap[i].number] % 10;
		rank = heap[i].card[heap[i].number] / 10;
		int next3 = find(i, 3);
		if(next3 >=0 && heap[next3].number>=1){
			suit_tmp = heap[next3].card[heap[next3].number] % 10;
			rank_tmp = heap[next3].card[heap[next3].number] / 10;
			if(rank_tmp == rank || suit_tmp == suit){
				heap[next3].number ++ ;
				heap[next3].card[heap[next3].number] = heap[i].card[heap[i].number];
				heap[i].number--;
				return 1;
			}
		}
		int next1 = find(i, 1);
		if(next1 >=0 && heap[next1].number>=1){
			suit_tmp = heap[next1].card[heap[next1].number] % 10;
			rank_tmp = heap[next1].card[heap[next1].number] / 10;
			if(rank_tmp == rank || suit_tmp == suit){
				heap[next1].number ++ ;
				heap[next1].card[heap[next1].number] = heap[i].card[heap[i].number];
				heap[i].number--;
				return 1;
			}
		}
	}
	return 0;
}
int find(int current, int position){
	if(!current)return -1;
	while(--current >= 0){
		if(heap[current].number){
			position--;
			if(!position)return current;
		}
	}
	if(current < 0)return -1;
}
int read_group(){
	char tmp[6];
	int i=0;
	//memset(heap, 0, sizeof(heap));
	scanf("%s", tmp);
	if(!strcmp(tmp, "#"))return i;
	heap[i].number = 1;
	heap[i].card[heap[i].number] = randmap[tmp[0]] + (tmp[1] % 10);
	for(i=1; i<CARDS; i++){
		scanf("%s", tmp);
		heap[i].number = 1;
		heap[i].card[heap[i].number] = randmap[tmp[0]] + (tmp[1] % 10);
	}
	return i;
}
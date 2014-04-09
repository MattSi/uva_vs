#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXMEM 1000010
#define MAXTEAM 1024
typedef struct _Member{
	int element;
	int team;
	struct _Member* forward;
	struct _Member* backward;
}Member;
typedef struct _queue{
	Member *head;
	Member *tail;
	int number;
}Queue;

Queue *queue;
Member* teams[MAXTEAM];
short *element;
void init();
void push(int team, int element, Member *location);
void pop(int bprint);


int main(){
	int team, times, i, j, tmp, s=0;
	char cmd[16];
	Member *tmpteam;
#ifndef ONLINE_JUDGE
	freopen("540.in", "r", stdin);
#endif
	queue = (Queue*)malloc(sizeof(Queue));
	element = (short*)calloc(MAXMEM, sizeof(short));
	while(scanf("%d\n", &times) != EOF){
		if(times == 0)break;
		init();
		for(i=0; i<times; i++){
			scanf("%d", &team);
			for(j=0; j<team; j++){
				scanf("%d", &tmp);
				element[tmp] = i;
			}				
		}

		printf("Scenario #%d\n", ++s);
		while(1){
			scanf("%s", cmd);
			if(strcmp(cmd, "ENQUEUE")==0){
				scanf("%d\n", &i);
				tmp = element[i]; /*Get the team which the element belongs to*/
				tmpteam = teams[tmp]; /*Check whether there is same team element in queue*/
				push(tmp, i, tmpteam);
			}else if(strcmp(cmd, "DEQUEUE")==0){
				pop(1);
			}else{ /* means command is STOP */	
				while(queue->number > 0)
					pop(0);
				break;
			}
		}
		printf("\n");
	}
	free(element);
	free(queue);
	return 0;
}

void init(){
	queue->head = NULL;
	queue->tail = NULL;
	queue->number = 0;
	memset(teams, NULL, sizeof(teams));
}
void push(int team, int element, Member *location){
	Member *member = (Member*)malloc(sizeof(Member));
	member->team = team;
	member->element = element;
	member->backward = NULL;
	member->forward = NULL;
	if(location == NULL){
		/* push it to tail. */
		if(queue->tail == NULL){
			queue->tail = member;
			queue->head = member;
		}else{
			queue->tail->backward = member;
			member->forward = queue->tail;
			queue->tail = member;
		}
	}else{
		/* push back of location */
		if(queue->tail == location){
			queue->tail->backward = member;
			member->forward = queue->tail;
			queue->tail = member;
		}else{
			member->backward = location->backward;
			member->forward = location;
			member->backward->forward = member;
			location->backward = member;
		}
	}
	teams[team] = member;
	queue->number ++;
}

void pop(int bprint){
	if(queue->number == 0)return;
	Member *item = queue->head;
	if(item->backward == NULL ){
		/*There is only one item in queue.*/
		teams[item->team] = NULL;
		queue->head = NULL;
		queue->tail = NULL;
	}else if(item->team != item->backward->team){
		teams[item->team] = NULL;
		queue->head = item->backward;
		item->backward->forward = NULL;
	}else{
		queue->head = item->backward;
		item->backward->forward = NULL;
	}
	if(bprint)
		printf("%d\n", item->element);
	free(item);
	queue->number--;
}







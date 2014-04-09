#include <stdio.h>

#define N 20
int q[N];
void play(int n, int k, int m);
int move(int n, int current, int step, int flag);
int main(){
#ifndef ONLINE_JUDGE
	freopen("133.in", "r", stdin);
#endif
	int n, k, m;
	int i,j;
	while(scanf("%d%d%d", &n, &k, &m) == 3){
		if(n==0 && k==0 && m==0)break;
		for(i=0; i<n; i++)q[i] = i+1;
		play(n, k, m);
	}
	return 0;
}

int move(int n, int current, int step, int flag){
	if(flag){ /*from small to big*/
		while(1){
			if(q[current]>0) 
				step--;
			if(!step)break;
			current = (current + 1)%n;
		}
	}else{
		while(1){
			if(q[current]>0)
				step--;
			if(!step)break;
			if(current == 0)
				current = n;
			current = (current - 1) % n;
		}
	}
	return current;
}

void play(int n, int k, int m){
	int i = 0, j = n-1, left = n;
	while(left > 0){
		i = move(n, i, k, 1);
		j = move(n, j, m, 0);
		if(i == j){
			left--;
			if(left<=0)
				printf("%3d", q[i]);
			else
				printf("%3d,", q[i]);
			q[i] = -1;			
		}else{
			left-=2;
			printf("%3d%3d", q[i], q[j]);
			if(left>0)printf(",");
			q[i] = -1;
			q[j] = -1;
			
		}
	}
	printf("\n");
}
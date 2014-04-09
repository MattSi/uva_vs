#include <stdio.h>

#define LENGTH 60

int bubble(int [], int length);
int main(){
	int n, l, train[LENGTH], count;
#ifndef ONLINE_JUDGE
	freopen("299.in", "r", stdin);
#endif
	scanf("%d\n", &n);
	while(n--){
		scanf("%d\n", &l);
		for(int i=0; i<l; i++){
			scanf("%d", &train[i]);
		}
		printf("Optimal train swapping takes %d swaps.\n", bubble(train, l));
	}
}
int bubble(int train[], int length){
	int count = 0;
	int flag = 0;
	for(int i=0; i<length; i++){
		flag = 0;
		for(int j=0; j<length - i -1; j++){
			if(train[j] > train[j + 1]){
				int tmp = train[j];
				train[j] = train[j + 1];
				train[j + 1] = tmp;
				count++;
				flag = 1;
			}
		}
		if(!flag)break;
	}
	return count;
}
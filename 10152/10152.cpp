#include <stdio.h>
#include <string.h>

#define len 201
#define le 81
char names[len][81];
int now[len];

int main(){
#ifndef ONLINE_JUDGE    
    freopen("./tests/10152.in", "r", stdin);
    freopen("./tests/10152.out", "w", stdout);

#endif
    int n, i, j, num;
    char tn[le];
    scanf("%d", &n);
    while(n--){
        scanf("%d\n", &num);
        for(i=0; i<num; i++)
            gets(names[i]);
        for(i=0; i<num; i++){
            gets(tn);
            for(j=0; j<num;j++)
                if(!strcmp(names[j], tn)){
                    now[i] = j;
                    break;;
                }
        }
        
        i = num-1;
        while(i>0){
            if(now[i] < now[i-1]){
                break;
            }
            i--;
        }

        if(i==0)printf("\n");
        else{
            for(--i; i>=0; i--)
                printf("%s\n", names[now[i]]);
            printf("\n");
        }
    }
}

/*
 * Uva 10887 - Concatenation of Languages 
 * ¹þÏ£±í
 * Time: 0.404s (UVa)
 * Author: D_Double
 */
#include<iostream>
#include<cstring>
#include<cstdio>
#define MAXN 1503
using namespace std;

char A[MAXN][12], C[MAXN*MAXN][24];
const int HashSize = MAXN*MAXN;
int head[HashSize], next[HashSize], rear, ans;

inline void init(){ rear=1; ans=0;  memset(head, 0, sizeof(head)); }

inline int hash(char *str){
    int seed=131, v=0;
    while(*str) v = v*seed + (*str++);
    return (v & 0x7FFFFFFF)%HashSize;
}

int try_to_insert(int s){
    int h = hash(C[s]);
    int u = head[h];
    while(u){
        if(strcmp(C[u], C[s])==0) return 0;
        u = next[u];
    }
    next[s] = head[h];
    head[h] = s;
    return 1;
}

int main(){
	freopen("code.in","r",stdin);
	freopen("other.out","w",stdout);
    int T, M, N, cas=1;
    scanf("%d%*c", &T);
    while(T--){
        scanf("%d %d%*c",&M,&N);
        for(int i=0; i<M; ++i) gets(A[i]);

        init();

        char str[12], link_word[24];
        for(int j=0; j<N; ++j){
            gets(str);
            for(int i=0; i<M; ++i){
                strcpy(link_word, A[i]);
                strcat(link_word, str);
                strcpy(C[rear], link_word);
                if(try_to_insert(rear)){ ++rear; ++ans; }
            }
        }
        printf("Case %d: %d\n", cas++, ans);
    }
    return 0;
}

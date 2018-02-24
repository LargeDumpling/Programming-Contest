#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
using namespace std;

const int Maxn=1010;
int tl[Maxn];
int n,m;

void init(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",tl+i);
	}
}

void work(){
	scanf("%d",&m);
	for(int i=1;i<=m;i++) {
		int cmd,a;
		scanf("%d%d",&cmd,&a);
		a++;
		if(cmd==1) {
			int ans=0;
			for(;a<=n;a=a+tl[a]) ans++;
			printf("%d\n",ans);
		}else {
			scanf("%d",tl+a);
		}
	}
}
		

int main() {
	freopen("in.txt","r",stdin);
	freopen("stdout.txt","w",stdout);
	
	init();
	work();
	
	return 0;
}


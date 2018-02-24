#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<ctime>

using namespace std;

int rand(int l,int r) {
	return l+((rand()<<16)+rand())%(r-l+1);
}

int main() {
	freopen("in.txt","w",stdout);
	
	srand(time(0));
	for(int T=1;T<=2;T++) {
		int n=10;
		printf("%d\n",n);
		for(int i=2;i<=n;i++) {
			printf("%d %d\n",i,rand(1,i-1));
		}
		for(int i=1;i<=n;i++) {
			printf("%d%c",rand(1,100),i==n?'\n':' ');
		}
		int m=10;
		printf("%d\n",m);
		for(int i=1;i<=m;i++) {
			int opt=rand(1,4);
			int x=rand(1,n),y=rand(1,n),w=rand(1,100);
			printf("%d ",opt);
			if(opt==3) printf("%d ",w);
			printf("%d %d\n",x,y);
		}
	}
	return 0;
}


#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<ctime>

using namespace std;

int ran(int l,int r) {
	return l+((rand()<<16)+rand())%(r-l+1);
}

int main() {
	freopen("in.txt","w",stdout);
	
	srand(time(0));
	
	int n=1000,m=1000;
	printf("%d\n",n);
	for(int i=1;i<=n;i++) {
		printf("%d%c",ran(1,n*2),i==n?'\n':' ');
	}
	printf("%d\n",m);
	for(int i=1;i<=m;i++){
		int cmd=ran(1,2);
		printf("%d %d",cmd,ran(0,n-1));
		if(cmd==2) printf(" %d",ran(1,n*2));
		puts("");
	}
	
	return 0;
}


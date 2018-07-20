//LargeDumpling
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=10;
const int MAXC=20;
int main(int argc,char *argv[])
{
	freopen("I.in","w",stdout);
	int x; sscanf(argv[1],"%d",&x); srand(x);
	int n=rand()%MAXN+1,c=rand()%MAXC+1;
	printf("%d %d\n",n,c);
	while(n--)
		printf("%d %d\n",rand()%MAXC+1,rand()%MAXC+1);
	return 0;
}



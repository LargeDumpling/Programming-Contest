#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int main()
{
	freopen("code.in","w",stdout);
	srand(time(NULL));
	int n,m,k,e,d;
	n=rand()%10+1,m=rand()%5+3,k=rand()%20;
	e=(m-1)*m/2; 
	printf("%d %d %d %d\n",n,m,k,e);
	for(int i=1;i<=m;i++)
		for(int j=i+1;j<=m;j++)
			printf("%d %d %d\n",i,j,rand()%20);
	d=rand()%n+1;
	printf("%d\n",d);
	for(int i=1;i<=d;i++)
		printf("%d %d %d\n",rand()%(m-2)+2,i,i);
	fclose(stdout);
	return 0;
}


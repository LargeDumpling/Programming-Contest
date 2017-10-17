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
	int n,m,p,sr,sb,sg;
	p=100007;
	sr=rand()%3;
	sb=rand()%3;
	sg=rand()%3;
	n=sr+sb+sg;
	int num[65];
	printf("%d %d %d",sr,sb,sg);
	m=rand()%5;
	printf(" %d %d\n",m+1,p);
	for(int i=0;i<=m;i++)
	{
		for(int j=1;j<=n;j++)num[j]=j;
		for(int j=1;j<=5;j++)
			swap(num[rand()%n+1],num[rand()%n+1]);
		for(int j=1;j<=n;j++)
			printf("%d ",num[j]);
		printf("\n");
	}
	fclose(stdout);
	return 0;
}


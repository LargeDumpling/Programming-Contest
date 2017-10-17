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
	int n=rand()%1000+1,m=rand()%1000+1;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
			printf("%d ",rand()%10);
		printf("\n");
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d ",rand()%10);
		printf("\n");
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
			printf("%d ",rand()%10);
		printf("\n");
	}
	fclose(stdout);
	return 0;
}


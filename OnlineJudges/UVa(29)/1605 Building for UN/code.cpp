#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int idx(int x)
{
	if(x<=26)
		return x+'A'-1;
	return x-26+'a'-1;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=-1)
	{
		printf("2 %d %d\n",n,n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				printf("%c",idx(j));
			printf("\n");
		}
		printf("\n");
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				printf("%c",idx(i));
			printf("\n");
		}
	}
}


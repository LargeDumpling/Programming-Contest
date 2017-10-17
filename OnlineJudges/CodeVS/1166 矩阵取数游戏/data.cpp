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
	int n=rand()%3+1,m=rand()%4+1;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d ",rand()%5);
		printf("\n");
	}
	fclose(stdout);
    return 0;
}


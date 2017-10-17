#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,num[21];
bool pri[41],exist[21];
void DFS(int x)
{
	if(!x)
	{
		memset(exist,false,sizeof(exist));
		num[1]=1;
		exist[1]=true;
		DFS(1);
		exist[1]=false;
		return;
	}
	else if(x==n)
	{
		if(!pri[num[1]+num[n]])
			return;
		for(int i=1;i<=n;i++)
		{
			if(i!=1)
				printf(" ");
			printf("%d",num[i]);
		}
		printf("\n");
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(exist[i]||!pri[num[x]+i])
			continue;
		num[x+1]=i;
		exist[i]=true;
		DFS(x+1);
		exist[i]=false;
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	memset(pri,true,sizeof(pri));
	pri[1]=false;
	for(int i=2;i<=40;i++)
		for(int j=2;j<=sqrt(i);j++)
			if(!(i%j))
				pri[i]=false;
	for(int cAse=1;scanf("%d",&n)!=-1;cAse++)
	{
		if(cAse!=1)
			printf("\n");
		printf("Case %d:\n",cAse);
		DFS(0);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


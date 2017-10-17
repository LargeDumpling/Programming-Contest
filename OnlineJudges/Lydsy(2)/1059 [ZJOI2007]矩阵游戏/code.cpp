#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n,m,lk[205];
bool exist[205],map[205][205];
bool sef(int x)
{
	for(int i=1;i<=n;i++)
		if(map[x][i]&&!exist[i])
		{
			exist[i]=true;
			if(!lk[i]||sef(lk[i]))
			{
				lk[i]=x;
				return true;
			}
		}
	return false;
}
bool hungary()
{
	for(int i=1;i<=n;i++)
	{
		memset(exist,false,sizeof(exist));
		if(!sef(i))
			return false;
	}
	return true;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int t;
	scanf("%d",&T);
	while(T--)
	{
		memset(map,0,sizeof(map));
		memset(lk,0,sizeof(lk));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&t);
				map[i][j]=t;
			}
		if(hungary())
			printf("Yes\n");
		else
			printf("No\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


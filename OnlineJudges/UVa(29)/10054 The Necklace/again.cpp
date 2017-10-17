/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-01	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int G[55][55];
void Euler(int u)
{
	for(int i=1;i<=50;i++) if(G[u][i])
	{
		G[u][i]--;
		G[i][u]--;
		Euler(i);
		printf("%d %d\n",i,u);
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T_T,n,a,b;
	bool flag;
	scanf("%d",&T_T);
	for(int cAse=1;cAse<=T_T;cAse++)
	{
		if(cAse!=1) puts("");
		printf("Case #%d\n",cAse);
		memset(G,0,sizeof(G));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			G[a][b]++;
			G[b][a]++;
		}
		flag=true;
		for(int i=1;i<=50;i++)
		{
			a=0;
			for(int j=1;j<=50;j++) a+=G[i][j];
			if(a&1)
			{
				flag=false;
				break;
			}
			if(a) b=i;
		}
		if(flag) Euler(b);
		else puts("some beads may be lost");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int INF=2139062143;
int T_T,n,m;
int f[101][55][55],g[101][55][55];
int main()
{
	int u,v,w,Q,k,ans;
	scanf("%d",&T_T);
	while(T_T--)
	{
		memset(f,127,sizeof(f));
		memset(g,127,sizeof(g));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			g[0][i][i]=f[0][i][i]=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			g[1][u][v]=min(g[1][u][v],w);
		}
		for(int l=1;l<100;l++)
			for(int k=1;k<=n;k++)
				for(int i=1;i<=n;i++)
					for(int j=1;j<=n;j++) if(g[l][i][k]!=INF&&g[1][k][j]!=INF)
						g[l+1][i][j]=min(g[l+1][i][j],g[l][i][k]+g[1][k][j]);
		memcpy(f[1],g[100],sizeof(g[100]));
		for(int l=1;l<100;l++)
			for(int k=1;k<=n;k++)
				for(int i=1;i<=n;i++)
					for(int j=1;j<=n;j++) if(f[l][i][k]!=INF&&f[1][k][j]!=INF)
						f[l+1][i][j]=min(f[l+1][i][j],f[l][i][k]+f[1][k][j]);
		for(int l=99;l;l--)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
						g[l][i][j]=min(g[l][i][j],g[l+1][i][j]);
		scanf("%d",&Q);
		while(Q--)
		{
			scanf("%d%d%d",&u,&v,&k);
			w=k/100;
			k%=100;
			ans=INF;
			for(int i=1;i<=n;i++) if(f[w][u][i]!=INF&&g[k][i][v]!=INF)
				ans=min(ans,f[w][u][i]+g[k][i][v]);
			if(ans==INF) ans=-1;
			printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


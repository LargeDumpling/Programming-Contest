/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-17	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int T,n,m,D,F,B,fir[3050],end[40050],next[40050],c[40050],f[40050],cur[3050];
int ed,sta,tar,ans,lev[3050];
char map[55][55];
void addedge(int u,int v,int cap)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	c[ed]=cap;
	f[ed]=0;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	f[ed]=c[ed]=cap;
	return;
}
bool BFS()
{
	int u;
	queue<int>q;
	memset(lev,0,sizeof(lev));
	lev[sta]=1;
	q.push(sta);
	while(q.size())
	{
		u=q.front();
		q.pop();
		for(int i=fir[u];i;i=next[i])if(c[i]>f[i]&&!lev[end[i]])
		{
			lev[end[i]]=lev[u]+1;
			q.push(end[i]);
		}
	}
	return lev[tar];
}
int DFS(int u,int maxf)
{
	if(u==tar)return maxf;
	int totf=0,temf;
	for(int i=fir[u];i;i=next[i])if(c[i]>f[i]&&lev[u]+1==lev[end[i]])
	{
		totf+=(temf=DFS(end[i],min(maxf,c[i]-f[i])));
		f[i]+=temf;
		maxf-=temf;
		f[i^1]-=temf;
	}
	if(!totf)lev[u]=-1;
	return totf;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int x,y,move[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d%d",&m,&n,&D,&F,&B);
		memset(fir,ans=0,sizeof(fir));
		ed=1;
		sta=(n+1)*m+1;
		tar=sta+1;
		for(int i=1;i<=n;i++)scanf("%s",map[i]+1);
		for(int i=1;i<=n;i++)
			if(i==1||i==n){for(int j=1;j<=m;j++)if(map[i][j]=='.')
			{
				map[i][j]='#';
				ans+=F;}
			}
			else
			{
				if(map[i][1]=='.')
				{
					map[i][1]='#';
					ans+=F;
				}
				if(map[i][m]=='.')
				{
					map[i][m]='#';
					ans+=F;
				}
			}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(map[i][j]=='#')
				{
					if(i!=1&&i!=n&&j!=1&&j!=m)
						addedge(sta,i*m+j,D);
					else
						addedge(sta,i*m+j,2147483647);
				}
				else if(map[i][j]=='.')addedge(i*m+j,tar,F);
				for(int k=0;k<=3;k++)
				{
					x=i+move[k][0];
					y=j+move[k][1];
					if(1<=x&&x<=n&&1<=y&&y<=m)
						addedge(i*m+j,x*m+y,B);
				}
			}
		}
		while(BFS())ans+=DFS(sta,2147483647);
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


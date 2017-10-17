/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-05	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=450;
const int MAXM=350000;
int fir[MAXN],cur[MAXN],lev[MAXN],end[MAXM],next[MAXM],f[MAXM],ed=1,S,T;
void init()
{
	memset(fir,0,sizeof(fir));
	ed=1; S=MAXN-2; T=MAXN-1;
	return;
}
void addedge(int u,int v,int cap)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	f[ed]=cap;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	f[ed]=0;
	return;
}
bool BFS()
{
	int u;
	queue<int> q;
	memset(lev,-1,sizeof(lev));
	lev[S]=0;
	q.push(S);
	while(q.size())
	{
		u=q.front(); q.pop();
		for(int i=fir[u];i;i=next[i]) if(f[i]&&lev[end[i]]==-1)
		{
			lev[end[i]]=lev[u]+1;
			q.push(end[i]);
		}
	}
	memcpy(cur,fir,sizeof(fir));
	return lev[T]!=-1;
}
int DFS(int u,int maxf)
{
	if(u==T||!maxf) return maxf;
	int cnt=0;
	for(int &i=cur[u],tem;i;i=next[i]) if(f[i]&&lev[end[i]]==lev[u]+1)
	{
		tem=DFS(end[i],min(f[i],maxf));
		maxf-=tem;
		f[i]-=tem;
		f[i^1]+=tem;
		cnt+=tem;
		if(!maxf) break;
	}
	if(!cnt) lev[u]=-1;
	return cnt;
}
int Dinic()
{
	int ans=0;
	while(BFS())
		ans+=DFS(S,2147483647);
	return ans;
}
int n,m,dis[20050][25][25],num[25][25],an,tot;
char map[25][25];
vector<int> wait;
void calc_dis()
{
	int u,move[4][2]={{1,0},{0,1},{-1,0},{0,-1}},x,y,xx,yy;
	bool exist[25][25];
	queue<int>q;
	tot=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(map[i][j]=='D') wait.push_back(i*100+j);
			else if(map[i][j]=='.') tot++;
		}
	for(unsigned j=0;j<wait.size();j++)
	{
		memset(exist,false,sizeof(exist));
		memset(dis[j],127,sizeof(dis[j]));
		dis[j][wait[j]/100][wait[j]%100]=0;
		exist[wait[j]/100][wait[j]%100]=true;
		q.push(wait[j]);
		while(q.size())
		{
			u=q.front(); q.pop();
			y=u%100; x=u/100;
			exist[x][y]=false;
			for(int i=0;i<4;i++)
			{
				xx=x+move[i][0];
				yy=y+move[i][1];
				if(1<=xx&&xx<=n&&1<=yy&&yy<=m&&map[xx][yy]=='.')
				{
					if(dis[j][x][y]+1<dis[j][xx][yy])
					{
						dis[j][xx][yy]=dis[j][x][y]+1;
						if(!exist[xx][yy])
						{
							exist[xx][yy]=true;
							q.push(xx*100+yy);
						}
					}
				}
			}
		}
	}
	return;
}
bool check(int x)
{
	init();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			if(map[i][j]=='X') continue;
			else if(map[i][j]=='D') addedge(num[i][j],T,x);
			else if(map[i][j]=='.')
			{
				addedge(S,num[i][j],1);
				for(unsigned k=0;k<wait.size();k++)
					if(dis[k][i][j]<=x)
						addedge(num[i][j],num[wait[k]/100][wait[k]%100],1);
			}
	}
	return Dinic()==tot;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%d",&n,&m);
	an=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",map[i]+1);
		for(int j=1;j<=m;j++) num[i][j]=++an;
	}
	calc_dis();
	int l=0,mid,r=500;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid;
	}
	if(check(l)) r=l;
	printf("%d",r);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


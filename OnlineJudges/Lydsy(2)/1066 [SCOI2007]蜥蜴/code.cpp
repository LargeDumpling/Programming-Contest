/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-02	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=1000;
const int MAXM=80000;
const int INF=1<<30;
int fir[MAXN],cur[MAXN],lev[MAXN],end[MAXM],next[MAXM],f[MAXM],ed,S,T;
int n,m,d;
void init(int SS,int TT)
{
	memset(fir,0,sizeof(fir));
	ed=1; S=SS; T=TT;
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
	queue<int>q;
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
	memcpy(cur,fir,sizeof fir);
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
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	char str[25];
	int an=0,in[25][25],out[25][25],x,tot=0;
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	scanf("%d%d%d",&n,&m,&d);
	init(n*m*2+1,n*m*2+2);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str+1);
		for(int j=1;j<=m;j++)
		{
			x=str[j]-'0';
			if(!x) continue;
			in[i][j]=++an; out[i][j]=++an;
			addedge(in[i][j],out[i][j],x);
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(in[i][j])
		for(int k=-d;k<=d;k++)
			for(int l=-d;l<=d;l++) if(k*k+l*l<=d*d)
			{
				if(1<=i+k&&i+k<=n&&1<=j+l&&j+l<=m)
					addedge(out[i][j],in[i+k][j+l],INF);
				else addedge(out[i][j],T,INF);
			}
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str+1);
		for(int j=1;j<=m;j++) if(str[j]=='L')
		{
			tot++;
			addedge(S,in[i][j],1);
		}
	}
	printf("%d",tot-Dinic());
	fclose(stdin);
	fclose(stdout);
	return 0;
}


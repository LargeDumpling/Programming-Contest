/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-11-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=550;
const int MAXM=300050;
const int INF=2147483647;
int fir[MAXN<<1],cur[MAXN<<1],lev[MAXN<<1],edd[MAXM<<1],nxt[MAXM<<1],f[MAXM<<1],ed,S,T;
int n,m,k;
void addedge(int u,int v,int cap)
{
	edd[++ed]=v;
	nxt[ed]=fir[u];
	fir[u]=ed;
	f[ed]=cap;
	edd[++ed]=u;
	nxt[ed]=fir[v];
	fir[v]=ed;
	f[ed]=0;
	return;
}
bool BFS()
{
	int u;
	memset(lev,-1,sizeof(lev));
	queue<int> q;
	lev[S]=0;
	q.push(S);
	while(q.size())
	{
		u=q.front(); q.pop();
		for(int i=fir[u];i;i=nxt[i]) if(f[i]&&lev[edd[i]]==-1)
		{
			lev[edd[i]]=lev[u]+1;
			q.push(edd[i]);
		}
	}
	memcpy(cur,fir,sizeof(fir));
	return lev[T]!=-1;
}
int DFS(int u,int maxf)
{
	if(u==T||!maxf) return maxf;
	int cnt=0;
	for(int &i=cur[u],tem;i;i=nxt[i]) if(f[i]&&lev[edd[i]]==lev[u]+1)
	{
		tem=DFS(edd[i],min(maxf,f[i]));
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
void init(int SS,int TT)
{
	memset(fir,0,sizeof(fir));
	ed=1;
	S=SS; T=TT;
	return;
}
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int main()
{
	int num,x;
	init((MAXN<<1)-2,(MAXN<<1)-1);
	read1n(n); read1n(m);
	read1n(k);
	addedge(S,(MAXN<<1)-3,k);
	for(int i=1;i<=n;i++)
	{
		read1n(num);
		while(num--)
		{
			read1n(x);
			addedge(i,n+x,1);
		}
	}
	for(int i=1;i<=n;i++)
	{
		addedge(S,i,1);
		addedge((MAXN<<1)-3,i,1);
	}
	for(int i=1;i<=m;i++)
		addedge(n+i,T,1);
	printf("%d",Dinic());
	fclose(stdin);
	fclose(stdout);
	return 0;
}


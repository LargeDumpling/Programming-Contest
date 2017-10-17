/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int fir[105],cur[105],lev[105],end[40050],next[40050],c[40050],f[40050],ed,n,sta,tar,m;
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
	memset(lev,0,sizeof(lev));
	queue<int>q;
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
	memcpy(cur,fir,sizeof fir);
	return lev[tar];
}
int DFS(int u,int maxf)
{
	if(u==tar)return maxf;
	int totf=0,temf;
	for(int &i=cur[u];i;i=next[i])if(c[i]>f[i]&&lev[end[i]]==lev[u]+1)
	{
		totf+=(temf=DFS(end[i],min(maxf,c[i]-f[i])));
		f[i]+=temf;
		f[i^1]-=temf;
		maxf-=temf;
	}
	if(!totf)lev[u]=-1;
	return totf;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b,cap,flow;
	for(int cAse=1;scanf("%d",&n)!=-1&&n;cAse++)
	{
		memset(fir,flow=0,sizeof(fir));
		ed=1;
		scanf("%d%d%d",&sta,&tar,&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&a,&b,&cap);
			addedge(a,b,cap);
			addedge(b,a,cap);
		}
		while(BFS())flow+=DFS(sta,2147483647);
		printf("Network %d\nThe bandwidth is %d.\n\n",cAse,flow);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1050,MAXM=2000050;
int n,m,fir[MAXN],end[MAXM],next[MAXM],ed=1,ans[MAXM];
bool vis[MAXM];
void addedge(int u,int v)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	return;
}/*
void DFS(int u)
{
	ans[++ans[0]]=u;
	for(int i=fir[u];i&&ans[0]!=m+1;i=next[i])
	{
		if(vis[i]||vis[i^1])
			continue;
		vis[i]=true;
		DFS(end[i]);
		if(ans[0]!=m+1)
		{
			vis[i]=false;
			ans[0]--;
		}
	}
	return;
}*/
int i;
void DFS(int u)
{
	for(i=fir[u];i&&ans[0]!=n+n+1;i=next[i])
	{
		if(vis[i]||vis[i^1])
			continue;
		vis[i]=true;
		DFS(end[i]);
		ans[++ans[0]]=u;
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		addedge(a,b);
	}
	DFS(1);
	for(int i=1;i<ans[0];i++)
		printf("%d %d\n",ans[i],ans[i+1]);
	fclose(stdin);
	fclose(stdout);
	return 0; 
}


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int fir[100050],son[100050],dis[100050],d[100050];
int end[200050],next[200050],len[200050],t[200050];//g[200050][2],f[200050][2];
int ed=0,size,root,n,maxdeep,md;
unsigned long long ans,g[200050][2],f[200050][2];
bool vis[100050];
void addedge(int u,int v,int l)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	len[ed]=l;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	len[ed]=l;
	return;
}
void DFS(int u,int f,int all)
{
	int maxs=0;
	son[u]=0;
	for(int i=fir[u];i;i=next[i])
	{
		if(vis[end[i]]||end[i]==f)
			continue;
		DFS(end[i],u,all);
		son[u]+=son[end[i]]+1;
		if(son[end[i]]+1>maxs)
			maxs=son[end[i]]+1;
	}
	if(all-son[u]-1>maxs)
		maxs=all-son[u]-1;
	if(maxs<size)
	{
		size=maxs;
		root=u;
	}
	return;
}
void cal(int u,int fa)
{
	if(d[u]>maxdeep)
		maxdeep=d[u];
	if(t[dis[u]])
		f[dis[u]][1]++;
	else
		f[dis[u]][0]++;
	t[dis[u]]++;
	for(int i=fir[u];i;i=next[i])
	{
		if(vis[end[i]]||end[i]==fa)
			continue;
		d[end[i]]=d[u]+1;
		dis[end[i]]=dis[u]+len[i];
		cal(end[i],u);
	}
	t[dis[u]]--;
	return;
}
void work(int u,int all)
{
	size=2147483647;
	DFS(u,u,all);
	u=root;
	vis[u]=true;
	md=0;
	g[n][0]=1;
	for(int i=fir[u];i;i=next[i])
	{
		if(vis[end[i]])
			continue;
		d[end[i]]=maxdeep=1;
		dis[end[i]]=n+len[i];
		cal(end[i],u);
		if(maxdeep>md)
			md=maxdeep;
		ans+=(g[n][0]-1)*f[n][0];
		for(int j=-maxdeep;j<=maxdeep;j++)
			ans+=f[n+j][1]*g[n-j][0]+f[n+j][0]*g[n-j][1]+f[n+j][1]*g[n-j][1];
		for(int j=n-maxdeep;j<=n+maxdeep;j++)
		{
			g[j][0]+=f[j][0];
			g[j][1]+=f[j][1];
			f[j][0]=f[j][1]=0;
		}
	}
	for(int i=n-md;i<=n+md;i++)
		g[i][0]=g[i][1]=0;
	for(int i=fir[u];i;i=next[i])
	{
		if(vis[end[i]])
			continue;
		work(end[i],son[end[i]]+1);
	}
	return;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("code.txt","w",stdout);
	int a,b,c;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(!c)
			c=-1;
		addedge(a,b,c);
	}
	work(1,n);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


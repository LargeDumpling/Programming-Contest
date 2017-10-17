#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int fir[10050],next[20050],end[20050],len[20050],son[10050],dis[10050],jp[10050];
int ed=0,root,size=2147483647,ans=0,n,k;
bool vis[10050];
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
void getjp(int u,int f)
{
	jp[++jp[0]]=dis[u];
	for(int i=fir[u];i;i=next[i])
	{
		if(vis[end[i]]||end[i]==f)
			continue;
		dis[end[i]]=dis[u]+len[i];
		getjp(end[i],u);
	}
	return;
}
void DFS(int u,int f,int all)
{
	int v,temp=0;
	son[u]=0;
	for(int i=fir[u];i;i=next[i])
	{
		if(end[i]==f||vis[end[i]])
			continue;
		v=end[i];
		DFS(v,u,all);
		son[u]+=son[v]+1;
		if(son[v]+1>temp)
			temp=son[v]+1;
	}
	if(all-son[u]-1>temp)
		temp=all-son[u]-1;
	if(temp<size)
	{
		size=temp;
		root=u;
	}
	return;
	
}
int calc(int u,int num)
{
	int l,r,t=0;
	dis[u]=num;
	jp[0]=0;
	getjp(u,u);
	sort(jp+1,jp+jp[0]+1);
	l=1;
	r=jp[0];
	while(l<r)
		if(jp[l]+jp[r]<=k)
			t+=r-(l++);
		else
			r--;
	return t;
}
void work(int u,int all)
{
	size=2147483647;
	DFS(u,u,all);
	u=root;
	ans+=calc(u,0);
	vis[u]=true;
	for(int i=fir[u];i;i=next[i])
	{
		if(vis[end[i]])
			continue;
		ans-=calc(end[i],len[i]);
		work(end[i],son[end[i]]);
	}
}
int main()
{
	int a,b,c;
	while(true)
	{
		memset(fir,ed=0,sizeof(fir));
		memset(vis,false,sizeof(vis));
		ans=0;
		scanf("%d%d",&n,&k);
		if(!n)
			break;
		for(int i=1;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			addedge(a,b,c);
		}
		work(1,n);
		printf("%d\n",ans);
	}
	return 0;
}


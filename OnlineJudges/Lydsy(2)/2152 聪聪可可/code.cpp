#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
//对于100%的数据，n<=20000。
int cnt[3],fir[20050],son[20050],jp[20050],dis[20050],end[40050],next[40050],len[40050];
int ed,ans,size,root,n;
bool vis[20050];
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
int gcd(int m,int n)
{
	int t;
	while(n)
	{
		t=m%n;
		m=n;
		n=t;
	}
	return m;
}
void DFS(int u,int f,int all)
{
	int temp=0;
	son[u]=0;
	for(int i=fir[u];i;i=next[i])
	{
		if(end[i]==f||vis[end[i]])
			continue;
		DFS(end[i],u,all);
		son[u]+=son[end[i]]+1;
		if(son[end[i]]+1>temp)
			temp=son[end[i]]+1;
	}
	if(all-son[u]-1>temp)
		temp=all-son[u]-1;
	if(temp<size)
	{
		root=u;
		size=temp;
	}
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
int calc(int u,int num)
{
	dis[u]=num;
	jp[0]=cnt[0]=cnt[1]=cnt[2]=0;
	getjp(u,u);
	for(int i=1;i<=jp[0];i++)
		cnt[jp[i]%3]++;
	return ((cnt[0]*(cnt[0]-1))/2+cnt[1]*cnt[2]);
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
	return;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("code.txt","w",stdout);
	int a,b,c,fm;
	scanf("%d",&n);
//	ans=n;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		addedge(a,b,c);
	}
	work(1,n);
	ans=2*ans+n;
	printf("%d/%d",ans/gcd(ans,n*n),n*n/gcd(ans,n*n));
	fclose(stdin);
	fclose(stdout);
	return 0;
}


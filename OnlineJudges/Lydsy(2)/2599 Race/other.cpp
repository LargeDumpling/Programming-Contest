#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<algorithm>
#define ll long long
#define inf 1000000000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,K,cnt,sum,root,ans;
int t[1000005],last[200005],son[200005],f[200005],dis[200005],d[200005];
bool vis[200005];
struct edge{int to,next,v;}e[400005];
void insert(int u,int v,int w)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;e[cnt].v=w;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;e[cnt].v=w;
}
void getroot(int x,int fa)
{
	son[x]=1;f[x]=0;
	for(int i=last[x];i;i=e[i].next)
		if(e[i].to!=fa&&!vis[e[i].to])	
		{
			getroot(e[i].to,x);
			son[x]+=son[e[i].to];
			f[x]=max(f[x],son[e[i].to]);
		}
	f[x]=max(f[x],sum-son[x]);
	if(f[x]<f[root])root=x;
}
void cal(int x,int fa)
{
	if(dis[x]<=K)ans=min(ans,d[x]+t[K-dis[x]]);
	for(int i=last[x];i;i=e[i].next)
		if(e[i].to!=fa&&!vis[e[i].to])
		{
			d[e[i].to]=d[x]+1;
			dis[e[i].to]=dis[x]+e[i].v;
			cal(e[i].to,x);
		}
}
void add(int x,int fa,bool flag)
{
	if(dis[x]<=K)
	{
		if(flag)t[dis[x]]=min(t[dis[x]],d[x]);
		else t[dis[x]]=inf;
	}
    for(int i=last[x];i;i=e[i].next)
		if(e[i].to!=fa&&!vis[e[i].to])
			add(e[i].to,x,flag);
}
void work(int x)
{
	vis[x]=1;t[0]=0;
	for(int i=last[x];i;i=e[i].next)
		if(!vis[e[i].to])
		{
			d[e[i].to]=1;dis[e[i].to]=e[i].v;
		    cal(e[i].to,0);
			add(e[i].to,0,1);
		}
	for(int i=last[x];i;i=e[i].next)
		if(!vis[e[i].to])
			add(e[i].to,0,0);
	for(int i=last[x];i;i=e[i].next)
		if(!vis[e[i].to])
		{
			root=0;sum=son[e[i].to];
			getroot(e[i].to,0);
			work(root);
		}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("other.txt","w",stdout);
	n=read();K=read();
	for(int i=1;i<=K;i++)t[i]=n;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=read();
		u++;v++;
		insert(u,v,w);
	}
	ans=sum=f[0]=n;
	getroot(1,0);
	work(root);
	if(ans!=n)printf("%d\n",ans);
	else puts("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

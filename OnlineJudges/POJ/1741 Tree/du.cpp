/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-04-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const int MAXL=1050;
int n,K;
int fir[MAXN],end[MAXN<<1],next[MAXN<<1],len[MAXN<<1],ed=0;
int size[MAXN],hson[MAXN],dis[MAXN],q[MAXN],root;
bool vis[MAXN];
void addedge(int u,int v,int lenth)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	len[ed]=lenth;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	len[ed]=lenth;
	return;
}
void init()
{
	memset(fir,ed=0,sizeof(fir));
	memset(vis,false,sizeof(vis));
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
void get_root(int u,int fa,int all)
{
	size[u]=1; hson[u]=0;
	for(int i=fir[u];i;i=next[i]) if(end[i]!=fa&&!vis[end[i]])
	{
		get_root(end[i],u,all);
		size[u]+=size[end[i]];
		hson[u]=max(hson[u],size[end[i]]);
	}
	hson[u]=max(hson[u],all-size[u]);
	if(root==-1||hson[u]<hson[root])
		root=u;
	return;
}
void DFS(int u,int fa)
{
	size[u]=1;
	if(dis[u]<=K) q[++q[0]]=dis[u];
	for(int i=fir[u];i;i=next[i]) if(end[i]!=fa&&!vis[end[i]])
	{
		dis[end[i]]=dis[u]+len[i];
		DFS(end[i],u);
		size[u]+=size[end[i]];
	}
	return;
}
long long Cnt(int u,int st_dis)
{
	long long sum=q[0]=0;
	dis[u]=st_dis;
	DFS(u,u);
	sort(q+1,q+q[0]+1);
	for(int l=1,r=1;l<=q[0];l++)
	{
		while(r<q[0]&&q[r+1]+q[l]<=K) r++;
		while(l<r&&K<q[r]+q[l]) r--;
		if(l<r) sum=sum+r-l;
	}
	return sum;
}
long long get_ans(int u,int all)
{
	long long ans=0;
	root=-1;
	get_root(u,u,all);
	u=root;
	vis[u]=true;
	ans+=Cnt(u,0);
	for(int i=fir[u];i;i=next[i]) if(!vis[end[i]])
		ans-=Cnt(end[i],len[i]);
	for(int i=fir[u];i;i=next[i]) if(!vis[end[i]])
		ans+=get_ans(end[i],size[end[i]]);
	return ans;
}
int main()
{
	//freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	int u,v,l;
	while(true)
	{
		read1n(n); read1n(K);
		if(n==0&&K==0) break;
		init();
		for(int i=1;i<n;i++)
		{
			read1n(u); read1n(v); read1n(l);
			addedge(u,v,l);
		}
		printf("%lld\n",get_ans(1,n));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-04-05	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=10050;
int n,k;
int fir[MAXN],end[MAXN<<1],next[MAXN<<1],len[MAXN<<1],ed=0;
int size[MAXN];
int ans,cur_root,cur_num;
bool vis[MAXN];
void addedge(int u,int v,int w)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	len[ed]=w;
	end[++ed]=v;
	next[ed]=fir[v];
	fir[v]=ed;
	len[ed]=w;
	return;
}
void init()
{
	memset(fir,ed=0,sizeof(fir));
	memset(vis,false,sizeof(vis));
	ans=0;
}
void find_root(int u,int fa,int totsize)
{
	int maxs=-1;
	size[u]=1;
	for(int i=fir[u];i;i=next[i]) if(!vis[end[i]]&&end[i]!=fa)
	{
		find_root(end[i],u,totsize);
		size[u]+=size[end[i]];
		maxs=max(maxs,size[end[i]]);
	}
	maxs=max(maxs,totsize-size[u]);
	if(cur_root==-1||maxs<cur_num)
	{
		cur_root=u;
		cur_num=maxs;
	}
	return;
}
void solve(int u,int totsize)
{
	cur_root=-1;
	find_root(u,u,totsize);
	u=cur_root;
	vis[u]=true;
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
	int u,v,w;
	while(true)
	{
		read1n(n); read1n(k);
		if(n==0&&k==0) break;
		init();
		for(int i=1;i<n;i++)
		{
			read1n(u); read1n(v); read1n(w);
			addedge(u,v,w);
			solve(1,n);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


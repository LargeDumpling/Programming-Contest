/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-02-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct jp
{
	int l,r,id,a,b;
}Q[100050];
int n,m,koloro[50050],fir[50050],end[100050],next[100050],ed=0,root;
int BLOCK,s[50050],anc[50050][21],deep[50050],dfn[50050],dfs_clock=0;
int bel[50050],tot=0,res[100050],ans,cnt[50050];
bool used[50050];
void addedge(int u,int v)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	return;
}
bool cnmp(jp a,jp b)
{ return bel[a.l]==bel[b.l]?dfn[a.r]<dfn[b.r]:bel[a.l]<bel[b.l]; }
void DFS(int u)
{
	int v,low=s[0];
	dfn[u]=++dfs_clock;
	for(int i=1;i<=17&&(1<<i)<=deep[u];i++)
		anc[u][i]=anc[anc[u][i-1]][i-1];
	for(int i=fir[u];i;i=next[i]) if((v=end[i])!=anc[u][0])
	{
		anc[v][0]=u;
		deep[v]=deep[u]+1;
		DFS(v);
		if(s[0]-low>=BLOCK)
		{
			++tot;
			while(s[0]>low) bel[s[s[0]--]]=tot;
		}
	}
	s[++s[0]]=u;
	return;
}
int LCA(int a,int b)
{
	int t;
	while(deep[a]<deep[b]) swap(a,b);
	t=deep[a]-deep[b];
	for(int i=18;i>=0&&deep[a]>deep[b];i--) if(t&(1<<i))
		a=anc[a][i];
	if(a==b) return a;
	for(int i=18;i>=0;i--) if(anc[a][i]!=anc[b][i])
		a=anc[a][i],b=anc[b][i];
	return anc[a][0];
}
void reverse(int x)
{
	if(!used[x])
	{
		ans+=(++cnt[koloro[x]]==1);
		used[x]=true;
	}
	else
	{
		ans-=(--cnt[koloro[x]]==0);
		used[x]=false;
	}
	return;
}
void work(int u,int v,int lca)
{
	while(u != v) {
	if(deep[u] > deep[v])
		reverse(u), u = anc[u][0];
	else
		reverse(v), v = anc[v][0];
}
return ;
	while(u!=lca)
	{
		reverse(u);
		u=anc[u][0];
	}
	while(v!=lca)
	{
		reverse(v);
		v=anc[v][0];
	}
	return;
}
int read1n()
{
	int x; char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(x=0;'0'<=ch&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
	return x;
}
int main()
{
	int u,v,lca;
	//scanf("%d%d",&n,&m);
	n=read1n(); m=read1n();
	BLOCK=sqrt(n);
	for(int i=1;i<=n;i++)// scanf("%d",&koloro[i]);
		koloro[i]=read1n();
	for(int i=1;i<=n;i++)
	{
		//scanf("%d%d",&u,&v);
		u=read1n(); v=read1n();
		if(!u) root=v;
		else if(!v) root=u;
		else addedge(u,v);
	}
	for(int i=1;i<=m;i++)
	{
		//scanf("%d%d%d%d",&Q[i].l,&Q[i].r,&Q[i].a,&Q[i].b);
		Q[i].l=read1n();
		Q[i].r=read1n();
		Q[i].a=read1n();
		Q[i].b=read1n();
		Q[i].id=i;
	}
	anc[root][0]=0;
	deep[root]=1;
	DFS(root);
	while(s[0]) bel[s[s[0]--]]=tot;
	sort(Q+1,Q+m+1,cnmp);
	work(Q[1].l,Q[1].r,lca=LCA(Q[1].l,Q[1].r));
	reverse(lca);
	res[Q[1].id]=ans;
	if(Q[1].a!=0&&Q[1].b!=0&&cnt[Q[1].a]!=0&&cnt[Q[1].b]!=0) res[Q[1].id]--;
	reverse(lca);
	for(int i=2;i<=m;i++)
	{
		work(Q[i-1].l,Q[i].l,lca=LCA(Q[i-1].l,Q[i].l));
		work(Q[i-1].r,Q[i].r,lca=LCA(Q[i-1].r,Q[i].r));
		lca=LCA(Q[i].l,Q[i].r);
		reverse(lca);
		res[Q[i].id]=ans;
		if(Q[i].a!=0&&Q[i].b!=0&&cnt[Q[i].a]!=0&&cnt[Q[i].b]!=0) res[Q[i].id]--;
		reverse(lca);
	}
	for(int i=1;i<=m;i++) printf("%d\n",res[i]);
	return 0;
}


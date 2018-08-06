/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-03	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=50050;
const int mod=2019;
int n,q,fir[MAXN],nExt[MAXN],fa[MAXN],fc[MAXN];
int dep[MAXN],size[MAXN],hson[MAXN],top[MAXN],w[MAXN],iw[MAXN],dfs_clock=0;
int d[MAXN<<2][4],L[MAXN<<2],R[MAXN<<2],tag[MAXN<<2];
//0 size
//1 size^2
//2 size*w
//3 size^2*w
void DFS1(int u)
{
	size[u]=1;
	for(int v=fir[u];v;v=nExt[v])
	{
		dep[v]=dep[u]+1;
		DFS1(v);
		size[u]+=size[v];
		if(size[hson[u]]<size[v])
			hson[u]=v;
	}
	return;
}
void DFS2(int u,int tOp)
{
	w[u]=++dfs_clock;
	iw[w[u]]=u;
	top[u]=tOp;
	if(hson[u]) DFS2(hson[u],tOp);
	for(int v=fir[u];v;v=nExt[v]) if(v!=hson[u])
		DFS2(v,v);
	return;
}
void down(int root)
{
	if(L[root]==R[root]||!tag[root]) return;
	for(int i=2;i<4;i++)
	{
		d[root<<1][i]=(d[root<<1][i]+d[root<<1][i-2]*tag[root]%mod)%mod;
		d[root<<1|1][i]=(d[root<<1|1][i]+d[root<<1|1][i-2]*tag[root]%mod)%mod;
	}
	tag[root<<1]=(tag[root<<1]+tag[root])%mod;
	tag[root<<1|1]=(tag[root<<1|1]+tag[root])%mod;
	tag[root]=0;
	return;
}
void maintain(int root)
{
	if(L[root]==R[root]) return;
	for(int i=2;i<4;i++)
		d[root][i]=(d[root<<1][i]+d[root<<1|1][i])%mod;
	return;
}
void build(int root,int l,int r)
{
	L[root]=l; R[root]=r;
	if(l==r)
	{
		d[root][0]=size[iw[l]]%mod;
		d[root][1]=d[root][0]*d[root][0]%mod;
		d[root][2]=d[root][0]*fc[iw[l]]%mod;
		d[root][3]=d[root][0]*d[root][2]%mod;
		return;
	}
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	for(int i=0;i<4;i++)
		d[root][i]=(d[root<<1][i]+d[root<<1|1][i])%mod;
	return;
}
void change(int root,int l,int r,int x)
{
	if(r<l) return;
	if(l<=L[root]&&R[root]<=r)
	{
		for(int i=2;i<4;i++)
			d[root][i]=(d[root][i]+d[root][i-2]*x%mod)%mod;
		tag[root]+=x;
		return;
	}
	down(root);
	int mid=(L[root]+R[root])>>1;
	if(l<=mid) change(root<<1,l,r,x);
	if(mid<r) change(root<<1|1,l,r,x);
	maintain(root);
	return;
}
int query(int root,int l,int r,int k)
{
	if(r<l) return 0;
	if(l<=L[root]&&R[root]<=r) return d[root][k];
	down(root);
	int mid=(L[root]+R[root])>>1,ans=0;
	if(l<=mid) ans=(ans+query(root<<1,l,r,k))%mod;
	if(mid<r) ans=(ans+query(root<<1|1,l,r,k))%mod;
	return ans;
}
void change(int u,int v,int x)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		change(1,w[top[u]],w[u],x);
		u=fa[top[u]];
	}
	if(dep[v]<dep[u]) swap(u,v);
	change(1,w[u]+1,w[v],x);
	return;
}
int query(int u)
{
	return (size[u]*query(1,w[u]+1,w[u]+size[u]-1,2)%mod-query(1,w[u]+1,w[u]+size[u]-1,3)+mod)%mod;
}
int main()
{
	int p,c,u,v,x;
	char str[5];
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++)
	{
		scanf("%d%d",&p,&c);
		fa[i]=p;
		fc[i]=c%mod;
		nExt[i]=fir[p];
		fir[p]=i;
	}
	dep[1]=0;
	DFS1(1);
	DFS2(1,1);
	build(1,1,n);
	while(q--)
	{
		scanf("%s",str);
		if(str[0]=='A')
		{
			scanf("%d",&u);
			printf("%d\n",query(u));
		}
		else
		{
			scanf("%d%d%d",&u,&v,&x);
			change(u,v,x%mod);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


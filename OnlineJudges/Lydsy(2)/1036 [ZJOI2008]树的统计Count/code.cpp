#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
const int MAXN=30050;
int fir[MAXN],end[MAXN<<1],next[MAXN<<1],deep[MAXN],fa[MAXN],top[MAXN],ed=0;
int w[MAXN],fw[MAXN],hson[MAXN],DFS_clock=0;
int data[MAXN<<2],sum[MAXN<<2];
int num[MAXN],n;
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
int DFS1(int u)
{
	int temp,size=1,mAx=0;
	for(int i=fir[u];i;i=next[i])
	{
		if(end[i]==fa[u])
			continue;
		deep[end[i]]=deep[u]+1;
		fa[end[i]]=u;
		size+=(temp=DFS1(end[i]));
		if(temp>mAx)
		{
			hson[u]=end[i];
			mAx=temp;
		}
	}
	return size;
}
void DFS2(int u,int tOp)
{
	w[++DFS_clock]=u;
	fw[u]=DFS_clock;
	top[u]=tOp;
	if(hson[u])
		DFS2(hson[u],tOp);
	for(int i=fir[u];i;i=next[i])
	{
		if(end[i]==fa[u]||end[i]==hson[u])
			continue;
		DFS2(end[i],end[i]);
	}
	return;
}
void build(int root,int l,int r)
{
	if(l==r)
	{
		data[root]=sum[root]=num[w[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	data[root]=max(data[root<<1],data[root<<1|1]);
	sum[root]=sum[root<<1]+sum[root<<1|1];
	return;
}
void change(int root,int pos,int x,int l,int r)
{
	if(l==pos&&pos==r)
	{
		data[root]=sum[root]=x;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)
		change(root<<1,pos,x,l,mid);
	else if(mid<pos)
		change(root<<1|1,pos,x,mid+1,r);
	data[root]=max(data[root<<1],data[root<<1|1]);
	sum[root]=sum[root<<1]+sum[root<<1|1];
	return;
}
int query_m(int root,int L,int R,int l,int r)
{
	if(L<=l&&r<=R)
		return data[root];
	int mid=(l+r)>>1,ans=-30001,a;
	if(L<=mid)
	{
		a=query_m(root<<1,L,R,l,mid);
		ans=max(ans,a);
	}
	if(mid<R)
	{
		a=query_m(root<<1|1,L,R,mid+1,r);
		ans=max(ans,a);
	}
	return ans;
}
int query_s(int root,int L,int R,int l,int r)
{
	if(L<=l&&r<=R)
		return sum[root];
	int mid=(l+r)>>1,ans=0;
	if(L<=mid)
		ans+=query_s(root<<1,L,R,l,mid);
	if(mid<R)
		ans+=query_s(root<<1|1,L,R,mid+1,r);
	return ans;
}
int lca(int u,int v)
{
	while(top[u]!=top[v])
		if(deep[top[u]]<deep[top[v]])
			v=fa[top[v]];
		else
			u=fa[top[u]];
	return deep[u]<deep[v]?u:v;
}
int Query_m(int x,int y)
{
	int ans=-30001,t=lca(x,y),a;
	/*while(top[x]!=top[y])
	{
		if(deep[top[x]]<deep[top[y]])
		{
			ans=max(ans,query_m(1,fw[top[y]],fw[y],1,n));
			y=fa[top[y]];
		}
		else
		{
			ans=max(ans,query_m(1,fw[top[x]],fw[x],1,n));
			x=fa[top[x]];
		}
	}
	if(deep[x]<deep[y])
		ans=max(ans,query_m(1,fw[x],fw[y],1,n));
	else
		ans=max(ans,query_m(1,fw[y],fw[x],1,n));
	return ans;*/
	for(;top[x]!=top[t];x=fa[top[x]])
	{
		a=query_m(1,fw[top[x]],fw[x],1,n);
		ans=max(ans,a);
	}
	for(;top[y]!=top[t];y=fa[top[y]])
	{
		a=query_m(1,fw[top[y]],fw[y],1,n);
		ans=max(ans,a);
	}
	if(deep[x]>deep[y])
		swap(x,y);
	a=query_m(1,fw[x],fw[y],1,n);
	ans=max(ans,a);
	return ans;
}
int Query_s(int x,int y)
{
	int ans=0,t=lca(x,y);
	/*while(top[x]!=top[y])
	{
		if(deep[top[x]]<deep[top[y]])
		{
			ans+=query_s(1,fw[top[y]],fw[y],1,n);
			y=fa[top[y]];
		}
		else
		{
			ans+=query_s(1,fw[top[x]],fw[x],1,n);
			x=fa[top[x]];
		}
	}
	if(deep[x]<deep[y])
		ans+=query_s(1,fw[x],fw[y],1,n);
	else
		ans+=query_s(1,fw[y],fw[x],1,n);*/
	for(;top[x]!=top[t];x=fa[top[x]])
		ans+=query_s(1,fw[top[x]],fw[x],1,n);
	for(;top[y]!=top[t];y=fa[top[y]])
		ans+=query_s(1,fw[top[y]],fw[y],1,n);
	if(deep[x]>deep[y])
		swap(x,y);
	ans+=query_s(1,fw[x],fw[y],1,n);
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b,m;
	char tex[8];
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		addedge(a,b);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	fa[1]=1;
	deep[1]=1;
	DFS1(1);
	DFS2(1,1);
	build(1,1,n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%s%d%d",tex,&a,&b);
		if(tex[1]=='H')
			change(1,fw[a],b,1,n);
		else if(tex[1]=='S')
			printf("%d\n",Query_s(a,b));
		else if(tex[1]=='M')
			printf("%d\n",Query_m(a,b));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


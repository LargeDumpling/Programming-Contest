/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int fir1[100050],next1[100050],fir2[100050],next2[100050],fa[100050],n;
int deep[100050],hson[100050],size[100050],top[100050],w[100050],fw[100050];
int DFS_clock=0;
int data[400050],tag[400050],root1,root2;
void DFS1(int u)
{
	size[u]=1;
	for(int v=fir2[u];v;v=next2[v])
	{
		deep[v]=deep[u]+1;
		DFS1(v);
		size[u]+=size[v];
		if(size[v]>size[hson[u]]) hson[u]=v;
	}
	return;
}
void DFS2(int u,int tOp)
{
	w[++DFS_clock]=u;
	fw[u]=DFS_clock;
	top[u]=tOp;
	if(hson[u]) DFS2(hson[u],tOp);
	for(int v=fir2[u];v;v=next2[v]) if(v!=hson[u]) DFS2(v,v);
	return;
}
void down(int root,int L,int R)
{
	if(!tag[root]) return;
	int mid=(L+R)>>1;
	data[root<<1]+=tag[root]*(mid-L+1);
	data[root<<1|1]+=tag[root]*(R-mid);
	tag[root<<1]+=tag[root];
	tag[root<<1|1]+=tag[root];
	tag[root]=0;
	return;
}
void add(int root,int l,int r,int x,int L,int R)
{
	down(root,L,R);
	if(l<=L&&R<=r)
	{
		data[root]+=x*(R-L+1);
		tag[root]+=x;
		return;
	}
	int mid=(L+R)>>1;
	if(l<=mid) add(root<<1,l,r,x,L,mid);
	if(mid<r) add(root<<1|1,l,r,x,mid+1,r);
	data[root]=data[root<<1]+data[root<<1|1];
	return;
}
void addtoroot(int x,int num)
{
	for(x=fa[x];x&&top[x]!=root2;x=fa[top[x]])
		add(1,fw[top[x]],fw[x],num,1,n);
	if(x) add(1,1,fw[x],num,1,n);
	return;
}
int query(int root,int l,int r,int L,int R)
{
	down(root,L,R);
	if(l<=L&&R<=r) return data[root];
	int mid=(L+R)>>1,ans=0;
	if(l<=mid) ans+=query(root<<1,l,r,L,mid);
	if(mid<r) ans+=query(root<<1|1,l,r,mid+1,r);
	return ans;
}
int querytoroot(int x)
{
	int ans=0;
	for(x=fa[x];x&&top[x]!=root2;x=fa[top[x]])
		ans+=query(1,fw[top[x]],fw[x],1,n);
	if(x) ans+=query(1,1,fw[x],1,n);
	return ans;
}
long long anan=0;
void DFS3(int u)
{
	anan+=(querytoroot(u));
	addtoroot(u,1);
	for(int v=fir1[u];v;v=next1[v])
		DFS3(v);
	addtoroot(u,-1);
	return;
}
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int a,b;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		fa[b]=a;
		next1[b]=fir1[a];
		fir1[a]=b;
	}
	for(int i=1;i<=n;i++)
	{
		if(!fa[i]) root1=i;
		fa[i]=0;
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		fa[b]=a;
		next2[b]=fir2[a];
		fir2[a]=b;
	}
	for(int i=1;i<=n;i++) if(!fa[i]) root2=i;
	fa[root2]=0;
	DFS1(root2);
	DFS2(root2,root2);
	DFS3(root1);
	printf("%lld",anan);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-14	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int NAXN=50050;
const int MOD=201314;
int fir[MAXN],next[MAXN],fa[MAXN],n,q;
int plus[MAXN],redu[MAXN];
int deep[MAXN],size[MAXN],top[MAXN];
struct question
{
	int l,r,z,id,sum;
	question(int a=0,int b=0,int c=0,int d=0):l(a),r(b),z(c),id(d) { sum=0; }
	bool operator<(const question Q) { return id<Q.id; }
}q[50050];
void DFS1(int u)
{
	size[u]=1;
	for(int v=fir[u];v;v=next[v])
	{
		deep[v]=deep[u]+1;
		DFS1(v);
		if(size[v]>size[hson[u]]) hson[u]=v;
		size[u]+=size[v];
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b,c;
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&c); c++;
		fa[u]=c;
		next[i]=fir[c];
		fir[c]=i;
	}
	deep[1]=1;
	fa[1]=1;
	DFS1(1);
	DFS2(1,1);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		q[i]=question(a,b,c,i); a--;
		redu[a]=i; plus[b]=i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


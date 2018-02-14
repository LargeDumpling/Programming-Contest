/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-05	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=500050;
int n,m,num[MAXN],root[MAXN];
int son[20*MAXN][2],data[20*MAXN],sz=0;
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
void build(int L,int R,int x,int last,int &now)
{
	now=++sz;
	son[now][0]=son[last][0];
	son[now][1]=son[last][1];
	data[now]=data[last]+1;
	if(R<=L) return;
	int mid=(L+R)>>1;
	if(x<=mid) build(L,mid,x,son[last][0],son[now][0]);
	else build(mid+1,R,x,son[last][1],son[now][1]);
	return;
}
int query(int l,int r)
{
	int L=1,R=n,mid,u=root[r],v=root[l-1],limit=(r-l+1)/2;
	while(L<R)
	{
		mid=(L+R)>>1;
		if(limit<data[son[u][0]]-data[son[v][0]])
		{
			u=son[u][0];
			v=son[v][0];
			R=mid;
		}
		else if(limit<=data[son[u][1]]-data[son[v][1]])
		{
			u=son[u][1];
			v=son[v][1];
			L=mid+1;
		}
		else return 0;
	}
	return L;
}
int main()
{
	int l,r;
	read1n(n);
	read1n(m);
	for(int i=1;i<=n;i++)
	{
		read1n(num[i]);
		build(1,n,num[i],root[i-1],root[i]);
	}
	for(int i=1;i<=m;i++)
	{
		read1n(l); read1n(r);
		printf("%d\n",query(l,r));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


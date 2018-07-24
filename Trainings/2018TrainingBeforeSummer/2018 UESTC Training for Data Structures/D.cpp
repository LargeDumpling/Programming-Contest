/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
struct jz
{
	int l,r,typ;
}O[MAXN];
int num[MAXN],sum[MAXN<<2],tag[MAXN<<2],L[MAXN<<2],R[MAXN<<2],n,m,k;
void maintain(int root)
{
	sum[root]=sum[root<<1]+sum[root<<1|1];
	return;
}
void build(int root,int l,int r,int x)
{
	L[root]=l; R[root]=r; tag[root]=-1;
	if(l==r)
	{
		sum[root]=(num[l]<=x)?0:1;
		return;
	}
	int mid=(l+r)>>1;
	build(root<<1,l,mid,x);
	build(root<<1|1,mid+1,r,x);
	maintain(root);
	return;
}
void down(int root)
{
	if(tag[root]==-1) return;
	sum[root<<1]=tag[root]*(R[root<<1]-L[root<<1]+1);
	tag[root<<1]=tag[root];
	sum[root<<1|1]=tag[root]*(R[root<<1|1]-L[root<<1|1]+1);
	tag[root<<1|1]=tag[root];
	tag[root]=-1;
	return;
}
void change(int root,int l,int r,int x)
{
	if(r<l) return; //because of line 98, 99, 103, 104, ignore this will cause a Wrong Answer.
	if(l<=L[root]&&R[root]<=r)
	{
		sum[root]=x*(R[root]-L[root]+1);
		tag[root]=x;
		return;
	}
	down(root);
	int mid=(L[root]+R[root])>>1;
	if(l<=mid) change(root<<1,l,r,x);
	if(mid<r) change(root<<1|1,l,r,x);
	/*if(l<=R[root<<1]) change(root<<1,l,r,x);
	if(R[root<<1]<r) change(root<<1|1,l,r,x);*/ //this will cause a Runtime Error.
	maintain(root);
	return;
}
int query(int root,int l,int r)
{
	if(r<l) return 0;
	if(l<=L[root]&&R[root]<=r) return sum[root];
	down(root);
	int ans=0,mid=(L[root]+R[root])>>1;
	if(l<=mid) ans+=query(root<<1,l,r);
	if(mid<r) ans+=query(root<<1|1,l,r);
	/*if(l<=R[root<<1]) ans+=query(root<<1,l,r);
	if(R[root<<1]<r) ans+=query(root<<1|1,l,r);*/
	return ans;
}
void read1n(int &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
bool check(int x)
{
	int cnt0,cnt1;
	build(1,1,n,x);
	for(int i=1;i<=m;i++)
	{
		cnt1=query(1,O[i].l,O[i].r);
		cnt0=O[i].r-O[i].l+1-cnt1;
		if(O[i].typ)
		{
			change(1,O[i].l,O[i].l+cnt1-1,1);
			change(1,O[i].r-cnt0+1,O[i].r,0);
		}
		else
		{
			change(1,O[i].l,O[i].l+cnt0-1,0);
			change(1,O[i].r-cnt1+1,O[i].r,1);
		}
	}
	return query(1,k,k)==0;
}
int main()
{
	int l,r,mid;
	read1n(n); read1n(k);
	for(int i=1;i<=n;i++)
		read1n(num[i]);
	read1n(m);
	for(int i=1;i<=m;i++)
	{
		read1n(O[i].typ);
		read1n(O[i].l);
		read1n(O[i].r);
	}
	l=0; r=n;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid;
	}
	printf("%d\n",r);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


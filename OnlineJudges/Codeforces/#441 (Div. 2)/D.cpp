/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-10-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=300050;
int n,d[MAXN<<2],L[MAXN<<2],R[MAXN<<2];
void build(int root,int l,int r)
{
	L[root]=l; R[root]=r;
	if(l==r)
	{
		d[root]=0;
		return;
	}
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	return;
}
void change(int root,int x)
{
	if(L[root]==x&&x==R[root])
	{
		d[root]=1;
		return;
	}
	if(x<=R[root<<1]) change(root<<1,x);
	else change(root<<1|1,x);
	if(R[root<<1|1]-R[root<<1]==d[root<<1|1])
		d[root]=d[root<<1]+d[root<<1|1];
	else d[root]=d[root<<1|1];
	return;
}
int query(int root,int l,int r)
{
	if(l<=L[root]&&R[root]<=r)
		return d[root];
	if(r<=R[root<<1]) return query(root<<1,l,r);
	else if(R[root<<1]<l) return query(root<<1|1,l,r);
	int lans=query(root<<1,l,r),rans=query(root<<1|1,l,r);
	return rans+(rans==r-R[root<<1])?lans:0;
}
int main()
{
	int x;
	scanf("%d",&n);
	build(1,1,n);
	printf("%d",1);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		change(1,x);
		printf(" %d",i-query(1,1,n)+1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


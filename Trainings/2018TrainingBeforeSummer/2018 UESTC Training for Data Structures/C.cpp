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
const int MAXN=1000050;
int data[MAXN<<2],L[MAXN<<2],R[MAXN<<2];
int n,c[MAXN],b[MAXN];
void build(int root,int l,int r)
{
	L[root]=l; R[root]=r;
	data[root]=-1;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	data[root]=min(data[root<<1],data[root<<1|1]);
	return;
}
void change(int root,int p,int x)
{
	if(L[root]==p&&p==R[root])
	{
		data[root]=x;
		return;
	}
	if(p<=R[root<<1]) change(root<<1,p,x);
	else change(root<<1|1,p,x);
	data[root]=min(data[root<<1],data[root<<1|1]);
	return;
}
int query(int root,int x)
{
	if(L[root]==R[root]) return L[root];
	if(data[root<<1]<x) return query(root<<1,x);
	return query(root<<1|1,x);
}
void read1n(int &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int main()
{
	read1n(n);
	build(1,1,n);
	change(1,1,0);
	for(int i=1;i<=n;i++)
	{
		read1n(c[i]);
		b[i]=query(1,i-c[i]);
		change(1,b[i],i);
		printf("%d ",b[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


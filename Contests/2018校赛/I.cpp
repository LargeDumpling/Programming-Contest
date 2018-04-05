/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ull unsigned long long
using namespace std;
const int MAXN=100050;
int A[MAXN],n,q;
int L[MAXN<<1],R[MAXN<<1];
ull d[MAXN<<2][2],tag[MAXN<<2][4];
void maintain(int root)
{
	d[root][0]=d[root<<1][0]+d[root<<1|1][0];
	d[root][1]=d[root<<1][1]+d[root<<1|1][1];
	return;
}
void build(int root,int l,int r)
{
	L[root]=l; R[root]=r;
	if(l==r)
	{
		d[root][0]=A[l];
		d[root][1]=tag[root][0]=tag[root][1]=0;
		return;
	}
	maintain(root);
	return;
}
void down(int root)
{
	if(!root||L[root]==R[root]) return;
	if(tag[root][0])
	{
		if(check
		d[root<<1][0]+=(ull)(R[root<<1]-L[root<<1]+1ULL)*tag[root][0];
		d[root<<1|1][0]+=(ull)(R[root<<1|1]-L[root<<1|1]+1ULL)*tag[root][0];
		tag[root<<1][0]+=tag[root][0];
		tag[root<<1|1][0]+=tag[root][0];
		tag[root][1]=0;
	}
	if(tag[root][1]!=0||tag[root][2]!=0)
	{
	}
	return;
}
void change(int root,int L,int R,int l,int r,int x)
{
}
int main()
{
	int l,r;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	build(1,1,n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


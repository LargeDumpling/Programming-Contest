/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-07-06	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=30050;
int n,m;
int data[MAXN<<2],tag[MAXN<<2],L[MAXN<<2],R[MAXN<<2];
void build(int root,int l,int r)
{
	L[root]=l; R[root]=r;
	if(l==r)
	{
		data[root]=1;
		return;
	}
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	data[root]=data[root<<1]+data[root<<1|1];
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%d",&n,&m);
	build(1,1,n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


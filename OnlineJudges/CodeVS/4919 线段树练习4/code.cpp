/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n,q,num[MAXN];
int data[MAXN<<2][7],tag[MAXN<<2],L[MAXN<<2],R[MAXN<<2];
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
void down(int root)
{
	if(L[root]==R[root]||!tag[root]) return;
	int tem[7],t=tag[root];
	for(int i=0;i<7;i++) tem[(i+t)%7]=data[root<<1][i];
	for(int i=0;i<7;i++) data[root<<1][i]=tem[i];
	for(int i=0;i<7;i++) tem[(i+t)%7]=data[root<<1|1][i];
	for(int i=0;i<7;i++) data[root<<1|1][i]=tem[i];
	tag[root<<1]+=t;
	tag[root<<1|1]+=t;
	tag[root]=0;
	return;
}
void build(int root,int l,int r)
{
	L[root]=l; R[root]=r;
	if(l==r)
	{
		memset(data[root],0,sizeof(data[root]));
		data[root][num[l]]++;
		tag[root]=0;
		return;
	}
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	for(int i=0;i<7;i++)
		data[root][i]=data[root<<1][i]+data[root<<1|1][i];
	return;
}
void add(int root,int l,int r,int x)
{
	if(l<=L[root]&&R[root]<=r)
	{
		int tem[7];
		for(int i=0;i<7;i++) tem[(i+x)%7]=data[root][i];
		for(int i=0;i<7;i++) data[root][i]=tem[i];
		tag[root]+=x;
		return;
	}
	down(root);
	int mid=(L[root]+R[root])>>1;
	if(l<=mid) add(root<<1,l,r,x);
	if(mid<r) add(root<<1|1,l,r,x);
	for(int i=0;i<7;i++)
		data[root][i]=data[root<<1][i]+data[root<<1|1][i];
	return;
}
int query(int root,int l,int r)
{
	if(l<=L[root]&&R[root]<=r)
		return data[root][0];
	down(root);
	int mid=(L[root]+R[root])>>1,ans=0;
	if(l<=mid) ans+=query(root<<1,l,r);
	if(mid<r) ans+=query(root<<1|1,l,r);
	return ans;
}
int main()
{
	char comm[10];
	int l,r,x;
	read1n(n);
	for(int i=1;i<=n;i++)
	{
		read1n(num[i]);
		num[i]%=7;
	}
	build(1,1,n);
	read1n(q);
	while(q--)
	{
		scanf("%s%d%d",comm,&l,&r);
		switch(comm[0])
		{
			case 'a':
				read1n(x);
				add(1,l,r,x%7);
				break;
			case 'c':
				printf("%d\n",query(1,l,r));
				break;
			default:
				break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


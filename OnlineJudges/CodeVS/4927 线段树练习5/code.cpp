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
int n,m,L[MAXN<<2],R[MAXN<<2];
long long num[MAXN],data[MAXN<<2][3],tag[MAXN<<2][2];
template<typename Ty>
void read1n(Ty &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
void down(int root)
{
	if(L[root]==R[root]||(!tag[root][0]&&!tag[root][1]))
		return;
	if(tag[root][1])
	{
		data[root<<1][0]=(R[root<<1]-L[root<<1]+1)*tag[root][1];
		data[root<<1][1]=data[root<<1][2]=tag[root][1];
		tag[root<<1][1]=tag[root][1];
		data[root<<1|1][0]=(R[root<<1|1]-L[root<<1|1]+1)*tag[root][1];
		data[root<<1|1][1]=data[root<<1|1][2]=tag[root][1];
		tag[root<<1|1][1]=tag[root][1];
		tag[root][0]=tag[root][1]=0;
	}
	if(tag[root][0])
	{
		data[root<<1][0]+=(R[root<<1]-L[root<<1]+1)*tag[root][0];
		data[root<<1][1]+=tag[root][0];
		data[root<<1][2]+=tag[root][0];
		tag[root<<1][0]+=tag[root][0];
		data[root<<1|1][0]+=(R[root<<1|1]-L[root<<1|1]+1)*tag[root][0];
		data[root<<1|1][1]+=tag[root][0];
		data[root<<1|1][2]+=tag[root][0];
		tag[root<<1|1][0]+=tag[root][0];
		tag[root][0]=0;
	}
	return;
}
void build(int root,int l,int r)
{
	L[root]=l; R[root]=r;
	tag[root][0]=tag[root][1]=0;
	if(l==r)
	{
		data[root][0]=data[root][1]=data[root][2]=num[l];
		return;
	}
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	data[root][0]=data[root<<1][0]+data[root<<1|1][0];
	data[root][1]=max(data[root<<1][1],data[root<<1|1][1]);
	data[root][2]=min(data[root<<1][2],data[root<<1|1][2]);
	return;
}
void add(int root,int l,int r,long long x)
{
	if(l<=L[root]&&R[root]<=r)
	{
		data[root][0]+=x*(R[root]-L[root]+1);
		data[root][1]+=x;
		data[root][2]+=x;
		tag[root][0]+=x;
		return;
	}
	down(root);
	int mid=(L[root]+R[root])>>1;
	if(l<=mid) add(root<<1,l,r,x);
	if(mid<r) add(root<<1|1,l,r,x);
	data[root][0]=data[root<<1][0]+data[root<<1|1][0];
	data[root][1]=max(data[root<<1][1],data[root<<1|1][1]);
	data[root][2]=min(data[root<<1][2],data[root<<1|1][2]);
	return;
}
void set(int root,int l,int r,long long x)
{
	if(l<=L[root]&&R[root]<=r)
	{
		data[root][0]=(R[root]-L[root]+1)*x;
		data[root][1]=data[root][2]=x;
		tag[root][1]=x;
		return;
	}
	down(root);
	int mid=(L[root]+R[root])>>1;
	if(l<=mid) set(root<<1,l,r,x);
	if(mid<r) set(root<<1|1,l,r,x);
	data[root][0]=data[root<<1][0]+data[root<<1|1][0];
	data[root][1]=max(data[root<<1][1],data[root<<1|1][1]);
	data[root][2]=min(data[root<<1][2],data[root<<1|1][2]);
	return;
}
long long sum(int root,int l,int r)
{
	if(l<=L[root]&&R[root]<=r)
		return data[root][0];
	down(root);
	int mid=(L[root]+R[root])>>1;
	long long ans=0;
	if(l<=mid) ans+=sum(root<<1,l,r);
	if(mid<r) ans+=sum(root<<1|1,l,r);
	return ans;
}
long long mAx(int root,int l,int r)
{
	if(l<=L[root]&&R[root]<=r)
		return data[root][1];
	down(root);
	int mid=(L[root]+R[root])>>1;
	if(r<=mid) return mAx(root<<1,l,r);
	else if(mid<l) return mAx(root<<1|1,l,r);
	return max(mAx(root<<1,l,r),mAx(root<<1|1,l,r));
}
long long mIn(int root,int l,int r)
{
	if(l<=L[root]&&R[root]<=r)
		return data[root][2];
	down(root);
	int mid=(L[root]+R[root])>>1;
	if(r<=mid) return mIn(root<<1,l,r);
	else if(mid<l) return mIn(root<<1|1,l,r);
	return min(mIn(root<<1,l,r),mIn(root<<1|1,l,r));
}
int main()
{
	char comm[10];
	int l,r;
	long long x;
	read1n(n); read1n(m);
	for(int i=1;i<=n;i++)
		read1n(num[i]);
	build(1,1,n);
	while(m-->0)
	{
		scanf("%s%d%d",comm,&l,&r);
		switch(comm[1])
		{
			case 'd':
				read1n(x);
				add(1,1,n,x);
				break;
			case 'e':
				set(1,1,n,x);
				read1n(x);
				break;
			case 'u':
				printf("%lld\n",sum(1,1,n));
				break;
			case 'a':
				printf("%lld\n",mAx(1,1,n));
				break;
			case 'i':
				printf("%lld\n",mIn(1,1,n));
				break;
			default:
				break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


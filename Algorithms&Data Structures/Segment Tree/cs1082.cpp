/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=200050;
int n,m,L[MAXN<<2],R[MAXN<<2];
long long num[MAXN],d[MAXN<<2],tag[MAXN<<2];
template<typename Ty>
bool read1n(Ty &x)
{
	char ch;
	bool neg=false;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
		if(ch==-1) return false;
		else if(ch=='-') neg=true;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	if(neg) x=-x;
	return true;
}
#define lch ((root)<<1)
#define rch ((root)<<1|1)
void maintain(int root)
{
	if(L[root]==R[root]) return;
	d[root]=d[lch]+d[rch];
	return;
}
void down(int root)
{
	if(!tag[root]) return;
	if(L[root]==R[root])
	{
		tag[root]=0;
		return;
	}
	d[lch]+=tag[root]*(R[lch]-L[lch]+1LL);
	d[rch]+=tag[root]*(R[rch]-L[rch]+1LL);
	tag[lch]+=tag[root];
	tag[rch]+=tag[root];
	tag[root]=0;
	return;
}
void build(int root,int l,int r)
{
	L[root]=l; R[root]=r;
	tag[root]=0;
	if(l==r)
	{
		d[root]=num[l];
		return;
	}
	int mid=(l+r)>>1;
	build(lch,l,mid);
	build(rch,mid+1,r);
	maintain(root);
	return;
}
void change(int root,int l,int r,long long x)
{
	if(l<=L[root]&&R[root]<=r)
	{
		tag[root]+=x;
		d[root]+=(R[root]-L[root]+1LL)*x;
		return;
	}
	down(root);
	int mid=(L[root]+R[root])>>1;
	if(l<=mid) change(lch,l,r,x);
	if(mid<r) change(rch,l,r,x); // *** NO "else" before "if"
	maintain(root);
	return;
}
long long query(int root,int l,int r)
{
	if(l<=L[root]&&R[root]<=r) return d[root];
	down(root);
	int mid=(L[root]+R[root])>>1;
	long long sum=0;
	if(l<=mid) sum+=query(lch,l,r);
	if(mid<r) sum+=query(rch,l,r); // *** NO "else" before "if" AGAIN
	return sum;
}
#undef lch
#undef rch
int main()
{
	int l,r,T_T;
	bool flag;
	char str[10];
	read1n(T_T);
	for(int T=1;T<=T_T;T++)
	{
		printf("Case %d:\n",T);
		read1n(n);
		for(int i=1;i<=n;i++)
			read1n(num[i]);
		build(1,1,n);
		flag=true;
		while(flag)
		{
			scanf("%s",str);
			switch(str[0])
			{
				case 'A':
					read1n(l); read1n(r);
					change(1,l,l,r);
					break;
				case 'S':
					read1n(l); read1n(r);
					change(1,l,l,-r);
					break;
				case 'Q':
					read1n(l); read1n(r);
					printf("%lld\n",query(1,l,r));
					break;
				case 'E':
					flag=false;
					break;
				default:
					break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

ch]-L[rch]+1LL);
	tag[lch]+=tag[root];
	tag[rch]+=tag[root];
	tag[root]=0;
	return;
}
void build(int root,int l,int r)
{
	L[root]=l; R[root]=r;
	tag[root]=0;
	if(l==r)
	{
		d[root]=num[l];
		return;
	}
	int mid=(l+r)>>1;
	build(lch,l,mid);
	build(rch,mid+1,r);
	maintain(root);
	return;
}
void change(int root,int l,int r,long long x)
{
	if(l<=L[root]&&R[root]<=r)
	{
		tag[root]+=x;
		d[root]+=(R[root]-L[root]+1LL)*x;
		return;
	}
	down(root);
	int mid=(L[root]+R[root])>>1;
	if(l<=mid) change(lch,l,r,x);
	if(mid<r) change(rch,l,r,x); // *** NO "else" before "if"
	maintain(root);
	return;
}
long long query(int root,int l,int r)
{
	if(l<=L[root]&&R[root]<=r) return d[root];
	down(root);
	int mid=(L[root]+R[root])>>1;
	long long sum=0;
	if(l<=mid) sum+=query(lch,l,r);
	if(mid<r) sum+=query(rch,l,r); // *** NO "else" before "if" AGAIN
	return sum;
}
#undef lch
#undef rch
int main()
{
	int l,r,T_T;
	bool flag;
	char str[10];
	read1n(T_T);
	for(int T=1;T<=T_T;T++)
	{
		printf("Case %d:\n",T);
		read1n(n);
		for(int i=1;i<=n;i++)
			read1n(num[i]);
		build(1,1,n);
		flag=true;
		while(flag)
		{
			scanf("%s",str);
			switch(str[0])
			{
				case 'A':
					read1n(l); read1n(r);
					change(1,l,l,r);
					break;
				case 'S':
					read1n(l); read1n(r);
					change(1,l,l,-r);
					break;
				case 'Q':
					read1n(l); read1n(r);
					printf("%lld\n",query(1,l,r));
					break;
				case 'E':
					flag=false;
					break;
				default:
					break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


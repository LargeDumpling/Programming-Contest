/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-02	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const int mod=998244353;
int n,L[MAXN<<2],R[MAXN<<2];
long long p[MAXN],h[MAXN],cr[MAXN],d[MAXN<<2][2],tag[MAXN<<2];
template<typename Ty>
void read1n(Ty &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
long long pOw(long long a,long long m)
{
	long long ans;
	for(ans=1;m;m>>=1,a=a*a%mod)
		if(m&1)
			ans=ans*a%mod;
	return ans;
}
void build(int root,int l,int r)
{
	d[root]=0;
	L[root]=l; R[root]=r;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(root<<1,l,mid);
	build(root<<1|1,mid+1,r);
	return;
}
int main()
{
	read1n(n);
	build(1,0,n);
	h[0]=0;
	for(int i=1;i<=n;i++)
	{
		read1n(p[i]);
		read1n(cr[i]);
		h[++h[0]]=cr[i];
	}
	sort(h+1,h+h[0]+1);
	h[0]=unique(h+1,h+h[0]+1)-h-1;
	for(int i=1;i<=n;i++)
	{
		cr[i]=lower_bound(h+1,h+h[0]+1,cr[i])-h-1;
	}
	build(1,1,n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


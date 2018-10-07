/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=300050;
const int mod=1000000007;
int n,num[MAXN],w[MAXN],ans=0;
int d[MAXN<<2][2],tag[MAXN<<2],L[MAXN<<2],R[MAXN<<2];
inline int mul_mod(int a,int b)
{
    int ret;
    __asm__ __volatile__("\tmull %%ebx\n\tdivl %%ecx\n":"=d"(ret):"a"(a),"b"(b),"c"(mod));
    return ret;
}
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
#define lch ((root)<<1)
#define rch ((root)<<1|1)
void build(int root,int l,int r)
{
	L[root]=l; R[root]=r;
	d[root][1]=tag[root]=0;
	if(l==r)
	{
		d[root][0]=w[l];
		return;
	}
	int mid=(l+r)>>1;
	build(lch,l,mid);
	build(rch,mid+1,r);
	d[root][0]=(d[lch][0]+d[rch][0])%mod;
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
	d[lch][1]=(d[lch][1]+mul_mod(tag[root],d[lch][0]))%mod;
	d[rch][1]=(d[rch][1]+mul_mod(tag[root],d[rch][0]))%mod;
	tag[lch]=(tag[lch]+tag[root])%mod;
	tag[rch]=(tag[rch]+tag[root])%mod;
	tag[root]=0;
	return;
}
void add(int root,int l,int r)
{
	if(l<=L[root]&&R[root]<=r)
	{
		tag[root]++;
		d[root][1]=(d[root][1]+d[root][0])%mod;
		return;
	}
	down(root);
	int mid=(L[root]+R[root])>>1;
	if(l<=mid) add(lch,l,r);
	if(mid<r) add(rch,l,r);
	d[root][1]=(d[lch][1]+d[rch][1])%mod;
	return;
}
#undef lch
#undef rch
int main()
{
	int limit;
	read1n(n);
	for(int i=1;i<=n;i++)
		read1n(num[i]);
	for(int i=1;i<=n;i++)
		read1n(w[i]);
	build(1,1,n);
	limit=(n+1)>>1;
	for(int i=1;i<=limit;i++)
	{
		add(1,i,n-i+1);
		ans=(ans+mul_mod(d[1][1],num[i]))%mod;
	}
	build(1,1,n);
	for(int i=1;i<=limit;i++)
	{
		if(i==n-i+1) break;
		add(1,i,n-i+1);
		ans=(ans+mul_mod(d[1][1],num[n-i+1]))%mod;
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


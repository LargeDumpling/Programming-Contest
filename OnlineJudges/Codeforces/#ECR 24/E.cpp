/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-07-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const int M=131072;
int n;
long long k,num[MAXN],d[M<<1],ans=0;
long long gcd(long long a,long long b)
{
	if(!a) return b;
	if(!b) return a;
	return gcd(b,a%b);
}
long long prod(int l,int r)
{
	long long pro=1LL;
	for(l=l+M-1,r=r+M+1;l<r-1;l>>=1,r>>=1)
	{
		if(!(l&1)) pro=pro*d[l^1]%k;
		if(r&1) pro=pro*d[r^1]%k;
	}
	return pro;
}
int main()
{
	int l,r,mid;
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
		d[M+i]=gcd(num[i],k);
	}
	for(int i=M;i;i--)
		d[i]=d[i<<1]*d[i<<1|1]%k;
	for(int i=1;i<=n;i++)
	{
		l=i; r=n;
		while(l<r-1)
		{
			mid=(l+r)>>1;
			if(!prod(i,mid)) r=mid;
			else l=mid;
		}
		if(!prod(i,l)) r=l;
		if(!prod(i,r)) ans+=(n-r+1);
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


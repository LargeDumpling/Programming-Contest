/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-12	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
unsigned long long seed;
long double gen()
{
	static const long double Z = ( long double )1.0 / (1LL<<32);
	seed >>= 16;
	seed &= ( 1ULL << 32 ) - 1;
	seed *= seed;
	return seed * Z;
}
unsigned long long read1n()
{
	unsigned long long x=0;char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(;'0'<=ch&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
	return x;
}
long double quad,firstp,tem,ans;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T,n;
	scanf("%d",&T);
	for(int cAse=1;cAse<=T;cAse++)
	{
		scanf("%d%llu",&n,&seed);
		//seed=read1n();
		quad=firstp=0;
		for(int i=1;i<=n;i++)
		{
			tem=gen();
			quad+=tem*tem;
			firstp+=tem;
		}
		tem=firstp/n;
		ans=quad-2*firstp*tem+tem*tem*n;
		ans/=n;
		printf("Case #%d: %.5f\n",cAse,(double)sqrt(ans));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


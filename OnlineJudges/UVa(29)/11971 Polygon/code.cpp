/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-09	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n,k;
long long gCd(long long a,long long b)
{
	long long t;
	while(b)
	{
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	long long fz,fm,tem;
	scanf("%d",&T);
	for(int cAse=1;cAse<=T;cAse++)
	{
		scanf("%d%d",&n,&k);
		fm=(1LL<<k);
		fz=fm-k-1;
		tem=gCd(fz,fm);
		fz/=tem;
		fm/=tem;
		printf("Case #%d: %lld/%lld\n",cAse,fz,fm);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


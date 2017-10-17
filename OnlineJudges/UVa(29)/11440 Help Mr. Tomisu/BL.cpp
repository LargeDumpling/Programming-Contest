/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-10	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int mod=100000007;
unsigned long long Moops;
int n,m,phifacm;
unsigned long long gCd(unsigned long long a,unsigned long long b)
{
	unsigned long long t;
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
	freopen("BL.out","w",stdout);
	while(scanf("%d%d",&n,&m)!=-1&&n&&m)
	{
		Moops=1;
		for(int i=1;i<=m;i++)Moops*=i;
		phifacm=0;
		for(unsigned long long i=2;i<=Moops;i++)if(gCd(Moops,i)==1)phifacm++;
		int ans=0;
		for(int i=m+1;i<=n;i++)
			ans=((long long)ans+phifacm)%mod;
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


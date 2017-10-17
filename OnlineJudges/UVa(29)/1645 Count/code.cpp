/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-11	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
long long f[1050];
void pre_calc()
{
	f[1]=f[2]=1;
	for(int i=3;i<=1000;i++)
	{
		f[i]=0;
		for(int j=1;j<i;j++)
			if(!((i-1)%j))
				f[i]=(f[i]+f[j])%mod;
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n;
	pre_calc();
	for(int cAse=1;scanf("%d",&n)!=-1&&n;cAse++)
		printf("Case %d: %lld\n",cAse,f[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


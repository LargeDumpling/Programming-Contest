/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long mod=1000000007;
const int MAXN=100050;
int Q,k;
long long f[MAXN][2],g[MAXN];
void pre_calc()
{
	f[0][0]=1;
	for(int i=1;i<MAXN;i++)
	{
		f[i][0]=(f[i][0]+f[i-1][0]+f[i-1][1])%mod;
		if(k<=i) f[i][1]=(f[i][1]+f[i-k][0])%mod;
	}
	g[0]=0;
	for(int i=1;i<MAXN;i++)
		g[i]=(g[i-1]+f[i][0]+f[i][1])%mod;
	return;
}
int main()
{
	int l,r;
	scanf("%d%d",&Q,&k);
	pre_calc();
	while(Q--)
	{
		scanf("%d%d",&l,&r);
		printf("%lld\n",(g[r]-g[l-1]+mod)%mod);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


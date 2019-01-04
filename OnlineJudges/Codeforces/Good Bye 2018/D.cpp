/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-12-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1000050;
const long long mod=998244353LL;
int n;
long long E[MAXN],F[MAXN];
void pre_calc()
{
	E[0]=0LL;
	F[0]=1LL;
	for(int i=1;i<MAXN;i++)
	{
		F[i]=F[i-1]*(long long)i%mod;
		E[i]=(E[i-1]+F[i-1]+mod-1LL)%mod*(long long)i%mod;
	}
	return;
}
int main()
{
	int n;
	scanf("%d",&n);
	pre_calc();
	printf("%I64d",(F[n]+E[n])%mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


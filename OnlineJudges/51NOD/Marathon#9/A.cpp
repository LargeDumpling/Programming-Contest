/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int mod=1000000007;
int num[100050];
unsigned long long ans=0,F[100050],fAc[100050];
long long fac(int x){return x<=1?1:fAc[x];}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int x,n;
	scanf("%d",&n);
	fAc[0]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		num[x]++;
		fAc[i]=(fAc[i-1]*i)%mod;
	}
	for(int i=1;i<=n;i++)
		num[i]=(num[i]+num[i-1])%mod;
	F[0]=1;
	for(int i=1;i<=n;i++)
		F[i]=(F[i-1]*max(num[i-1]-i+1,0))%mod;
	for(int i=1;i<n;i++)
		ans=(ans+(i*F[i]%mod)*(max(n-num[i],0)*fac(n-i-1)%mod))%mod;
	ans=(ans+(n*F[n]%mod))%mod;
	cout<<ans;
	return 0;
}


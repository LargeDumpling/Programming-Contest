/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-04-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long mod=998244353;
const int MAXN=25;
int T_T,m;
long long p[MAXN],q[MAXN],invp[MAXN],n,ans;
long long pOw(long long a,long long n)
{
	long long ans;
	for(ans=1;n;n>>=1,a=a*a%mod)
		if(n&1)
			ans=ans*a%mod;
	return ans;
}
long long inv(long long x) { return pOw(x,mod-2); }
void DFS(int u,long long quan,long long a,long long b)
{
	if(u==m)
	{
		if(a==1&&b==1) ans=(ans+n)%mod;
		return;
	}
	DFS(u+1,quan,a,b);
	quan=quan*q[u]%mod;
	a=a*(p[u]-1LL)%mod;
	b=b*invp[u]%mod;
	long long phi=n*a%mod*b%mod;
	ans=(ans+phi*quan%mod)%mod;
	DFS(u+1,quan,a,b);
	//DFS(u+1,quan*q[u]%mod,a*(p[u]-1LL)%mod,b*p[u]%mod);
	return;
}
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		ans=0;
		n=1;
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			scanf("%lld%lld",&p[i],&q[i]);
			n=n*pOw(p[i],q[i])%mod;
			invp[i]=inv(p[i]);
		}
		/*limit=1LL<<m;
		for(int i=0;i<limit;i++)
		{
			quan=phi=1LL;
			a=b=1;
			for(int j=0;j<m;j++) if((i>>j)&1)
			{
				quan=quan*q[j]%mod;
				a=a*(p[j]-1LL)%mod;
				b=b*p[j]%mod;
			}
			phi=n*a%mod*inv(b)%mod;
			ans=(ans+phi*quan%mod)%mod;
		}*/
		DFS(0,1,1,1);
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


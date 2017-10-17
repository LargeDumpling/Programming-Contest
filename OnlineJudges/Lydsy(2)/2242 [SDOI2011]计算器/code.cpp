/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-17	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
long long mod,fir,sec;
long long q_pow(long long a,long long n)
{
	long long ans;
	for(ans=1;n;n>>=1,a=(a*a)%mod) if(n&1) ans=(ans*a)%mod;
	return ans;
}
void solve()
{
	fir%=mod;
	if(!fir&&!sec) { puts("1"); return; }
	else if(!fir) { puts("Orz, I cannot find x!"); return; }
	map<long long,long long>f;
	int limit=(int)sqrt(mod);
	long long a=q_pow(fir,mod-2),b=1;
	for(int i=0;i<limit;i++,b=b*a%mod) f[b*sec%mod]=i;
	a=q_pow(fir,limit),b=1;
	for(int i=0;i*limit<=mod;i++,b=b*a%mod)
		if(f.count(b))
		{
			printf("%lld\n",f[b]+i*limit);
			return;
		}
	puts("Orz, I cannot find x!");
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T_T,type;
	scanf("%d%d",&T_T,&type);
	while(T_T--)
	{
		scanf("%lld%lld%lld",&fir,&sec,&mod);
		if(type==1) printf("%lld\n",q_pow(fir,sec));
		else if(type==2)
		{
			fir%=mod;
			sec%=mod;
			if(!fir&&!sec) puts("0");
			else if(!fir) puts("Orz, I cannot find x!");
			else printf("%lld\n",sec*q_pow(fir,mod-2)%mod);
		}
		else if(type==3) solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


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
int m,n;
long long phifacm[10000050];
bool exist[10000050];
long long pri[10000050];
void calc_pri()
{
	memset(exist,true,sizeof(exist));
	int tem;
	exist[1]=false;
	pri[0]=0;
	for(long long i=2;i<=10000000;i++)
	{
		if(exist[i])pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&(tem=i*pri[j])<=10000000;j++)
		{
			exist[tem]=false;
			if(!(i%pri[j]))break;
		}
	}
	return;
}
/*long long pOw(long long a,int n)
{
	long long ans=1;
	for(;n;n>>=1)
	{
		if(n&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}*/
void calc_Moops()
{
	phifacm[1]=phifacm[2]=1;
	exist[1]=false;
	for(int i=3;i<=10000000;i++)
	{
		if(exist[i])phifacm[i]=phifacm[i-1]*(i-1)%mod;
		else phifacm[i]=phifacm[i-1]*i%mod;
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	long long ans;
	calc_pri();
	calc_Moops();
	while(scanf("%d%d",&n,&m)!=-1&&n&&m)
	{
		ans=phifacm[m];
		for(int i=m+1;i<=n;i++)
			ans=ans*i%mod;
		printf("%lld\n",(ans+mod-1)%mod);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


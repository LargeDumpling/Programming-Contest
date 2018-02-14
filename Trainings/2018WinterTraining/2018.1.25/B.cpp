/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long mod=1000000007;
const int MAXN=55;
long long fac[MAXN],inv[MAXN],num[MAXN];
long long pOw(long long a,long long n)
{
	long long ans;
	for(ans=1;n;n>>=1,a=a*a%mod)
		if(n&1)
			ans=ans*a%mod;
	return ans;
}
void pre_calc()
{
	fac[1]=1;
	for(int i=2;i<MAXN;i++)
		fac[i]=fac[i-1]*(long long)i%mod;
	inv[MAXN-1]=pOw(fac[MAXN-1],mod-2);
	for(int i=MAXN-2;i;i--)
		inv[i]=inv[i+1]*(long long)(i+1)%mod;
	return;
}
int main()
{
	long long ans=0;
	int S[55]={0};
	char str[55];
	pre_calc();
	while(gets(str)!=NULL)
	{
		S[0]=ans=0;
		memset(num,0,sizeof(num));
		for(int i=0;str[i]!='\0';i++)
		{
			if(str[i]=='A')
			{
				S[++S[0]]=1;
				num[1]++;
			}
			else if(str[i]=='0')
			{
				S[++S[0]]=10;
				num[10]++;
			}
			else if('2'<=str[i]&&str[i]<='9')
			{
				S[++S[0]]=str[i]-'0';
				num[str[i]-'0']++;
			}
			else if(str[i]=='J')
			{
				S[++S[0]]=11;
				num[11]++;
			}
			else if(str[i]=='Q')
			{
				S[++S[0]]=12;
				num[12]++;
			}
			else if(str[i]=='K')
			{
				S[++S[0]]=13;
				num[13]++;
			}
		}
		long long tem=1;
		for(int i=1;i<=13;i++)
		{
			num[i]=4-num[i];
			if(num[i]) tem=tem*inv[num[i]]%mod;
			num[0]+=num[i];
		}
		tem=tem*fac[num[0]]%mod;
		for(int i=1;i<=S[0];i++)
		{
			for(int j=1;j<S[i];j++) if(num[j])
				ans=(ans+tem*num[j]%mod*pOw(num[0],mod-2)%mod)%mod;
			if(num[S[i]]) tem=tem*(num[S[i]]--)%mod*pOw(num[0]--,mod-2)%mod;
			else
			{
				if(i!=1&&!num[0]) ans=(ans+1LL)%mod;
				break;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


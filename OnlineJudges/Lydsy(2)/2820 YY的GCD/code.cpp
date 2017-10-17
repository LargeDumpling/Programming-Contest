/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=10000050;
int pri[MAXN],u[MAXN],sum[MAXN];
bool exist[MAXN];
void pre_calc()
{
	memset(exist,true,sizeof(exist));
	u[1]=1; pri[0]=0;
	for(int i=2;i<MAXN;i++)
	{
		if(exist[i]) pri[++pri[0]]=i,u[i]=-1;
		for(int j=1;j<=pri[0]&&i*pri[j]<MAXN;j++)
		{
			exist[i*pri[j]]=false;
			if(i%pri[j]) u[i*pri[j]]=-u[i];
			else
			{
				u[i*pri[j]]=0;
				break;
			}
		}
	}
	for(int i=1;i<=pri[0];i++)
		for(int j=pri[i];j<MAXN;j+=pri[i])
			sum[j]+=u[j/pri[i]];
	for(int i=1;i<MAXN;i++)
		sum[i]+=sum[i-1];
	return;
}
long long solve(int n,int m)
{
	if(n>m) swap(n,m);
	long long ans=0;
	int last=0,now=0;
	for(int i=1;i<=n;i=(last=now)+1)
	{
		now=min(n/(n/i),m/(m/i));
		ans+=(long long)(n/now)*(m/now)*(sum[now]-sum[last]);
	}
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T_T,n,m;
	pre_calc();
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%d",&n,&m);
		printf("%lld\n",solve(n,m));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


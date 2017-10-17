/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int INF=2147483647;
const int MAXN=55000;
int T_T;
int pri[MAXN],u[MAXN];
bool exist[MAXN];
void pre_calc()
{
	pri[0]=0;
	memset(exist,true,sizeof(exist));
	u[1]=1;
	for(int i=2;i<=MAXN;i++)
	{
		if(exist[i]) pri[++pri[0]]=i,u[i]=-1;
		for(int j=1;j<=pri[0]&&i*pri[j]<MAXN;j++)
		{
			exist[i*pri[j]]=false;
			if(i%pri[j]==0)
			{
				u[i*pri[j]]=0;
				break;
			}
			else u[i*pri[j]]=-u[i];
		}
	}
}
long long calc(long long x)
{
	long long ans=0;
	int limit=sqrt(x);
	for(int i=1;i<=limit;i++) if(u[i])
		ans+=u[i]*(x/(i*i));
	return ans;
}
long long solve(int x)
{
	long long l=0,r=INF,mid;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(x<=calc(mid)) r=mid;
		else l=mid;
	}
	return r;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n;
	pre_calc();
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d",&n);
		printf("%lld\n",solve(n));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


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
const int MAXN=50050;
int pri[MAXN],u[MAXN],sum[MAXN];
bool exist[MAXN];
void pre_calc()
{
	memset(exist,true,sizeof(exist));
	pri[0]=0; u[1]=1;
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
	for(int i=1;i<MAXN;i++) sum[i]=sum[i-1]+u[i];
	return;
}
long long solve(int n,int m)
{
	if(n>m) swap(n,m);
	int last;
	long long ans=0;
	for(int i=1;i<=n;i=last+1)
	{
		last=min(n/(n/i),m/(m/i));
		ans+=(long long)(n/i)*(m/i)*(sum[last]-sum[i-1]);
	}
	//printf("%d %d %lld\n",n,m,ans);
	return ans;
}
long long solve(int x1,int x2,int y1,int y2)
{ return solve(x2,y2)-solve(x1,y2)-solve(x2,y1)+solve(x1,y1); }
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T_T,a,b,c,d,k;
	pre_calc();
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		a--; c--;
		a/=k; b/=k; c/=k; d/=k;
		printf("%lld\n",solve(a,b,c,d));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


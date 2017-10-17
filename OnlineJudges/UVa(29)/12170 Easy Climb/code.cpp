/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-12	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=105;
const long long INF=1LL<<62;
int T_T,n,d,h[MAXN];
long long num[MAXN*MAXN*2],f[MAXN][MAXN*MAXN*2];
void F()
{
	int q[MAXN*MAXN*2],l,r,t;
	memset(q,0,sizeof(q));
	for(int i=1;i<=num[0];i++) f[1][i]=num[i]==h[1]?0:INF;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=num[0];j++)
			f[i][j]=INF;
	for(int i=2;i<=n;i++)
	{
		r=t=0; l=1;
		for(int j=1;j<=num[0];j++)
		{
			for(;t<num[0]&&num[t+1]<=num[j]+d;t++)
				if(f[i-1][t+1]!=INF)
				{
					while(l<=r&&f[i-1][q[r]]>=f[i-1][t+1]) r--;
					if(r<l||f[i-1][q[r]]<f[i-1][t+1]) q[++r]=t+1;
				}
			while(l<=r&&num[q[l]]+d<num[j]) l++;
			if(l<=r) f[i][j]=abs(h[i]-num[j])+f[i-1][q[l]];
		}
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&T_T);
	while(T_T--)
	{
		num[0]=0;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&h[i]);
			for(int j=-n;j<=n;j++) num[++num[0]]=h[i]+j*d;
		}
		if(1LL*(n-1)*d<abs(h[1]-h[n]))
		{
			puts("impossible");
			continue;
		}
		else
		{
			sort(num+1,num+num[0]+1);
			num[0]=unique(num+1,num+num[0]+1)-num-1;
			F();
			long long ans=INF;
			for(int i=1;i<=num[0];i++)
				if(num[i]==h[n])
				{
					ans=f[n][i];
					break;
				}
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


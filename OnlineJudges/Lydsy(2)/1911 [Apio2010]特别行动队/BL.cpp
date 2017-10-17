/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1000050;
int n,k[MAXN];
long long a,b,c,S[MAXN],f[MAXN];
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	scanf("%d%lld%lld%lld",&n,&a,&b,&c);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&S[i]);
		S[i]+=S[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=-1LL*(1LL<<61);
		for(int j=0;j<i;j++)
		{
			if(f[i]<f[j]+(a*(S[i]-S[j])+b)*(S[i]-S[j])+c)
			{
				k[i]=j;
				f[i]=max(f[i],f[j]+(a*(S[i]-S[j])+b)*(S[i]-S[j])+c);
			}
		}
		//printf("%d %lld\n",k[i],f[i]);
		//printf("%lld %lld %lld %d\n",-2LL*a*S[i],f[i]+a*S[i]*S[i]-b*S[i],f[i],k[i]);
		//printf("%d\n",k[i]);
	}
	printf("%lld",f[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


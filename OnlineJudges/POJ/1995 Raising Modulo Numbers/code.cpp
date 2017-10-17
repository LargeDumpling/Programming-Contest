#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int mod,T;
int q_poi(int a,int t)
{
	int ans=1;
	for(;t;t>>=1,a=(a*a)%mod)
		if(t&1)
			ans=(ans*a)%mod;
	return ans;
}
int main()
{
	int ans,a,b,n;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		ans=0;
		scanf("%d%d",&mod,&n);
		for(int j=1;j<=n;j++)
		{
			scanf("%d%d",&a,&b);
			a%=mod;
			ans=(ans+q_poi(a,b))%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}


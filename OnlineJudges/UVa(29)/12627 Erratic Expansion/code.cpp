#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,K,A,B;
long long c[31];
long long f(int ti,int x)
{
	if(!x)return 0;
	if(!ti)return 1;
	if(x==(1<<ti))return c[ti];
	if(x<=(1<<(ti-1)))
		return f(ti-1,x)<<1;
	return (c[ti-1]<<1)+f(ti-1,x-(1<<(ti-1)));
}
int g(int ti,int x)
{
	if(!ti)return 0;
	if(x<=(1<<(ti-1)))
		return g(ti-1,x);
	return g(ti-1,(1<<(ti-1)))+(g(ti-1,x-(1<<(ti-1)))<<1);
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	long long ans;
	scanf("%d",&T);
	c[0]=1;
	for(int i=1;i<=30;i++)c[i]=c[i-1]*3LL;
	for(int cAse=1;cAse<=T;cAse++)
	{
		printf("Case %d: ",cAse);
		scanf("%d%d%d",&K,&A,&B);
		ans=f(K,B)-f(K,A-1);
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


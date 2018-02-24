#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int mod=1000000007;
int n,p[10000050],q[1000050];
bool exist[1000050];
void calc_q()
{
	memset(exist,true,sizeof(exist));
	q[1]=0;
	for(int i=2;i<1000050;i++)
	{
		if(exist[i])p[++p[0]]=i,q[i]=i-1;
		for(int j=1;j<=p[0]&&i*p[j]<1000050;j++)
		{
			exist[i*p[j]]=false;
			if(i%p[j])
				q[i*p[j]]=q[i]*(p[j]-1);
			else
				q[i*p[j]]=q[i]*p[j];
		}
	}
	return;
}
int calc(int x)
{
	long long ans=0;
	for(int i=1;i<=x;i++)
		ans=(ans+(q[i]<<1))%mod;
	return ans;
}
long long ans=0;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&n);
	calc_q();
	for(int i=1;i<=p[0]&&p[i]<=n;i++)
		ans=(ans+calc(n/p[i]))%mod+1;
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


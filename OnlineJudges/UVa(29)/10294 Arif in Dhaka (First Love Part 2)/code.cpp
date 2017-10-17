#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long pOw[60],n,t,ans,a,b;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	pOw[0]=1;
	while(true)
	{
		if(scanf("%lld%lld",&n,&t)==-1)
			break;
		pOw[0]=1;
		for(int i=1;i<=n;i++)pOw[i]=pOw[i-1]*t;
		a=0;
		for(int i=1;i<=n;i++)a+=pOw[gcd(i,n)];
		if(n&1)
			b=n*pOw[(n+1)>>1];
		else
			b=(n>>1)*(pOw[n>>1]+pOw[(n>>1)+1]);
		printf("%lld %lld\n",a/n,(a+b)/2/n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


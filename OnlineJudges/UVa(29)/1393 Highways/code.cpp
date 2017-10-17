/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-10	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
bool prime[305][305];
bool gCd(int a,int b)
{
	int t;
	while(b)
	{
		t=a%b;
		a=b;
		b=t;
	}
	return a==1;
}
void pre_gcd()
{
	for(int i=1;i<=300;i++)
		for(int j=1;j<=i;j++)
			prime[i][j]=prime[j][i]=gCd(i,j);
	return;
}
long long solve()
{
	long long ans=0;
	if(n>m)
	{
		n^=m;
		m=n^m;
		n^=m;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)if(prime[i][j])
			ans+=((n-i)*(m-j)-max(0,n-(i<<1))*max(0,m-(j<<1)));
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	pre_gcd();
	while(scanf("%d%d",&n,&m)!=-1&&n&&m)
		printf("%lld\n",solve()<<1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


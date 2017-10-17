#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define M 131072
using namespace std;
int n,q;
long long d[M<<1];
void change(int L,int R,long long x)
{
	int num=1;
	for(L=L+M-1,R=R+M+1;L^R^1;L>>=1,R>>=1,num<<=1)
	{
		if(!(L&1))d[L^1]+=num*x;
		if(R&1)d[R^1]+=num*x;
	}
	return;
}
long long query(int L,int R)
{
	long long sum=0;
	for(L=L+M-1,R=R+M+1;L^R^1;L>>=1,R>>=1)
	{
		if(!(L&1))sum+=d[L^1];
		if(R&1)sum+=d[R^1];
	}
	return sum;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("zkw.out","w",stdout);
	int a,b;
	long long c;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&d[i+M]);
	for(int i=M-1;i;i--)d[i]=d[i<<1]+d[i<<1|1];
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&a);
		if(a==1)
		{
			scanf("%d%d%lld",&a,&b,&c);
			change(a,b,c);
		}
		else
		{
			scanf("%d%d",&a,&b);
			printf("%lld\n",query(a,b));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


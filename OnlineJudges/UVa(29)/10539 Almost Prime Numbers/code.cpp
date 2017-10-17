/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-11	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long pri[750000];
void get_prime()
{
	bool exist[1000050];
	memset(exist,true,sizeof(exist));
	for(int i=2;i<=500000;i++)
		for(int j=i<<1;j<=1000000;j+=i)
			exist[j]=false;
	for(int i=2;i<=1000000;i++)if(exist[i])pri[++pri[0]]=i;
	return;
}
long long pOw(long long a,int n)
{
	long long ans=1;
	for(int i=1;i<=n;i++)ans*=a;
	return ans;
}
long long calc(long long L,long long R)
{
	long long ans=0;
	long long k;
	for(int i=1;i<=pri[0];i++)
	{
		if(pri[i]*pri[i]>R)break;
		k=log(L)/log(pri[i]);
		k=pOw(pri[i],k);
		while(k<L||k<=pri[i])k*=pri[i];
		while(k<=R)k*=pri[i],ans++;
	}
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int N;
	long long L,R;
	get_prime();
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%lld%lld",&L,&R);
		printf("%lld\n",calc(L,R));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


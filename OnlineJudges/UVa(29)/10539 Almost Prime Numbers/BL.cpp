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
bool exist[100050];
void get_prime()
{
	memset(exist,true,sizeof(exist));
	exist[1]=false;
	for(int i=2;i<=50000;i++)
		for(int j=i<<1;j<=100000;j+=i)
			exist[j]=false;
	for(long long i=100000;i>1;i--)if(exist[i])
	{
		for(long long j=i*i;j<=100000;j*=i)
			exist[j]=true;
		exist[i]=false;
	}
	return;
}
long long solve(long long L,long long R)
{
	long long ans=0;
	for(long long i=L;i<=R;i++)if(exist[i])ans++;
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	int N;
	long long L,R;
	scanf("%d",&N);
	get_prime();
	while(N--)
	{
		scanf("%lld%lld",&L,&R);
		printf("%lld\n",solve(L,R));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


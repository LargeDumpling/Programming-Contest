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
int pri[10050];
void get_primes()
{
	bool exist[10050];
	memset(exist,true,sizeof(exist));
	for(int i=2;i<=10000;i++)
		for(int j=i<<1;j<=10000;j+=i)
			exist[j]=false;
	pri[0]=0;
	for(int i=2;i<=10000;i++)if(exist[i])pri[++pri[0]]=i;
	return;
}
int solve(int x)
{
	int l=1,r=0,sum=0,ans=0;
	while(r<pri[0]&&(!r||pri[r]<=x))
	{
		sum+=pri[++r];
		while(sum>x)sum-=pri[l++];
		if(sum==x)ans++;
	}
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n;
	get_primes();
	while(scanf("%d",&n)!=-1&&n)
		printf("%d\n",solve(n));
	fclose(stdin);
	fclose(stdout);
	return 0;
}


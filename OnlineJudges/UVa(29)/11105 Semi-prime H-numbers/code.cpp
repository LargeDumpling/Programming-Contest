/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-13	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1000000;
int pri[MAXN+50],exist[MAXN+50];
void pre_calc()
{
	memset(exist,-1,sizeof(exist));
	pri[0]=0;
	for(long long i=5;i<MAXN;i+=4)
		for(long long j=5;i*j<=MAXN;j+=4)
			if(exist[i]==-1&&exist[j]==-1)exist[i*j]=1;
			else exist[i*j]=0;
	for(int i=5;i<=MAXN;i+=4)if(exist[i]==1)pri[++pri[0]]=i;
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n;
	pre_calc();
	while(scanf("%d",&n)!=-1&&n)
		printf("%d %lld\n",n,upper_bound(pri+1,pri+pri[0]+1,n)-pri-1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


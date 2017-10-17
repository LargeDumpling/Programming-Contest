/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-01	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int m,n;
int cnt[2050][2050],d[2050][2050],feat[150];
int max(const int &A,const int &B){return A<B?B:A;}
int min(const int &A,const int &B){return A<B?A:B;}
int dp(int S,int W)
{
	if(d[S][W]!=-1)return d[S][W];
	if(cnt[S][W]<=1)return d[S][W]=0;
	int &ans=d[S][W]=2147483647;
	for(int i=0;i<m;i++)
		if(!(S&(1<<i)))
		ans=min(ans,max(dp(S|(1<<i),W|(1<<i)),dp(S|(1<<i),W))+1);
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	char tex[12];
	while(scanf("%d%d",&m,&n)&&n&&m)
	{
		for(int i=1;i<=n;i++)
		{
			feat[i]=0;
			scanf("%s",tex);
			for(int j=0;j<m;j++)
				feat[i]=(feat[i]<<1)|(tex[j]=='1');
		}
		memset(d,-1,sizeof(d));
		for(int S=(1<<m)-1;S>=0;S--)
		{
			fill(cnt[S],cnt[S]+S+1,0);
			for(int i=1;i<=n;i++)
				cnt[S][feat[i]&S]++;
		}
		printf("%d\n",dp(0,0));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


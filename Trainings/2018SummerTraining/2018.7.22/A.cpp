/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=500050;
int x,na,nb,nc;
int a[MAXN],b[MAXN],c[MAXN],d;
long long ans;
int main()
{
	long long tem1,tem2;
	while(scanf("%d%d%d%d",&d,&na,&nb,&nc)!=-1)
	{
		ans=0;
		for(int i=1;i<=na;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=nb;i++)
			scanf("%d",&b[i]);
		for(int i=1;i<=nc;i++)
			scanf("%d",&c[i]);
		for(int i=1;i<=na;i++)
		{
			tem1=upper_bound(b+1,b+nb+1,a[i]+d)-lower_bound(b+1,b+nb+1,a[i]);
			tem2=upper_bound(c+1,c+nc+1,a[i]+d)-lower_bound(c+1,c+nc+1,a[i]);
			ans+=tem1*tem2;
		}
		for(int i=1;i<=nb;i++)
		{
			tem1=upper_bound(a+1,a+na+1,b[i]+d)-lower_bound(a+1,a+na+1,b[i]);
			tem2=upper_bound(c+1,c+nc+1,b[i]+d)-lower_bound(c+1,c+nc+1,b[i]);
			ans+=tem1*tem2;
		}
		for(int i=1;i<=nc;i++)
		{
			tem1=upper_bound(a+1,a+na+1,c[i]+d)-lower_bound(a+1,a+na+1,c[i]);
			tem2=upper_bound(b+1,b+nb+1,c[i]+d)-lower_bound(b+1,b+nb+1,c[i]);
			ans+=tem1*tem2;
		}
		for(int i=1;i<=na;i++)
		{
			tem1=upper_bound(b+1,b+nb+1,a[i])-lower_bound(b+1,b+nb+1,a[i]);
			tem2=upper_bound(c+1,c+nc+1,a[i]+d)-lower_bound(c+1,c+nc+1,a[i]);
			ans-=tem1*tem2;
		}
		for(int i=1;i<=nb;i++)
		{
			tem1=upper_bound(a+1,a+na+1,b[i]+d)-lower_bound(a+1,a+na+1,b[i]);
			tem2=upper_bound(c+1,c+nc+1,b[i])-lower_bound(c+1,c+nc+1,b[i]);
			ans-=tem1*tem2;
		}
		for(int i=1;i<=nc;i++)
		{
			tem1=upper_bound(a+1,a+na+1,c[i])-lower_bound(a+1,a+na+1,c[i]);
			tem2=upper_bound(b+1,b+nb+1,c[i]+d)-lower_bound(b+1,b+nb+1,c[i]);
			ans-=tem1*tem2;
		}
		for(int i=1;i<=na;i++)
		{
			tem1=upper_bound(b+1,b+nb+1,a[i])-lower_bound(b+1,b+nb+1,a[i]);
			tem2=upper_bound(c+1,c+nc+1,a[i])-lower_bound(c+1,c+nc+1,a[i]);
			ans+=tem1*tem2;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


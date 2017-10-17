/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-02-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,n,k;
int temp[100];
int next(int &x)
{
	if(!x) return 0;
	int len=0,lEn;
	long long tem=(long long)x*x;
	for(;tem;tem/=10LL)
		temp[len++]=tem%10LL;
	lEn=min(len,n);
	for(int i=x=0;i<lEn;i++) x=(x<<1)+(x<<3)+temp[--len];
	return x;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int k1,k2,ans;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%d",&n,&k);
		k1=k2=ans=k;
		do
		{
			ans=max(ans,next(k1));
			ans=max(ans,next(k2));
			ans=max(ans,next(k2));
		}while(k1!=k2);
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


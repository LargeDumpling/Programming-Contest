/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-27	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,num[400050],mIn=2147483647,l,r;
long long ans=0,cnt;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		num[i+n]=num[i];
		mIn=min(mIn,num[i]);
	}
	for(int i=1;i<=n;i++)num[i]=num[i+n]=num[i]-mIn;
	l=1;
	while(l<=n)
	{
		r=l;
		cnt=0;
		while(num[r])cnt++,r++;
		ans=max(ans,cnt);
		l=r+1;
	}
	ans+=(long long)n*mIn;
	cout<<ans;
	return 0;
}


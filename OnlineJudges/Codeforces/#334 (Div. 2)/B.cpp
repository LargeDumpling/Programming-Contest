/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,k,l,r,cnt;
long long s[200050],ans=0;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%I64d",&s[i]);
	cnt=0; k=n-k; ans=s[n];
	for(int i=1;cnt<k;i++)
	{
		ans=max(ans,s[i]+s[(k<<1)-i+1]);
		l+=2;
		cnt++;
	}
	printf("%I64d",ans);
	return 0;
}


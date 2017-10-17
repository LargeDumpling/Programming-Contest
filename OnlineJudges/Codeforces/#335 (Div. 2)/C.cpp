/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,f[100050];
int main()
{
	int x,ans;
	ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		f[x]=f[x-1]+1;
		ans=max(ans,f[x]);
	}
	ans=n-ans;
	printf("%d",ans);
	return 0;
}


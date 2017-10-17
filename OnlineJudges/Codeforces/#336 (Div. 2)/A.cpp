/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int n,s,ans=0,a,b;
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		ans=max(ans,max(s-a,b)+a);
	}
	printf("%d",ans);
	return 0;
}


/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
long long ans,x,num[35];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&num[i]);
	sort(num+1,num+n+1);
	ans=x=1;
	for(int i=n;i;i--)
	{
		x*=num[i];
		ans+=x;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


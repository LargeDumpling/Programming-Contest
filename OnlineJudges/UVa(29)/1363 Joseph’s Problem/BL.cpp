/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-09	File created.
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
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	long long n,k,ans;
	while(scanf("%lld%lld",&n,&k)!=-1)
	{
		ans=0;
		for(int i=1;i<=n;i++)
			ans+=k%i;
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


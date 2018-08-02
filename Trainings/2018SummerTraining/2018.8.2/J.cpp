/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-02	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,p2,p3,ans;
long long calc(long long x)
{
	if(x==1) return min(p2,p3);
	long long a=x/2LL,b=x%2LL; a-=b;
	if(3LL*p2<=2LL*p3) return a*p2+b*p3;
	long long k=a/3LL;
	a-=3LL*k; b+=2LL*k;
	return a*p2+b*p3;
}
int main()
{
	scanf("%lld%lld%lld",&n,&p2,&p3);
	ans=calc(n);
	ans=min(ans,calc(n+1LL));
	ans=min(ans,calc(n+2LL));
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


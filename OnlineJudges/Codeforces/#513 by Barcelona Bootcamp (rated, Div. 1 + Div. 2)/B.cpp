/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long n;
int ans=0;
int S(long long x)
{
	int sum;
	for(sum=0;x;x/=10)
		sum+=x%10;
	return sum;
}
int main()
{
	scanf("%I64d",&n);
	for(long long a=0;a<n;a=a*10LL+9LL)
		ans=max(ans,S(a)+S(n-a));
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


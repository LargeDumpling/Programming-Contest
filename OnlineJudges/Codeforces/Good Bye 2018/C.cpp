/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-12-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
long long ans[MAXN];
int gcd(int n,int m)
{
	int t;
	while(m)
	{
		t=n%m;
		n=m;
		m=t;
	}
	return n;
}
long long calc(int x,int n)
{
	long long num=(n/x);
	return (long long)x*(num-1LL)*num/2LL+num;
}
int main()
{
	int n;
	ans[0]=0;
	scanf("%d",&n);
	for(int i=1;i*i<=n;i++) if(!(n%i))
	{
		ans[++ans[0]]=calc(gcd(i,n),n);
		ans[++ans[0]]=calc(gcd(n/i,n),n);
	}
	sort(ans+1,ans+ans[0]+1);
	ans[0]=unique(ans+1,ans+ans[0]+1)-ans-1;
	for(int i=1;i<=ans[0];i++)
		printf("%I64d ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


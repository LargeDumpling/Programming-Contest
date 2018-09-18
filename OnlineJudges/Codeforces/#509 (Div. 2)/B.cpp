/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long a,b,x,y;
long long gcd(long long n,long long m)
{
	long long t;
	while(m)
	{
		t=n%m;
		n=m;
		m=t;
	}
	return n;
}
int main()
{
	long long t,ans;
	cin>>a>>b>>x>>y;
	t=gcd(x,y);
	x/=t; y/=t;
	ans=min(a/x,b/y);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long mod=1e9+7;
const int MAXN=700;
int n;
long long l[MAXN],h[MAXN];
int main()
{
	long long tem;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		for(int j=i;j<n;j++)
		{
			tem=(long long)i*j%mod;
			l[i]=(l[i]+tem)%mod;
			h[j]=(h[j]+tem)%mod;
		}
	tem=0;
	for(int i=1;i<n;i++)
		for(int j=i;j<n;j++)
			tem=(tem+h[i]*l[j]%mod)%mod;
	printf("%lld",tem);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


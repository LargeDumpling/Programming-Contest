/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-06-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,k,cnt;
int main()
{
	//freopen("A.in","r",stdin);
	//freopen("A.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	cnt=(n>>1)/(k+1LL);
	printf("%lld %lld %lld",cnt,cnt*k,n-cnt*(k+1LL));
	fclose(stdin);
	fclose(stdout);
	return 0;
}


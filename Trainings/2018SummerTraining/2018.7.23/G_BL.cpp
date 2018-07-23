/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const int mod=1000000007;
int a[MAXN],s[MAXN];
int main()
{
	freopen("BL.txt","w",stdout);
	a[1]=a[2]=s[1]=1;
	s[2]=2;
	for(int i=1;i<=100000;i++)
	{
		if(3<=i)
		{
			a[i]=(a[i-a[i-1]]+a[i-1-a[i-2]])%mod;
			s[i]=(s[i-1]+a[i])%mod;
		}
		printf("%d\n",s[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


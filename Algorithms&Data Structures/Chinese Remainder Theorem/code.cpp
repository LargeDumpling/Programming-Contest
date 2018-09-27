/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-26	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
//n¸ö·½³Ì:x=a[i](mod m[i]) 0<=i<n
typedef long long LL;
LL CRT(int n,int *a,int *m)
{
	LL M=1,d,y,x=0;
	for(int i=0;i<n;i++) M*=m[i];
	for(int i=0;i<n;i++)
	{
		LL w=M/m[i];
		gcd(m[i],w,d,d,y);
		x=(x+y*w*a[i])%M;
	}
	return (x+M)%M;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


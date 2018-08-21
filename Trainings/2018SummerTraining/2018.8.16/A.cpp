/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const long long mod=1000000007LL;
long long idu;
long long pOw(long long x,long long n)
{
	long long ans;
	for(ans=1LL;n;n>>=1,x=x*x%mod)
		if(n&1)
			ans=ans*x%mod;
	return ans;
}
void solve(const vector<long long> &A,vector<long long> &X,const vector<long long> &B,int n)
{
	if(n==1)
	{
		X.push_back(B[0]*pOw(A[0],mod-2)%mod);
		return;
	}
	int m=n>>1;
	vector<long long> a[2],b[2],x[2];
	for(int i=0;i<m;i++)
	{
		a[0].push_back((A[i]+A[i+m])%mod);
		a[1].push_back((A[i]-A[i+m]+mod)%mod);
		b[0].push_back((B[i]+B[i+m])%mod);
		b[1].push_back((B[i]-B[i+m]+mod)%mod);
	}
	for(int i=0;i<2;i++)
		solve(a[i],x[i],b[i],m);
	for(int i=0;i<m;i++)
		X.push_back((x[0][i]+x[1][i])%mod*idu%mod);
	for(int i=0;i<m;i++)
		X.push_back((x[0][i]-x[1][i]+mod)%mod*idu%mod);
	return;
}
int main()
{
	int n;
	long long x;
	vector<long long> A,B,X;
	idu=pOw(2LL,mod-2);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&x);
		A.push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&x);
		B.push_back(x);
	}
	solve(A,X,B,n);
	for(int i=0;i<n;i++)
		printf("%lld\n",X[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


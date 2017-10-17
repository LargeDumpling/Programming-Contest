/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1000050;
struct jp { long long X,P,C; }fac[MAXN];
int n,l,r,q[MAXN];
long long f[MAXN],S1[MAXN],S2[MAXN],x[MAXN],y[MAXN],ans;
double solve(int p1,int p2) { return (double)(y[p2]-y[p1])/(x[p2]-x[p1]); }
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&fac[i].X,&fac[i].P,&fac[i].C);
		S1[i]=S1[i-1]+fac[i].P*fac[i].X;
		S2[i]=S2[i-1]+fac[i].P;
	}
	l=r=q[0]=0;
	for(int i=1;i<=n;i++)
	{
		while(l<r&&solve(q[l],q[l+1])<=fac[i].X) l++;
		f[i]=f[q[l]]+fac[i].X*(S2[i]-S2[q[l]])-(S1[i]-S1[q[l]])+fac[i].C;
		x[i]=S2[i]; y[i]=f[i]+S1[i];
		while(l<r&&solve(q[r],i)<=solve(q[r],q[r-1])) r--;
		q[++r]=i;
	}
	printf("%lld",f[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


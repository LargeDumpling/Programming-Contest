/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=50050;
int n,c,q[MAXN],l,r;
long long S[MAXN],f[MAXN],x[MAXN],y[MAXN];
long long calc_y(int x) { return f[x]+S[x]*S[x]+2LL*S[x]*c; }
long long calc_x(int x) { return -2*S[x]; }
double notslope(int p1,int p2)
{ return (double)(y[p1]-y[p2])/(x[p2]-x[p1]); }
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%d",&n,&c); c++;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&S[i]);
		S[i]+=S[i-1]+1;
	}
	l=r=q[0]=0;
	x[0]=y[0]=0;
	for(int i=1;i<=n;i++)
	{
		while(l<r&&notslope(q[l],q[l+1])<=S[i]) l++;
		f[i]=f[q[l]]+(S[i]-S[q[l]]-c)*(S[i]-S[q[l]]-c);
		x[i]=calc_x(i); y[i]=calc_y(i);
		while(l<r&&notslope(q[r-1],q[r])>=notslope(q[r-1],i)) r--;
		q[++r]=i;
	}
	printf("%lld",f[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


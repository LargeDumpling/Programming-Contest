/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1000050;
char a;
int n,l,r,q[MAXN];
long long A[MAXN],B[MAXN],C[MAXN],x[MAXN],y[MAXN],f[MAXN];
//long long dx(int p1,int p2) { return B[p2]-B[p1]; }
long long dx(int p1,int p2) { return x[p2]-x[p1]; }
//long long dy(int p1,int p2) { return f[p2]+C[p2]-f[p1]-C[p1]; }
long long dy(int p1,int p2) { return y[p2]-y[p1]; }
char b;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&A[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&B[i]);
		C[i]=C[i-1]+B[i]*i;
		B[i]+=B[i-1];
	}
	q[0]=l=r=0;
	for(int i=1;i<=n;i++)
	{
		while(l<r&&dy(q[l],q[l+1])<=i*dx(q[l],q[l+1])) l++;
		f[i]=f[q[l]]+i*(B[i-1]-B[q[l]])-(C[i-1]-C[q[l]])+A[i];
		x[i]=B[i]; y[i]=f[i]+C[i];
		while(l<r&&dy(q[r],i)*dx(q[r-1],q[r])<=dx(q[r],i)*dy(q[r-1],q[r])) r--;
		q[++r]=i;
	}
	printf("%lld",f[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


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
int n,l,r,q[MAXN];
long long cost[MAXN],x[MAXN],y[MAXN],f[MAXN];
inline long long dx(int p1,int p2) { return x[p2]-x[p1]; }
inline long long dy(int p1,int p2) { return y[p2]-y[p1]; }
inline int read1n()
{
	int x; char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(x=0;'0'<=ch&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
	return x;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	//scanf("%d",&n);
	n=read1n();
	for(int i=1;i<=n;i++)// scanf("%lld",&cost[i]);
		cost[i]=read1n();
	q[0]=l=r=0;
	for(int i=1;i<=n;i++)
	{
		while(l<r&&dy(q[l],q[l+1])<=(long long)i*dx(q[l],q[l+1])) l++;
		f[i]=f[q[l]]+(long long)(i-q[l])*(i-q[l]-1)/2+cost[i];
		x[i]=i; y[i]=f[i]+(long long)i*(i+1)/2;
		while(l<r&&dy(q[r],i)*dx(q[r-1],q[r])<=dy(q[r-1],q[r])*dx(q[r],i)) r--;
		q[++r]=i;
	}
	printf("%lld",f[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


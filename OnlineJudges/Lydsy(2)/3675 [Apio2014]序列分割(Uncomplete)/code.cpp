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
const int MAXN=100050;
int n,k;
long long S[MAXN],f[2][MAXN],x[MAXN],y[MAXN];
int q[MAXN],l,r;
long long dx(int p1,int p2) { return x[p2]-x[p1]; }
long long dy(int p1,int p2) { return y[p2]-y[p1]; }
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int now=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&S[i]);
		S[i]+=S[i-1];
	}
	q[0]=l=r=0;
	for(int j=1;j<=k;j++)
	{
		now^=1;
		for(int i=1;i<=n;i++)
		{
			while(l<=r&&) l++;
			f[now][i]=f[now^1][q[l]]+(S[i]-S[q[l]])*(S[n]-S[i]);
		}
		q[0]=l=r=0;
		for(int i=1;i<=n;i++)
		{
			x[i]=S[i];
			y[i]=f[now][i]-S[i]*S[n];
			while(l<r&&) r--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


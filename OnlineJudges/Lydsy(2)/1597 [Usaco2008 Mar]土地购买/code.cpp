/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=50050;
struct jp
{
	int x,y;
	bool operator<(const jp &P)const { return x==P.x?P.y<y:x<P.x; }
}fie[MAXN],ff[MAXN];
int n,nn,q[MAXN],l,r;
long long f[MAXN];
double Slope(int p1,int p2)
{ return (double)(f[p2]-f[p1])/(ff[p2+1].y-ff[p1+1].y); }
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&fie[i].x,&fie[i].y);
	sort(fie+1,fie+n+1);
	nn=0;
	for(int i=1;i<=n;ff[++nn]=fie[i++]) while(nn&&ff[nn].y<=fie[i].y) nn--;
	q[l=r=0]=0;
	for(int i=1;i<=nn;i++)
	{
		while(l<r&&Slope(q[l],q[l+1])>=ff[i].x*-1.) l++;
		f[i]=f[q[l]]+(long long)ff[i].x*ff[q[l]+1].y;
		while(l<r&&Slope(q[r],q[r-1])<=Slope(q[r],i)) r--;
		q[++r]=i;
	}
	printf("%lld",f[nn]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


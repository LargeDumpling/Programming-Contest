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
const long long INF=1e12+50;
struct jp
{
	int x,y;
	bool operator<(const jp &P)const { return x==P.x?y>P.y:x<P.x; }
}fie[MAXN],ff[MAXN];
int n,nn=0,s[MAXN],k[MAXN];
long long f[MAXN];
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&fie[i].x,&fie[i].y);
	sort(fie+1,fie+n+1);
	for(int i=1;i<=n;i++)
	{
		while(nn&&ff[nn].y<=fie[i].y) nn--;
		ff[++nn]=fie[i];
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=INF;
		for(int j=0;j<i;j++) if(f[j]+(long long)ff[i].x*ff[j+1].y<f[i])
		{
			k[i]=j;
			f[i]=f[j]+(long long)ff[i].x*ff[j+1].y;
		}
	}
	//printf("x\ty\tt\n");
	//for(int i=0;i<=nn;i++)
		//printf("%d\t%lld\t%d\n",ff[i+1].y,f[i],k[i]);
	printf("%lld",f[nn]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


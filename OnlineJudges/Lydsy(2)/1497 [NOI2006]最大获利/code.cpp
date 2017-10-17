/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,sta,tar,fir[60000],cur[60000],lev[60000],end[400000],next[400000],c[400000],f[400000],len[400000],ed=1;
void addedge(int u,int v,int cap,int lenth)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	c[ed]=cap;
	f[ed]=0;
	len[ed]=lenth;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	f[ed]=c[ed]=cap;
	len[ed]=-lenth;
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b,c;
	scanf("%d%d",&n,&m);
	sta=n+m+1;
	tar=sta+1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		addedge(sta,i,2147483647,a);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


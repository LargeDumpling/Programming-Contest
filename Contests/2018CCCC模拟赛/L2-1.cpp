/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int N,fir[MAXN],nExt[MAXN];
double gl[MAXN],r,dd[MAXN];
double DFS(int u)
{
	double sum=0;
	if(dd[u]<1e100)
		sum+=gl[u]*dd[u];
	else for(int v=fir[u];v;v=nExt[v])
	{
		gl[v]=gl[u]*r;
		sum+=DFS(v);
	}
	return sum;
}
int main()
{
	int k,x;
	scanf("%d%lf%lf",&N,&gl[0],&r);
	r=(100.-r)/100.;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&k);
		if(k==0) scanf("%lf",&dd[i]);
		else
		{
			dd[i]=1e100;
			while(k--)
			{
				scanf("%d",&x);
				nExt[x]=fir[i];
				fir[i]=x;
			}
		}
	}
	printf("%lld",(long long)DFS(0));
	fclose(stdin);
	fclose(stdout);
	return 0;
}


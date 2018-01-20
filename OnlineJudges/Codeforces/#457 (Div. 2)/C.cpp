/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=200050;
int n,m,pri[MAXN],dis[MAXN>>1];
bool exist[MAXN];
void pre_calc()
{
	memset(exist,true,sizeof(exist));
	pri[0]=0;
	for(int i=2;i<MAXN;i++)
	{
		if(exist[i]) pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&i*pri[j]<MAXN;j++)
		{
			exist[i*pri[j]]=false;
			if(!(i%pri[j])) break;
		}
	}
	return;
}
int main()
{
	int m0,nex;
	memset(dis,0,sizeof(dis));
	pre_calc();
	scanf("%d%d",&n,&m);
	nex=pri[lower_bound(pri+1,pri+pri[0]+1,n-1)-pri];
	printf("%d %d\n",nex,nex);
	dis[1]=0;
	for(int i=2;i<=n;i++)
	{
		dis[i]=dis[i-1]+1;
		if(i-1<=nex-n+1) dis[i]++;
		printf("%d %d %d\n",i-1,i,dis[i]-dis[i-1]);
	}
	m0=n-1;
	for(int i=1;i<n&&m0<m;i++)
		for(int j=i+2;j<=n&&m0<m;j++)
		{
			m0++;
			printf("%d %d %d\n",i,j,dis[j]-dis[i]);
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


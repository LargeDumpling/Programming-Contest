/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-05-06	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=105;
typedef unsigned long long ull;
int n,fir[MAXN<<1],end[MAXN<<1],next[MAXN<<1],ed=0;
int in[MAXN];
ull num[MAXN];
void addedge(int u,int v)
{
	in[v]++;
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	return;
}
void print(int u)
{
	cout<<num[u]<<" ";
	for(int i=fir[u];i;i=next[i])
		print(end[i]);
	return;
}
int main()
{
	ull tem;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		cin>>num[i];
	for(int i=1;i<=n;i++)
	{
		if(!(num[i]%3))
		{
			tem=num[i]/3;
			for(int j=1;j<=n;j++) if(num[j]==tem)
				addedge(i,j);
		}
		if(!(num[i]%2))
		{
			tem=num[i]/2;
			for(int j=1;j<=n;j++) if(num[j]==tem)
				addedge(j,i);
		}
	}
	for(int i=1;i<=n;i++) if(!in[i])
	{
		print(i);
		break;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


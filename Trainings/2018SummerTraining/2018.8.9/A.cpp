/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-10	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=500050;
int Log[MAXN],par[MAXN],n;
void match(int x)
{
	int t=1<<Log[x];
	if(t==x) for(int i=0;i<x;i++)
		par[i]=x-1-i;
	else
	{
		for(int i=0;i<x-t;i++)
		{
			par[t+i]=t-1-i;
			par[t-1-i]=t+i;
		}
		match(2*t-x);
	}
	return;
}
int main()
{
	Log[0]=-1;
	for(int i=1;i<MAXN;i++)
		Log[i]=Log[i>>1]+1;
	scanf("%d",&n);
	match(n);
	for(int i=0;i<n;i++)
		printf("%d ",par[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-10-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,pOw[10],ps[10];
int ans[10000050];
void DFS(int u,int x,int sum)
{
	if(u==-1)
	{
		if(x+sum==n) ans[++ans[0]]=x;
		return;
	}
	if(x*pOw[u+1]+sum+9*ps[u]<n||n<x*pOw[u+1]+sum) return;
	for(int i=0;i<10;i++)
		DFS(u-1,x*10+i,sum+i);
	return;
}
int main()
{
	pOw[0]=1;
	for(int i=1;i<10;i++)
		pOw[i]=pOw[i-1]*10;
	ps[0]=2;
	for(int i=1;i<10;i++)
		ps[i]=ps[i-1]+pOw[i]+1;
	scanf("%d",&n);
	DFS(8,0,0);
	sort(ans+1,ans+ans[0]+1);
	printf("%d\n",ans[0]);
	for(int i=1;i<=ans[0];i++)
		printf("%d ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


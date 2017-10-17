/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-07-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=15;
const int MAXM=15;
int n,m,a[MAXN][MAXM],b[MAXN];
int num[MAXN],kol[MAXM],ans=1001;
void DFS(int x,int sum)
{
	if(ans<=sum) return;
	for(int i=1;i<=m&&kol[i]*m==sum;i++)
		if(i==m)
		{
			if(!sum) break;
			ans=min(ans,sum);
			return;
		}
	if(n<x) return;
	if(num[x]<b[x])
	{
		num[x]++;
		for(int i=1;i<=m;i++)
			kol[i]+=a[x][i];
		DFS(x,sum+a[x][0]);
		num[x]--;
		for(int i=1;i<=m;i++)
			kol[i]-=a[x][i];
	}
	DFS(x+1,sum);
	return;
}
int main()
{
	memset(a,0,sizeof(a));
	memset(num,0,sizeof(num));
	memset(kol,0,sizeof(kol));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			a[i][0]+=a[i][j];
		}
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	DFS(1,0);
	if(ans==1001) puts("alternative!");
	else printf("%d",ans);
	return 0;
}


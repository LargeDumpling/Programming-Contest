/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int fir[MAXN],nExt[MAXN],cnt[MAXN];
void DFS(int u,int dep)
{
	cnt[dep]^=1;
	for(int v=fir[u];v;v=nExt[v])
		DFS(v,dep+1);
	return;
}
int main()
{
	int n,p,sum=0;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&p);
		nExt[i]=fir[p];
		fir[p]=i;
	}
	DFS(1,1);
	for(int i=1;i<=n;i++)
		sum+=cnt[i];
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


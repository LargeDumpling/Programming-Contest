/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-04-06	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=300050;
int n,num[MAXN][2],c[MAXN],pre[2]={-1,-1},ans=-1;
int main()
{
	memset(num,-1,sizeof(num));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		if(num[c[i]][0]==-1)
			num[c[i]][0]=num[c[i]][1]=i;
		else
		{
			num[c[i]][0]=min(num[c[i]][0],i);
			num[c[i]][1]=max(num[c[i]][1],i);
		}
	}
	for(int i=1;i<=n;i++) if(num[i][0]!=-1)
	{
		if(pre[0]!=-1) ans=max(ans,max(abs(num[i][1]-pre[0]),abs(num[i][0]-pre[1])));
		if(pre[0]==-1) pre[0]=num[i][0];
		else pre[0]=min(pre[0],num[i][0]);
		if(pre[1]==-1) pre[1]=num[i][1];
		else pre[1]=max(pre[1],num[i][1]);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


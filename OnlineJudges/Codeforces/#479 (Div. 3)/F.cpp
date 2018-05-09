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
#include<map>
#include<algorithm>
using namespace std;
const int MAXN=200050;
int n,num[MAXN],pre[MAXN],g[MAXN],ans;
int st[MAXN];
map<int,int> f;
int main()
{
	int u;
	ans=-1;
	st[0]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		if(!f.count(num[i]-1))
		{
			g[i]=1;
			pre[i]=-1;
		}
		else
		{
			g[i]=g[pre[i]=f[num[i]-1]]+1;
		}
		if(!f.count(num[i]))
			f[num[i]]=i;
		else
		{
			u=f[num[i]];
			f[num[i]]=g[u]<g[i]?i:u;
		}
		if(ans==-1||g[ans]<g[i])
			ans=i;
	}
	for(int i=ans;i!=-1;i=pre[i])
		st[++st[0]]=i;
	printf("%d\n",st[0]);
	while(st[0])
		printf("%d ",st[st[0]--]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


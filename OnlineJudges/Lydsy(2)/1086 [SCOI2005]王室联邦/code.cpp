/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-02-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int N,B,fir[1050],end[2050],next[2050],ed=0;
int tot=0,belong[1050],cap[1050];
void addedge(int u,int v)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	return;
}
int s[1050];
void DFS(int u,int f)
{
	int v,low=s[0];
	for(int i=fir[u];i;i=next[i]) if((v=end[i])!=f)
	{
		DFS(v,u);
		if(s[0]-low>=B)
		{
			cap[++tot]=u;
			while(s[0]>low)
				belong[s[s[0]--]]=tot;
		}
	}
	s[++s[0]]=u;
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%d",&N,&B);
	if(N<B)
	{
		puts("0");
		return 0;
	}
	int a,b;
	for(int i=1;i<N;i++)
	{
		scanf("%d%d",&a,&b);
		addedge(a,b);
	}
	s[0]=0;
	DFS(1,1);
	while(s[0])
		belong[s[s[0]--]]=tot;
	printf("%d\n",tot);
	for(int i=1;i<=N;i++)
		printf("%d ",belong[i]);
	putchar('\n');
	for(int i=1;i<=tot;i++)
		printf("%d ",cap[i]);
	putchar('\n');
	fclose(stdin);
	fclose(stdout);
	return 0;
}


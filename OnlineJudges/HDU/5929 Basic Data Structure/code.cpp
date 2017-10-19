/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-10-17	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=200050;
int T_T;
int n,q[MAXN<<1],top[2],inc[2]={1,-1},now;
int nExt[MAXN<<1][2];
int fInd(int u,int d)
{
	int x;
	for(x=u;x!=nExt[x][d];x=nExt[x][d]);
	for(int nex=nExt[u][d];u!=x;nex=nExt[u=nex][d])
		nExt[u][d]=x;
	return nExt[u][d];
}
int query()
{
	if(top[now]==top[now^1]) return q[top[now]];// only one element
	nExt[top[now^1]][now]=fInd(top[now^1],now);
	if(nExt[top[now^1]][now]<top[1]||top[0]<nExt[top[now^1]][now])
		return (top[0]-top[1]+1)&1;
	return (abs(nExt[top[now^1]][now]-top[now^1])+(int)(nExt[top[now^1]][now]!=top[now]))&1;
}
int main()
{
	char str[10];
	int x;
	scanf("%d",&T_T);
	for(int i=(MAXN<<1)-1;0<=i;i--)
		nExt[i][0]=nExt[i][1]=i;
	for(int T=1;T<=T_T;T++)
	{
		printf("Case #%d:\n",T);
		top[0]=(top[1]=MAXN)-1;
		now=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",str);
			if(str[2]=='S')
			{
				scanf("%d",&x);
				q[top[now]+=inc[now]]=x;
				nExt[top[now]][now]=top[now]+x*inc[now];
				nExt[top[now]][now^1]=top[now]+x*inc[now^1];
			}
			else if(str[2]=='P')
			{
				nExt[top[now]][0]=nExt[top[now]][1]=top[now];
				top[now]+=inc[now^1];
			}
			else if(str[2]=='V')
				now^=1;
			else if(str[2]=='E')
			{
				if(top[0]<top[1])
					puts("Invalid.");
				else
					printf("%d\n",query());
			}
		}
		while(top[1]<MAXN)
			nExt[top[1]][0]=nExt[top[1]][1]=top[1]++;
		while(top[1]<=top[0])
			nExt[top[0]][0]=nExt[top[0]][1]=top[0]--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


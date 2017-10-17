/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-07-10	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=200050;
int dis[MAXN],s[MAXN],n;
bool exist[MAXN];
void BFS()
{
	int u;
	queue<int>q;
	memset(exist,false,sizeof(exist));
	memset(dis,127,sizeof(dis));
	dis[0]=dis[1]=dis[n+1]=0;
	q.push(1);
	while(q.size())
	{
		u=q.front(); q.pop();
		exist[u]=false;
		if(dis[u]+1<dis[s[u]])
		{
			dis[s[u]]=dis[u]+1;
			if(!exist[s[u]])
			{
				exist[s[u]]=true;
				q.push(s[u]);
			}
		}
		if(dis[u]+1<dis[u-1])
		{
			dis[u-1]=dis[u]+1;
			if(!exist[u-1])
			{
				exist[u-1]=true;
				q.push(u-1);
			}
		}
		if(dis[u]+1<dis[u+1])
		{
			dis[u+1]=dis[u]+1;
			if(!exist[u+1])
			{
				exist[u+1]=true;
				q.push(u+1);
			}
		}
	}
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i]);
	BFS();
	for(int i=1;i<=n;i++)
		printf("%d ",dis[i]);
	return 0;
}


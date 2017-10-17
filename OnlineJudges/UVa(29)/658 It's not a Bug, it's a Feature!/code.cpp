/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int n,m,cost[105],dis[1050000];
char A[105][25],B[105][25];
bool exist[1050000];
int check(int S,int x)
{
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(((S&(1<<i))&&A[x][i]=='-')||(!(S&(1<<i))&&A[x][i]=='+'))return -1;
		if(B[x][i]=='0')ans|=(S&(1<<i));
		else if(B[x][i]=='+')ans|=1<<i;
	}
	return ans;
}
int SPFA()
{
	int u,v;
	queue<int>q;
	memset(dis,127,sizeof(dis));
	dis[(1<<n)-1]=0;
	q.push((1<<n)-1);
	while(q.size())
	{
		u=q.front();
		q.pop();
		exist[u]=false;
		for(int i=1;i<=m;i++)if((v=check(u,i))!=-1&&dis[u]+cost[i]<dis[v])
		{
			dis[v]=dis[u]+cost[i];
			if(!exist[v])
			{
				exist[v]=true;
				q.push(v);
			}
		}
	}
	if(dis[0]==dis[1049999])dis[0]=-1;
	return dis[0];
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int ans;
	for(int cAse=1;scanf("%d%d",&n,&m)!=-1&&n&&m;cAse++)
	{
		for(int i=1;i<=m;i++) scanf("%d%s%s",&cost[i],A[i],B[i]);
		ans=SPFA();
		printf("Product %d\n",cAse);
		if(ans==-1)puts("Bugs cannot be fixed.\n");
		else printf("Fastest sequence takes %d seconds.\n\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


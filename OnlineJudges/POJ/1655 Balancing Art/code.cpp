#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int end[40050],fir[40050],next[40050],son[20050],t,n,node,size,ed=0;
/*
The first line of input contains a single integer t (1 <= t <= 20), the number of test cases.
The first line of each test case contains an integer N (1 <= N <= 20,000), the number of congruence.
The next N-1 lines each contains two space-separated node numbers that are the endpoints of an edge
in the tree. No edge will be listed twice, and all edges will be listed.
*/
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
void DFS(int u,int f)
{
	int v,cnt=0;
	son[u]=0;
	for(int i=fir[u];i;i=next[i])
	{
		if(end[i]==f)
			continue;
		v=end[i];
		DFS(v,u);
		son[u]+=son[v]+1;
		if(son[v]+1>cnt)
			cnt=son[v]+1;
	}
	if(n-son[u]-1>cnt)
		cnt=n-son[u]-1;
	if(cnt<size||(cnt==size&&u<node))
	{
		node=u;
		size=cnt;
	}
	return;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("code.txt","w",stdout);
	int a,b;
	scanf("%d",&t);
	while(t--)
	{
		node=size=2147483647;
		memset(fir,0,sizeof(fir));
		memset(next,0,sizeof(next));
		memset(end,0,sizeof(end));
		ed=0;
		scanf("%d",&n);
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			addedge(a,b);
		}
		DFS(1,1);
		printf("%d %d\n",node,size);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


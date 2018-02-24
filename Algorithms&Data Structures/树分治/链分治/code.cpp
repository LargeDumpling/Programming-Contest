#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
//n<=100000
int end[200050],next[200050],fir[100050],fa[100050],sn[100050],hson[100050],top[100050],len[100050];
int n,ed=0,pos[100050];
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
void DFS(int u)
{
	int temp;
	sn[u]=1;
	hson[u]=0;
	for(int i=fir[u];i;i=next[i])
	{
		if(end[i]==fa[u])
			continue;
		fa[end[i]]=u;
		DFS(end[i]);
		if(sn[end[i]]>sn[hson[u]])
			hson[u]=end[i];
		sn[u]+=sn[end[i]];
	}
	return;
}
void build_tree(int u,int num)
{
	top[u]=num;
	pos[u]=++len[num];
	if(hson[u])
		build_tree(hson[u],num);
	for(int i=fir[u];i;i=end[i])
	{
		if(end[i]==fa[u]||end[i]==hson[u])
			continue;
		build_tree(end[i],++num);
	}
	return;
}
void print(int u)
{
	printf("fa: %d",fa[u]);
	if(sn[u]>1)
	{
		printf(" son:");
		for(int i=fir[u];i;i=next[i])
		{
			if(end[i]==fa[u])
				continue;
			printf(" %d",end[i]);
		}
	}
	printf(" hson: %d top: %d pos: %d\n",hson[u],top[u],pos[u]);
	for(int i=fir[u];i;i=next[i])
	{
		if(end[i]==fa[u])
			continue;
		print(end[i]);
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		addedge(a,b);
	}
	fa[1]=1;
	DFS(1);
	build_tree(1,1);
	print(1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


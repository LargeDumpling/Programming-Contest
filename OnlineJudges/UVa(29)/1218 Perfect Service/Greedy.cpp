/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-11-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int fir[10050],next[20050],end[20050],ed=0,n,dfn[10050],dfc=0,sta[10050],fa[10050];
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
	dfn[++dfc]=u;
	for(int i=fir[u];i;i=next[i])
	{
		if(end[i]==fa[u])continue;
		fa[end[i]]=u;
		DFS(end[i]);
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b,ans;
	while(true)
	{
		memset(sta,ans=dfc=0,sizeof(sta));
		memset(fir,ed=0,sizeof(fir));
		scanf("%d",&n);
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			addedge(a,b);
		}
		fa[1]=1;
		DFS(1);
		for(int i=n;i;i--)
			if(!sta[dfn[i]])
			{
				if(sta[fa[dfn[i]]]!=1)
				{
					ans++;
					sta[fa[dfn[i]]]=1;
				}
				sta[dfn[i]]=2;
			}
			else if(sta[dfn[i]]==1&&!sta[fa[dfn[i]]])
				sta[fa[dfn[i]]]=2;
		printf("%d\n",ans);
		scanf("%d",&a);
		if(a==-1)break;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define max(a,b) (a>b?a:b)
using namespace std;
int fir[100050],hea[100050],end[200050],next[200050],num[100050];
int n,ed=0,ln=-1;
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
int DFS(int u,int f)
{
	int cnt=1,size,maxsize=0;
	for(int i=fir[u];i;i=next[i])
	{
		if(end[i]==f)
			continue;
		cnt+=(size=DFS(end[i],u));
		num[end[i]]=++ln;
		if(size>maxsize)
		{
			maxsize=size;
			hea[u]=i;
		}
	}
	num[end[hea[u]]]=num[u];
	return cnt;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int a,b;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		addedge(a,b);
	}
	DFS(1,1);
	for(int i=1;i<=n;i++)
		printf("%d:%d\n",i,end[hea[i]]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


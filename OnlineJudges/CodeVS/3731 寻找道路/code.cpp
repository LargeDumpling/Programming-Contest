#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int fir[10050],end[400050],next[400050],ed=1;
int acc[10050],out[10050],s,t;
void addedge(int u,int v)
{
	out[u]++;
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	return;
}
void pRe()
{
	for(int i=1;i<=n;i++)
		if(!out[i])
			add[i]=false;
	queue<int>q;
	int u;
	q.push(s);
	while(q.size())
	{
		u=q.front();
		q.pop();
		for(int i=fir[u];i;i=next[i])
		{
			if(!(i&1))
				continue;
		}
	}
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		addedge(a,b);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


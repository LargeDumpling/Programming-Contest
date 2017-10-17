#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int d[10050][3],fir[10050],end[20050],next[20050],ed=0;
int n;
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
int min(const int &a,const int &b){return a<b?a:b;}
const int INF=2147483647;
void dp(int u,int fa)
{
	if(d[u][0]!=-1)return;
	d[u][0]=1;
	d[u][1]=0;
	d[u][2]=INF;
	for(int i=fir[u];i;i=next[i])
	{
		if(end[i]==fa)continue;
		dp(end[i],u);
		d[u][0]+=min(d[end[i]][0],d[end[i]][1]);
		if(d[u][1]!=INF)
			if(d[end[i]][2]==INF)
				d[u][1]=INF;
			else
				d[u][1]+=d[end[i]][2];
	}
	for(int i=fir[u];i;i=next[i])
		if(end[i]!=fa)
			d[u][2]=min(d[u][2],d[u][1]-d[end[i]][2]+d[end[i]][0]);
	if(d[u][2]==2147483647)d[u][2]=0;
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b;
	while(true)
	{
		memset(fir,ed=0,sizeof(fir));
		memset(d,-1,sizeof(d));
		scanf("%d",&n);
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			addedge(a,b);
		}
		dp(1,1);
		printf("%d\n",min(d[1][0],d[1][2]));
		scanf("%d",&a);
		if(a==-1)break;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


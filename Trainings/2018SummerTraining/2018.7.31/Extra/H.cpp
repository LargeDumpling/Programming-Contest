/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-31	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=1000050;
struct jz
{
	int u,w,dis;
	jz(const int &U=0,const int &W=0,const int &D=0):u(U),w(W),dis(D) { };
	bool operator<(const jz &X)const { return dis>X.dis; }
};
int fir[MAXN],eNd[MAXN],nExt[MAXN],len[MAXN],ed=0;
int dis[MAXN][2];
bool exist[MAXN][2];
int T_T,n,m;
void addedge(int u,int v,int l)
{
	eNd[++ed]=v;
	nExt[ed]=fir[u];
	len[ed]=l;
	fir[u]=ed;
	return;
}
void read1n(int &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int Hijkstra()
{
	int u,w;
	priority_queue<jz> q;
	memset(dis,127,sizeof(dis));
	memset(exist,false,sizeof(exist));
	for(int i=fir[1];i;i=nExt[i])
	{
		if(len[i]==0)
		{
			q.push(jz(eNd[i],0,1));
			dis[eNd[i]][0]=1;
		}
		else
		{
			q.push(jz(eNd[i],len[i]-1,0));
			dis[eNd[i]][len[i]-1]=0;
		}
	}
	while(q.size())
	{
		jz tem;
		do
		{
			tem=q.top();
			q.pop();
			u=tem.u; w=tem.w;
		}while(q.size()&&(exist[u][w]||dis[u][w]!=tem.dis));
		if(exist[u][w]||dis[u][w]!=tem.dis)
			break;
		exist[u][w]=true;
		for(int i=fir[u];i;i=nExt[i])
		{
			if(w+1<len[i])
			{
				if(dis[u][w]<dis[eNd[i]][len[i]-1])
				{
					dis[eNd[i]][len[i]-1]=dis[u][w];
					q.push(jz(eNd[i],len[i]-1,dis[eNd[i]][len[i]-1]));
				}
			}
			else
			{
				if(dis[u][w]+w+1-len[i]<dis[eNd[i]][w])
				{
					dis[eNd[i]][w]=dis[u][w]+w+1-len[i];
					q.push(jz(eNd[i],w,dis[eNd[i]][w]));
				}
			}
		}
	}
	return min(dis[n][0],dis[n][1]);
}
int main()
{
	int u,v,w;
	read1n(T_T);
	while(T_T--)
	{
		read1n(n); read1n(m);
		while(m--)
		{
			read1n(u); read1n(v); read1n(w);
			addedge(u,v,w);
		}
		printf("%d\n",Hijkstra());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


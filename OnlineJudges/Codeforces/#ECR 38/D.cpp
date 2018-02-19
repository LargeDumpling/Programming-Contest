/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-16	File created.
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
struct jz
{
	int u;
	long long dis;
	jz(const int &U=0,const long long &D=0):u(U),dis(D) { }
	bool operator<(const jz &X)const { return dis>X.dis; }
};
int n,m;
int fir[MAXN],eNd[MAXN<<1],nExt[MAXN<<1],ed=0;
bool vis[MAXN];
long long dis[MAXN],len[MAXN<<1];
template<typename Ty>
void read1n(Ty &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
void addedge(int u,int v,long long w)
{
	eNd[++ed]=v;
	nExt[ed]=fir[u];
	fir[u]=ed;
	len[ed]=w;
	eNd[++ed]=u;
	nExt[ed]=fir[v];
	fir[v]=ed;
	len[ed]=w;
	return;
}
int main()
{
	int u,v;
	long long w;
	priority_queue<jz> q;
	memset(vis,false,sizeof(vis));
	read1n(n); read1n(m);
	for(int i=1;i<=m;i++)
	{
		read1n(u);
		read1n(v);
		read1n(w);
		addedge(u,v,w*2LL);
	}
	for(int i=1;i<=n;i++)
	{
		read1n(dis[i]);
		q.push(jz(i,dis[i]));
	}
	for(int cnt=1;cnt<=n;cnt++)
	{
		while(vis[q.top().u]||dis[q.top().u]!=q.top().dis)
			q.pop();
		u=q.top().u; q.pop();
		vis[u]=true;
		for(int i=fir[u];i;i=nExt[i]) if(dis[u]+len[i]<dis[eNd[i]])
		{
			dis[eNd[i]]=dis[u]+len[i];
			q.push(jz(eNd[i],dis[eNd[i]]));
		}
	}
	for(int i=1;i<=n;i++)
		cout<<dis[i]<<" ";
	return 0;
}


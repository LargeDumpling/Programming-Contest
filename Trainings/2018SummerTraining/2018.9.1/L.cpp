/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-01	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const int MAXM=200050;
struct jz
{
	int u;
	long long dis;
	jz(const int &U=0,const long long &D=0):u(U),dis(D) { }
	bool operator<(const jz &X)const { return dis==X.dis?u>X.u:dis>X.dis; }
};
bool aaa;
int T_T,n,m,k;
int fir[MAXN*15],eNd[MAXM*25],nxt[MAXM*25],ed=0;
bool vis[MAXN*15];
long long len[MAXM*25],dis[MAXN*15],ans;
bool bbb;
void addedge(int u,int v,int w)
{
	eNd[++ed]=v;
	nxt[ed]=fir[u];
	len[ed]=w;
	fir[u]=ed;
	return;
}
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
void init()
{
	memset(fir,ed=0,sizeof(fir));
	memset(dis,-1,sizeof(dis));
	memset(vis,false,sizeof(vis));
	return;
}
void Hijkstra()
{
	int u;
	priority_queue<jz> q;
	dis[1]=0;
	q.push(jz(1,0));
	while(q.size())
	{
		while(q.size()&&(vis[q.top().u]||dis[q.top().u]!=q.top().dis))
			q.pop();
		if(!q.size()) break;
		u=q.top().u; q.pop();
		vis[u]=true;
		for(int i=fir[u];i;i=nxt[i]) if(dis[eNd[i]]==-1||dis[u]+len[i]<dis[eNd[i]])
		{
			dis[eNd[i]]=dis[u]+len[i];
			q.push(jz(eNd[i],dis[eNd[i]]));
		}
	}
	return;
}
int Rand()
{
	return (rand()<<15)+rand();
}
int main()
{
	int u,v,w;
	read1n(T_T);
	//T_T=5;
	while(T_T--)
	{
		init();
		read1n(n);
		//n=100000;
		read1n(m);
		//m=200000;
		read1n(k);
		//k=10;
		for(int i=1;i<=m;i++)
		{
			read1n(u);
			//u=Rand()%n+1;
			read1n(v);
			//v=Rand()%n+1;
			read1n(w);
			//w=1000000000;
			for(int j=0;j<=k;j++)
			{
				addedge(u+j*n,v+j*n,w);
				if(j<k) addedge(u+j*n,v+(j+1)*n,0);
			}
		}
		Hijkstra();
		ans=dis[n];
		for(int i=1;i<=k;i++)
			ans=min(ans,dis[(i+1)*n]);
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-03	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
struct Jinic
{
	static const int MAXN=10000;
	static const int MAXM=70000;
	static const int INF=0x7f7f7f7f;
	int fir[MAXN],cur[MAXN],lev[MAXN],S,T;
	int end[MAXM],next[MAXM],f[MAXM],mono[MAXM],ed;
	bool exist[MAXN];
	void init(int SS,int TT)
	{
		memset(fir,0,sizeof(fir));
		S=SS; T=TT; ed=1;
	}
	void init()
	{
		memset(fir,0,sizeof(fir));
		S=MAXN-2; T=S+1;
		ed=1;
	}
	void addedge(int u,int v,int cap,int mon)
	{
		end[++ed]=v;
		next[ed]=fir[u];
		fir[u]=ed;
		f[ed]=cap;
		mono[ed]=mon;
		end[++ed]=u;
		next[ed]=fir[v];
		fir[v]=ed;
		f[ed]=0;
		mono[ed]=-1*mon;
		return;
	}
	bool SPFA()
	{
		int u;
		queue<int>q;
		memset(exist,false,sizeof(exist));
		memset(lev,127,sizeof(lev));
		lev[S]=0;
		q.push(S);
		while(q.size())
		{
			u=q.front(); q.pop();
			exist[u]=false;
			for(int i=fir[u];i;i=next[i]) if(f[i]&&lev[u]+mono[i]<lev[end[i]])
			{
				lev[end[i]]=lev[u]+mono[i];
				if(!exist[end[i]])
				{
					exist[end[i]]=true;
					q.push(end[i]);
				}
			}
		}
		memcpy(cur,fir,sizeof(fir));
		return lev[T]!=INF;
	}
	int DFS(int u,int maxf)
	{
		if(u==T||!maxf) return maxf;
		exist[u]=true;
		int cnt=0;
		for(int &i=cur[u],tem;i;i=next[i]) if(f[i]&&lev[end[i]]==lev[u]+mono[i])
		{
			if(exist[end[i]]) continue;
			tem=DFS(end[i],min(f[i],maxf));
			maxf-=tem;
			f[i]-=tem;
			f[i^1]+=tem;
			cnt+=tem;
			if(!maxf) break;
		}
		if(!cnt) lev[u]=-1*INF;
		exist[u]=false;
		return cnt;
	}
	int Ans()
	{
		int ans=0;
		memset(exist,false,sizeof(exist));
		while(SPFA())
			ans+=DFS(S,INF)*lev[T];
		return ans;
	}
}MCMF;
int n,m,num[45][45],in[45][45],out[45][45],an=0;
void build1()
{
	//MCMF.init(n*(n+1)*2+1,n*(n+1)*2+2);
	MCMF.init();
	for(int i=1;i<=m;i++) MCMF.addedge(MCMF.S,in[1][i],1,0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i+m-1;j++)
		{
			MCMF.addedge(in[i][j],out[i][j],1,-1*num[i][j]);
			MCMF.addedge(out[i][j],in[i+1][j],1,0);
			MCMF.addedge(out[i][j],in[i+1][j+1],1,0);
		}
	for(int i=1;i<=n+m-1;i++) MCMF.addedge(out[n][i],MCMF.T,1,0);
	return;
}
void build2()
{
	//MCMF.init(n*(n+1)*2+1,n*(n+1)*2+2);
	MCMF.init();
	for(int i=1;i<=m;i++) MCMF.addedge(MCMF.S,in[1][i],1,0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i+m-1;j++)
		{
			MCMF.addedge(in[i][j],out[i][j],MCMF.INF,-1*num[i][j]);
			MCMF.addedge(out[i][j],in[i+1][j],1,0);
			MCMF.addedge(out[i][j],in[i+1][j+1],1,0);
		}
	for(int i=1;i<=n+m-1;i++) MCMF.addedge(out[n][i],MCMF.T,MCMF.INF,0);
	return;
}
void build3()
{
	//MCMF.init(n*(n+1)*2+1,n*(n+1)*2+2);
	MCMF.init();
	for(int i=1;i<=m;i++) MCMF.addedge(MCMF.S,in[1][i],1,0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i+m-1;j++)
		{
			MCMF.addedge(in[i][j],out[i][j],MCMF.INF,-1*num[i][j]);
			MCMF.addedge(out[i][j],in[i+1][j],MCMF.INF,0);
			MCMF.addedge(out[i][j],in[i+1][j+1],MCMF.INF,0);
		}
	for(int i=1;i<=n+m-1;i++) MCMF.addedge(out[n][i],MCMF.T,MCMF.INF,0);
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	memset(out,0,sizeof(out));
	scanf("%d%d",&m,&n);
	an=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i+m-1;j++)
		{
			in[i][j]=++an; out[i][j]=++an;
			scanf("%d",&num[i][j]);
		}
	build1();
	printf("%d\n",-1*MCMF.Ans());
	build2();
	printf("%d\n",-1*MCMF.Ans());
	build3();
	printf("%d",-1*MCMF.Ans());
	fclose(stdin);
	fclose(stdout);
	return 0;
}


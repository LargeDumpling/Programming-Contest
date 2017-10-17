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
struct Pinic
{
	static const int MAXN=200;
	static const int MAXM=14000;
	static const int INF=0x7f7f7f7f;
	int fir[MAXN],cur[MAXN],lev[MAXN],end[MAXM],next[MAXM],mono[MAXM],f[MAXM];
	int S,S1,T,ed;
	bool exist[MAXN];
	void init()
	{
		memset(fir,0,sizeof(fir));
		ed=1; S=MAXN-3; S1=MAXN-2; T=MAXN-1;
		return;
	}
	void addedge(int u,int v,int cap,int val)
	{
		end[++ed]=v;
		next[ed]=fir[u];
		fir[u]=ed;
		f[ed]=cap;
		mono[ed]=val;
		end[++ed]=u;
		next[ed]=fir[v];
		fir[v]=ed;
		f[ed]=0;
		mono[ed]=-1*val;
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
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n,a,b,A[100],B[100];
	scanf("%d%d%d",&n,&a,&b);
	MCMF.init();
	MCMF.addedge(MCMF.S,MCMF.S1,n,0);
	for(int i=1;i<=a;i++)
	{
		scanf("%d",&A[i]);
		MCMF.addedge(MCMF.S1,i,1,A[i]*A[i]);
	}
	for(int i=1;i<=b;i++)
	{
		scanf("%d",&B[i]);
		for(int j=1;j<=a;j++)
			MCMF.addedge(j,i+a,1,-2*A[j]*B[i]);
		MCMF.addedge(i+a,MCMF.T,1,B[i]*B[i]);
	}
	printf("%d",MCMF.Ans());
	fclose(stdin);
	fclose(stdout);
	return 0;
}


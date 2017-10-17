/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-02-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int pri[205],num[50][50],an=0;
void get_pri()
{
	bool exist[205];
	memset(exist,true,sizeof(exist));
	pri[0]=0;
	for(int i=2;i<=200;i++)
	{
		if(exist[i]) pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&i*pri[j]<=200;j++)
		{
			exist[i*pri[j]]=false;
			if(!(i%pri[j])) break;
		}
	}
	return;
}
vector<int> fac[205];
int n1,n2,fir[701000],cur[701000],end[3500000],next[3500000],f[3500000],ed=1;
int lev[701000],S,T;
void addedge(int u,int v,int cap)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	f[ed]=cap;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	f[ed]=0;
	return;
}
bool BFS()
{
	int u;
	queue<int> q;
	memset(lev,-1,sizeof(lev));
	lev[S]=1;
	q.push(S);
	while(q.size())
	{
		u=q.front(); q.pop();
		for(int i=fir[u];i;i=next[i]) if(f[i]&&lev[end[i]]==-1)
		{
			lev[end[i]]=lev[u]+1;
			q.push(end[i]);
		}
	}
	memcpy(cur,fir,sizeof fir);
	return lev[T]!=-1;
}
int DFS(int u,int maxf)
{
	if(!maxf||u==T) return maxf;
	int cnt=0,temp;
	for(int &i=cur[u];i;i=next[i]) if(f[i]&&lev[end[i]]==lev[u]+1)
	{
		temp=DFS(end[i],min(maxf,f[i]));
		maxf-=temp;
		f[i]-=temp;
		cnt+=temp;
		f[i^1]+=temp;
		if(maxf==0) break;
	}
	if(!cnt) lev[u]=-1;
	return cnt;
}
int Dinic()
{
	int ans=0;
	while(BFS())
		ans+=DFS(S,2147483647);
	return ans;
}
void build(int u,int a,int b,int c,int sta)
{
	for(unsigned i=0;i<fac[a].size();i++)
		for(unsigned j=0;j<fac[b].size();j++)
			if(sta) addedge(u,num[fac[a][i]][fac[b][j]],1);
			else addedge(num[fac[a][i]][fac[b][j]],u,1);
	for(unsigned i=0;i<fac[b].size();i++)
		for(unsigned j=0;j<fac[c].size();j++)
			if(sta) addedge(u,num[fac[b][i]][fac[c][j]]+46*46,1);
			else addedge(num[fac[b][i]][fac[c][j]]+46*46,u,1);
	for(unsigned i=0;i<fac[a].size();i++)
		for(unsigned j=0;j<fac[c].size();j++)
			if(sta) addedge(u,num[fac[a][i]][fac[c][j]]+46*46*2,1);
			else addedge(num[fac[a][i]][fac[c][j]]+46*46*2,u,1);
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b,c;
	get_pri();
	for(int i=1;i<=200;i++)
	{
		//printf("\n%d:\n",i);
		for(int j=1;j<=pri[0];j++) if(!(i%pri[j]))
		{
			fac[i].push_back(j);
			//printf("%d ",j);
		}
	}
	scanf("%d%d",&n1,&n2);
	an=n1+n2;
	for(int i=1;i<=pri[0];i++)
		for(int j=1;j<=pri[0];j++)
			num[i][j]=++an;
	S=n1+n2+46*46*3+1; T=S+1;
	for(int i=1;i<=n1;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		addedge(S,i,1);
		build(i,a,b,c,1);
	}
	for(int i=1;i<=n2;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		addedge(i+n1,T,1);
		build(i+n1,a,b,c,0);
	}
	printf("%d",Dinic());
	fclose(stdin);
	fclose(stdout);
	return 0;
}


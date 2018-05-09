/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-04-13	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN=3050;
const int MAXM=4000050;
const int INF=1000000050;
int s,r,ff,t;
map<string,int> state_name;
int fir[MAXN],cur[MAXN],lev[MAXN],end[MAXM],next[MAXM],f[MAXM],ed,S,T;
int type[MAXN];
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
	memset(lev,-1,sizeof(lev));
	queue<int>q;
	lev[S]=0;
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
	if(u==T||!maxf) return maxf;
	int cnt=0;
	for(int &i=cur[u],tem;i;i=next[i]) if(f[i]&&lev[end[i]]==lev[u]+1)
	{
		tem=DFS(end[i],min(maxf,f[i]));
		maxf-=tem;
		f[i]-=tem;
		f[i^1]+=tem;
		cnt+=tem;
		if(!maxf) break;
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
void init(int SS,int TT)
{
	memset(fir,0,sizeof(fir));
	ed=1;
	S=SS; T=TT;
	return;
}
int get_id(string name)
{
	if(!state_name.count(name)) state_name[name]=1+state_name.size();
	return state_name[name];
}
int in[MAXN],out[MAXN];
int main()
{
	//freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	int n,tem;
	memset(type,-1,sizeof(type));
	cin>>s>>r>>ff>>t;
	init(1,MAXN-1);
	string str;
	for(int i=1;i<=r;i++)
	{
		cin>>str;
		tem=get_id(str);
		addedge(S,tem,1);
		type[tem]=0;
	}
	for(int i=1;i<=ff;i++)
	{
		cin>>str;
		tem=get_id(str);
		addedge(tem,T,1);
		type[tem]=1;
	}
	for(int i=1;i<=t;i++)
		in[i]=s+2*i-1,out[i]=s+2*i;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		addedge(in[i],out[i],1);
		for(int j=1;j<=n;j++)
		{
			cin>>str;
			tem=get_id(str);
			if(type[tem]==0)
				addedge(tem,in[i],INF);
			else if(type[tem]==1)
				addedge(out[i],tem,INF);
			else
			{
				addedge(tem,in[i],INF);
				addedge(out[i],tem,INF);
			}
		}
		/*if(i==t) addedge(out[i],in[1],INF);
		else addedge(out[i],in[i+1],INF);*/
	}
	printf("%d",Dinic());
	fclose(stdin);
	fclose(stdout);
	return 0;
}


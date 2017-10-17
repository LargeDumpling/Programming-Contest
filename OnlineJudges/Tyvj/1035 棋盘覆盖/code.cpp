/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-01	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=10100;
const int MAXM=100000;
const int INF=1<<30;
int n,m;
int fir[MAXN],cur[MAXN],lev[MAXN],end[MAXM],next[MAXM],f[MAXM],ed,S,T;
int koloro[105][105],num[105][105],an=0;
bool useable[105][105];
void addedge(int u,int v,int cap)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	f[ed]=cap;
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
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b,move[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
	memset(useable,true,sizeof(useable));
	memset(num,an=0,sizeof(num));
	memset(koloro,0,sizeof(koloro));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		useable[a][b]=false;
	}
	init(n*n+1,n*n+2);
	koloro[1][1]=1;
	for(int i=2;i<=n;i++) koloro[i][1]=3-koloro[i-1][1];
	for(int i=1;i<=n;i++)
		for(int j=2;j<=n;j++)
			koloro[i][j]=3-koloro[i][j-1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			num[i][j]=++an;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) if(useable[i][j])
		{
			if(koloro[i][j]==1)
			{
				addedge(S,num[i][j],1),addedge(num[i][j],S,0);
				for(int k=0;k<4;k++)
				{
					a=i+move[k][0];
					b=j+move[k][1];
					if(1<=a&&a<=n&&1<=b&&b<=n)
						addedge(num[i][j],num[a][b],1)
							,addedge(num[a][b],num[i][j],0);
				}
			}
			else if(koloro[i][j]==2)
				addedge(num[i][j],T,1),addedge(T,num[i][j],0);
		}
	printf("%d",Dinic());
	fclose(stdin);
	fclose(stdout);
	return 0;
}


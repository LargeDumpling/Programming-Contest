/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int INF=1<<30;
int fir[105],cur[105],lev[105],end[20050],next[20050],c[20050],f[20050],ed,sta,tar;
void addedge(int u,int v,int cap)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	c[ed]=cap;
	f[ed]=0;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	c[ed]=f[ed]=cap;
	return;
}
queue<int>q;
bool BFS()
{
	int u;
	memset(lev,0,sizeof(lev));
	while(q.size())q.pop();
	lev[sta]=1;
	q.push(sta);
	while(q.size())
	{
		u=q.front();
		q.pop();
		for(int i=fir[u];i;i=next[i])if(c[i]>f[i]&&!lev[end[i]])
		{
			lev[end[i]]=lev[u]+1;
			q.push(end[i]);
		}
	}
	memcpy(cur,fir,sizeof fir);
	return lev[tar];
}
int DFS(int u,int maxf)
{
	if(u==tar)return maxf;
	int totf=0,temf;
	for(int &i=cur[u];i;i=next[i])if(c[i]>f[i]&&lev[end[i]]==lev[u]+1)
	{
		totf+=(temf=DFS(end[i],min(maxf,c[i]-f[i])));
		f[i]+=temf;
		f[i^1]-=temf;
		maxf-=temf;
	}
	if(!totf)lev[u]=-1;
	return totf;
}
int max_flow()
{
	int ans=0;
	while(BFS())
		ans+=DFS(sta,INF);
	return ans;
}
bool read1n(int &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())if(ch==-1)return false;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
	return true;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n,m,a,b,ans;
	while(read1n(n))
	{
		read1n(m);
		memset(fir,0,sizeof(fir));
		ed=1;
		for(int i=1;i<=n;i++)addedge(i,i+50,1);
		for(int i=1;i<=m;i++)
		{
			read1n(a);read1n(b);
			a++;b++;
			addedge(a+50,b,INF);
			addedge(b+50,a,INF);
		}
		ans=n;
		sta=n+50;
		for(tar=1;tar<n;tar++)
		{
			ans=min(ans,max_flow());
			for(int i=2;i<=ed;i++)f[i]=(i&1)?c[i]:0;
		}
		if(ans==INF)ans=n;
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


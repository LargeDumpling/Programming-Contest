/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-02-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
const int MAXN=100000<<1;
const int MAXM=100000<<1;
const int D=10000000;
int n,m,koloro[MAXN+50];
int fir[MAXN+50],end[MAXM+50],next[MAXM+50],ed=0,root;
int anc[MAXN+50][21],Log[MAXN+50],deep[MAXN+50];
int BLOCK,bel[MAXN+50],dfn[MAXN+50],tot=0,dfs_clock=0;
int cnt[MAXN+50],res[MAXM+50],ans,cNt=0;
bool used[MAXN+50];
char in[D],*I=in,out[D/10],*O=out;
struct jp
{
	int u,v,a,b,id;
	bool operator<(const jp &x)const
	{ return bel[u]==bel[x.u]?dfn[v]<dfn[x.v]:bel[u]<bel[x.u]; }
}Q[MAXM];
inline int read1n()
{
	int x=0;
	while(*I<'0'||'9'<*I)I++;
	while('0'<=*I&&*I<='9') x=(x<<1)+(x<<3)+*(I++)-'0';
	return x;
}
inline void write1n(int x)
{
	static int ss[100];
	if(!x)
	{
		*(O++)='0';
		return;
	}
	for(ss[0]=0;x;x/=10) ss[++ss[0]]=x%10;
	while(ss[0]) *(O++)=ss[ss[0]--]+'0';
	return;
}
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
int s[MAXN];
void DFS(int u)
{
	dfn[u]=++dfs_clock;
	int v,low=s[0];
	for(int i=1;i<=16;i++) anc[u][i]=anc[anc[u][i-1]][i-1];
	for(int i=fir[u];i;i=next[i]) if((v=end[i])!=anc[u][0])
	{
		deep[v]=deep[u]+1;
		anc[v][0]=u;
		DFS(v);
		if((s[0]-low)>=BLOCK)
		{
			tot++;
			while(s[0]>low) bel[s[s[0]--]]=tot;
		}
	}
	s[++s[0]]=u;
	return;
}
int LCA(int u,int v)
{
	if(deep[u]<deep[v]) swap(u,v);
	if(deep[u]>deep[v])
	{
		int t=deep[u]-deep[v];
		for(int i=Log[t];i>=0;i--) if(t&(1<<i))
			u=anc[u][i];
	}
	if(u==v) return u;
	if(u!=v) for(int i=Log[n];i>=0;i--) if(anc[u][i]!=anc[v][i])
		u=anc[u][i],v=anc[v][i];
	return anc[u][0];
}
inline void reverse(int x)
{
	if(used[x]) ans-=(--cnt[koloro[x]]==0);
	else ans+=(++cnt[koloro[x]]==1);
	used[x]^=1;
	return;
}
int laboras(int u,int v)
{
	while(u!=v)
		if(deep[u]>deep[v]) reverse(u),u=anc[u][0];
		else reverse(v),v=anc[v][0];
	return u;
}
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	in[fread(in,1,D,stdin)]=-1;
	int u,v,lca;
	n=read1n(),m=read1n();
	BLOCK=sqrt(n);
	for(int i=1;i<=n;i++) koloro[i]=read1n();
	Log[0]=-1;
	for(int i=1;i<=n;i++)
	{
		u=read1n(),v=read1n();
		if(!u) root=v;
		else if(!v) root=u;
		else addedge(u,v);
		Log[i]=Log[i>>1]+1;
	}
	for(int i=1;i<=m;i++)
		Q[i].u=read1n(),Q[i].v=read1n(),Q[i].a=read1n(),Q[i].b=read1n(),Q[i].id=i;
	anc[root][0]=0;
	deep[root]=1;
	DFS(root);
	while(s[0]) bel[s[s[0]--]]=tot;

	sort(Q+1,Q+m+1);
	lca=laboras(Q[1].u,Q[1].v);
	reverse(lca);
	res[Q[1].id]=ans;
	if(cnt[Q[1].a]&&cnt[Q[1].b]&&Q[1].a!=Q[1].b) res[Q[1].id]--;
	reverse(lca);
	for(int i=2;i<=m;i++)
	{
		laboras(Q[i-1].u,Q[i].u);
		laboras(Q[i-1].v,Q[i].v);
		lca=LCA(Q[i].u,Q[i].v);
		reverse(lca);
		res[Q[i].id]=ans;
		if(cnt[Q[i].a]&&cnt[Q[i].b]&&Q[i].a!=Q[i].b) res[Q[i].id]--;
		reverse(lca);
	}
	for(int i=1;i<=m;i++)// printf("%d\n",res[i]);
		write1n(res[i]),*(O++)='\n';
	fwrite(out,1,O-out,stdout);
	//cerr<<(double)clock()/CLOCKS_PER_SEC;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


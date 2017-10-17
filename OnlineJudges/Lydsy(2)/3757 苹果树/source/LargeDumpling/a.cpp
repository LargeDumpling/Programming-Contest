/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-02-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int n,m,koloro[100050],fir[100050],end[100050],next[100050],ed=0,root;
int BLOCK,s[100050],anc[100050][21],deep[100050],dfn[100050],dfs_clock=0;
int bel[100050],tot=0,res[100050],ans,cnt[100050],lOg[100050];
bool used[100050];
struct jp
{
	int l,r,id,a,b;
	bool operator<(const jp &k)const
	{
		if(bel[l]==bel[k.l]) return dfn[r]<dfn[k.r];
		else return bel[l]<bel[k.l];
	}
}Q[100050];
inline void addedge(int u,int v)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	return;
}
bool cnmp(jp a,jp b)
{
	if(bel[a.l]!=bel[b.l])
		return bel[a.l]<bel[b.l];
	return dfn[a.r]<dfn[b.r];
//	return bel[a.l]==bel[b.l]?dfn[a.r]<dfn[b.r]:bel[a.l]<bel[b.l];
}
void LCA_init()
{
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i<=n;i++)
			anc[i][j]=anc[anc[i][j-1]][j-1];
	return;
}
int DFS(int u)
{
	//int v,low=s[0];
	int size=0;
	dfn[u]=++dfs_clock;
	//for(int i=1;i<=17&&(1<<i)<=deep[u];i++)
		//anc[u][i]=anc[anc[u][i-1]][i-1];
	for(int i=fir[u];i;i=next[i]) if(end[i]!=anc[u][0])
	{
		anc[end[i]][0]=u;
		deep[end[i]]=deep[u]+1;
		size+=DFS(end[i]);
		if(size>=BLOCK)
		{
			++tot;
			for(int j=1;j<=size;j++) bel[s[s[0]--]]=tot;
			size = 0;
		}
	}
	s[++s[0]]=u;
	return size+1;
}
int LCA(int a,int b)
{
	while(deep[a]<deep[b]) swap(a,b);
	int t=deep[a]-deep[b];
	for(int i=lOg[t];i>=0;i--) if(t&(1<<i))
		a=anc[a][i];
	for(int i=lOg[n];i>=0;i--) if(anc[a][i]!=anc[b][i])
		a=anc[a][i],b=anc[b][i];
	if(a!=b) return anc[a][0];
	else return a;
}
void reverse(int x)
{
	if(!used[x]) ans+=(++cnt[koloro[x]]==1);
	else ans-=(--cnt[koloro[x]]==0);
	used[x]^=true;
	return;
}
void laboras(int u,int v,int lca)
{
	while(u!=lca)
	{
		//reverse(u);
		if(!used[u]) { cnt[koloro[u]]++,used[u]=true; if(cnt[koloro[u]]==1) ans++;}
		else {cnt[koloro[u]]--,used[u]=false; if(cnt[koloro[u]]==0) ans--; }
		u=anc[u][0];
	}
	while(v!=lca)
	{
		//reverse(v);
		if(!used[v]) { cnt[koloro[v]]++,used[v]=true; if(cnt[koloro[v]]==1) ans++;}
		else {cnt[koloro[v]]--,used[v]=false; if(cnt[koloro[v]]==0) ans--; }
		v=anc[v][0];
	}
	return;
}
int laboras(int u,int v)
{
	while(u!=v)
	{
		if(deep[u]>deep[v]) reverse(u),u=anc[u][0];
		else reverse(v),v=anc[v][0];
	}
	return u;
}
inline int read1n()
{
	int x; char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(x=0;'0'<=ch&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
	return x;
}
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int u,v,lca,remain;
	//scanf("%d%d",&n,&m);
	n=read1n(); m=read1n();
	BLOCK=(int)sqrt(n);
	lOg[0]=-1;
	for(int i=1;i<=n;i++)// scanf("%d",&koloro[i]);
	{
		koloro[i]=read1n();
		lOg[i]=lOg[i>>1]+1;
	}
	for(int i=1;i<=n;i++)
	{
		//scanf("%d%d",&u,&v);
		u=read1n(); v=read1n();
		if(!u) root=v;
		else if(!v) root=u;
		else addedge(u,v);
	}
	for(int i=1;i<=m;i++)
	{
		//scanf("%d%d%d%d",&Q[i].l,&Q[i].r,&Q[i].a,&Q[i].b);
		Q[i].l=read1n();
		Q[i].r=read1n();
		Q[i].a=read1n();
		Q[i].b=read1n();
		Q[i].id=i;
	}
	//sort(Q+1,Q+m+1,cnmp);
	anc[root][0]=0;
	deep[root]=1;
	remain=DFS(root);
	for(int i=1;i<=remain;i++) bel[s[s[0]--]]=tot;
	sort(Q+1,Q+m+1);
	LCA_init();
	//tot++; while(s[0]) bel[s[s[0]--]]=tot;
	laboras(Q[1].l,Q[1].r,lca=LCA(Q[1].l,Q[1].r));
	//lca=laboras(Q[1].l,Q[1].r);
	//reverse(lca);
	if(!used[lca]){cnt[koloro[lca]]++,used[lca]=true;if(cnt[koloro[lca]]==1)ans++;}
	else{cnt[koloro[lca]]--,used[lca]=false;if(cnt[koloro[lca]]==0)ans--;}
	res[Q[1].id]=ans;
	//if(Q[1].a!=0&&Q[1].b!=0&&cnt[Q[1].a]!=0&&cnt[Q[1].b]!=0&&Q[1].a!=Q[1].b)
		//res[Q[1].id]--;
	if(cnt[Q[1].a]!=0&&cnt[Q[1].b]!=0) res[Q[1].id]--;
	if(!used[lca]){cnt[koloro[lca]]++,used[lca]=true;if(cnt[koloro[lca]]==1)ans++;}
	else{cnt[koloro[lca]]--,used[lca]=false;if(cnt[koloro[lca]]==0)ans--;}
	//reverse(lca);
	for(int i=2;i<=m;i++)
	{
		laboras(Q[i-1].l,Q[i].l,LCA(Q[i-1].l,Q[i].l));
		//laboras(Q[i-1].l,Q[i].l);
		laboras(Q[i-1].r,Q[i].r,LCA(Q[i-1].r,Q[i].r));
		//laboras(Q[i-1].r,Q[i].r);
		lca=LCA(Q[i].l,Q[i].r);
		//reverse(lca);
		if(!used[lca])
		{cnt[koloro[lca]]++,used[lca]=true;if(cnt[koloro[lca]]==1)ans++;}
		else
		{cnt[koloro[lca]]--,used[lca]=false;if(cnt[koloro[lca]]==0)ans--;}
		res[Q[i].id]=ans;
		//if(Q[i].a!=0&&Q[i].b!=0&&cnt[Q[i].a]!=0&&cnt[Q[i].b]!=0&&Q[i].a!=Q[i].b)
			//res[Q[i].id]--;
		if(cnt[Q[i].a]!=0&&cnt[Q[i].b]!=0&&Q[i].a!=Q[i].b) res[Q[i].id]--;
		if(!used[lca])
		{cnt[koloro[lca]]++,used[lca]=true;if(cnt[koloro[lca]]==1)ans++;}
		else
		{cnt[koloro[lca]]--,used[lca]=false;if(cnt[koloro[lca]]==0)ans--;}
		//reverse(lca);
	}
	for(int i=1;i<=m;i++) printf("%d\n",res[i]);
	return 0;
}


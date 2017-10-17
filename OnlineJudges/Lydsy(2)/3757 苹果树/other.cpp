#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<cmath>
#include<ctime>
using namespace std;
inline int getint()
{
	char c=getchar();
	int con=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') con=con*10+c-'0',c=getchar();
	return con;
}
const int MAXN=100010;
int n,m,K,lca,u,v,c[MAXN],dfn[MAXN],belongn[MAXN];
int tot,root,dfs_clock,remain;
int head[MAXN],to[MAXN],next[MAXN],cnt;
int anc[MAXN][21],dep[MAXN],Log[MAXN];
int Stack[MAXN],top;
int p[MAXN],ans,con[MAXN];
bool used[MAXN];
int cNt=0;
struct Query
{
	int u,v,a,b,sub;
	friend bool operator<(const Query &i,const Query &j)
	{
		if(belongn[i.u]==belongn[j.u]) return dfn[i.v]<dfn[j.v];
		else return belongn[i.u]<belongn[j.u];
	}
}Q[MAXN];
inline void adde(int f,int t)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
	cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
 }
int DFS(int x)
{
	//if(++cNt<100)
		//fprintf(stderr,"%d\n",x);
	int size=0;
	dfn[x]=++dfs_clock;
	for(int i=head[x];i;i=next[i])
		if(to[i]!=anc[x][0])
		{
			dep[to[i]]=dep[x]+1,anc[to[i]][0]=x;
			size+=DFS(to[i]);
			if(size>=K)
			{
				tot++;
				for(int i=1;i<=size;i++)
					belongn[Stack[top--]]=tot;
				size=0;
			}
		}
	Stack[++top]=x;
	return size+1;
}
int LCA(int p,int q)
{
	if(dep[p]<dep[q]) swap(p,q);
	int d=dep[p]-dep[q];
	for(int i=Log[d];i>=0;i--)
		if(d&(1<<i)) p=anc[p][i];
	for(int i=Log[n];i>=0;i--)
		if(anc[p][i]!=anc[q][i]) p=anc[p][i],q=anc[q][i];
	if(p!=q) return anc[p][0];
	else return p;
}
void work(int u,int v,int lca)
{
	while(u!=lca)
	{
		if(!used[u]) {p[c[u]]++,used[u]=true;if(p[c[u]]==1) ans++;}
		else {p[c[u]]--,used[u]=false;if(p[c[u]]==0) ans--;}
		u=anc[u][0];
		cNt++;
	}
	while(v!=lca)
	{
		if(!used[v]) {p[c[v]]++,used[v]=true;if(p[c[v]]==1) ans++;}
		else {p[c[v]]--,used[v]=false;if(p[c[v]]==0) ans--;}
		v=anc[v][0];
		cNt++;
	}
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("other.out","w",stdout);
	n=getint(),m=getint();
	K=(int)sqrt(n);
	for(int i=1;i<=n;i++) c[i]=getint();
	for(int i=1;i<=n;i++)
	{
		u=getint(),v=getint();
		if(u==0) root=v;
		else if(v==0) root=u;
		else adde(u,v);
	}
	for(int i=1;i<=m;i++)
	{
		Q[i].u=getint(),Q[i].v=getint();
		Q[i].a=getint(),Q[i].b=getint();
		Q[i].sub=i;
	}
	fprintf(stderr,"%d\n",root);
	remain=DFS(root);
	fprintf(stderr,"%d\n",dfs_clock);
	for(int i=1;i<=remain;i++) belongn[Stack[top--]]=tot;
	for(int i=1;i<=1000;i++)
	{
		//fprintf(stderr,"%d\n",dfn[i]);
	}
	sort(Q+1,Q+m+1);
	//for(int i=1;i<=100;i++) printf("%d %d\n",Q[i].u,Q[i].v);
	Log[0]=-1;
	for(int i=1;i<=n;i++) Log[i]=Log[i>>1]+1;
	for(int i=1;i<=Log[n];i++)
		for(int j=1;j<=n;j++)
			anc[j][i]=anc[anc[j][i-1]][i-1];
	//fprintf(stderr,"%.6f\n",(double)clock()/CLOCKS_PER_SEC);
	work(Q[1].u,Q[1].v,lca=LCA(Q[1].u,Q[1].v));
	if(!used[lca]) {p[c[lca]]++,used[lca]=true;if(p[c[lca]]==1) ans++;}
	else {p[c[lca]]--,used[lca]=false;if(p[c[lca]]==0) ans--;}
	con[Q[1].sub]=ans;
	if(p[Q[1].a]!=0&&p[Q[1].b]!=0) con[Q[1].sub]--;
	if(!used[lca]) {p[c[lca]]++,used[lca]=true;if(p[c[lca]]==1) ans++;}
	else {p[c[lca]]--,used[lca]=false;if(p[c[lca]]==0) ans--;}
	for(int i=2;i<=m;i++)
	{
		work(Q[i-1].u,Q[i].u,LCA(Q[i-1].u,Q[i].u));
		work(Q[i-1].v,Q[i].v,LCA(Q[i-1].v,Q[i].v));
		lca=LCA(Q[i].u,Q[i].v);
		if(!used[lca]) {p[c[lca]]++,used[lca]=true;if(p[c[lca]]==1) ans++;}
		else {p[c[lca]]--,used[lca]=false;if(p[c[lca]]==0) ans--;}
		con[Q[i].sub]=ans;
		if(p[Q[i].a]!=0&&p[Q[i].b]!=0&&Q[i].a!=Q[i].b) con[Q[i].sub]--;
		if(!used[lca]) {p[c[lca]]++,used[lca]=true;if(p[c[lca]]==1) ans++;}
		else {p[c[lca]]--,used[lca]=false;if(p[c[lca]]==0) ans--;}
		//if(i%1000==0)
			//fprintf(stderr,"%.6f\n",(double)clock()/CLOCKS_PER_SEC);
	}
	//for(int i=1;i<=m;i++) printf("%d\n",con[i]);
	//for(int i=1;i<=n;i++) printf("%d\n",dfn[i]);
	//fprintf(stderr,"%.6f\n%d %d\n",(double)clock()/CLOCKS_PER_SEC,m,cNt);
	return 0;
}

#include<cstdio>
#include<cstring>
#include<algorithm>
#define fir first
#define sec second
#define MP(a,b) make_pair(a,b)
using namespace std;

const int N=30010,M=N*2,INF=~0U>>1;
typedef pair<int,int> pii;

int head[N],next[M],en[M],tot;
void add(int u,int v) {
	en[++tot]=v;
	next[tot]=head[u];
	head[u]=tot;
}

int sz[N],fa[N],son[N],dep[N];
void dfs(int u) {
	sz[u]=1;
	son[u]=0;
	for(int k=head[u];k;k=next[k]) {
		int v=en[k];
		if(v==fa[u])continue;
		fa[v]=u;
		dep[v]=dep[u]+1;
		dfs(v);
		sz[u]+=sz[v];
		if(sz[son[u]]<sz[v])son[u]=v;
	}
}

int pos[N],root[N],top[N],len[N];
void build_tree(int u,int pre) {
	top[u]=pre;
	pos[u]=++len[pre];
	if(son[u])build_tree(son[u],pre);
	for(int k=head[u];k;k=next[k]) {
		int v=en[k];
		if(v==fa[u]||v==son[u])continue;
		build_tree(v,v);
	}
}

int sum[N*2],maxn[N*2],lc[N*2],rc[N*2],lft,rgt,w,idx;

void up(int s) {
	sum[s]=sum[lc[s]]+sum[rc[s]];
	maxn[s]=max(maxn[lc[s]],maxn[rc[s]]);
}

void change(int& s,int l,int r) {
	if(!s) {
		s=++idx;
		lc[s]=rc[s]=0;
	}
	if(l==r&&l==lft) {
		sum[s]=maxn[s]=w;
		return;
	}
	int mid=(l+r)>>1;
	if(lft<=mid)change(lc[s],l,mid);
	else change(rc[s],mid+1,r);
	up(s);
}

pii ask(int s,int l,int r) {
	if(lft<=l&&r<=rgt)return MP(sum[s],maxn[s]);
	int mid=(l+r)>>1;
	if(rgt<=mid)return ask(lc[s],l,mid);
	if(lft>mid)return ask(rc[s],mid+1,r);
	pii t1=ask(lc[s],l,mid);
	pii t2=ask(rc[s],mid+1,r);
	return MP(t1.fir+t2.fir,max(t1.sec,t2.sec));
}

pii query(int a,int b) {
	int _sum=0,_max=-INF,ta=top[a],tb=top[b];
	while(ta!=tb) {
		if(dep[ta]<dep[tb])swap(a,b),swap(ta,tb);
		lft=pos[ta],rgt=pos[a];
		pii res=ask(root[ta],1,len[ta]);
		_sum+=res.fir,_max=max(_max,res.sec);
		a=fa[ta];
		ta=top[a];
	}
	if(dep[a]>dep[b])swap(a,b);
	lft=pos[a],rgt=pos[b];
	pii res=ask(root[ta],1,len[ta]);
	_sum+=res.fir,_max=max(_max,res.sec);
	return MP(_sum,_max);
}

int main() {
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1);
	build_tree(1,1);
	for(int i=1;i<=n;i++) {
		lft=pos[i];
		scanf("%d",&w);
		change(root[top[i]],1,len[top[i]]);
	}
	scanf("%d",&m);
	while(m--) {
		int a,b;
		char cmd[10];
		scanf("%s%d%d",cmd,&a,&b);
		if(cmd[0]=='C')lft=pos[a],w=b,change(root[top[a]],1,len[top[a]]);
		else if(cmd[1]=='S')printf("%d\n",query(a,b).fir);
		else printf("%d\n",query(a,b).sec);
	}
	return 0;
}

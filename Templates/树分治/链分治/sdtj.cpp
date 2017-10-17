#include<cstdio>
#include<cstring>
#include<algorithm>
#define fir first
#define sec second
#define MP(a,b) make_pair(a,b)
using namespace std;

const int N=30010,M=N*2,INF=~0U>>1;
typedef pair<int,int> pii;
int n,m;

int head[N],next[M],en[M],tot;
void add(int u,int v) {
	en[++tot]=v;
	next[tot]=head[u];
	head[u]=tot;
}

struct SegmentTree {
	int _max[N*4],_sum[N*4],lft,rgt,w;
	void up(int s) {
		int lc=s<<1,rc=s<<1|1;
		_sum[s]=_sum[lc]+_sum[rc];
		_max[s]=max(_max[lc],_max[rc]);
	}
	void change(int s,int l,int r) {
		if(l==r&&l==lft) {
			_sum[s]=_max[s]=w;
			return;
		}
		int mid=(l+r)>>1;
		if(lft<=mid)change(s<<1,l,mid);
		else change(s<<1|1,mid+1,r);
		up(s);
	}
	pii ask(int s,int l,int r) {
		if(lft<=l&&r<=rgt)return MP(_sum[s],_max[s]);
		int mid=(l+r)>>1;
		if(rgt<=mid)return ask(s<<1,l,mid);
		if(lft>mid)return ask(s<<1|1,mid+1,r);
		pii t1=ask(s<<1,l,mid);
		pii t2=ask(s<<1|1,mid+1,r);
		return MP(t1.fir+t2.fir,max(t1.sec,t2.sec));
	}
}seg;

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

int pos[N],top[N],tm;
void build(int u,int pre) {
	top[u]=pre;
	pos[u]=++tm;
	if(son[u])build(son[u],pre);
	for(int k=head[u];k;k=next[k]) {
		int v=en[k];
		if(v==fa[u]||v==son[u])continue;
		build(v,v);
	}
}

pii query(int a,int b) {
	int _sum=0,_max=-INF,ta=top[a],tb=top[b];
	while(ta!=tb) {
		if(dep[ta]<dep[tb])swap(a,b),swap(ta,tb);
		seg.lft=pos[ta],seg.rgt=pos[a];
		pii res=seg.ask(1,1,n);
		_sum+=res.fir,_max=max(_max,res.sec);
		a=fa[ta];
		ta=top[a];
	}
	if(dep[a]>dep[b])swap(a,b);
	seg.lft=pos[a],seg.rgt=pos[b];
	pii res=seg.ask(1,1,n);
	_sum+=res.fir,_max=max(_max,res.sec);
	return MP(_sum,_max);
}

int main() {
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1);
	build(1,1);
	for(int i=1;i<=n;i++) {
		seg.lft=pos[i];
		scanf("%d",&seg.w);
		seg.change(1,1,n);
	}
	scanf("%d",&m);
	while(m--) {
		char cmd[10];
		int a,b;
		scanf("%s%d%d",cmd,&a,&b);
		if(cmd[0]=='C')seg.lft=pos[a],seg.w=b,seg.change(1,1,n);
		else if(cmd[1]=='S')printf("%d\n",query(a,b).fir);
		else printf("%d\n",query(a,b).sec);
	}
	return 0;
}

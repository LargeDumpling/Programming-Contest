#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<map>

using namespace std;

//default source begin==========
const int D=30000000;
char in[D],out[300010*10],*I=in+D,*O=out;

char gc() {
	if(I==in+D) fread(in,1,D,stdin),I=in;
	return *(I++);
}
#define gc gc()
#define pc(x) ((*O++)=x)
#define tQ template <typename Q>
tQ void gt(Q&x) {
	static char c,f;
	for(f=0;c=gc,!isdigit(c);)if(c=='-') f=1;
	for(x=0;isdigit(c);c=gc) x=x*10+c-'0';
	f && (x=-x);
}
tQ void pt(Q x){
	static char stk[20];
	static int top;
	top=0;
	if(x==0) pc('0');
	for(;x;x/=10) stk[++top] = x%10+'0';
	for(;top;top--) pc(stk[top]);
}
//default source end=============

const int Maxn=100100,Maxm=1000010,Maxq=100010;
int n,m,Q;

int ch[Maxn+Maxm][2],p[Maxn+Maxm],flip[Maxn+Maxm],mx[Maxn+Maxm],w[Maxn+Maxm];
map<pair<int,int> ,struct Edge*> hash;
int ddb[Maxn+Maxm];
typedef long long ll;
/*
const unsigned int Hmod=1e6+7;
struct Node{
	ll hs;
	int id;
	Node*next;
	Node(ll hs=0,int id=0,Node*next=0):hs(hs),id(id),next(next){}
}da[Maxm],*fir[Hmod];

int find(ll x){
	unsigned md=x%Hmod;
	for(Node*p=fir[md];p;p=p->next){
		if(p->hs==x) return p->id;
	}
	return NULL;
}

int insert(ll x){
	unsigned md=x%Hmod;
*/	

#define l ch[x][0]
#define r ch[x][1]
void update(int x){
	if(!x) return;
	mx[x]=x;
	if(w[mx[l]]>w[mx[x]]) mx[x]=mx[l];
	if(w[mx[r]]>w[mx[x]]) mx[x]=mx[r];
}
void down(int x) {
	if(!x || !flip[x]) return;
	swap(l,r);
	flip[l]^=1;
	flip[r]^=1;
	flip[x]=0;
}
#undef l
#undef r
inline bool isroot(int x) {
	return ch[p[x]][0]!=x && ch[p[x]][1]!=x;
}
inline void rotate(int x){
	int y=p[x],z=p[y];
	int l=ch[y][1]==x,r=l^1;
	if(!isroot(y)){
		ch[z][ch[z][1]==y]=x;
	}
	p[y]=x;
	p[ch[x][r]]=y;
	p[x]=z;
	
	ch[y][l]=ch[x][r];
	ch[x][r]=y;
	
	update(y);
//	update(x);
}

int stk[Maxn],top;
inline void splay(int x){
	stk[top=1]=x;
	for(int t=x;!isroot(t);stk[++top]=t=p[t]);
	for(;top;top--) down(stk[top]);
	for(;!isroot(x);){
		int y=p[x],z=p[y];
		if(!isroot(y)) {
			if( (ch[y][0]==x) ^ (ch[z][0]==y)) rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
	update(x);
}

inline void access(int x) {
	for(int t=0;x;x=p[t=x]){
		splay(x);
		ch[x][1]=t;
		update(x);
	}
}

inline void newroot(int x) {
	access(x);
	splay(x);
	flip[x]^=1;
}

inline void n_as(int u,int v){
	newroot(u);
	access(v);
	splay(v);
}

inline void Cut(int x,int y) {
	n_as(x,y);
	ch[y][0]=p[x]=0;
	update(x);
}

inline void Link(int x,int y) {
	newroot(x);
	p[x]=y;
}

struct Edge{
	int u,v,w,id;
	bool deled;
	void read() {
		gt(u);gt(v);gt(w);
		if(u>v) swap(u,v);
	}
	bool operator<(const Edge&rhs)const {
		return u<rhs.u || (u==rhs.u&&v<rhs.v);
	}
	bool operator == (const Edge&rhs)const {
		return u==rhs.u && v==rhs.v;
	}
	bool operator <= (const Edge&rhs)const {
		return *this<rhs || *this==rhs;
	}
	Edge(int u=0,int v=0):u(u),v(v){}
}e[Maxm];

bool cmpw(const Edge&lhs,const Edge&rhs) {
	return lhs.w<rhs.w;
}

struct Que{
	int k,u,v;
	Que (int k=0,int u=0,int v=0):k(k),u(u),v(v){}
}que[Maxq];

int bs(const Edge&target) {
	int l=1,r=m,res=-1;
	for(int mid;l<=r;) {
		mid=(l+r)>>1;
		if(e[mid]<=target) res=mid,l=mid+1;
		else r=mid-1;
	}
	if(res==-1) exit(-1);
	return res;
}

int fa[Maxn];
int Find(int x){
	return fa[x]==x?x:fa[x]=Find(fa[x]);
}
bool Union(int x,int y) {
	x=Find(x),y=Find(y);
	if(x==y) return 0;
	return fa[x]=y,1;
}
void ufs_init(int n) {
	for(int i=0;i<=n;i++) fa[i]=i;
}
void AddEdge(int i) {
	const int&u=e[i].u,&v=e[i].v;
	if(Union(u,v)) Link(u,i+n),Link(v,i+n);
	else {
		n_as(u,v);int t=mx[v];
		if(w[t] > e[i].w) {
//			Cut(e[t-n].u,t);
			Cut(e[t-n].v,t);
			Link(u,i+n);
			Link(v,i+n);
		}
	}
}

bool cmpid(const Edge&lhs,const Edge&rhs){
	return lhs.id<rhs.id;
}

void init() {
	gt(n),gt(m),gt(Q);
	for(int i=1;i<=m;i++) e[i].read();
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++) e[i].id=i,w[i+n]=e[i].w;
	for(int k,u,v,i=1;i<=Q;i++) {
		gt(k),gt(u),gt(v);
		if(u>v) swap(u,v);
		que[i]=Que(k,u,v);
		if(k==2) e[bs(Edge(u,v))].deled=1;
	}
}

void Kruskal() {
	sort(e+1,e+m+1,cmpw);
	ufs_init(n);
	for(int i=1,MST=0;i<=m;i++) {
		if(e[i].deled) continue;
		if(!Union(e[i].u,e[i].v)) continue;
		Link(e[i].u,e[i].id+n);
		Link(e[i].v,e[i].id+n);
		if(++MST==n-1) break;
	}
}

int ans[Maxq],tq=0;
void work() {
	Kruskal();
	sort(e+1,e+m+1);
	for(int i=Q;i;i--) {
		const Que&q=que[i];
		if(q.k==1) {
			n_as(q.u,q.v);
			ans[++tq] = w[mx[q.v]];
		}else {
			AddEdge(bs(Edge(q.u,q.v)));
		}
	}
	for(int i=tq;i;i--) pt(ans[i]),pc('\n');
}

int main() {
#ifdef DEBUG
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	
	init();
	work();
	
	return printf(out),0;
}

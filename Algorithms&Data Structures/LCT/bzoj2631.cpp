#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>

using namespace std;

const int D=15000000;
char in[D],out[100010*10],*I=in,*O=out;
#define gc (*I++)
#define pc(x) ((*O++)=x)
template <typename Q> 
void gt(Q&x) {
	static char c,f;
	for(c=gc,f=0;!isdigit(c);c=gc)if(c=='-') f=1;
	for(x=0;isdigit(c);c=gc) x=x*10+c-'0';
	f && (x=-x);
}
template <typename Q>
void pt(Q x){
	static char stk[20];
	static int top;
	top=0;
	if(x==0) pc('0');
	for(;x;x/=10) stk[++top] = x%10+'0';
	for(;top;top--) pc(stk[top]);
}

typedef unsigned ll;
const int Maxn=100010,Mod=51061;
int n,m;
ll w[Maxn],tagm[Maxn],taga[Maxn],sz[Maxn];
int ch[Maxn][2],p[Maxn],flip[Maxn],sum[Maxn];

void update(int x){
	if(x==0) return;
	int&l=ch[x][0],&r=ch[x][1];
	sum[x] = (sum[l] + sum[r] + w[x])%Mod;
	sz[x] = (sz[l] + sz[r] + 1)%Mod;
}

template <typename Q>
void addit(Q&x,const Q&y){
	x+=y;
	if(x>=Mod) x-=Mod;
}

void add_tag(int x,ll a,ll m){
	if(!x) return;
	sum[x] = (sum[x]*m+a*sz[x])%Mod;
	w[x] = (w[x]*m+a)%Mod;
	tagm[x] = tagm[x]*m%Mod;
	taga[x] = (taga[x]*m+a)%Mod;
}

/*void tag_mul(int x,ll _v) {
	(sum[x]*=_v)%=Mod;
	(w[x]*=_v)%=Mod;
	(tagm[x]*=_v)%=Mod;
	(taga[x]*=_v)%=Mod;
}

void tag_add(int x,ll _v) {
	(sum[x]+=(sz[x]*_v)%Mod)%=Mod;
	(w[x]+=_v)%=Mod;
	(taga[x]+=_v)%=Mod;
}*/

bool isroot(int x) {
	return ch[p[x]][0]!=x && ch[p[x]][1]!=x;
}

void down(int x) {
	int &l=ch[x][0],&r=ch[x][1];
	if(flip[x]) {
		swap(l,r);
		flip[l]^=1;
		flip[r]^=1;
		flip[x]=0;
	}
	/*if(tagm[x]!=1) {
		for(int i=0;i<2;i++)if(ch[x][i])tag_mul(ch[x][i],tagm[x]);
		tagm[x]=1;
	}
	if(taga[x]!=0) {
		for(int i=0;i<2;i++)if(ch[x][i])tag_add(ch[x][i],taga[x]);
		taga[x]=0;
	}*/
	ll&a=taga[x],&m=tagm[x];
	if(a!=0 || m!=1) {
		add_tag(l,a,m);
		add_tag(r,a,m);
		a=0;m=1;
	}
}

void rotate(int x){
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
void splay(int x){
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

void access(int x) {
	for(int t=0;x;x=p[t=x]){
		splay(x);
		ch[x][1]=t;
		update(x);
	}
}

void newroot(int x) {
	access(x);
	splay(x);
	flip[x]^=1;
}

inline void n_as(int u,int v){
	newroot(u);
	access(v);
	splay(v);
}

void Cut(int x,int y) {
	n_as(x,y);
	ch[y][0]=p[x]=0;
	update(y);
}

void Link(int x,int y) {
	newroot(x);
	p[x]=y;
}

int en[Maxn*2],next[Maxn*2],fir[Maxn];
void Add(int from,int to) {
	static int tot=0;
	en[++tot]=to;
	next[tot]=fir[from];
	fir[from]=tot;
}

void BFS(int u) {
	int *q=stk,ql=0,qr=0;
	q[++qr]=u;
	for(int x;ql<qr;){
		x=q[++ql];
		for(int k=fir[x];k;k=next[k]){
			int v=en[k];
			if(v==p[x]) continue;
			p[v]=x;
			q[++qr]=v;
		}
	}
}
		
void init(){
	gt(n),gt(m);
	for(int u,v,i=1;i<n;i++) {
		gt(u),gt(v);
		Add(u,v),Add(v,u);
//		Link(u,v);
	}
	BFS(1);
	tagm[0]=1;
	for(int i=1;i<=n;i++) sz[i]=sum[i]=tagm[i]=w[i]=1;
}

void work() {
	char c;
	ll u,v,d;
	/*printf("round%d:\n",0);
		for(int i=1;i<=n;i++) {
			printf("%d :p=%d,ch=(%d,%d),w=%d,taga=%d,tagm=%d\n",i,p[i],ch[i][0],ch[i][1],w[i],taga[i],tagm[i]);
		}*/
	for(int i=1;i<=m;i++) {
		for(;;) {
			c=gc;
			if(c=='+') {
				gt(u),gt(v),gt(d);
				n_as(u,v);
//				tag_add(v,d);
				add_tag(v,d,1);
				break;
			}if(c=='-') {
				gt(u),gt(v);
				Cut(u,v);
				gt(u),gt(v);
				Link(u,v);
				break;
			}if(c=='*') {
				gt(u),gt(v),gt(d);
				n_as(u,v);
				add_tag(v,0,d);
//				tag_mul(v,d);
				break;
			}if(c=='/'){
				gt(u),gt(v);
				n_as(u,v);
				pt(sum[v]);
				pc('\n');
				break;
			}
		}
		/*printf("round%d:\n",i);
		for(int i=1;i<=n;i++) {
			printf("%d :p=%d,ch=(%d,%d),w=%d,taga=%d,tagm=%d,sum=%d\n",i,p[i],ch[i][0],ch[i][1],w[i],taga[i],tagm[i],sum[i]);
		}*/
	}
}

int main() {
#ifdef DEBUG
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
#endif
	fread(in,1,D,stdin);
	
	init();
	work();
	
	return printf(out),0;
}


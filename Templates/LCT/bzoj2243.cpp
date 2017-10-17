#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
using namespace std;

const int Maxn = 100010;

int ch[Maxn][2],p[Maxn],sz[Maxn],flip[Maxn],tag[Maxn];
int col[Maxn];
int n,m;

const int D=15000000;
char in[D],out[300010*10],*I=in,*O=out;
#define gc (*I++)
#define pc(x) ((*O++)=x)
template <typename Q> 
void gt(Q&x) {
	static char c,f;
	for(c=gc,f=0;!isdigit(c);c=gc)if(c=='-') f=1;
	for(x=0;isdigit(c);c=gc) x=x*10+c-'0';
	f && (x=-x);
}

struct Data {
	int l,r,num;
	Data(int l=-1,int r=-1,int num=0):l(l),r(r),num(num) {}
	Data operator + (const Data& rhs) const {
		if(!num) return rhs;
		if(!rhs.num) return *this;
		return Data (l,rhs.r,num+rhs.num-(r==rhs.l));
	}
	void flip() {
		swap(l,r);
	}
}da[Maxn];

template <typename Q>
void pt(Q x){
	static char stk[20];
	static int top;
	top=0;
	if(x==0) pc('0');
	for(;x;x/=10) stk[++top] = x%10+'0';
	for(;top;top--) pc(stk[top]);
}

int fir[Maxn],next[Maxn*2],en[Maxn*2];
void Add(int from,int to) {
	static int tot=0;
	en[++tot]=to;
	next[tot]=fir[from];
	fir[from]=tot;
}

void add_tag(int x,int Col) {
	if(x==0) return;
	col[x] = tag[x] = Col;
	da[x] = Data(Col,Col,1);
}

void down(int x) {
	if(flip[x]) {
		swap(ch[x][0],ch[x][1]);
		flip[ch[x][0]]^=1; da[ch[x][0]].flip();
		flip[ch[x][1]]^=1; da[ch[x][1]].flip();
		flip[x]=0;
	}
	if(tag[x]!=-1) {
		add_tag(ch[x][0],tag[x]);
		add_tag(ch[x][1],tag[x]);
		tag[x]=-1;
	}
}

bool isroot(int x){
	return ch[p[x]][0]!=x && ch[p[x]][1]!=x;
}

void update(int x) {
	if(x==0) return;
	sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
	da[x]=da[ch[x][0]]+Data(col[x],col[x],1)+da[ch[x][1]];
}

void rotate(int x) {
	int y=p[x],z=p[y];
	int l=ch[y][1]==x,r=l^1;
	if(!isroot(y)) ch[z][ch[z][1]==y]=x;
	p[ch[x][r]]=y;
	p[y]=x;
	p[x]=z;
	
	ch[y][l]=ch[x][r];
	ch[x][r]=y;
	
	update(y);
	update(x);
}

void splay(int x){
	static int stk[Maxn],top;
	stk[top=1]=x;
	for(int t=x;!isroot(t);t=p[t]) stk[++top] = p[t];
	for(;top;top--) down(stk[top]);
	for(;!isroot(x);){
		int y=p[x],z=p[y];
		if(!isroot(y)){
			if( (ch[y][1]==x)^(ch[z][1]==y) )
				rotate(x);else rotate(y);
		}
		rotate(x);
	}
}

void access(int x){
	for(int t=0;x;x=p[t=x]){
		splay(x);
		ch[x][1]=t;
		update(x);
	}
}

int getroot(int x){
	for(access(x),splay(x);ch[x][0];x=ch[x][0]);
	return x;
}

void cut(int x){
	access(x);
	splay(x);
	p[ch[x][0]]=0;
	ch[x][0]=0;
	update(x);	
}

void combine(int x,int y) {
	cut(x);
	p[x]=y;
	update(y);
}

void newroot(int x){
	access(x);
	splay(x);
	flip[x]^=1;
	da[x].flip();
}

void dfs(int x) {
	for(int k=fir[x];k;k=next[k]) {
		int v=en[k];
		if(v==p[x]) continue;
		p[v]=x;
		dfs(v);
	}
}

void init(){
	gt(n);gt(m);
	memset(tag,-1,sizeof(*tag)*(n+1));
	for(int i=1;i<=n;i++) {
		gt(col[i]);
		sz[i]=1;
		da[i] = Data( col[i],col[i],1);
	}
	for(int u,v,i=1;i<n;i++) {
		gt(u),gt(v);
		Add(u,v);
		Add(v,u);
	}
	dfs(1);
}

void work() {
	char cmd;
	int a,b,c;
	for(int i=1;i<=m;i++) {
		for(cmd=gc;cmd!='C' && cmd!='Q';cmd=gc);
		gt(a);gt(b);
		newroot(a);
		access(b);
		splay(b);
		if(cmd=='C') {
			gt(c);
			add_tag(b,c);
		}else {
			pt(da[b].num);
			pc('\n');
		}
	}
}
int main() {
#ifdef DEBUG
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
#endif
	fread(in,1,D,stdin);

	init();
	work();
	
	return printf(out),0;
}


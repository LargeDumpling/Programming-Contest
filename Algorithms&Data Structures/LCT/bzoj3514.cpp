#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cctype>

using namespace std;

const int Maxn=200020;
const int logn=21;

int a[Maxn],b[Maxn],ntr[Maxn];
int n,m,k,type;

template<typename Q> void gt(Q&x) {
	static char c;
	static bool f;
	for(f=0;c=getchar(),!isdigit(c);) if(c=='-') f=1;
	for(x=0;isdigit(c);c=getchar()) x=x*10+c-'0';
	f && (x=-x);
}

struct PST {
	int seq[Maxn];
	
	struct Node{
		Node *l,*r;
		int sz;
	}pool[Maxn*logn],*pis,*root[Maxn],*null;
	
	void build(Node*&o,Node *p,int l,int r,int rk) {
		o=pis++;
		*o=*p;
		o->sz++;
		if(l==r) return;
		int mid=(l+r)>>1;
		if(rk<=mid) build(o->l,p->l,l,mid,rk);
		else build(o->r,p->r,mid+1,r,rk);
	}
	
	void init() {
		pis=pool;
		memcpy(seq,ntr,sizeof seq);
		sort(seq+1,seq+m+1);
		null=pis++;
		null->l=null->r=null;
		null->sz=0;
		root[0]=null;
		for(int i=1;i<=m;i++) {
			build(root[i],root[i-1],1,m+2,ntr[i]);
		}
	}
	
	int query(Node*L,Node*R,int l,int r,int lft,int rgt) {
		if(lft<=l && r<=rgt) return R->sz - L->sz;
		int mid=(l+r)>>1;
		int ans=0;
		if(lft<=mid) ans+=query(L->l,R->l,l,mid,lft,rgt);
		if(mid<rgt) ans+=query(L->r,R->r,mid+1,r,lft,rgt);
		return ans;
	}
	
	int query(int l,int r,int x) {
		return query(root[l-1],root[r],1,m+2,1,x);
	}
}pst;

int ch[Maxn*2][2],w[Maxn*2],mn[Maxn*2],p[Maxn*2],flip[Maxn*2];

#define l ch[x][0]
#define r ch[x][1]
void update(int x) {
	mn[x]=x;
	if(w[mn[l]]<w[mn[x]]) mn[x]=mn[l];
	if(w[mn[r]]<w[mn[x]]) mn[x]=mn[r];
}

void down(int x) {
	if(flip[x]) {
		swap(l,r);
		flip[l]^=1;
		flip[r]^=1;
		flip[x]^=1;
	}
}
#undef l
#undef r

bool isroot(int x) {
	return ch[p[x]][0]!=x && ch[p[x]][1]!=x;
}

void rotate(int x) {
	int y=p[x],z=p[y];
	if(!isroot(y)) ch[z][ch[z][1]==y]=x;
	int l=ch[y][1]==x,r=l^1;
	p[x]=z;
	p[y]=x;
	p[ch[x][r]]=y;
	
	ch[y][l]=ch[x][r];
	ch[x][r]=y;
	
	update(y);
//	update(x);
}

void splay(int x) {
	static int stk[Maxn],top;
	stk[top=1]=x;
	for(int t=x;!isroot(t);t=p[t]) stk[++top]=p[t];
	while(top) down(stk[top--]);
	
	for(;!isroot(x);) {
		int y=p[x],z=p[y];
		if(!isroot(y)) {
			if( (ch[y][0]==x)^(ch[z][0]==y) )rotate(x);
			rotate(y);
		}
		rotate(x);
	}
	update(x);
}

void access(int x) {
	for(int t=0;x;x=p[t=x]) {
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

void Link(int x,int y) {
	newroot(x);
	p[x]=y;
}

void Cut(int x,int y) {
	newroot(y);
	access(x);
	splay(x);
	if(ch[x][0]==y) {
		ch[x][0]=0;
		p[y]=0;
		update(x);
	}
}

int getroot(int x) {
	for(access(x),splay(x);ch[x][0];x=ch[x][0]);
	return x;
}

const int INF=0x3f3f3f3f;

void init() {
	scanf("%d%d%d%d",&n,&m,&k,&type);
	for(int i=0;i<=n;i++) {
		w[i]=INF;
		mn[i]=i;
	}
	for(int x,y,i=1;i<=m;i++) {
//		scanf("%d%d",a+i,b+i);
		gt(a[i]),gt(b[i]);
		x=a[i],y=b[i];
		if(x==y) {
			ntr[i]=i;
			continue;
		}
		if(getroot(x)==getroot(y)) {
			newroot(y);
			access(x);
			splay(x);
			int t=mn[x];
			ntr[i]=w[t];
			Cut(t,a[w[t]]);
//			Cut(t,b[w[t]]);
		}
		mn[i+n]=i+n;
		w[i+n]=i;
		Link(x,i+n);
		Link(y,i+n);
	}
	for(int i=1;i<=m;i++) ntr[i]+=2;
	pst.init();
}

void work() {
	for(int l,r,last_ans=0;k--;) {
//		scanf("%d%d",&l,&r);
		gt(l),gt(r);
		if(type) l^=last_ans,r^=last_ans;
		
		last_ans=n-pst.query(l,r,l+1);
		printf("%d\n",last_ans);
	}
}

void PST_test() {
	scanf("%d",&m);
	for(int i=1;i<=m;i++) {
		scanf("%d",ntr+i);
	}
	for(int i=1;i<=m;i++) ntr[i]+=2;
	pst.init();
	for(scanf("%d",&k);k--;) {
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);w++;
		printf("%d\n",pst.query(x,y,w));
	}
}

int main() {
#ifdef DEBUG
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
#endif
	
//	PST_test();return 0;
	
	init();
	work();
	
	return 0;
}


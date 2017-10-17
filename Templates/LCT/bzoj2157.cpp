#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>

using namespace std;

const int Maxn=200010;

int ch[Maxn][2],w[Maxn],sum[Maxn],mn[Maxn],mx[Maxn],p[Maxn];
bool flip[Maxn],rev[Maxn];

bool isroot(int x) {
	return ch[p[x]][0]!=x && ch[p[x]][1]!=x;
}

#define l ch[x][0]
#define r ch[x][1]
int n;

void update(int x) {
	if(!x) return;
	sum[x] = w[x] + sum[l] + sum[r];
	mn[x] = min(mn[l],mn[r]);
	mx[x] = max(mx[l],mx[r]);
	if(x>n) mn[x]=min(mn[x],w[x]),
			mx[x]=max(mx[x],w[x]);
}

void rever(int x) {
	sum[x]*=-1;
	w[x]*=-1;
	swap(mn[x],mx[x]);
	mn[x]*=-1;
	mx[x]*=-1;
	rev[x]^=1;
}

void down(int x) {
	if(!x) return;
	if(flip[x]) {
		swap(l,r);
		flip[l]^=1;
		flip[r]^=1;
		flip[x]^=1;
	}
	if(rev[x]) {
		rev[x] = 0;
		if(l) rever(l);
		if(r) rever(r);
	}
}


#undef l
#undef r

void rotate(int x) {
	int y=p[x],z=p[y];
	if(!isroot(y)) ch[z][ch[z][1]==y] = x;
	int l=ch[y][1]==x,r=l^1;
	p[x]=z;
	p[y]=x;
	p[ch[x][r]]=y;
	
	ch[y][l]=ch[x][r];
	ch[x][r]=y;
	
	update(y);
	update(x);
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
}

void access(int x) {
	for(int t=0;x;x=p[t=x]) {
		splay(x);
		ch[x][1]=t;
		update(x);
	}
}

int getroot(int x) {
	for(access(x),splay(x);ch[x][0];x=ch[x][0]);
	return x;
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

int m;
const int INF=int(1e9);
void init() {
	scanf("%d",&n);
	int u,v,W;
	for(int i=0;i<=n;i++){
		mn[i]=INF,mx[i]=-INF;
	}
	for(int i=1;i<n;i++) {
		scanf("%d%d%d",&u,&v,&W);u++,v++;
		w[i+n]=W;
		Link(u,i+n),Link(v,i+n);
	}
}

void work() {
	char opt[100];
	int x,y;
	for(scanf("%d",&m);m--;) {
		scanf("%s%d%d",opt,&x,&y);
		if(opt[0]=='C') {
			access(x+n);
			splay(x+n);
			w[x+n]=y;
			update(x+n);
		}else if(opt[0]=='N') {
			x++,y++;
			newroot(x);
			access(y);
			splay(y);
			rever(y);
		}else if(opt[0]=='S') {
			x++,y++;
			newroot(x);
			access(y);
			splay(y);
			printf("%d\n",sum[y]);
		}else if(opt[0]=='M'&&opt[1]=='A') {
			x++,y++;
			newroot(x);
			access(y);
			splay(y);
			printf("%d\n",mx[y]);
		}else /*if(opt[0]==e)*/ {
			x++,y++;
			newroot(x);
			access(y);
			splay(y);
			printf("%d\n",mn[y]);
		}
	}
}

int main() {
#ifdef DEBUG
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	
	init();
	work();
	
	return 0;
}


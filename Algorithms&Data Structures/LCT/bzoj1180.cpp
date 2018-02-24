#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>

using namespace std;

const int Maxn=30010;

int ch[Maxn][2],w[Maxn],sum[Maxn],p[Maxn];
bool flip[Maxn];

bool isroot(int x) {
	return ch[p[x]][0]!=x && ch[p[x]][1]!=x;
}

#define l ch[x][0]
#define r ch[x][1]

void update(int x) {
	if(!x) return;
	sum[x] = w[x] + sum[l] + sum[r];
}

void down(int x) {
	if(!x) return;
	if(flip[x]) {
		swap(l,r);
		flip[l]^=1;
		flip[r]^=1;
		flip[x]^=1;
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

int n,m;

void init() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",w+i);
		sum[i]=w[i];
	}
}

void work() {
	char opt[100];
	int x,y;
	for(scanf("%d",&m);m--;) {
		scanf("%s%d%d",opt,&x,&y);
		if(opt[0]=='b') {
			if(getroot(x)==getroot(y)) puts("no");
			else Link(x,y),puts("yes");
		}else if(opt[0]=='p') {
			access(x);
			splay(x);
			w[x]=y;
			update(x);
		}else /*if(opt[0]==e)*/ {
			if(getroot(x)!=getroot(y)) puts("impossible");
			else {
				newroot(x);
				access(y);
				splay(y);
				printf("%d\n",sum[y]);
			}
		}
	}
}

int main() {
#ifdef DEBUG
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
#endif
	
	init();
	work();
	
	return 0;
}


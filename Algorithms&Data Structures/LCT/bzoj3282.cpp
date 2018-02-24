#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>

using namespace std;

const int Maxn=300000+10;

int ch[Maxn][2],v[Maxn],s[Maxn],p[Maxn];
bool flip[Maxn];

#define l ch[x][0]
#define r ch[x][1]
void update(int x) {
	s[x]=s[l]^v[x]^s[r];
}

void down(int x) {
	if(!flip[x]) return;
	swap(l,r);
	flip[l]^=1;
	flip[r]^=1;
	flip[x]=0;
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
			if( (ch[y][1]==x)^(ch[z][1]==y) ) rotate(x);
			else rotate(y);
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

void Cut(int x) {
	access(x);
	splay(x);
	ch[p[x]][0]=0;
	p[x]=0;
}

void Cut(int x,int y) {
	newroot(y);
	access(x);
	splay(x);
	if(ch[x][0]==y) p[y]=0,ch[x][0]=0;
}

void Link(int x,int y) {
	newroot(x);
	p[x]=y;
}

int n,m;
void init() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d",v+i);
		s[i]=v[i];
	}
}

void work() {
	for(int opt,x,y;m--;) {
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==0) {
			newroot(y);
			access(x);
			splay(x);
			printf("%d\n",s[x]);
		}else if(opt==1) {
			if(getroot(x)!=getroot(y)) Link(x,y);
		}else if(opt==2) {
			if(getroot(x)==getroot(y)) Cut(x,y);
		}else /*if(opt==3)*/ {
			access(x);
			splay(x);
			v[x]=y;
			update(x);
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


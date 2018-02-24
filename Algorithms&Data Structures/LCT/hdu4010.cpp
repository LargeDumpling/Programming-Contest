#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>

using namespace std;

const int Maxn=300010;

int ch[Maxn][2],w[Maxn],tag[Maxn],flip[Maxn],mx[Maxn];

#define l ch[x][0]
#define r ch[x][1]
void update(int x) {
	mx[x] = max(max(mx[l],mx[r]) ,w[x]);
}

void add_tag(int x,int d) {
	if(!x) return;
	tag[x] += d;
	w[x] += d;
	mx[x] += d;
}

void down(int x) {
	if(flip[x]) {
		swap(l,r);
		flip[l]^=1;
		flip[r]^=1;
		flip[x]^=1;
	}
	if(tag[x]) {
		if(l)add_tag(l,tag[x]);
		if(r)add_tag(r,tag[x]);
		tag[x]=0;
	}
//	update(x);
}

#undef l
#undef r

int p[Maxn];
bool isroot(int x) {
	return ch[p[x]][0]!=x && ch[p[x]][1]!=x;
}

void rotate(int x) {
	int y=p[x],z=p[y];
	if(!isroot(y)) ch[z][ch[z][1]==y] = x;
	int l=ch[y][1]==x,r=l^1;

	p[ch[x][r]]=y;
	p[x]=z;
	p[y]=x;

	ch[y][l]=ch[x][r];
	ch[x][r]=y;
	update(y);
	update(x);
}

void splay(int x) {
	static int stk[Maxn],top;
	stk[top=1]=x;
	for(int t=x; !isroot(t); t=p[t]) stk[++top] = p[t];
	while(top) down(stk[top--]);

	for(; !isroot(x);) {
		int y=p[x],z=p[y];
		if(!isroot(y)) {
			if( (ch[y][0]==x)^(ch[z][0]==y) ) rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
}

void access(int x) {
	for(int t=0; x; x=p[t=x]) {
		splay(x);
		ch[x][1]=t;
		update(x);
	}
}

int getroot(int x) {
	for(access(x),splay(x); ch[x][0]; x=ch[x][0]);
	return x;
}

void newroot(int x) {
	access(x);
	splay(x);
	flip[x]^=1;
}

void Cut(int x,int y) {
	newroot(x);
	access(y);
	splay(y);
	p[ch[y][0]]=0;
	ch[y][0]=0;
	update(y);
}

void Link(int x,int y) {
	newroot(x);
	p[x]=y;
}

bool init() {
	int n;
	if(scanf("%d",&n)==-1) return 0;
	
	for(int i=0; i<=n; i++) {
		p[i]=ch[i][0]=ch[i][1]=tag[i]=flip[i]=0;
	}
	mx[0]=-0x3f3f3f3f;
	
	for(int i=1; i<n; i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		Link(x,y);
	}
	for(int i=1; i<=n; i++) {
		scanf("%d",w+i);
		mx[i]=w[i];
	}
	return 1;
}

void work() {
	int m;
	int opt,x,y,W;
	for(scanf("%d",&m); m--;) {
		if(m==6)
		m=6;
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==1) {
			if(getroot(x)==getroot(y)) puts("-1");
			else Link(x,y);
		} else if(opt==2) {
			if(getroot(x)!=getroot(y) || x==y) puts("-1");
			else Cut(x,y);
		} else if(opt==3) {
			W=x,x=y;
			scanf("%d",&y);
			if(getroot(x)!=getroot(y)) puts("-1");
			else {
				newroot(x);
				access(y);
				splay(y);
				add_tag(y,W);
			}
		} else { /*if(opt==4)*/
			if(getroot(x)!=getroot(y)) puts("-1");
			else {
				newroot(x);
				access(y);
				splay(y);
				printf("%d\n",mx[y]);
			}
		}
	}
	puts("");
}


int main() {
#ifdef DEBUG
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif

	for(; init(); work());

	return 0;
}


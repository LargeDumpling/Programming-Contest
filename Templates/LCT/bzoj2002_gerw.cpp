#include<cstdio>
#include<cstring>
#include<algorithm>
#define REP(i,n) for(int i=0;i<(n);i++)
using namespace std;

const int N=50010,M=100010;

int ch[N][2],p[N];

inline bool isroot(int x) {
	return ch[p[x]][0]!=x&&ch[p[x]][1]!=x;
}

void rotate(int x) {
	int y=p[x],z=p[y];
	if(!isroot(y)) {
		ch[z][ch[z][1]==y]=x;
	}
	int l=ch[y][1]==x,r=l^1;
	p[ch[x][r]]=y;
	p[y]=x;
	p[x]=z;
	ch[y][l]=ch[x][r];
	ch[x][r]=y;
}

void splay(int x) {
	while(!isroot(x)) {
		int y=p[x],z=p[y];
		if(!isroot(y)) {
			if((ch[y][1]==x)^(ch[z][1]==y)) {
				rotate(x);
			} else {
				rotate(y);
			}
		}
		rotate(x);
	}
}

void access(int x) {
	int t=0;
	while(x) {
		splay(x);
		ch[x][1]=t;
		t=x;
		x=p[x];
	}
}

int getroot(int x) {
	access(x);
	splay(x);
	while(ch[x][0]) {
		x=ch[x][0];
	}
	return x;
}

void cut(int x) {
	access(x);
	splay(x);
	p[ch[x][0]]=0;
	ch[x][0]=0;
}

void join(int x,int y) {
	if(x==y) {
		return;
	}
	if(!y) {
		cut(x);
	} else {
		access(y);
		splay(y);
		if(isroot(x)) {
			
		} else {
			int t=x;
			while(!isroot(p[t])&&p[t]!=y) {
				t=p[t];
			}
			if(t==ch[y][0]) {
				return;
			}
		}
		/*
		呵呵,这题如果y已经是x的祖宗
		(不一定是直接父亲也可以跳过操作,
		因为不会改变最外面的盒子的值
		注释掉的是跳过的
		没注释的是严格判断x是不是y的父亲的 
		*/
		/*
		int t=x;
		while(!isroot(t)) {
			t=p[t];
		}
		if(t==y) {
			return;
		}
		*/
		cut(x);
		p[x]=y;
	}
}

int n,m;

template<typename T>
void gint(T& a) {
	char c=getchar();
	while(c<'0'||c>'9') {
		c=getchar();
	}
	a=c-'0';
	while((c=getchar())>='0'&&c<='9') {
		a=a*10+c-'0';
	}
}

int main() {
	freopen("input.txt","r",stdin);
	bool first=true;
	while(~scanf("%d",&n)) {
		if(first)first=false;
		else puts("");
		for(int i=1;i<=n;i++) {
			gint(p[i]);
			ch[i][0]=ch[i][1]=0;
		}
		scanf("%d",&m);
		while(m--) {
			char s[10];
			int x,y;
			scanf("%s",s);
			if(s[0]=='Q') {
				gint(x);
				printf("%d\n",getroot(x));
			} else {
				gint(x);
				gint(y);
				join(x,y);
			}
		}
	}
	return 0;
}

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
using namespace std;

const int Maxn = 10010;

int ch[Maxn][2],p[Maxn],flip[Maxn];
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

template <typename Q>
void pt(Q x){
	static char stk[20];
	static int top;
	top=0;
	if(x==0) pc('0');
	for(;x;x/=10) stk[++top] = x%10+'0';
	for(;top;top--) pc(stk[top]);
}

void down(int x){
	if(flip[x]) {
		swap(ch[x][0],ch[x][1]);
		flip[ch[x][0]]^=1;
		flip[ch[x][1]]^=1;
		flip[x]=0;
	}
}

bool isroot(int x){
	return ch[p[x]][0]!=x && ch[p[x]][1]!=x;
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
}

void splay(int x){
	static int stk[Maxn],top;
	stk[top=1]=x;
	for(int t=x;!isroot(t);t=p[t]) stk[++top]=p[t];
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
	}
}

int getroot(int x){
	for(access(x),splay(x);ch[x][0];x=ch[x][0]);
	return x;
}
	
void newroot(int x) {
	access(x);
	splay(x);
	flip[x]^=1;
}

void cut(int x){
	access(x);
	splay(x);
	p[ch[x][0]]=0;
	ch[x][0]=0;
}

void combine(int x,int y) {
	newroot(x);
	p[x]=y;
}

void work() {
	gt(n),gt(m);
	char c;
	int a,b;
	for(int i=1;i<=m;i++) {
		for(;c=gc,c!='Q' && c!='C' &&c!='D';);
		gt(a),gt(b);
		if(c=='Q') printf("%s\n",getroot(a)==getroot(b)?"Yes" : "No");
		else if(c=='C') combine(a,b);
		else newroot(a),cut(b);
	}
}

int main() {
#ifdef DEBUG
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	fread(in,1,D,stdin);
	
	work();
	
	return printf(out),0;
}


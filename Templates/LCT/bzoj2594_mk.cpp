#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<cctype>
#include<ctime>

using namespace std;

const int D=200000;
char in[D],out[3000000*10],*I=in,*O=out,*_end=I;
#define gc (I==_end?_end=fread(_end,1,D,stdin):0,(*I++))
#define pc(x) ((*O++)=x)

template <typename Q>
void gt(Q&x) {
	static char c,f;
	for(f=0;c=gc,!isdigit(c);)if(c=='-') f=1;
	for(;isdigit(c);c=gc) x=x*10+c-'0';
	f && (x=-x);
}
template <typename Q>
void pt(Q x){
	static int stk[20],top;
	if(x<0) pc('-'),x=-x;
	if(x==0) pc('0');
	for(top=0;x;x/=10) stk[++top] = x%10+'0';
	for(;top;top--) pc(stk[top]);
}

int ran(int l,int r){
	return ((rand()<<16)+rand())%(r-l+1)+l;
}

const int Maxn=100001;
#include<map>
map<pair<int,int>,bool> vis;

#define vis(u,v) vis[make_pair(u,v)]

int main(){
	freopen("in.txt","w",stdout);
	
	srand(time(0));
	int n=5,m=10,Q=10;
	printf("%d %d %d\n",n,m,Q);
	int u,v;
	for(int i=1;i<=m;i++) {
		for(;(u=ran(1,n),v=ran(1,n)),u==v||vis(u,v););
		vis(u,v)=vis(v,u)=1;
//		printf("%d %d %d\n",u,v,ran(1,int(2e3)));
		pt(u);pc(' ');pt(v);pc(' ');pt(ran(1,int(2e3)));pc('\n');
	}
	for(int i=1;i<=Q;i++){
		int k=ran(1,2);
		for(;u=ran(1,n),v=ran(1,n),(u==v||!(vis(u,v)||k==1)););
		if(k==2) vis(u,v)=vis(v,u)=0;
		pt(k);pc(' ');pt(u);pc(' ');pt(v);pc('\n');
	}
	
	return printf(out),0;
}


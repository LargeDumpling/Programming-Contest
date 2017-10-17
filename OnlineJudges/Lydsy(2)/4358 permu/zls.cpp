#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
const int N = 5e4+7;

int getin () {
	int sum = 0,fh = 1;
	char a;
	for(a=getchar();a<'0' || a>'9';a=getchar()) if(a == '-') fh = -1;
	for(;a>='0' && a<='9';a=getchar()) sum = sum * 10 + a - '0';
	return sum * fh;
}

int max (int A,int B) {
	return A > B ? A : B;
}

int min (int A,int B) {
	return A < B ? A : B;
}
struct lvc {
	int a,b;
	bool operator < (const lvc &rhs) const {
		return a < rhs.a;
	}
};

int f[N],size[N];

int n,m,a[N],max1;
lvc c[N];
int find (int x) { return f[x] == x ? x : f[x] = find (f[x]);}
void merge (int x) {
	++size[a[x]]; 
	if(size[a[x]+1]) {
		f[a[x]+1] = f[a[x]]; 
		size[a[x]] += size[a[x]+1];
	}
	if(size[a[x]-1]) {
		f[a[x]] = find(a[x]-1);
		size [f[a[x]]] += size [a[x]];
	}
	max1 = std::max(max1,size[f[a[x]]]);
}

int unit;

struct item {
	int l,r,id;
	bool operator < (const item &rhs ) const {
		int x = (l - 1) / unit,y = (rhs.l-1) / unit;
		if(x == y) return r < rhs.r;
		return x < y ;
	}
}clc[N];

int l,r,ks,fk,max2,tail,ans[N];

int main () {
	freopen("code.in","r",stdin);
	freopen("zls.out","w",stdout);
	n = getin(); m = getin();
	for(int i=1;i<=n;++i) c[i].a=a[i]=getin(),c[i].b=i;
	unit = ceil ( sqrt ( n ) ) ;
	ks = (n-1) / unit;
	for(int i=0;i<ks;++i)	std::sort (c+1+i*unit,c+1+(i+1)*unit);
	std::sort(c+unit*ks+1,c+n+1);
	for(int i=1;i<=m;++i) scanf("%d%d",&clc[i].l,&clc[i].r),clc[i].id=i;
	std::sort (clc+1,clc+m+1);
	for(int pc=1;pc<=m;++pc) {
		fk = (clc[pc].l-1) / unit;tail = 0;
		if(pc == 1 ||  fk != (clc[pc-1].l-1) /  unit) {
			max1 = 0; r = ((clc[pc].l-1)/unit+1)*unit+1;
			for(int ccc=0;ccc<=n;++ccc) f[ccc] = ccc,size[ccc]=0;
		}
		while(r<=clc[pc].r)	merge (r),r++;
		max2 = max1;	
		for(int i=std::min((fk+1)*unit,n);i>=fk*unit+1;--i) {
			if(c[i].b < clc[pc].l || c[i].b > clc[pc].r) continue;
			if(i-1 && c[i-1].b >= clc[pc].l  && c[i-1].b <= clc[pc].r && (c[i].a-1 == c[i-1].a || (size[c[i].a-1] && find(c[i].a-1)-1 == c[i-1].a)))
			{	if(!tail) tail = size [c[i].a+1]; 
				tail += size[f[c[i].a-1]] + 1;}
			else
				max2 = max (max2 ,max(tail,size[c[i].a+1]) + 1 + size[find(c[i].a-1)]),tail = 0;
			continue ;
		}
		ans[clc[pc].id] = max2;
	}
	for(int i=1;i<=m;++i) printf("%d\n",ans[i]);
	fprintf(stderr,"%.6f\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}


//YHY
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rep(i,x,y) for(int i=x;i<=y;++i)
using namespace std;
const int maxn = 3e5+5;
int n,m;
int d[maxn],to[maxn][20],t1[maxn],t2[maxn];
int sa[maxn][20],c[maxn];

void read1n(int &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
		if(ch==-1) return;
	x = ch-'0'+1;
	return;
}

void build_sa(){
	int i,j,p,len=10;
	int *x=t1,*y=t2;
	memset(c,0,sizeof(c));
	for(i=0;i<n;i++) c[x[i]=d[i]]++;
	for(i=1;i<=len;i++) c[i]+=c[i-1];
	for(i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
	for(i=0;i<m;i++){
		memset(c,0,sizeof(c));
		for(j=0;j<n;j++) y[j]=x[to[j][i]];
		
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int tut=1;tut<=t;tut++){
		scanf("%d",&n);
		int i,j=0,a,b;
		for(i=0;i<n;i++){
			read1n(d[i]);
			to[i][0]=((long long)i*i+1)%n;
		}
		for(m=1;;m++){
			for(j=0;j<n;j++)to[j][m]=to[to[j][m-1]][m-1];
			if(1<<m>=n)break;
		}
		build_sa();
	}
}


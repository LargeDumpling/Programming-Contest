/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-09	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=50050;
const int M=65536;
struct jz
{
	long long x,y,t;
	jz() { x=y=t=0; }
	bool operator<(const jz &X)const { return x<X.x; }
}w[MAXN];
int d[M<<1],n;
long long ans=0;
template<typename ty>
void read1n(ty &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int calc(int a,int b) { return w[a].t<w[b].t?b:a; }
void build()
{
	for(int i=1;i<=n;i++)
		d[i+M]=i;
	for(int i=M-1;i;i--)
		d[i]=calc(d[i<<1],d[i<<1|1]);
	return;
}
int query(int L,int R)
{
	int ans=0;
	for(L=L+M-1,R=R+M+1;L<R-1;L>>=1,R>>=1)
	{
		if(!(L&1)) ans=calc(ans,d[L^1]);
		if(R&1) ans=calc(ans,d[R^1]);
	}
	return ans;
}
void query(int l,int r,long long xs,long long ys)
{
	if(r<l) return;
	int t=query(l,r);
	ans+=w[t].x-xs+w[t].y-ys;
	query(l,t-1,xs,w[t].y);
	query(t+1,r,w[t].x,ys);
	return;
}
int main()
{
	read1n(n);
	for(int i=1;i<=n;i++)
	{
		read1n(w[i].x);
		read1n(w[i].y);
		w[i].t=i;
	}
	sort(w+1,w+n+1);
	build();
	query(1,n,0,0);
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


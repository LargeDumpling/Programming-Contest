//LargeDumpling
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=200050;
const int M=131072;
struct jz
{
	int l,r,cnt[2];
	jz(const int &L=0,const int &R=0):l(L),r(R) { }
	bool operator<(const jz &X)const { return l==X.l?r<X.r:l<X.l; }
}sec[MAXN];
int d[M<<1],ans[2],n,c[MAXN];
void change(int p,int x)
{
	for(p+=M;p;p>>=1)
		d[p]+=x;
	return;
}
int query(int l,int r)
{
	int ans=0;
	for(l+=M-1,r+=M+1;l<r-1;l>>=1,r>>=1)
	{
		if(!(l&1)) ans+=d[l^1];
		if(r&1) ans+=d[r^1];
	}
	return ans;
}
bool cmpl(jz a,jz b)
{
	return a.l==b.l?a.r<=b.r:a.l<b.l;
}
bool cmpr(jz a,jz b)
{
	return a.r==b.r?a.l<b.l:a.r<b.r;
}
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int main()
{
	ans[0]=ans[1]=0;
	read1n(n);
	for(int i=1;i<=n;i++)
	{
		read1n(sec[i].l); sec[i].l++;
		read1n(sec[i].r);
		sec[i].cnt[0]=sec[i].cnt[1]=0;
	}
	memset(d,0,sizeof(d));
	for(int i=1;i<=n;i++)
		change(sec[i].l,1);
	for(int i=1;i<=n;i++)
		sec[i].cnt[0]=query(sec[i].r+1,M-2);
	memset(d,0,sizeof(d));
	for(int i=1;i<=n;i++)
		change(sec[i].r,1);
	for(int i=1;i<=n;i++)
	{
		sec[i].cnt[1]=query(1,sec[i].l-1);
		ans[0]=max(ans[0],n-sec[i].cnt[0]-sec[i].cnt[1]);
	}
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++)
	{
		c[sec[i].l]++;
		c[sec[i].r+1]--;
	}
	for(int i=1;i<MAXN;i++)
		ans[1]=max(ans[1],c[i]+=c[i-1]);
	printf("%d %d",ans[0],ans[1]);
	return 0;
}



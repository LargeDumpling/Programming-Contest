/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-14	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const int M=262144;
int h[MAXN<<1];
long long V,E;
int d[M<<1];
struct jz
{
	int x,y;
	bool operator<(const jz &P)const { return x==P.x?y<P.y:x<P.x; }
}P[MAXN];
template<typename Ty>
void read1n(Ty &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int query(int L,int R)
{
	int ans=0;
	for(L=L+M-1,R=R+M+1;L<R-1;L>>=1,R>>=1)
	{
		if(!(L&1)) ans+=d[L^1];
		if(R&1) ans+=d[R^1];
	}
	return ans;
}
void calc(int n)
{
	h[0]=0;
	for(int i=1;i<=n;i++)
	{
		read1n(P[i].x);
		read1n(P[i].y);
		h[++h[0]]=P[i].x;
		h[++h[0]]=P[i].y;
	}
	sort(h+1,h+h[0]+1);
	h[0]=unique(h+1,h+h[0]+1)-h-1;
	for(int i=1;i<=n;i++)
	{
		P[i].x=lower_bound(h+1,h+h[0]+1,P[i].x)-h;
		P[i].y=lower_bound(h+1,h+h[0]+1,P[i].y)-h;
	}
	sort(P+1,P+n+1);
	for(int i=1;i<=n;i++)
	{
		int t=query(P[i].y,MAXN<<1);
		V+=t;
		E+=t+t;
		for(int x=P[i].y+M;x;x>>=1)
			d[x]++;
	}
	for(int i=1;i<=n;i++)
		for(int x=P[i].y+M;x;x>>=1)
			d[x]--;
	return;
}
int main()
{
	int n,m;
	scanf("%*d%*d");
	read1n(n); read1n(m);
	V=(long long)n*m+2LL*(n+m);
	E=(long long)n*(m+1LL)+(long long)m*(n+1LL)+2LL*(n+m);
	calc(n);
	calc(m);
	printf("%lld",1LL+E-V);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


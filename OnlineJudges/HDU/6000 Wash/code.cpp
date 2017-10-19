/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-10-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXL=1000050;
const int MAXN=100050;
int T_T;
int L,N,M,W;
long long t[MAXL],ans;
struct jp
{
	long long fir,sec;
	jp(const long long &F=0,const long long &S=0) { fir=F; sec=S; }
	bool operator<(const jp &X)const { return sec==X.sec?fir<X.fir:sec<X.sec; }
}tem;
template<typename Ty>
struct heap
{
	int tOp;
	int L[MAXN],R[MAXN],dist[MAXN],p[MAXN];
	Ty data[MAXN];
	heap()
	{
		tOp=0;
		memset(L,0,sizeof(L));
		memset(R,0,sizeof(R));
		memset(dist,0,sizeof(dist));
		for(int i=1;i<MAXN;i++)
			p[i]=i;
		p[0]=MAXN-1;
	}
	void clear()
	{
		tOp=0;
		memset(L,0,sizeof(L));
		memset(R,0,sizeof(R));
		memset(dist,0,sizeof(dist));
		for(int i=1;i<MAXN;i++)
			p[i]=i;
		p[0]=MAXN-1;
		return;
	}
	bool empty() { return (bool)tOp; }
	int merge(int A,int B)
	{
		if(!A) return B;
		if(!B) return A;
		if(data[B]<data[A]) swap(A,B);
		R[A]=merge(R[A],B);
		if(dist[L[A]]<dist[R[A]]) swap(L[A],R[A]);
		dist[A]=R[A]?dist[R[A]]+1:0;
		return A;
	}
	void push(Ty X)
	{
		data[p[p[0]]]=X;
		tOp=merge(tOp,p[p[0]--]);
		return;
	}
	void pop()
	{
		p[++p[0]]=tOp;
		tOp=merge(L[tOp],R[tOp]);
		L[p[p[0]]]=R[p[p[0]]]=0;
		return;
	}
	Ty top() { return data[tOp]; }
};
heap<jp> h;
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
	read1n(T_T);
	for(int T=1;T<=T_T;T++)
	{
		h.clear();
		ans=0;
		read1n(L);
		read1n(N);
		read1n(M);
		for(int i=1;i<=N;i++)
		{
			read1n(W);
			h.push(jp(W,W));
		}
		for(int i=1;i<=L;i++)
		{
			tem=h.top(); h.pop();
			t[i]=tem.sec;
			h.push(jp(tem.fir,tem.fir+tem.sec));
		}
		h.clear();
		for(int i=1;i<=M;i++)
		{
			read1n(W);
			h.push(jp(W,W));
		}
		for(int i=1;i<=L;i++)
		{
			tem=h.top(); h.pop();
			ans=max(ans,tem.sec+t[L-i+1]);
			h.push(jp(tem.fir,tem.fir+tem.sec));
		}
		printf("Case #%d: %lld\n",T,ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
template<typename Ty>
struct heap
{
	static const int MAXN=1000050;
	int tOp;
	int L[MAXN],R[MAXN],dist[MAXN],p[MAXN];
	Ty data[MAXN];
	heap()
	{
		tOp=0;
		memset(L,0,sizeof(L));
		memset(R,0,sizeof(R));
		memset(dist,0,sizeof(dist));
		for(int i=1;i<MAXN;i++) p[i]=i;
		p[0]=MAXN-1;
	}
	void clear()
	{
		tOp=0;
		memset(L,0,sizeof(L));
		memset(R,0,sizeof(R));
		memset(dist,0,sizeof(dist));
		for(int i=1;i<MAXN;i++) p[i]=i;
		p[0]=MAXN-1;
		return;
	}
	bool empty() { return (bool)tOp; }
	int merge(int A,int B)
	{
		if(!A) return B;
		if(!B) return A;
		if(data[A]>data[B]) swap(A,B);
		R[A]=merge(R[A],B);
		if(dist[L[A]]<dist[R[A]])
			swap(L[A],R[A]);
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
heap<int> s;
void read1n(int &x)
{
	char ch;
	bool neg=false;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
		if(ch==-1) return;
		else if(ch=='-') neg=true;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	if(neg) x=-x;
	return;
}
int main()
{
	int n,op,x;
	read1n(n);
	while(n--)
	{
		read1n(op);
		switch(op)
		{
			case 1:
				read1n(x);
				s.push(x);
				break;
			case 2:
				printf("%d\n",s.top());
				break;
			case 3:
				s.pop();
				break;
			default:
				break;
		}
	}
	return 0;
}


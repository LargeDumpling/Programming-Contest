/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-10-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=4050;
const int INF=2147400000;
struct Edge
{
	int u,v,w;
}E[MAXN];
struct jp
{
	int x,y;
	jp(const int &X=0,const int &Y=0):x(X),y(Y) { }
	bool operator<(const jp &X)const { return x==X.x?y<X.y:x<X.x; }
	bool operator==(const jp &X)const { return x==X.x&&y==X.y; }
}p[MAXN<<1],h[MAXN<<1];
struct JP
{
	int u,dis;
	JP(const int &U=0,const int &D=0):u(U),dis(D) { }
	bool operator<(const JP &X)const { return dis<X.dis; }
};
template<typename Ty>
struct heap
{
	static const int MAXN=100050;
	int tOp;
	int L[MAXN],R[MAXN],dist[MAXN],p[MAXN];
	Ty data[MAXN];
	heap()
	{
		tOp=0;
		memset(L,0,sizeof(L));
		memset(R,0,sizeof(R));
		memset(dist,0,sizeof(dist));
template<typename Ty>
struct heap
{
	static const int MAXN=100050;
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
		if(data[A]<data[B]) swap(A,B);
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
	bool empty() { return !(bool)tOp; }
	int merge(int A,int B)
	{
		if(!A) return B;
		if(!B) return A;
		if(data[A]<data[B]) swap(A,B);
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
int T_T,m,hn;
int fir[MAXN<<1],end[MAXN<<1],next[MAXN<<1],len[MAXN<<1],ed=0,ans;
int dis[MAXN<<1];
bool exist[MAXN<<1];
void read1n(int &x)
{
	char ch; bool neg=false;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
		if(ch=='-')
			neg=true;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	if(neg) x=-x;
	return;
}
void addedge(int u,int v,int w)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	len[ed]=w;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	len[ed]=w;
	return;
}
void Hijkstra(int x)
{
	int u;
	heap<JP> q;
	memset(exist,false,sizeof(exist));
	for(int i=1;i<=hn;i++) dis[i]=INF;
	dis[E[x].u]=0;
	q.push(JP(E[x].u,0));
	for(int cnt=1;cnt<=hn;cnt++)
	{
		while(!q.empty()&&(exist[q.top().u]||dis[q.top().u]!=q.top().dis)) q.pop();
		if(q.empty()) break;
		u=q.top().u; q.pop();
		if(ans<=dis[u]+E[x].w) return;
		exist[u]=true;
		for(int i=fir[u];i;i=next[i]) if((i>>1)!=x)
		{
			if(dis[u]+len[i]<dis[end[i]])
			{
				dis[end[i]]=dis[u]+len[i];
				q.push(JP(end[i],dis[end[i]]));
			}
		}
	}
	ans=min(ans,dis[E[x].v]+E[x].w);
	return;
}
int main()
{
	read1n(T_T);
	for(int T=1;T<=T_T;T++)
	{
		memset(fir,0,sizeof(fir));
		ed=1;
		ans=INF;
		read1n(m);
		hn=0;
		for(int i=1;i<=m;i++)
		{
			E[i].u=i<<1;
			E[i].v=i<<1|1;
			scanf("%d%d%d%d%d",&p[E[i].u].x,&p[E[i].u].y,&p[E[i].v].x,&p[E[i].v].y,&E[i].w);
			h[++hn]=p[E[i].u];
			h[++hn]=p[E[i].v];
		}
		sort(h+1,h+hn+1);
		hn=unique(h+1,h+hn+1)-h-1;
		for(int i=1;i<=m;i++)
		{
			E[i].u=lower_bound(h+1,h+hn+1,p[E[i].u])-h;
			E[i].v=lower_bound(h+1,h+hn+1,p[E[i].v])-h;
			addedge(E[i].u,E[i].v,E[i].w);
		}
		for(int i=1;i<=m;i++)
			Hijkstra(i);
		printf("Case #%d: %d\n",T,ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


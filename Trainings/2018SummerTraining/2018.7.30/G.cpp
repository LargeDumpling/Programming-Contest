/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=200050;
typedef struct Poi Vec;
struct Poi
{
	long long x,y;
	int id;
	Poi(const long long &a=0,const long long &b=0):x(a),y(b) { }
	Poi operator-(const Poi &P)const { return Poi(x-P.x,y-P.y); }
	bool operator<(const Poi &P)const
	{
		if(x==P.x&&y==P.y) return id<P.id;
		return x==P.x?y<P.y:x<P.x;
	}
	bool operator==(const Poi &P)const { return x==P.x&&y==P.y; }
}P[MAXN],Q[MAXN];
int T_T,n;
bool vis[MAXN];
long long dOt(const Vec &V1,const Vec &V2) { return V1.x*V2.x+V1.y*V2.y; }
long long cRoss(const Vec &V1,const Vec &V2) { return V1.x*V2.y-V1.y*V2.x; }
bool onseg(const Poi &A,const Poi &B,const Poi &P)
{
	Vec PA=A-P,PB=B-P;
	if(cRoss(PA,PB)==0&&dOt(PA,PB)<=0) return true;
	return false;
}
int Andrew(Poi *A,int N,Poi *B)
{
	int m=0;
	sort(A,A+N);
	/*for(int i=0;i<N;B[m++]=A[i++])
		while(m>1&&cRoss(B[m-1]-B[m-2],A[i]-B[m-2])<=0) m--;
	for(int i=N-2,k=m;i>=0;B[m++]=A[i--])
		while(m>k&&cRoss(B[m-1]-B[m-2],A[i]-B[m-2])<=0) m--;*/
	for(int i=0;i<N;B[m++]=A[i++])
		while(m>1&&(cRoss(B[m-1]-B[m-2],A[i]-B[m-2])>0
					||(cRoss(B[m-1]-B[m-2],A[i]-B[m-2])==0&&A[i].id<B[m-1].id))) m--;
	/*for(int i=0;i<N;B[m++]=A[i++])
		while(m>1&&cRoss(B[m-1]-B[m-2],A[i]-B[m-2])>0)
			m--;*/
	//if(N>1) m--;
	B[m]=B[0];
	return m;
}
int main()
{
	int m,nn;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d",&n);
		memset(vis,true,sizeof(vis));
		for(int i=0;i<n;i++)
		{
			scanf("%lld%lld",&P[i].x,&P[i].y);
			P[i].id=i+1;
		}
		sort(P,P+n);
		nn=0;
		for(int i=0;i<n;i++)
		{
			if(i!=0&&P[i]==P[i-1]&&!(P[i]==P[n]))
				continue;
			P[nn++]=P[i];
		}
		n=nn;
		m=Andrew(P,n,Q);
		/*for(int i=0;i<m-2;i++)
			if(onseg(Q[i],Q[i+2],Q[i+1]))
				if(Q[i+2].id<Q[i+1].id)
					vis[i+1]=false;*/
		for(int i=0;i<m;i++)// if(vis[i])
			printf("%d%c",Q[i].id,i==m-1?'\n':' ');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


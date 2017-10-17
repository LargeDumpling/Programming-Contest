/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
template<typename Ty>
class pRiority_queue
{
	private:
		Ty data[100050];
		int p[100050],tOp,L[100050],R[100050],dist[100050];
		int get_node(){return p[++p[0]];}
		void del_node(int x){L[x]=R[x]=0;p[p[0]--]=x;}
		void sWap(int& A,int& B)
		{
			A^=B;
			B=A^B;
			A^=B;
			return;
		}
		int merge(int A,int B)
		{
			if(!A)return B;
			if(!B)return A;
			if(data[A]<data[B])sWap(A,B);
			R[A]=merge(R[A],B);
			if(dist[L[A]]<dist[R[A]])sWap(L[A],R[A]);
			dist[A]=R[A]?dist[R[A]]+1:0;
			return A;
		}
	public:
		pRiority_queue()
		{
			memset(dist,0,sizeof(dist));
			memset(L,0,sizeof(L));
			memset(R,0,sizeof(R));
			tOp=0;
			for(int i=0;i<100050;i++)p[i]=i;
		}
		void push(Ty x)
		{
			int pos=get_node();
			data[pos]=x;
			tOp=merge(tOp,pos);
			return;
		}
		Ty top(){return data[tOp];}
		void pop()
		{
			int k=merge(L[tOp],R[tOp]);
			del_node(tOp);
			tOp=k;
			return;
		}
};
struct jp
{
	int fir,sec;
	jp(int A=0,int B=0):fir(A),sec(B){}
	bool operator<(const jp &X){return fir==X.fir?sec>X.sec:fir>X.fir;}
};
pRiority_queue<jp> q;
map<int,int>s;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	jp tem;
	int a,b;
	char tex[10];
	while(true)
	{
		scanf("%s",tex);
		if(tex[0]=='#')break;
		scanf("%d%d",&a,&b);
		s[a]=b;
		q.push(jp(b,a));
	}
	scanf("%d",&b);
	while(b--)
	{
		tem=q.top();
		q.pop();
		printf("%d\n",tem.sec);
		q.push(jp(tem.fir+s[tem.sec],tem.sec));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-31	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=1000050;
struct jz
{
	int w,id;
	jz(const int &W=0,const int &ID=0):w(W),id(ID) { }
	bool operator<(const jz &X)const { return w==X.w?id>X.id:w>X.w; }
};
struct Que
{
	int t,q,ans,id;
	bool operator<(const Que &Q)const { return t<Q.t; }
}Q[MAXN];
int T_T,n,m,nowt;
int f[MAXN];
int fInd(int x)
{
	if(f[x]!=f[f[x]]) f[x]=fInd(f[x]);
	return f[x];
}
void mErge(int a,int b)
{
	if(b<a) swap(a,b);
	f[b]=a;
	return;
}
bool cmp(Que a,Que b) { return a.id<b.id; }
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
	int w;
	read1n(T_T);
	while(T_T--)
	{
		nowt=0;
		priority_queue<jz> q;
		read1n(n); read1n(m);
		for(int i=1;i<=n;i++)
		{
			read1n(w);
			q.push(jz(w,i));
			f[i]=i;
		}
		for(int i=1;i<=m;i++)
		{
			read1n(Q[i].t);
			read1n(Q[i].q);
			Q[i].ans=0;
			Q[i].id=i;
		}
		sort(Q+1,Q+m+1);
		for(int i=1;i<=m;i++)
		{
			while(nowt<Q[i].t)
			{
				jz tema,temb;
				tema=q.top(); q.pop();
				temb=q.top(); q.pop();
				mErge(tema.id,temb.id);
				q.push(jz(tema.w+temb.w,min(tema.id,temb.id)));
				nowt++;
			}
			Q[i].ans=fInd(Q[i].q);
		}
		sort(Q+1,Q+m+1,cmp);
		for(int i=1;i<=m;i++)
			printf("%d\n",Q[i].ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


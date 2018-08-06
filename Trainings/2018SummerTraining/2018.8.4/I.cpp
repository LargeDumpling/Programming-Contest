/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=200050;
//const int M=2097152;
const int M=1048576;
const long long mod=998244353;
int T_T,n,m,tim[MAXN];
long long l[MAXN],r[MAXN],h[MAXN<<1],res=0;
vector<long long> d[M<<1];
template<typename Ty>
void read1n(Ty &x)
{
	char ch; bool neg=false;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
		if(ch=='-') neg=true;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	if(neg) x=-x;
	return;
}
int get_id(long long x)
{
	if(h[h[0]]<x) return 2*h[0]+1;
	int t=lower_bound(h+1,h+h[0]+1,x)-h;
	return h[t]==x?(2*t):(2*t-1);
}
void init()
{
	for(int i=(M<<1)-1;0<=i;i--)
		d[i].reserve(1);
	h[0]=res=0;
	memset(tim,0,sizeof(tim));
	return;
}
void change(int L,int R,long long x)
{
	for(L=L+M-1,R=R+M+1;L<R-1;L>>=1,R>>=1)
	{
		if(!(L&1)) d[L^1].push_back(x);
		if(R&1) d[R^1].push_back(x);
	}
	return;
}
int query(int i,int x)
{
	int cnt=0;
	res=1;
	for(x+=M;x;x>>=1)
	{
		for(unsigned j=0;j<d[x].size();j++)
			if(!tim[d[x][j]])
			{
				tim[d[x][j]]=i;
				res=res*(long long)d[x][j]%mod;
				cnt++;
			}
		d[x].reserve(1);
	}
	if(!cnt) res=0;
	return cnt;
}
int main()
{
	long long x;
	//read1n(T_T);
	scanf("%d",&T_T);
	for(int T=1;T<=T_T;T++)
	{
		printf("Case #%d:\n",T);
		init();
		//read1n(n); read1n(m);
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			//read1n(l[i]);
			//read1n(r[i]);
			scanf("%lld%lld\n",&l[i],&r[i]);
			h[++h[0]]=l[i];
			h[++h[0]]=r[i];
		}
		sort(h+1,h+h[0]+1);
		h[0]=unique(h+1,h+h[0]+1)-h-1;
		for(int i=1;i<=n;i++)
			change(get_id(l[i]),get_id(r[i]),i);
		for(int i=1;i<=m;i++)
		{
			scanf("%lld",&x);
			printf("%d\n",query(i,get_id(x^res)));
		}
		for(int i=1;i<=n;i++)
			printf("%d%c",tim[i],i==n?'\n':' ');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


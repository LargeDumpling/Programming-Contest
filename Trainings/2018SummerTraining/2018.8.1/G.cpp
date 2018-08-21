/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long mod=1000000007;
const int MAXN=1000050;
int T_T,n,B[MAXN];
int fir[MAXN],end[MAXN<<1],next[MAXN<<1],ed=0;
int num[MAXN];
long long fac[MAXN],ifac[MAXN];
template<typename Ty>
void read1n(Ty &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
void addedge(int u,int v)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
}
int main()
{
	int u,v;
	fac[0]=1LL;
	for(int i=1;i<MAXN;i++) fac[i]=fac[i-1]*i%mod;
	ifac[1]=1;
	for(int i=2;i<MAXN;i++)
		ifac[i]=-(mod/i)*ifac[mod%i];
	read1n(T_T);
	while(T_T--)
	{
		read1n(n);
		for(int i=1;i<=n;i++)
			read1n(B[i]);
		for(int i=1;i<n;i++)
		{
			read1n(u);
			read1n(v);
			addedge(u,v);
		}
		DFS1(B[1],B[1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


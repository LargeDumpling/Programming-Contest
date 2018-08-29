/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const int MAXA=1000050;
const int MM=131072;
const int mod=1000000007;
int d[MM<<1][3][2],ans[MAXN],sum[MM<<1];
int T_T,n,Q,A[MAXN],L[MAXN],R[MAXN];
int Log[MAXA],M;
int st[50];
inline void read1n(int &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar()) if(ch==-1) break;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
inline void write1n(int x)
{
	st[0]=0;
	if(!x) st[++st[0]]=0;
	for(;x;x/=10)
		st[++st[0]]=x%10;
	while(st[0])
		putchar('0'+st[st[0]--]);
	return;
}
inline int add(int A,int B)
{
	int ans=A+B;
	if(mod<=ans) ans-=mod;
	return ans;
}
inline int add(int A,int B,int C,int D) { return ((long long)A+B+C+D)%mod; }
inline int multi(int a,int b)
{
	int ret;
	__asm__ __volatile__("\tmull %%ebx\n\tdivl %%ecx\n":"=d"(ret):"a"(a),"b"(b),"c"(mod));
	return ret;
}
inline void build(int k)
{
	for(int i=1;i<=n;i++)
	{
		sum[i+M]=(A[i]>>k)&1;
		memset(d[i+M],0,sizeof(d[i+M]));
		d[i+M][2][sum[i+M]]++;
		for(int j=0;j<2;j++)
		{
			d[i+M][j][0]=d[i+M][2][0];
			d[i+M][j][1]=d[i+M][2][1];
		}
	}
#define l (i<<1)
#define r (i<<1|1)
	for(int i=M-1;i;i--)
	{
		sum[i]=sum[l]^sum[r];
		d[i][2][1]=add(d[l][2][1],d[r][2][1],multi(d[l][1][0],d[r][0][1]),multi(d[l][1][1],d[r][0][0]));
		d[i][0][0]=add(d[l][0][0],d[r][0][sum[l]]);
		d[i][0][1]=add(d[l][0][1],d[r][0][sum[l]^1]);
		d[i][1][0]=add(d[r][1][0],d[l][1][sum[r]]);
		d[i][1][1]=add(d[r][1][1],d[l][1][sum[r]^1]);
	}
#undef l
#undef r
	return;
}
inline int query(int L,int R)
{
	int cntL[3][2],cntR[3][2],sumL=0,sumR=0;
	memset(cntL,0,sizeof(cntL));
	memset(cntR,0,sizeof(cntR));
	for(L=L+M-1,R=R+M+1;L<R-1;L>>=1,R>>=1)
	{
		if(!(L&1))
		{
			cntL[2][1]=add(cntL[2][1],d[L^1][2][1],multi(cntL[1][0],d[L^1][0][1]),multi(cntL[1][1],d[L^1][0][0]));
			cntL[0][0]=add(cntL[0][0],d[L^1][0][sumL]);
			cntL[0][1]=add(cntL[0][1],d[L^1][0][sumL^1]);
			cntL[1][0]=add(d[L^1][1][0],cntL[1][sum[L^1]]);
			cntL[1][1]=add(d[L^1][1][1],cntL[1][sum[L^1]^1]);
			sumL^=sum[L^1];
		}
		if(R&1)
		{
			cntR[2][1]=add(d[R^1][2][1],cntR[2][1],multi(d[R^1][1][0],cntR[0][1]),multi(d[R^1][1][1],cntR[0][0]));
			cntR[0][0]=add(d[R^1][0][0],cntR[0][sum[R^1]]);
			cntR[0][1]=add(d[R^1][0][1],cntR[0][sum[R^1]^1]);
			cntR[1][0]=add(cntR[1][0],d[R^1][1][sumR]);
			cntR[1][1]=add(cntR[1][1],d[R^1][1][sumR^1]);
			sumR^=sum[R^1];
		}
	}
	return add(cntL[2][1],cntR[2][1],multi(cntL[1][0],cntR[0][1]),multi(cntL[1][1],cntR[0][0]));
}
int cnt[MAXN][2];
int main()
{
	int t;
	Log[0]=-1;
	for(int i=1;i<MAXA;i++)
		Log[i]=Log[i>>1]+1;
	read1n(T_T);
	while(T_T--)
	{
		t=0;
		read1n(n); read1n(Q);
		M=1<<(Log[n]+1);
		for(int i=1;i<=n;i++)
		{
			read1n(A[i]);
			t=max(t,Log[A[i]]);
		}
		t++;
		for(int i=1;i<=Q;i++)
		{
			read1n(L[i]); read1n(R[i]);
			ans[i]=0;
		}
		for(int i=0;i<20;i++)
		{
			build(i);
			for(int j=1;j<=Q;j++)
				ans[j]=add(ans[j],multi(query(L[j],R[j]),(1LL<<i)));
		}
		for(int i=1;i<=Q;i++)
		{
			write1n(ans[i]);
			putchar('\n');
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

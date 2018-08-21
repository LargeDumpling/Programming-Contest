/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long mod=998244353;
const int MAXN=300050;
struct jz
{
	int x,y;
	long long w;
	jz(const int &X=0,const int &Y=0,const long long &W=0):x(X),y(Y),w(W) { }
}C[MAXN];
int T_T,n,m,cn,curx;
long long fac[MAXN],ifac[MAXN];
template<typename Ty>
void read1n(Ty &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch)
		ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
long long Pow(long long x,long long N)
{
	long long ans;
	for(ans=1;N;N>>=1,x=x*x%mod)
		if(N&1)
			ans=ans*x%mod;
	return ans;
}
void pre_calc()
{
	fac[0]=ifac[0]=1;
	for(int i=1;i<MAXN;i++)
		fac[i]=fac[i-1]*i%mod;
	ifac[MAXN-1]=Pow(fac[MAXN-1],mod-2);
	for(int i=MAXN-2;i;i--)
		ifac[i]=ifac[i+1]*(i+1)%mod;
	return;
}
void init()
{
	cn=0;
	curx=1;
	return;
}
long long calc_C(int N,int M)
{
	return fac[N]*ifac[M]%mod*ifac[N-M]%mod;
}
long long query(int x,int y)
{
	int dx,dy;
	long long ans=0;
	for(int i=0;i<cn;i++)
	{
		if(x<C[i].x) break;
		if(y<C[i].y) continue;
		dx=x-C[i].x;
		dy=y-C[i].y;
		ans=(ans+C[i].w*calc_C(dx+dy-1,dy)%mod)%mod;
	}
	return ans;
}
int main()
{
	int opt,L,R;
	long long w;
	pre_calc();
	read1n(T_T);
	while(T_T--)
	{
		init();
		read1n(n); read1n(m);
		while(m--)
		{
			read1n(opt);
			switch(opt)
			{
				case 1:
					read1n(L); read1n(R);
					read1n(w);
					C[cn++]=jz(curx-1,L,w);
					C[cn++]=jz(curx-1,R+1,mod-w);
					break;
				case 2:
					curx++;
					break;
				case 3:
					read1n(L); read1n(R);
					printf("%lld\n",(query(curx+1,R)-query(curx+1,L-1)+mod)%mod);
					break;
				default:
					break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-05-12	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1000050;
const int DD=1000000;
const long long mod=1000000007;
int T,n,m;
long long D[MAXN],fac[MAXN],faci[MAXN];
char in[DD],*I=in+DD;
inline char getc()
{
	if(I==in+DD)
	{
		fread(in,1,DD,stdin);
		I=in;
	}
	return *(I++);
}
inline void read1n(int &x)
{
	char ch;
	for(ch=getc();ch<'0'||'9'<ch;ch=getc());
	for(x=0;'0'<=ch&&ch<='9';ch=getc()) x=(x<<1)+(x<<3)+ch-'0';
	return;
}
long long q_pow(long long a,long long x)
{
	long long ans;
	for(ans=1;x;x>>=1,a=a*a%mod)
		if(x&1) ans=ans*a%mod;
	return ans;
}
void pre_calc()
{
	D[0]=1; D[1]=0;
	fac[0]=fac[1]=1;
	for(long long i=2;i<MAXN;i++)
	{
		D[i]=(i-1)*(D[i-1]+D[i-2])%mod;
		fac[i]=i*fac[i-1]%mod;
	}
	faci[MAXN-1]=q_pow(fac[MAXN-1],mod-2);
	for(long long i=MAXN-2;i>=0;i--) faci[i]=(i+1)*faci[i+1]%mod;
	return;
}
inline long long C(int a,int b)
{ return fac[a]*faci[b]%mod*faci[a-b]%mod; }
int s[100];
inline void write1n(long long x)
{
	if(!x)
	{
		puts("0");
		return;
	}
	for(s[0]=0;x;x/=10LL) s[++s[0]]=x%10;
	while(s[0]) putchar('0'+s[s[0]--]);
	putchar('\n');
	return;
}
int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	pre_calc();
	//scanf("%d",&T);
	read1n(T);
	while(T--)
	{
		//scanf("%d%d",&n,&m);
		read1n(n); read1n(m);
		//printf("%lld\n",D[n-m]*C(n,m)%mod);
		write1n(D[n-m]*C(n,m)%mod);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


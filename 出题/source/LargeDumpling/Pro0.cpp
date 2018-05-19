#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const long long P=(479<<21)+1,G=3,D=10000000;
int rev[MAXN<<2],n,m,lenth,inver;
long long f[3][MAXN<<2],g[3][MAXN<<2];
char A[MAXN],B[MAXN];
long long pOw(long long a,int n)
{
	long long ans;
	for(ans=1;n;n>>=1,a=a*a%P)
		if(n&1) ans=ans*a%P;
	return ans;
}
void FFT_pre(int &n)
{
	int tem;for(tem=0;(1<<tem)<n;tem++);n=1<<tem;
	for(int i=0;i<n;i++)rev[i]=rev[i>>1]>>1|((i&1)<<(tem-1));
	inver=pOw(n,P-2);
	return;
}
void FFT(long long X[],int n,bool inv)
{
	for(int i=0;i<n;i++)if(rev[i]>i)swap(X[i],X[rev[i]]);
	long long temk,w,cur,temp;
	for(int k=2;k<=n;k<<=1)
	{
		temk=k>>1;
		cur=1;w=pOw(G,(P-1)/k);
		if(inv)w=pOw(w,k-1);
		for(int i=0;i<temk;i++)
		{
			for(int j=0;j<n;j+=k)
			{
				temp=cur*X[i+j+temk]%P;
				X[i+j+temk]=(X[i+j]-temp+P)%P;
				X[i+j]=(X[i+j]+temp)%P;
			}
			cur=cur*w%P;
		}
	}
	if(inv)
		for(int i=0;i<n;i++)
			X[i]=X[i]*inver%P;
	return;
}
int main()
{
	scanf("%s%s",A,B);
	n=strlen(A); m=strlen(B);
	for(int i=0;i<n;i++)
	{
		f[0][i]=A[n-1-i]=='?'?0:A[n-1-i]-'a'+1;
		f[1][i]=f[0][i]*f[0][i];
		f[2][i]=f[1][i]*f[0][i];
	}
	for(int i=0;i<m;i++)
	{
		g[0][i]=B[i]=='?'?0:B[i]-'a'+1;
		g[1][i]=g[0][i]*g[0][i];
		g[2][i]=g[1][i]*g[0][i];
	}
	n+=m;
	FFT_pre(n);
	for(int i=0;i<3;i++)
	{
		FFT(f[i],n,false);
		FFT(g[i],n,false);
	}
	for(int i=0;i<n;i++)
		f[0][i]=(f[2][i]*g[0][i]%P-2LL*f[1][i]%P*g[1][i]%P+P+f[0][i]*g[2][i]%P)%P;
	FFT(f[0],n,true);
	for(int i=n-1;0<=i;i--)
		printf("%lld ",f[0][i]);
	return 0;
}


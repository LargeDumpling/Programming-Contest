#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int P=(479<<21)+1,G=3,D=10000000;
int A[405000],B[405000],rev[400050],n,m,lenth,inver;
char in[D],*I=in,out[D/10],*O=out;
template<typename Ty>void read1n(Ty &x)
{
	for(x=0;*I<'0'||'9'<*I;I++);
	while('0'<=*I&&*I<='9')x=(x<<1)+(x<<3)+*(I++)-'0';
	return;
}
template<typename Ty>void write1n(Ty x)
{
	static int s[70];
	if(!x)*(O++)='0';
	for(s[0]=0;x;x/=10)s[++s[0]]=(int)x%10;
	while(s[0])*(O++)=s[s[0]--]+'0';
	return;
}
int pOw(int a,int n)
{
	int ans;
	for(ans=1;n;n>>=1,a=(int)((long long)a*a%P))
		if(n&1)ans=(int)((long long)ans*a%P);
	return ans;
}
void FFT_pre(int &n)
{
	int tem;for(tem=0;(1<<tem)<n;tem++);n=1<<tem;
	for(int i=0;i<n;i++)rev[i]=rev[i>>1]>>1|((i&1)<<(tem-1));
	inver=pOw(n,P-2);
	return;
}
void FFT(int X[],int n,bool inv)
{
	for(int i=0;i<n;i++)if(rev[i]>i)swap(X[i],X[rev[i]]);
	int temk,w,cur,temp;
	for(int k=2;k<=n;k<<=1)
	{
		temk=k>>1;
		cur=1;w=pOw(G,(P-1)/k);
		if(inv)w=pOw(w,k-1);
		for(int i=0;i<temk;i++)
		{
			for(int j=0;j<n;j+=k)
			{
				temp=(int)((long long)cur*X[i+j+temk]%P);
				X[i+j+temk]=(int)((long long)(X[i+j]-temp+P)%P);
				X[i+j]=(int)((long long)(X[i+j]+temp)%P);
			}
			cur=(int)((long long)cur*w%P);
		}
	}
	if(inv)for(int i=0;i<n;i++)X[i]=(int)((long long)X[i]*inver%P);
	return;
}
int main()
{
	in[fread(in,1,D,stdin)]=-1;
	read1n(n);read1n(m);n++;m++;
	lenth=n+m-1;
	for(int i=0;i<n;i++)read1n(A[i]);
	for(int i=0;i<m;i++)read1n(B[i]);
	n=max(n,m);
	n<<=1;
	FFT_pre(n);
	FFT(A,n,false);
	FFT(B,n,false);
	for(int i=0;i<n;i++)A[i]=(int)((long long)A[i]*B[i]%P);
	FFT(A,n,true);
	for(int i=0;i<lenth;i++)write1n(A[i]),*(O++)=' ';
	fwrite(out,1,O-out,stdout);
	return 0;
}


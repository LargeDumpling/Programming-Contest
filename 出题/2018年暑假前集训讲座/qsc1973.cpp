/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-27	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>
#include<algorithm>
using namespace std;
const int MAXN=300050;
/*struct cp
{
	double r,i;
	cp(const double &a=0,const double &b=0):r(a),i(b) { }
	cp operator+(const cp &X)const { return cp(r+X.r,i+X.i); }
	cp operator-(const cp &X)const { return cp(r-X.r,i-X.i); }
	cp operator*(const cp &X)const { return cp(r*X.r-i*X.i,r*X.i+i*X.r); }
	cp operator/(const double &P)const { return cp(r/P,i/P); }
}A[3][MAXN<<2],B[3][MAXN<<2],C[3][MAXN<<2];
int rev[MAXN<<2],lenA,lenB;
int ans[MAXN<<2];
char strA[MAXN],strB[MAXN];
int trans(char ch) { return ch=='?'?0:(ch-'a'+1); }
void FFT_pre(int &n)
{
	int tem; for(tem=0;(1<<tem)<n;tem++); n=1<<tem;
	rev[0]=0;
	for(int i=1;i<n;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(tem-1));
	return;
}
void DFT(cp X[],int n,bool inv)
{
	int temk;
	double wn1=inv?-2.*acos(-1.):2.*acos(-1.);
	cp w,cur,tem;
	for(int i=1;i<n;i++) if(rev[i]>i) swap(X[i],X[rev[i]]);
	for(int k=2;k<=n;k<<=1)
	{
		temk=k>>1;
		cur=cp(1.,0.);
		w=cp(cos(wn1/k),sin(wn1/k));
		for(int j=0;j<temk;j++)
		{
			for(int i=0;i<n;i+=k)
			{
				tem=cur*X[i+j+temk];
				X[i+j+temk]=X[i+j]-tem;
				X[i+j]=X[i+j]+tem;
			}
			cur=cur*w;
		}
	}
	if(inv) for(int i=0;i<n;i++) X[i]=X[i]/n;
	return;
}*/
const int P=(479<<21)+1,G=3;
int A[3][MAXN<<2],B[3][MAXN<<2],C[3][MAXN<<2],rev[MAXN<<2],inver;
int ans[MAXN],lenA,lenB;
char strA[MAXN],strB[MAXN];
int trans(char ch) { return ch=='?'?0:(ch-'a'+1); }
inline int mul(int a,int b,int m)
{
	int ret;
	__asm__ __volatile__("\tmull %%ebx\n\tdivl %%ecx\n":"=d"(ret):"a"(a),"b"(b),"c"(m));
	return ret;
}
int pOw(int a,int n)
{
	int ans;
	for(ans=1;n;n>>=1,a=mul(a,a,P))
		if(n&1) ans=mul(ans,a,P);
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
				temp=mul(cur,X[i+j+temk],P);
				X[i+j+temk]=X[i+j]-temp+P;
				assert(0<=X[i+j+temk]&&X[i+j+temk]-P<P);
				while(P<=X[i+j+temk]) X[i+j+temk]-=P;
				//X[i+j+temk]=(int)((long long)(X[i+j]-temp+P)%P);
				//assert(X[i+j+temk]==(X[i+j]-temp+P)%P);
				assert(i+j<(MAXN<<2));

				X[i+j]=X[i+j]+temp;
				assert(0<=X[i+j]&&X[i+j]-P<P);
				while(P<=X[i+j]) X[i+j]-=P;
				//X[i+j]=(int)((long long)(X[i+j]+temp)%P);
			}
			cur=mul(cur,w,P);
		}
	}
	if(inv)for(int i=0;i<n;i++)X[i]=mul(X[i],inver,P);
	return;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,x,len;
	ans[0]=0;
	scanf("%s%s",strA,strB);
	lenA=strlen(strA); lenB=strlen(strB);
	if(lenA<lenB) puts("0");
	else
	{
		for(int i=0;i<lenA;i++)
		{
			x=trans(strA[i]);
			A[0][i]=x;
			A[1][i]=x*x;
			A[2][i]=x*x*x;
		}
		for(int i=0;i<lenB;i++)
		{
			x=trans(strB[lenB-i-1]);
			B[0][i]=x;
			B[1][i]=x*x;
			B[2][i]=x*x*x;
		}
		len=lenA+lenB-1;
		n=max(lenA,lenB)<<1;
		FFT_pre(n);
		for(int i=0;i<3;i++)
		{
			FFT(A[i],n,false);
			FFT(B[i],n,false);
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<3;j++)
				C[j][i]=mul(A[2-j][i],B[j][i],P);
		for(int i=0;i<3;i++)
			FFT(C[i],n,true);
		for(int i=lenB-1;i<len&&i<lenA;i++)
			if(C[0][i]+C[2][i]==(C[1][i]<<1))
				ans[++ans[0]]=i-lenB+1;
		printf("%d\n",ans[0]);
		for(int i=1;i<=ans[0];i++)
			printf("%d ",ans[i]+1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-21	File created.
 Hint:
	This is a recursive edition of fast fourier transform
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=131072;
struct jz
{
	double r,i;
	jz(const double &R=0,const double &I=0):r(R),i(I) { }
	double len() { return sqrt(r*r+i*i); }
	jz conjugate() { return jz(r,-i); }
	jz operator+(const jz &J)const { return jz(r+J.r,i+J.i); }
	jz operator-(const jz &J)const { return jz(r-J.r,i-J.i); }
	jz operator*(double P)const { return jz(r*P,i*P); }
	jz operator/(double P)const { return jz(r/P,i/P); }
};
jz mult(jz A,jz B) { return jz(A.r*B.r-A.i*B.i,A.i*B.r+A.r*B.i); }
jz devi(jz A,jz B) { return mult(A,B.conjugate())/B.len(); }
int n,m,N=MAXN<<1;
vector<jz> A(MAXN<<1),B(MAXN<<1);
void DFT()
{
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)
	{
		scanf("%lf",&A[i].r);
		A[i].i=0;
	}
	for(int i=n+1;i<N;i++)
		A[i]=jz(0);
	for(int i=0;i<=m;i++)
	{
		scanf("%lf",&B[i].r);
		B[i].r=0;
	}
	for(int i=m+1;i<N;i++)
	{
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


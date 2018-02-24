/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-05	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
struct jp
{
	ull d[3];
	jp(ull a=0,ull b=0,ull c=0)
	{
		ull v[]= {a, b, c};
		memcpy(d,v,sizeof v);
	}
	bool operator==(const jp x)const {return memcmp(d, x.d, sizeof d) == 0;}
	jp operator-(const jp x)const
	{ return jp(d[0]-x.d[0],d[1]-x.d[1],d[2]-x.d[2]); }
	template<typename Ty>
	jp operator*(Ty x) { return jp(d[0]*x,d[1]*x,d[2]*x); }
	jp operator*(jp x) { return jp(d[0]*x.d[0],d[1]*x.d[1],d[2]*x.d[2]);}
	jp operator%(jp x) { return jp(d[0]%x.d[0],d[1]%x.d[1],d[2]%x.d[2]); }
	bool operator<(const jp x)const
	{
		if(d[0]==x.d[0])return d[1]==x.d[1]?d[2]<x.d[2]:d[1]<x.d[1];
		return d[0]<x.d[0];
	}
	template<typename Ty>
	jp operator+(const Ty x)const{return jp(d[0]+x,d[1]+x,d[2]+x);}
}A[50050],P[50050],B[50050],mod;
void pre()
{
	mod=jp(2305843009213693951ULL,4611686018427387903ULL,9223372036854775807ULL);
	P[0]=jp(1,1,1);
	P[1]=jp(26,31,37);
	for(int i=2;i<50050;i++) P[i]=P[i-1]*P[1];
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	char stra[50050],strb[50050];
	int lena,lenb;
	pre();
	scanf("%s",stra);
	scanf("%s",strb);
	lena=strlen(stra); lenb=strlen(strb);
	A[lena]=jp(0,0,0);
	//for(int i=lena-1;i>=0;i--) A[i]=((A[i+1]*P[1])%mod+(stra[i]-'a'+1))%mod;
	for(int i=lena-1;i>=0;i--) A[i]=((A[i+1]*P[1])+(stra[i]-'a'+1));
	B[lenb]=jp(0,0,0);
	//for(int i=lenb-1;i>=0;i--) B[i]=((B[i+1]*P[1])%mod+(strb[i]-'a'+1))%mod;
	for(int i=lenb-1;i>=0;i--) B[i]=((B[i+1]*P[1])+(strb[i]-'a'+1));
	if(A[0]==B[0]) puts("≤›ƒ‚ÙŒÙŒ");
	else puts("≤ª‹≥¡À");
	fclose(stdin);
	fclose(stdout);
	return 0;
}


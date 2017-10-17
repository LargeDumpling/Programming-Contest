/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-12	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
unsigned long long seed;
long double gen()
{
	static const long double Z = ( long double )1.0 / (1LL<<32);
	seed >>= 16;
	seed &= ( 1ULL << 32 ) - 1;
	seed *= seed;
	return seed * Z;
}
unsigned long long read1n()
{
	unsigned long long x=0;char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(;'0'<=ch&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
	return x;
}
int main()
{
	//freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	seed=read1n();
	for(int i=1;i<=10;i++)
		printf("%f\n",(double)gen());
	putchar('\n');
	fclose(stdin);
	fclose(stdout);
	return 0;
}


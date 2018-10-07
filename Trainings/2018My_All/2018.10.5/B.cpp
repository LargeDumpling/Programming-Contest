/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-05	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int T_T;
long long a0,a1,an,m0,m1,c,M,k,ans,A[1000050][3][3];
template<typename Ty>
void read1n(Ty &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
inline long long mul_mod(const long long &a,const long long &b)
{
    long long ret;
    __asm__ __volatile__("\tmull %%ebx\n\tdivl %%ecx\n":"=d"(ret):"a"(a),"b"(b),"c"(M));
    return ret;
}
long long multi(const long long &tp1,const long long &tp2)
{
    long long ret=0;
    __asm__("movq %1,%%rax\n imulq %2\n idivq %3\n":"=d"(ret):"m"(tp1),"m"(tp2),"m"(M):"%rax");
    return ret;
}
inline long long mul(const long long &x,const long long &y)
{
	return (x*y-(long long)((long double)x/M*y)*M+M)%M;
}
int main()
{
	read1n(T_T);
	T_T=1;
	while(T_T--)
	{
		read1n(a0);
		read1n(a1);
		read1n(m0);
		read1n(m1);
		read1n(c);
		read1n(M);
		read1n(k);
		ans=mul(a0,a1);
		for(int i=2;i<=k;i++)
		{
			an=mul(m0,a1)+mul(m1,a0)+c;
			ans=mul(ans,an);
			a0=a1;
			a1=an;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


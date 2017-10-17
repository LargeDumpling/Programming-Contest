/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-05	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
const int D=10000000;
char in[D],*I=in;
template<typename Ty>
void read1n(Ty &x)
{
	while(*I<'0'||'9'<*I)I++;
	for(x=0;'0'<=*I&&*I<='9';)x=(x<<1)+(x<<3)+*(I++)-'0';
	return;
}
int T,m;
unsigned long long a,b;
int cn[1050],fib;
void pre()
{
	int a,b;
	for(int i=2,j;i<=1000;i++)
	{
		a=0;
		b=1;
		for(j=1;;j++)
		{
			b=(a+b)%i;
			a=(b-a+i)%i;
			if(a==0&&b==1)break;
		}
		cn[i]=j;
	}
	return;
}
int pOw(int a,unsigned long long x,int mod)
{
	if(!a||mod==1)return 0;
	int ans=1;
	for(;x;x>>=1,a=(a*a)%mod)if(x&1)ans=(ans*a)%mod;
	return ans;
}
int solve()
{
	if(!a||m==1)return 0;
	int pos=pOw(a%cn[m],b,cn[m]),A=0,B=1;
	for(int i=1;i<=pos;i++)
	{
		B=(A+B)%m;
		A=(B-A+m)%m;
	}
	return A;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	in[fread(in,1,D,stdin)]=-1;
	pre();
	read1n(T);
	while(T--)
	{
		read1n(a),read1n(b),read1n(m);
		printf("%d\n",solve());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


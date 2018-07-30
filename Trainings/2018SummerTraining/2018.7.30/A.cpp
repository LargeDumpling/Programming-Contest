/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=10000050;
int T_T,n,m,k,p,q,r,mod;
int a[MAXN],Q[MAXN],head,tail;
long long A,B;
void read1n(int &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int main()
{
	read1n(T_T);
	while(T_T--)
	{
		read1n(n);
		read1n(m);
		read1n(k);
		read1n(p);
		read1n(q);
		read1n(r);
		read1n(mod);
		A=B=head=tail=0;
		for(int i=1;i<=k;i++)
			read1n(a[i]);
		for(int i=k+1;i<=n;i++)
			a[i]=((long long)p*a[i-1]%mod+(long long)q*i%mod+r)%mod;
		for(int i=1;i<m;i++)
		{
			while(head<tail&&a[Q[tail]]<=a[n-i+1]) tail--;
			Q[++tail]=n-i+1;
		}
		for(int i=n-m+1;i;i--)
		{
			while(head<tail&&a[Q[tail]]<=a[i]) tail--;
			Q[++tail]=i;
			if(i+m-1<Q[head+1]) head++;
			A+=(a[Q[head+1]]^i);
			B+=((tail-head)^i);
		}
		printf("%lld %lld\n",A,B);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


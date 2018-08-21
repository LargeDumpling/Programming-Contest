/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long mod=998244353;
const int MAXN=100050;
int T_T;
long long n,m,S[MAXN];
long long pOw(long long a,long long x)
{
	long long ans;
	for(ans=1;x;x>>=1,a=a*a%mod)
		if(x&1)
			ans=ans*a%mod;
	return ans;
}
template<typename Ty>
void read1n(Ty &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int main()
{
	int t,L,R;
	long long ans,w;
	read1n(T_T);
	while(T_T--)
	{
		read1n(n);
		read1n(m);
		w=pOw(2,n*m%(mod-1));
		S[0]=0;
		for(int i=1;i<=n;i++)
		{
			read1n(S[i]);
			S[i]=(S[i]+S[i-1])%mod;
		}
		while(m--)
		{
			read1n(t);
			read1n(L);
			read1n(R);
			if(t==2)
			{
				ans=(S[R]-S[L-1]+mod)%mod*w%mod;
				printf("%lld\n",ans);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


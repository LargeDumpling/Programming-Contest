/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long mod=1e9+7;
const int MAXN=100050;
long long pOw(long long a,long long n)
{
	long long ans;
	for(ans=1;n;n>>=1,a=a*a%mod)
		if(n&1)
			ans=ans*a%mod;
	return ans;
}
int n,m;
long long A[MAXN],B[MAXN],inv[MAXN];
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
	read1n(n); read1n(m);
	long long ans=0,tem=1;
	inv[0]=1LL;
	inv[1]=pOw(m,mod-2);
	bool flag=false;
	for(int i=1;i<=n;i++)
	{
		read1n(A[i]);
		inv[i]=inv[i-1]*inv[1]%mod;
	}
	for(int i=1;i<=n;i++)
		read1n(B[i]);
	for(int i=1;i<=n;i++)
	{
		if(A[i]==0&&B[i]==0)
		{
			if(m!=1)
			{
				flag=true;
				ans=(ans+tem*(m-1)%mod*pOw(2LL*m, mod-2)%mod)%mod;
			}
			tem=tem*inv[1]%mod;
		}
		else if(A[i]==0)
		{
			if(B[i]!=m)
			{
				flag=true;
				ans=(ans+tem*(m-B[i])%mod*pOw(m,mod-2)%mod)%mod;
			}
			tem=tem*inv[1]%mod;
		}
		else if(B[i]==0)
		{
			if(A[i]!=1)
			{
				flag=true;
				ans=(ans+tem*(A[i]-1)%mod*pOw(m,mod-2)%mod)%mod;
			}
			tem=tem*inv[1]%mod;
		}
		else if(A[i]<B[i])
			break;
		else if(A[i]>B[i])
		{
			ans=(ans+tem)%mod;
			break;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


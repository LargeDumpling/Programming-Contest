/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-17	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1000050;
const long long mod=1e9+7;
int h[MAXN],num[MAXN],n;
long long fac[MAXN],f2[MAXN],s[MAXN];
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
void pre_calc()
{
	fac[1]=1LL;
	for(int i=1;i<MAXN;i++)
		fac[i]=fac[i-1]*(long long)i%mod;
	return;
}
long long ans=0;
int main()
{
	pre_calc();
	read1n(n);
	h[0]=0;
	for(int i=1;i<=n;i++)
	{
		read1n(num[i]);
		h[++h[0]]=num[i];
	}
	sort(h+1,h+h[0]+1);
	h[0]=unique(h+1,h+h[0]+1)-h-1;
	for(int i=1;i<=n;i++)
	{
		num[i]=lower_bound(h+1,h+h[0]+1,num[i])-h;
		s[num[i]]++;
	}
	f2[0]=fac[0]*fac[n-1]%mod;
	for(int i=1;i<=n;i++)
		f2[i]=(f2[i-1]+fac[i]*fac[n-i-1]%mod)%mod;
	for(int i=1;i<=h[0];i++)
		s[i]+=s[i-1];
	for(int i=1;i<h[0];i++)
		ans=(ans+(s[i]-s[i-1])*h[i]%mod*f2[s[i-1]]%mod)%mod;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


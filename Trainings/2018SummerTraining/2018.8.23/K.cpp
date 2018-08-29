/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<tr1/unordered_map>
#include<algorithm>
using namespace std::tr1;
const int MAXN=100050;
unordered_map<long long,int> f;
int n,Q,L[105],R[105];
long long p[MAXN],h[MAXN],ip[MAXN],P,q[105],ans[105];
char str[MAXN];
long long pow(long long x,long long N)
{
	long long ans;
	for(ans=1;N;N>>=1,x=x*x%P)
		if(N&1)
			ans=ans*x%P;
	return ans;
}
void inc(long long x)
{
	if(!f.count(x)) f[x]=1;
	else f[x]=f[x]+1;
}
int query(long long x)
{
	if(!f.count(x)) return 0;
	return f[x];
}
int main()
{
	scanf("%s",str+1);
	n=strlen(str+1);
	scanf("%d%lld",&Q,&P);
	ip[0]=p[0]=1;
	p[1]=10;
	ip[1]=pow(p[1],P-2);
	h[0]=0;
	for(int i=2;i<MAXN;i++)
	{
		p[i]=p[i-1]*p[1]%P;
		ip[i]=ip[i-1]*ip[1]%P;
	}
	for(int i=1;i<=n;i++)
		h[i]=(h[i-1]*10+str[i]-'0')%P;
	for(int i=1;i<=Q;i++)
		scanf("%lld",&q[i]);
	for(int i=0;i<=n;i++)
	{
		if(i)
		{
			for(int j=1;j<=Q;j++)
			{
				int k=query((h[i]-q[j]+P)%P*ip[i]%P);
				if(k)
				{
					R[j]=i;
					ans[j]+=k;
				}
			}
		}
		inc(h[i]*ip[i]%P);
	}
	for(int j=1;j<=Q;j++)
	{
		for(int i=0;i<R[j];i++) if((h[i]*ip[i]%P+q[j]*ip[R[j]]%P)%P==h[R[j]]*ip[R[j]]%P)
		{
			L[j]=i+1;
			break;
		}
		printf("%lld %d %d\n",ans[j],L[j],R[j]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


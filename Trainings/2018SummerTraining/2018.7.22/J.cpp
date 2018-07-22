/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=200050;
const int M=262144;
const long long mod=1000000007;
long long d[M<<1][20],a[MAXN],ans[20];
int n,m;
template<typename Ty>
void read1n(Ty &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
void query(int L,int R)
{
	int Lans[20],Rans[20],tem[20];
	memset(Lans,0,sizeof(Lans));
	memset(Rans,0,sizeof(Rans));
	Lans[0]=Rans[0]=1;
	for(L=L+M-1,R=R+M+1;L<R-1;L>>=1,R>>=1)
	{
		if(!(L&1))
		{
			memset(tem,0,sizeof(tem));
			for(int i=0;i<m;i++) for(int j=0;j<m;j++) tem[(i+j)%m]=(tem[(i+j)%m]+Lans[i]*d[L^1][j]%mod)%mod;
			memcpy(Lans,tem,sizeof(tem));
		}
		if(R&1)
		{
			memset(tem,0,sizeof(tem));
			for(int i=0;i<m;i++) for(int j=0;j<m;j++) tem[(i+j)%m]=(tem[(i+j)%m]+d[R^1][i]*Rans[j]%mod)%mod;
			memcpy(Rans,tem,sizeof(tem));
		}
	}
	memset(ans,0,sizeof(ans));
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			ans[(i+j)%m]=(ans[(i+j)%m]+Lans[i]*Rans[j]%mod)%mod;
	return;
}
int main()
{
	int l,r,Q;
	long long tem[20];
	read1n(n); read1n(m);
	for(int i=0;i<(M<<1);i++)
		d[i][0]=1;
	for(int i=1;i<=n;i++)
	{
		read1n(a[i]);
		d[i+M][a[i]%m]++;
	}
	for(int r=M-1;r;r--)
	{
		memset(tem,0,sizeof(tem));
		for(int i=0;i<m;i++)
			for(int j=0;j<m;j++)
				tem[(i+j)%m]=(tem[(i+j)%m]+d[r<<1][i]*d[r<<1|1][j]%mod)%mod;
		memcpy(d[r],tem,sizeof(tem));
	}
	read1n(Q);
	while(Q-->0)
	{
		read1n(l); read1n(r);
		query(l,r);
		printf("%lld\n",ans[0]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=200050;
const int mod=1000000007;
struct jz
{
	int l,r;
	long long ans;
	jz() { l=r=ans=0; }
}Q[MAXN];
int n,m,qn,a[MAXN];
long long f[MAXN][20];
void read1n(int &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
void calc(int l,int r,vector<int> &q)
{
	if(l==r)
	{
		int cnt=1;
		if(a[l]%m==0) cnt++;
		for(unsigned i=0;i<q.size();i++)
			Q[q[i]].ans=cnt;
		return;
	}
	int mid=(l+r)>>1;
	vector<int> qn[2];
	/*for(int i=l;i<=r;i++)
	{
		memset(f[i],0,sizeof(f[i]));
		f[i][0]++;
		f[i][a[i]%m]++;
	}
	for(int i=mid-1;l<=i;i--)
	{
		long long tem[20];
		memset(tem,0,sizeof(tem));
		for(int j=0;j<m;j++) // This is not necessary, j is useful only when j==0 or j==a[i]
			for(int k=0;k<m;k++)
				tem[(j+k)%m]=(tem[(j+k)%m]+f[i][j]*f[i+1][k]%mod)%mod;
		memcpy(f[i],tem,sizeof(tem));
	}
	for(int i=mid+2;i<=r;i++)
	{
		long long tem[20];
		memset(tem,0,sizeof(tem));
		for(int j=0;j<m;j++)
			for(int k=0;k<m;k++)
				tem[(j+k)%m]=(tem[(j+k)%m]+f[i][j]*f[i-1][k]%mod)%mod;
		memcpy(f[i],tem,sizeof(tem));
	}*/
	memset(f[mid],0,sizeof(f[mid]));
	f[mid][0]++; f[mid][a[mid]%m]++;
	memset(f[mid+1],0,sizeof(f[mid+1]));
	f[mid+1][0]++; f[mid+1][a[mid+1]%m]++;
	long long tem[20];
	for(int i=mid-1;l<=i;i--)
	{
		memset(tem,0,sizeof(tem));
		for(int j=0;j<m;j++)
		{
			tem[j]=(tem[j]+f[i+1][j])%mod;
			tem[(j+a[i])%m]=(tem[(j+a[i])%m]+f[i+1][j])%mod;
		}
		memcpy(f[i],tem,sizeof(tem));
	}
	for(int i=mid+2;i<=r;i++)
	{
		memset(tem,0,sizeof(tem));
		for(int j=0;j<m;j++)
		{
			tem[j]=(tem[j]+f[i-1][j])%mod;
			tem[(j+a[i])%m]=(tem[(j+a[i])%m]+f[i-1][j])%mod;
		}
		memcpy(f[i],tem,sizeof(tem));
	}
	for(unsigned i=0;i<q.size();i++)
	{
		if(Q[q[i]].r<=mid) qn[0].push_back(q[i]);
		if(mid<Q[q[i]].l) qn[1].push_back(q[i]);
		if(Q[q[i]].l<=mid&&mid<Q[q[i]].r)
		{
			for(int j=0;j<m;j++)
				Q[q[i]].ans=(Q[q[i]].ans+f[Q[q[i]].l][j]*f[Q[q[i]].r][(m-j)%m])%mod;
		}
	}
	if(qn[0].size()) calc(l,mid,qn[0]);
	if(qn[1].size()) calc(mid+1,r,qn[1]);
	return;
}
int main()
{
	read1n(n); read1n(m);
	for(int i=1;i<=n;i++)
		read1n(a[i]);
	read1n(qn);
	vector<int> q;
	for(int i=1;i<=qn;i++)
	{
		read1n(Q[i].l);
		read1n(Q[i].r);
		q.push_back(i);
	}
	calc(1,n,q);
	for(int i=1;i<=qn;i++)
		printf("%lld\n",Q[i].ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


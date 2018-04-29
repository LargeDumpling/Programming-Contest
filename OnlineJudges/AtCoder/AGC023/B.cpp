/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-04-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=350;
const unsigned long long mod=1000000007;
char str[MAXN][MAXN];
unsigned long long r[MAXN][MAXN],c[MAXN][MAXN],P[MAXN];
int n,ans=0;
int get(int x) { return (x+2*n)%n; }
unsigned long long get_hash_r(int i,int x)
{
	if(x==0) return r[i][n-1];
	else return ((r[i][n-1]-r[i][x-1]*P[n-x]%mod+mod)%mod*P[x]%mod+r[i][x-1])%mod;
}
unsigned long long get_hash_c(int i,int x)
{
	if(x==0) return c[i][n-1];
	else return ((c[i][n-1]-c[i][x-1]*P[n-x]%mod+mod)%mod*P[x]%mod+c[i][x-1])%mod;
}
bool check(int A,int B)
{
	for(int i=0;i<n;i++)
		if(get_hash_r((i+A)%n,B)!=get_hash_c((i+B)%n,A))
			return false;
	return true;
}
int main()
{
	P[0]=1;
	P[1]=23;
	for(int i=1;i<MAXN;i++)
		P[i]=P[i-1]*P[1]%mod;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",str[i]);
		r[i][0]=str[i][0];
		for(int j=1;j<n;j++)
			r[i][j]=(r[i][j-1]*P[1]%mod+str[i][j])%mod;
	}
	for(int i=0;i<n;i++)
	{
		c[i][0]=str[0][i];
		for(int j=1;j<n;j++)
			c[i][j]=(c[i][j-1]*P[1]%mod+str[j][i])%mod;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(check(i,j))
				ans++;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


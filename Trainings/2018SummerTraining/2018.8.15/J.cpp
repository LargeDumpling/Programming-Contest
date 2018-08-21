/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-15	File created.
*/


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const int INF=2147483647;
int T_T,n,m,h[MAXN],f[MAXN][17];
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int get(int p,int x)
{
	if(p==n+1) return p;
	for(int i=16;0<=i;i--)
	{
		if(x<h[f[p][i]]) continue;
		p=f[p][i];
	}
	return x<h[p]?p:f[p][0];
}
int main()
{
	int ans,p,x,u;
	read1n(T_T);
	while(T_T--)
	{
		read1n(n); read1n(m);
		for(int i=1;i<=n;i++)
			read1n(h[i]);
		h[n+1]=INF;
		for(int i=0;i<17;i++)
			f[n+1][i]=n+1;
		for(int i=n;i;i--)
		{
			for(f[i][0]=i+1;h[f[i][0]]<=h[i];f[i][0]=f[f[i][0]][0]);
			for(int j=1;j<17;j++)
				f[i][j]=f[f[i][j-1]][j-1];
		}
		while(m--)
		{
			read1n(p); read1n(x);
			ans=0;
			if(p==1)
			{
				ans=1;
				u=get(2,x);
				if(u!=n+1) ans++;
				for(int i=16;0<=i;i--)
				{
					if(n<f[u][i])
						continue;
					ans+=(1<<i);
					u=f[u][i];
				}
			}
			else
			{
				ans=u=1;
				for(int i=16;0<=i;i--)
				{
					if(p<=f[u][i])
						continue;
					ans+=(1<<i);
					u=f[u][i];
				}
				if(h[u]<x)
				{
					ans++;
					u=get(p+1,x);
				}
				else u=get(p+1,h[u]);
				if(u!=n+1) ans++;
				for(int i=16;0<=i;i--)
				{
					if(n<f[u][i])
						continue;
					ans+=(1<<i);
					u=f[u][i];
				}
			}
			printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

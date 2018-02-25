/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;;
int n,c;
int f[MAXN][17],Log[MAXN];
long long g[MAXN];
int mIn(int l,int r)
{
	int t=Log[r-l+1];
	return min(f[l][t],f[r-(1<<t)+1][t]);
}
int main()
{
	long long sum=0;
	Log[0]=-1;
	for(int i=1;i<MAXN;i++)
		Log[i]=Log[i>>1]+1;
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i][0]);
		sum+=f[i][0];
	}
	for(int j=1;j<17;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	for(int i=1;i<=n;i++)
	{
		g[i]=g[i-1];
		if(0<=i-c)
			g[i]=max(g[i],g[i-c]+mIn(i-c+1,i));
	}
	cout<<sum-g[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}


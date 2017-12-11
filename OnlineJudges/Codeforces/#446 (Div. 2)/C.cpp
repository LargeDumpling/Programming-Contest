/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-11-17	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=2050;
int n,G[MAXN][MAXN],ans=2147483647,cnt=0;
int gcd(int A,int B)
{
	int t;
	while(B)
	{
		t=A%B;
		A=B;
		B=t;
	}
	return A;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&G[i][i]);
		if(G[i][i]==1)
			cnt++;
	}
	for(int i=1;i<=n;i++)
	{
		if(G[i][i]==1) ans=0;
		for(int j=i+1;j<=n;j++)
		{
			G[i][j]=gcd(G[i][j-1],G[j][j]);
			if(G[i][j]==1)
				ans=min(ans,j-i);
		}
	}
	if(G[1][n]!=1) puts("-1");
	else if(cnt) printf("%d",n-cnt);
	else printf("%d",ans+n-1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


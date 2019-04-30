/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-04-13	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<bitset>
#include<algorithm>
using namespace std;
bitset<1050> f[1050];
int T_T,W,H,n,m,A[1050],B[1050];
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%d%d%d",&W,&H,&n,&m);
		long long ans=0,sum;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&A[i]);
			for(int j=0;j<1050;j++)
				f[i][j]=0;
		}
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&B[j]);
			for(int i=1;i<=n;i++)
				if(0<=A[i]+B[j]&&A[i]+B[j]<=2*W&&0<=A[i]-B[j]&&A[i]-B[j]<=2*H)
					f[i][j]=1;
		}
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
			{
				sum=(f[i]&f[j]).count();
				ans=(ans+sum*(sum-1)/2LL)%1000000007;
			}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-12	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
unsigned long long f[70][35][105][2];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T,n,K;
	scanf("%d",&T);
	for(int cAse=1;cAse<=T;cAse++)
	{
		scanf("%d%d",&n,&K);
		if(n&1)
		{
			printf("Case %d: 0\n",cAse);
			continue;
		}
		memset(f,0,sizeof(f));
		f[0][0][0][0]=1;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=i;j++)
				for(int k=0;k<K;k++)if(f[i][j][k])
				{
					f[i+1][j+1][(k+(1LL<<i))%K][1]+=f[i][j][k][0]+f[i][j][k][1];
					f[i+1][j][k][0]+=f[i][j][k][0]+f[i][j][k][1];
				}
		printf("Case %d: %llu\n",cAse,f[n][n/2][0][1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


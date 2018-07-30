/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long mod=1000000007;
int SS[10][10][300],T_T,n,m,limit;
long long f[1024][6];
char op[3];
void pre_calc()
{
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++) if(i!=j)
		{
			SS[i][j][0]=0;
			for(int S=0;S<1024;S++) if(((S>>i)&1)&&((S>>j)&1))
				SS[i][j][++SS[i][j][0]]=S;
		}
	return;
}
int main()
{
	int u,v;
	scanf("%d",&T_T);
	pre_calc();
	while(T_T--)
	{
		memset(f,0,sizeof(f));
		scanf("%d%d",&n,&m);
		limit=1<<n;
		for(int i=0;i<limit;i++)
			f[i][0]=1;
		for(int i=1;i<=m;i++)
		{
			scanf("%s%d%d",op,&u,&v);
			u--; v--;
			if(op[0]=='+')
			{
				for(int j=1,S;j<=SS[u][v][0];j++)
				{
					S=SS[u][v][j];
					if(limit<=S) break;
					int nS=S^(1<<u)^(1<<v);
					for(int k=1;k<=n/2;k++)
						f[S][k]=(f[S][k]+f[nS][k-1])%mod;
				}
			}
			else
			{
				for(int j=1,S;j<=SS[u][v][0];j++)
				{
					S=SS[u][v][j];
					if(limit<=S) break;
					int nS=S^(1<<u)^(1<<v);
					for(int k=1;k<=n/2;k++)
						f[S][k]=(f[S][k]-f[nS][k-1]+mod)%mod;
				}
			}
			for(int j=1;j<=n/2;j++)
				printf("%lld%c",f[limit-1][j],j==(n/2)?'\n':' ');
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


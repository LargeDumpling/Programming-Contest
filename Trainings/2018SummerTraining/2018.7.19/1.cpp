/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1050;
const long long mod=1000000007;
long long f[MAXN][MAXN][3];
void pre_calc()
{
	for(int i=0;i<3;i++)
		f[1][1][i]=1;
	for(int i=1;i<=1000;i++)
		for(int j=1;j<=1000;j++)
		{
			if(i==1&&j==1) continue;
			/*if(i==1)
				for(int k=0;k<3;k++)
					for(int l=0;l<=k;l++)
						f[i][j][k]=(f[i][j][k]+f[i][j-1][l])%mod;
			else if(j==1)
				for(int k=0;k<3;k++)
					for(int l=0;l<=k;l++)
						f[i][j][k]=(f[i][j][k]+f[i-1][j][l])%mod;
			else for(int k=0;k<3;k++)
					for(int l=0;l<=k;l++)
						for(int p=0;p<=k;p++)
							f[i][j][k]=(f[i][j][k]+f[i-1][j][l]+f[i][j-1][p])%mod;*/
		}
	return;
}
int main()
{
	int n,m;
	pre_calc();
	while(scanf("%d%d",&n,&m)!=-1)
		cout<<(f[n][m][0]+f[n][m][1]+f[n][m][2])%mod<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


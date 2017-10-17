/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-07	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int mod=10056;
int T,n,f[1050],C[1050][1050];
void calc_C()
{
	C[0][0]=C[1][0]=C[1][1]=1;
	for(int i=2;i<=1000;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	return;
}
void calc_F()
{
	f[0]=1;
	for(int i=0;i<=1000;i++)
		for(int j=1;i+j<=1000;j++)
			f[i+j]=(f[i+j]+C[i+j][j]*f[i])%mod;
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&T);
	memset(f,0,sizeof(f));
	calc_C();
	calc_F();
	for(int cAse=1;cAse<=T;cAse++)
	{
		scanf("%d",&n);
		printf("Case %d: %d\n",cAse,f[n]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


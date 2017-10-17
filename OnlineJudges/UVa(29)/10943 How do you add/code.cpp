/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int C[205][205];
void calc_C()
{
	C[0][0]=1;
	for(int i=1;i<=200;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%1000000;
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n,k;
	calc_C();
	while(scanf("%d%d",&n,&k)!=-1&&(n||k))
		printf("%d\n",C[n+k-1][k-1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


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
double f[50050];
void pre_calc()
{
	f[0]=1;
	for(int i=1;i<=50000;i++)
		f[i]=((i<<1)-1)*f[i-1]/(i<<1);
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T,n;
	pre_calc();
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		printf("%.4lf\n",1.0-(f[(n-2)>>1]));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


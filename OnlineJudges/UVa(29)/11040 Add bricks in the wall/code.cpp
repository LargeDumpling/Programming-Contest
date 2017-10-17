/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-10	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int f[10][10];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=9;i+=2)
			for(int j=1;j<=i;j+=2)
				scanf("%d",&f[i][j]);
		for(int i=1;i<=7;i+=2)
			for(int j=1;j<=i;j+=2)
			{
				f[i+2][j+1]=(f[i][j]-f[i+2][j]-f[i+2][j+2])>>1;
				f[i+1][j]=f[i+2][j]+f[i+2][j+1];
				f[i+1][j+1]=f[i+2][j+1]+f[i+2][j+2];
			}
		for(int i=1;i<=9;i++)
			for(int j=1;j<=i;j++)
			{
				printf("%d",f[i][j]);
				if(j==i)putchar('\n');
				else putchar(' ');
			}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-03	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=105;
int num[MAXN][MAXN],a[MAXN],b[MAXN];
int main()
{
	int n,m,x=0,d;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			num[i][j]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		x^=a[i];
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		x^=b[i];
	}
	if(x) puts("NO");
	else
	{
		puts("YES");
		if(n<=m)
		{
			d=1;
			int k,i,j;
			for(k=i=j=1;k<=m;k++)
			{
				num[i][j]=b[j];
				num[i][j+1]=a[i]^b[j];
				b[j+1]^=num[i][j+1];
				j++;
				if(i==n) d=-1;
				if(i==1) d=1;
				i+=d;
			}
		}
		else
		{
			d=1;
			int k,i,j;
			for(k=i=j=1;k<=n;k++)
			{
				num[i][j]=a[i];
				num[i+1][j]=a[i]^b[j];
				a[i+1]^=num[i+1][j];
				i++;
				if(j==m) d=-1;
				if(j==1) d=1;
				j+=d;
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				printf("%d%c",num[i][j],j==m?'\n':' ');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
FILE *fin1,*fin2;
int T,temp,num[25][25],C[25],R[25],n,m;
int main()
{
	fin1=fopen("code.in","r");
	fin2=fopen("code.out","r");
	char tex[20];
	fscanf(fin1,"%d",&T);
	for(int i=1;i<=T;i++)
	{
		fscanf(fin1,"%d%d",&n,&m);
		fscanf(fin2,"%s%d",tex,&temp);
		for(int i=1;i<=n;i++)fscanf(fin1,"%d",&C[i]);
		for(int i=1;i<=m;i++)fscanf(fin1,"%d",&R[i]);
		for(int i=n;i;i--)C[i]-=C[i-1];
		for(int i=m;i;i--)R[i]-=R[i-1];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				fscanf(fin2,"%d",&num[i][j]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				C[i]-=num[i][j];
				R[j]-=num[i][j];
			}
		for(int i=1;i<=n;i++)if(C[i]!=0)return 1;
		for(int i=1;i<=m;i++)if(R[i]!=0)return 1;
	}
	printf("No problem!\n");
	fclose(fin1);
	fclose(fin2);
	return 0;
}


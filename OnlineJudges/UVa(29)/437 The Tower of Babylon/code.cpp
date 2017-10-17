/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History: 
	2015-11-26	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,d[35][3],f[35][3];
bool map[35][3][35][3];
void swap(int &a,int &b){a^=b;b=a^b;a^=b;}
bool nEst(int x1,int d1,int x2,int d2)
{
	int x[4],sn=0;
	for(int i=0;i<=2;i++)if(i!=d1)x[sn++]=d[x1][i];
	for(int i=0;i<=2;i++)if(i!=d2)x[sn++]=d[x2][i];
	if(x[0]<x[1])swap(x[0],x[1]);
	if(x[2]<x[3])swap(x[2],x[3]);
	return ((x[0]>x[2])&(x[1]>x[3]));
}
int dp(int x,int D)
{
	if(f[x][D]>=0)return f[x][D];
	int &ans=f[x][D]=d[x][D];
	for(int i=1;i<=n;i++)
		for(int j=0;j<=2;j++)
			if(map[x][D][i][j])
				ans=max(ans,d[x][D]+dp(i,j));
	return ans;		
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int ans=0;
	for(int cAse=1;;cAse++)
	{
		scanf("%d",&n);
		if(!n)break;
		memset(f,-1,sizeof(f));
		ans=0;
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&d[i][0],&d[i][1],&d[i][2]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=0;k<=2;k++)
					for(int l=0;l<=2;l++)
							map[i][k][j][l]=nEst(i,k,j,l);
		for(int i=1;i<=n;i++)
			for(int j=0;j<=2;j++)
				ans=max(ans,dp(i,j));
		printf("Case %d: maximum height = %d\n",cAse,ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


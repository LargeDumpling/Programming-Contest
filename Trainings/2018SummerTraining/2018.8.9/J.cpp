/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-09	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1024;
int n,m,f[2][MAXN][MAXN][10][10],last[52],Log[MAXN];
long long ans=0;
char str[MAXN][MAXN];
int idx(char ch)
{
	if('A'<=ch&&ch<='Z')
		return ch-'A';
	return ch-'a'+26;
}
void pre_calc()
{
	Log[0]=-1;
	for(int i=1;i<MAXN;i++)
		Log[i]=Log[i>>1]+1;
	for(int i=n-1;0<=i;i--)
	{
		for(int j=0;j<52;j++)
			last[j]=m;
		for(int j=m-1;0<=j;j--)
		{
			f[0][i][j][0][0]=last[idx(str[i][j])];
			for(int k=1;k<10;k++)
			{
				if(j+(1<<(k-1))<m)
					f[0][i][j][0][k]=min(f[0][i][j][0][k-1],f[0][i][j+(1<<(k-1))][0][k-1]);
				if(i+(1<<(k-1))<n)
					f[0][i][j][k][0]=min(f[0][i][j][k-1][0],f[0][i+(1<<(k-1))][j][k-1][0]);
			}
			last[idx(str[i][j])]=j;
		}
	}
	for(int j=m-1;0<=j;j--)
	{
		for(int i=0;i<52;i++)
			last[i]=n;
		for(int i=n-1;0<=i;i--)
		{
			f[1][i][j][0][0]=last[idx(str[i][j])];
			for(int k=1;k<10;k++)
			{
				if(j+(1<<(k-1))<m)
					f[1][i][j][0][k]=min(f[1][i][j][0][k-1],f[1][i][j+(1<<(k-1))][0][k-1]);
				if(i+(1<<(k-1))<n)
					f[1][i][j][k][0]=min(f[1][i][j][k-1][0],f[1][i+(1<<(k-1))][j][k-1][0]);
			}
			last[idx(str[i][j])]=i;
		}
	}
	for(int k=0;k<2;k++)
		for(int i=n-1;0<=i;i--)
			for(int j=m-1;0<=j;j--)
				for(int ht=1;ht<10&&(1<<ht)<=n;ht++)
				{
					for(int hw=1;hw<10&&(1<<hw)<=m;hw++)
					{
						/*f[k][i][j][ht][hw]=min(
								min(f[k][i][j][ht-1][hw-1]
									,f[k][i][j+(1<<(hw-1))][ht-1][hw-1]),
								min(f[k][i+(1<<(ht-1))][j][ht-1][hw-1]
									,f[k][i+(1<<(ht-1))][j+(1<<(hw-1))][ht-1][hw-1])
								);*/
						f[k][i][j][ht][hw]=f[k][i][j][ht-1][hw-1];
						if(i+(1<<(ht-1))<n)
						{
							f[k][i][j][ht][hw]=min(f[k][i][j][ht][hw],f[k][i+(1<<(ht-1))][j][ht-1][hw-1]);
							if(j+(1<<(hw-1))<m)
								f[k][i][j][ht][hw]=min(f[k][i][j][ht][hw]
										,f[k][i+(1<<(ht-1))][j+(1<<(hw-1))][ht-1][hw-1]);
						}
						if(j+(1<<(hw-1))<m)
							f[k][i][j][ht][hw]=min(f[k][i][j][ht][hw] ,f[k][i][j+(1<<(hw-1))][ht-1][hw-1]);
					}
				}
	return;
}
int query(int x1,int y1,int x2,int y2,int k)
{
	int ht=Log[x2-x1+1],hw=Log[y2-y1+1];
	return min(
			min(f[k][x1][y1][ht][hw]
				,f[k][x1][y2-(1<<hw)+1][ht][hw])
			,min(f[k][x2-(1<<ht)+1][y1][ht][hw]
				,f[k][x2-(1<<ht)+1][y2-(1<<hw)+1][ht][hw])
			);
}
int main()
{
	//freopen("J.in","r",stdin);
	int r,limit;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",str[i]);
	pre_calc();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			limit=f[0][i][r=j][0][0];
			while(r<limit-1&&r<m-1)
				limit=min(limit,f[0][i][++r][0][0]);
			ans=ans+(r-j+1);
			for(int h=1;i+h<n&&j<=r;h++)
			{
				while(j<=r&&(query(i,j,i+h,r,0)<=r||query(i,j,i+h,r,1)<=i+h))
					r--;
				if(j<=r) ans=ans+(r-j+1);
			}
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


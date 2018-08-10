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
const int M=1024;
int n,m,f[2][MAXN][M<<1],last[52],Log[MAXN];
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
			f[0][i][j+M]=last[idx(str[i][j])];
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
int main()
{
	//freopen("J.in","r",stdin);
	int limith,limitw,h,w;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
		scanf("%s",str[i]+1);
	pre_calc();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			h=w; w=j;
			limitw=f[0][i][j+M];
			limith=f[1][i][j+M];
			while(w<limitw-1&&w<m)
			{
				w++;
				limitw=min(limitw,f[0][i][w+M]);
				limith=min(limith,f[1][i][w+M]);
			}
			ans=ans+(w-j+1);
			for(int h=i+1;h<ceil&&h<=n&&j<=r;h++)
			while(h<limith-1&&h<n)
			{
				while(j<=r&&(query(h,j,r,0)<=r||query(h,j,r,1)<=h))
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


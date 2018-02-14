/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,n;
int num[25][25];
char com[10];
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		memset(num,0,sizeof(num));
		scanf("%d%s",&n,com);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&num[i][j]);
		if(com[0]=='l')
		{
			for(int i=1,k;i<=n;i++)
			{
				for(int j=k=1;j<=n;j++) if(num[i][j])
					num[i][k++]=num[i][j];
				while(k<=n) num[i][k++]=0;
				for(int j=1;j<=n;j++)
				{
					if(num[i][j]==num[i][j+1]&&num[i][j])
					{
						num[i][j]+=num[i][j+1];
						for(int k=j+1;k<=n;k++)
							num[i][k]=num[i][k+1];
					}
				}
			}
		}
		else if(com[0]=='r')
		{
			for(int i=1,k;i<=n;i++)
			{
				for(int j=k=n;j;j--) if(num[i][j])
					num[i][k--]=num[i][j];
				while(k) num[i][k--]=0;
				for(int j=n;j;j--)
				{
					if(num[i][j]==num[i][j-1]&&num[i][j])
					{
						num[i][j]+=num[i][j-1];
						for(int k=j-1;k;k--)
							num[i][k]=num[i][k-1];
					}
				}
			}
		}
		else if(com[0]=='u')
		{
			for(int j=1,k;j<=n;j++)
			{
				for(int i=k=1;i<=n;i++) if(num[i][j])
					num[k++][j]=num[i][j];
				while(k<=n) num[k++][j]=0;
				for(int i=1;i<=n;i++)
				{
					if(num[i][j]==num[i+1][j]&&num[i][j])
					{
						num[i][j]+=num[i+1][j];
						for(int k=i+1;k<=n;k++)
							num[k][j]=num[k+1][j];
					}
				}
			}
		}
		else if(com[0]=='d')
		{
			for(int j=n,k;j;j--)
			{
				for(int i=k=n;i;i--) if(num[i][j])
					num[k--][j]=num[i][j];
				while(k) num[k--][j]=0;
				for(int i=n;i;i--)
				{
					if(num[i][j]==num[i-1][j]&&num[i][j])
					{
						num[i][j]+=num[i-1][j];
						for(int k=i-1;k;k--)
							num[k][j]=num[k-1][j];
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				printf("%d%c",num[i][j],j==n?'\n':' ');
	}
	fclose(stdout);
	return 0;
}


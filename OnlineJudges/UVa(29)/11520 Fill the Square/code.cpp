/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-02-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char grid[15][15];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T_T,n;
	scanf("%d",&T_T);
	for(int cAse=1;cAse<=T_T;cAse++)
	{
		printf("Case %d:\n",cAse);
		scanf("%d",&n);
		for(int i=0;i<=n+1;i++)
			memset(grid[i],0,sizeof(grid[i]));
		for(int i=1;i<=n;i++)
			scanf("%s",grid[i]+1);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(grid[i][j]!='.') continue;
				for(int k='A';k<='Z';k++)
				{
					grid[i][j]=k;
					if(grid[i][j]!=grid[i][j-1]
					&&grid[i][j]!=grid[i][j+1]
					&&grid[i][j]!=grid[i-1][j]
					&&grid[i][j]!=grid[i+1][j])
						break;
				}
			}
			grid[i][n+1]='\0';
			printf("%s\n",grid[i]+1);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


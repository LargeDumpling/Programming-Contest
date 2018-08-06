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
const int MAXN=55;
int T_T,n,m,mOve[4][2]={{1,0},{0,1},{-1,0},{0,-1}},ans=-1;
char str[MAXN][MAXN];
int check(int x,int y,int k)
{
	int cnt=0;
	while(0<=x&&x<n&&0<=y&&y<m)
	{
		x+=mOve[k][0];
		y+=mOve[k][1];
		if(x<0||n<=x||y<0||m<=y)
			break;
		if(str[x][y]=='#')
			return -1;
		cnt++;
	}
	return cnt;
}
int main()
{
	int tem;
	scanf("%d",&T_T);
	while(T_T--)
	{
		ans=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%s",str[i]);
		for(int i=0;i<n&&ans!=-1;i++)
			for(int j=0;j<m&&ans!=-1;j++)
				if(str[i][j]=='S')
				{
					for(int k=0;k<4&&ans!=-1;k++)
					{
						tem=check(i,j,k);
						if(tem==-1) ans=-1;
						else ans+=tem;
					}
				}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


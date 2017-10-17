/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char nAme[1050];
int num[105][105],f[105][105],T,R,C;
int move[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int dp(int x,int y)
{
	if(f[x][y]!=-1)return f[x][y];
	int xx,yy;
	f[x][y]=1;
	for(int k=0;k<4;k++)
	{
		xx=x+move[k][0]; yy=y+move[k][1];
		if(1<=xx&&xx<=R&&1<=yy&&yy<=C&&num[xx][yy]<num[x][y])
			 f[x][y]=max(f[x][y],dp(xx,yy)+1);
	}
	return f[x][y];
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	bool flag;
	int xx,yy,ans=1;
	scanf("%d",&T);
	while(T--)
	{
		memset(f,-1,sizeof(f));
		scanf("%s%d%d",nAme,&R,&C);
		ans=1;
		for(int i=1;i<=R;i++)
			for(int j=1;j<=C;j++)
				scanf("%d",&num[i][j]);
		for(int i=1;i<=R;i++)
			for(int j=1;j<=C;j++)
			{
				flag=true;
				for(int k=0;k<4;k++)
				{
					xx=i+move[k][0]; yy=j+move[k][1];
					if(1<=xx&&xx<=R&&1<=yy&&yy<=C&&num[xx][yy]>num[i][j])
						flag=false;
				}
				if(flag)ans=max(ans,dp(i,j));
			}
		printf("%s: %d\n",nAme,ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


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
#include<queue>
#include<algorithm>
using namespace std;
int n,xl[1050],yl[1050];
float dis[1050][1050],f[1050][1050];
bool exist[1050][1050];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int x,y;
	queue<int>q;
	while(scanf("%d",&n)==1)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&xl[i],&yl[i]);
			for(int j=1;j<i;j++)
				dis[i][j]=dis[j][i]=sqrt((xl[i]-xl[j])*(xl[i]-xl[j])+(yl[i]-yl[j])*(yl[i]-yl[j]));
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=2147483647;
		f[1][1]=0;
		while(q.size())q.pop();
		q.push(1*10000+1);
		exist[1][1]=true;
		while(q.size())
		{
			x=q.front();
			q.pop();
			y=x%10000;
			x/=10000;
			exist[x][y]=false;
			if(f[x][y]+dis[x][x+1]<f[x+1][y])
			{
				f[x+1][y]=f[x][y]+dis[x][x+1];
				if(!exist[x+1][y])
				{
					exist[x+1][y]=true;
					q.push((x+1)*10000+y);
				}
			}
			if(f[x][y]+dis[y][x+1]<f[x+1][x])
			{
				f[x+1][x]=f[x][y]+dis[y][x+1];
				if(!exist[x+1][x])
				{
					exist[x+1][x]=true;
					q.push((x+1)*10000+x);
				}
			}
		}
		for(int i=1;i<n;i++)
			f[n][n]=min(f[n][n],f[n][i]+dis[i][n]);
		printf("%.2f\n",f[n][n]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-04-13	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=105;
int n,m;
int dis[MAXN][MAXN],move[4][2]={{0,1},{0,-1},{1,0},{-1,0}},mAx;
char str[MAXN];
void write1n(int x,int dig)
{
	int s[4];
	for(s[0]=0;x;x/=10)
		s[++s[0]]=x%10;
	for(int i=1;i<=dig-s[0];i++)
		putchar('.');
	while(s[0]) putchar('0'+s[s[0]--]);
	return;
}
int main()
{
	int x,y,xx,yy;
	queue<int> q;
	scanf("%d%d",&n,&m);
	mAx=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str+1);
		for(int j=1;j<=m;j++)
			if(str[j]=='T')
				dis[i][j]=-1;
			else
			{
				dis[i][j]=0;
				q.push(i*1000+j);
			}
	}
	for(int i=0;i<=m+1;i++)
	{
		dis[0][i]=dis[n+1][i]=0;
		q.push(i);
		q.push((n+1)*1000+i);
	}
	for(int i=1;i<=n;i++)
	{
		dis[i][0]=dis[i][m+1]=0;
		q.push(i*1000);
		q.push(i*1000+m+1);
	}
	while(q.size())
	{
		x=q.front(); q.pop();
		y=x%1000; x/=1000;
		mAx=max(mAx,dis[x][y]);
		for(int i=0;i<4;i++)
		{
			xx=x+move[i][0]; yy=y+move[i][1];
			if(1<=xx&&xx<=n&&1<=yy&&yy<=m&&dis[xx][yy]==-1)
			{
				dis[xx][yy]=dis[x][y]+1;
				q.push(xx*1000+yy);
			}
		}
	}
	if(10<=mAx) mAx=3;
	else mAx=2;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			write1n(dis[i][j],mAx);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


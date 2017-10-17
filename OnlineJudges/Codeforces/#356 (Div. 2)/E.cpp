/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-06-26	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int n,k,move[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int bel[550][550],havajho[550],ccn=0,bestans=0;
char map[550][550];
void DFS(int x,int y,int ccnum)
{
	if(x<0||y<0||n<x||n<y) return;
	havajho[ccnum]++;
	bel[x][y]=ccnum;
	for(int i=0;i<4;i++)
		DFS(x+move[i][0],y+move[i][1],ccnum);
	return;
}
int main()
{
	scanf("%d%d",&n,&k);
	memset(bel,-1,sizeof(bel));
	for(int i=1;i<=n;i++) scanf("%s",map[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) if(map[i][j]=='.'&&bel[i][j]==-1)
			DFS(i,j,ccn);
	int in[550];
	bool con[550];
	for(int i=k;i<=n;i++)
	{
		memset(in,0,sizeof(in));
		memset(con,false,sizeof(con));
		for(int j=i-k+1;j<=i;j++)
			for(int l=1;l<=k;l++) if(bel[j][l]!=-1)
				in[bel[j][l]]++;
		if(k<i)
			for(int l=1;l<=k;l++)
				if(bel[i-k][l]!=-1)
					con[bel[i-k][l]]=true;
		for(int j=k;j<=n;j++)
		{
			int cnt=0;
			if(k<i)
		}
	}
}


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define cOde(a,b) ((a-1)/3*3+(b-1)/3+1)
using namespace std;
int score[10][10]={ {0,0,0,0,0,0,0,0,0,0},
					{0,6,6,6,6,6,6,6,6,6},
					{0,6,7,7,7,7,7,7,7,6},
					{0,6,7,8,8,8,8,8,7,6},
					{0,6,7,8,9,9,9,8,7,6},
					{0,6,7,8,9,10,9,8,7,6},
					{0,6,7,8,9,9,9,8,7,6},
					{0,6,7,8,8,8,8,8,7,6},
					{0,6,7,7,7,7,7,7,7,6},
					{0,6,6,6,6,6,6,6,6,6}};
bool c[10][10],r[10][10],g[10][10];
int num[10][10],ans=-1;
void DFS(int x,int y)
{
	int xx,yy;
	if(y==9) xx=x+1,yy=1;
	else xx=x,yy=y+1;
	if(9<x)
	{
		int sum=0;
		for(int i=1;i<=9;i++)
			for(int j=1;j<=9;j++)
				sum+=score[i][j]*num[i][j];
		ans=max(ans,sum);
	}
	else
	{
		if(num[x][y]!=0)
			DFS(xx,yy);
		else for(int i=1;i<=9;i++) if(!c[y][i]&&!r[x][i]&&!g[cOde(x,y)][i])
		{
			c[y][i]=true;
			r[x][i]=true;
			g[cOde(x,y)][i]=true;
			num[x][y]=i;
			DFS(xx,yy);
			num[x][y]=0;
			c[y][i]=false;
			r[x][i]=false;
			g[cOde(x,y)][i]=false;
		}
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
		{
			scanf("%d",&num[i][j]);
			c[j][num[i][j]]=true;
			r[i][num[i][j]]=true;
			g[cOde(i,j)][num[i][j]]=true;
		}
	DFS(1,1);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


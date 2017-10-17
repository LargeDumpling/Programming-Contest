#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define head q[0]
#define tail q[1000049]
using namespace std;
int n,m,k,stx,sty,move[4][2]={{0,1},{1,0},{0,-1},{-1,0}},ord[10050],q[1000050];
bool map[55][55],exist[55][55],inq[1050][55][55];
int inc(int &x){return (++x)>1000048?x-1000048:x;}
void BFS()
{
	int x,y,xx,yy,u;
	q[inc(tail)]=10000+stx*100+sty;
	while(head!=tail)
	{
		u=q[inc(head)];
		y=u%100;
		u/=100;
		x=u%100;
		u/=100;
		inq[u][x][u]=false;
		if(u==k+1)
		{
			exist[x][y]=true;
			continue;
		}
		for(int i=1;;i++)
		{
			xx=x+move[ord[u]][0]*i;
			yy=y+move[ord[u]][1]*i;
			if(!map[xx][yy]||xx<1||xx>n||yy<1||yy>m)
				break;
			if(!inq[u+1][xx][yy])
			{
				q[inc(tail)]=(u+1)*10000+xx*100+yy;
				inq[u+1][xx][yy]=true;
			}
		}
	}
	return;
}
int main()
{
	char ch[55];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",ch+1);
		for(int j=1;j<=m;j++)
		{
			map[i][j]=true;
			if(ch[j]=='X')
				map[i][j]=false;
			if(ch[j]=='*')
				stx=i,sty=j;
		}
	}
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%s",ch);
		if(ch[0]=='E')
			ord[i]=0;
		else if(ch[0]=='S')
			ord[i]=1;
		else if(ch[0]=='W')
			ord[i]=2;
		else if(ch[0]=='N')
			ord[i]=3;
	}
	BFS();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			if(!map[i][j])
				printf("X");
			else if(exist[i][j])
				printf("*");
			else
				printf(".");
		printf("\n");
	}
	return 0;
}


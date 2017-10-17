#include<iostream>
#include<cstdio>
#include<cstdlib> 
#include<cstring>
#include<cmath>
#include<algorithm>
#define min(a,b) (a<b?a:b)
using namespace std;
bool map[30][30],exist[30][30][4][5];
int move[4][2]={{-1,0},{0,1},{1,0},{0,-1}},dis[30][30][4][5],q[100001],x,y,xx,yy,zx,zy,sx,sy,n,m;
int inc(int &x){return ++x>99999?x-99999:x;}
void BFS()
{
	int x,y,xx,yy,und,fac;
	while(q[0]!=q[100000])
	{
		x=q[inc(q[0])];
		und=x%10;x/=10;
		fac=x%10;x/=10;
		y=x%100;x/=100;
		exist[x][y][fac][und]=false;
		if(dis[x][y][fac][und]+1<dis[x][y][(fac+1)%4][und])
		{
			dis[x][y][(fac+1)%4][und]=dis[x][y][fac][und]+1;
			if(!exist[x][y][(fac+1)%4][und])
			{
				q[inc(q[100000])]=x*10000+y*100+((fac+1)%4)*10+und;
				exist[x][y][(fac+1)%4][und]=true;
			}
		}
		if(dis[x][y][fac][und]+1<dis[x][y][(fac+3)%4][und])
		{
			dis[x][y][(fac+3)%4][und]=dis[x][y][fac][und]+1;
			if(!exist[x][y][(fac+3)%4][und])
			{
				q[inc(q[100000])]=x*10000+y*100+((fac+3)%4)*10+und;
				exist[x][y][(fac+3)%4][und]=true;
			}
		}
		xx=x+move[fac][0];
		yy=y+move[fac][1];
		if(1<=xx&&xx<=n&&1<=yy&&yy<=m&&map[xx][yy]&&dis[x][y][fac][und]+1<dis[xx][yy][fac][(und+1)%5])
		{
			dis[xx][yy][fac][(und+1)%5]=dis[x][y][fac][und]+1;
			if(!exist[xx][yy][fac][(und+1)%5])
			{
				q[inc(q[100000])]=xx*10000+yy*100+fac*10+(und+1)%5;
				exist[xx][yy][fac][(und+1)%5]=true;
			}
		}
	}
	return;
}
int main()
{
	int ans;
	char tex[30];
	for(int T=1;;T++)
	{
		scanf("%d%d",&n,&m);
		if(!n&&!m)
			return 0;
		memset(dis,127,sizeof(dis));
		memset(map,true,sizeof(map));
		memset(exist,false,sizeof(exist));
		if(T>1)
			printf("\n"); 
		for(int i=1;i<=n;i++)
		{
			scanf("%s",tex+1);
			for(int j=1;j<=m;j++)
			{
				if(tex[j]=='#')
					map[i][j]=false;
				else if(tex[j]=='S')
					sx=i,sy=j;
				else if(tex[j]=='T')
					zx=i,zy=j;
			}
		}
		dis[sx][sy][0][0]=0;q[0]=q[100000]=0;
		q[inc(q[100000])]=sx*10000+sy*100+0*10+0;
		BFS();
		ans=2147483647;
		for(int i=0;i<4;i++)
			ans=min(ans,dis[zx][zy][i][0]);
		printf("Case #%d\n",T);
		if(ans==2139062143)
			printf("destination not reachable\n");
		else
			printf("minimum time = %d sec\n",ans);
	}
	return 0; 
}


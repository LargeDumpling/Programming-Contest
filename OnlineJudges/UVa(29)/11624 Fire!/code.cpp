#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n,m,x,y,xx,yy,sx,sy,dis[1050][1050],FT[1050][1050],move[4][2]={{0,1},{1,0},{0,-1},{-1,0}},q[10000050];
bool map[1050][1050],exist[1050][1050];
int inc(int &x){return x=(++x)>10000048?x-10000048+1:x;}
void Fire()
{
	while(q[0]!=q[10000049])
	{
		x=q[inc(q[0])];
		y=x%10000;x/=10000;
		exist[x][y]=false;
		for(int i=0;i<4;i++)
		{
			xx=x+move[i][0];yy=y+move[i][1];
			if(xx<1||xx>n||yy<1||yy>m||!map[xx][yy]||FT[x][y]+1>=FT[xx][yy])
				continue;
			FT[xx][yy]=FT[x][y]+1;
			if(exist[xx][yy])
				continue;
			q[inc(q[10000049])]=xx*10000+yy;
			exist[xx][yy]=true;
		}
	}
	return;
}
void Joe()
{
	q[0]=q[10000049]=0;
	memset(exist,false,sizeof(exist));
	q[inc(q[10000049])]=sx*10000+sy;
	while(q[0]!=q[10000049])
	{
		x=q[inc(q[0])];
		y=x%10000;x/=10000;
		exist[x][y]=false;
		for(int i=0;i<4;i++)
		{
			xx=x+move[i][0];yy=y+move[i][1];
			if(!map[xx][yy]||dis[x][y]+1>=FT[xx][yy]||dis[x][y]+1>=dis[xx][yy])
				continue;
			else if(xx<1||xx>n||yy<1||yy>m)
			{
				if(dis[1049][1049]>dis[x][y]+1)
					dis[1049][1049]=dis[x][y]+1;
				continue;
			}
			dis[xx][yy]=dis[x][y]+1;
			if(exist[xx][yy])
				continue;
			q[inc(q[10000049])]=xx*10000+yy;
			exist[xx][yy]=true;
		}
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	char tex[1050];
	scanf("%d",&T);
	while(T--)
	{
		q[0]=q[10000049]=0;
		memset(dis,127,sizeof(dis));
		memset(FT,127,sizeof(FT));
		memset(map,true,sizeof(map));
		memset(exist,false,sizeof(exist));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",tex+1);
			for(int j=1;j<=m;j++)
				if(tex[j]=='#')
					map[i][j]=false;
				else if(tex[j]=='J')
					dis[sx=i][sy=j]=0;
				else if(tex[j]=='F')
					q[inc(q[10000049])]=i*10000+j,FT[i][j]=0,exist[i][j]=true;
		}
		Fire();
		Joe();
		if(dis[1049][1049]==2139062143)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n",dis[1049][1049]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


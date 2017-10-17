#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int Y[11][4],n,dist[11][11];
bool acc[11][4][11][4];
int cross(int x1,int y1,int x2,int y2){return (x1*y2-x2*y1);}
bool intersect(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
	return (cross(x3-x1,y3-y1,x2-x1,y2-y1)>0&&cross(x2-x1,y2-y1,x4-x1,y4-y1)>0
		&& cross(x2-x3,y2-y3,x4-x3,y4-y3)>0&&cross(x4-x3,y4-y3,x1-x3,y1-y3));
}
bool aCc(int x,int y,int x1,int y1,int x2,int y2)
{
	for(int i=x+1;i<y;i++)
	{
		if(!Y[i][0]&&!Y[i][1]&&!Y[i][2]&&!Y[i][3])
			continue;
		if(intersect(x1,y1,x2,y2,i,0,i,Y[i][0]))
			return false;
		if(intersect(x1,y1,x2,y2,i,Y[i][1],i,Y[i][2]))
			return false;
		if(intersect(x1,y1,x2,y2,i,Y[i][3],i,10))
			return false;
	}
	return true;
}
void DP()
{
	dis[0][1]=0;
	for(int i=1;i<=10;i++)
	{
		if(!Y[i][0]&&!Y[i][1]&&!Y[i][2]&&!Y[i][3])
			continue;
		for(int k=0;k<=3;k++)
		{
			for(int j=0;j<i;j++)
			{
				for(int l=0;l<=3;l++)
				{
					if(acc[i][k][j][l])
					{
						dis[i][k]
					}
				}
			}
		}
	}
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int temp;
	Y[0][0]=Y[10][0]=5;
	while(true)
	{
		scanf("%d",&n);
		if(n==-1)
			break;
		for(int i=0;i<=n;i++)
		{
			scanf("%d",&temp);
			scanf("%d%d%d%d",&Y[temp][0],&Y[temp][1],&Y[temp][2],&Y[temp][3]);
			for(int j=0;j<i;j++)
				for(int k=0;k<4;k++)
					for(int l=0;l<4;l++)
						acc[i][k][j][l]=aCc(i,k,j,l);
		}
		for(int 
		DP();
		printf("%.2f\n",dis[10][5]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


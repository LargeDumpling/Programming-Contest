/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-17	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,k;
int mov[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int q[4000050][2],dis[2050][2050],vis[2050][2050],head,tail,ansx,ansy;
int main()
{
	int x,y,xx,yy,T=0;
	while(scanf("%d%d",&n,&m)!=-1)
	{
		T++;
		head=tail=0;
		dis[ansx=0][ansy=0]=-1;
		scanf("%d",&k);
		for(int i=1;i<=k;i++)
		{
			scanf("%d%d",&x,&y);
			q[tail][0]=x;
			q[tail][1]=y;
			tail++;
			dis[x][y]=0;
			vis[x][y]=T;
		}
		while(head<tail)
		{
			y=q[head][0];
			x=q[head][1];
			head++;
			for(int i=0;i<4;i++)
			{
				xx=x+mov[i][0];
				yy=y+mov[i][1];
				if(1<=xx&&xx<=n&&1<=yy&&yy<=m&&vis[xx][yy]!=T)
				{
					vis[xx][yy]=T;
					dis[xx][yy]=dis[x][y]+1;
					if(dis[ansx][ansy]<dis[xx][yy])
					{
						ansx=xx;
						ansy=yy;
					}
					else if(dis[ansx][ansy]==dis[xx][yy])
					{
						if(ansx==xx) ansy=min(ansy,yy);
						else
						{
							ansx=xx;
							ansy=yy;
						}
					}
					q[tail][0]=xx;
					q[tail][1]=yy;
					tail++;
				}
			}
		}
		printf("%d %d\n",ansx,ansy);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


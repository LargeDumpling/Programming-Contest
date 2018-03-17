/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-10	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=505;
char map[MAXN][MAXN];
int R,C,mOve[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main()
{
	int xx,yy;
	bool flag=true;
	scanf("%d%d",&R,&C);
	for(int i=1;i<=R;i++)
		scanf("%s",map[i]+1);
	for(int i=1;i<=R;i++)
		for(int j=1;j<=C;j++) if(map[i][j]=='W')
		{
			for(int k=0;k<4;k++)
			{
				xx=i+mOve[k][0];
				yy=j+mOve[k][1];
				if(xx<1||R<xx||yy<1||C<yy) continue;
				if(map[xx][yy]=='S') flag=false;
			}
		}
	if(flag)
	{
		puts("Yes");
		for(int i=1;i<=R;i++)
			for(int j=1;j<=C;j++) if(map[i][j]=='S')
			{
				for(int k=0;k<4;k++)
				{
					xx=i+mOve[k][0];
					yy=j+mOve[k][1];
					if(xx<1||R<xx||yy<1||C<yy) continue;
					if(map[xx][yy]=='.') map[xx][yy]='D';
				}
			}
		for(int i=1;i<=R;i++)
			puts(map[i]+1);
	}
	else puts("No");
	fclose(stdin);
	fclose(stdout);
	return 0;
}


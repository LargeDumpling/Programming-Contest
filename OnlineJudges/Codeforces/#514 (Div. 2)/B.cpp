/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-05	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1050;
int n,m,mov[8][2]={{0,0},{0,1},{0,2},{1,0},{1,2},{2,0},{2,1},{2,2}};
bool vis[MAXN][MAXN],able[MAXN][MAXN];
char str[MAXN][MAXN];
bool check(int x,int y,int k)
{
	int xx,yy;
	for(int i=0;i<8;i++)
	{
		xx=x+mov[i][0]-mov[k][0];
		yy=y+mov[i][1]-mov[k][1];
		if(xx<1||n<xx||yy<1||m<yy||str[xx][yy]!='#')
			return false;
	}
	return true;
}
int main()
{
	bool flag=true;
	memset(vis,false,sizeof(vis));
	memset(able,true,sizeof(able));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",str[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) if(str[i][j]=='#')
		{
			bool cur=false;
			for(int k=0;k<8;k++)
				cur|=check(i,j,k);
			flag&=cur;
		}
	}
	if(flag) puts("YES");
	else puts("NO");
	fclose(stdin);
	fclose(stdout);
	return 0;
}


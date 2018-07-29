/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=2050;
int T_T,n,m,hx,hy;
char map[MAXN][MAXN];
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%s",map[i]);
		hx=n/2-1;
		hy=m/2-1;
		for(int i=0;i<n/2&&hx&&hy;i++)
			for(int j=0;j<m/2&&hx&&hy;j++)
			{
				if(map[i][j]==map[n-1-i][j]&&map[i][j]==map[n-1-i][m-1-j]&&map[i][j]==map[i][m-1-j]);
				else
				{
					hx=min(hx,i);
					hy=min(hy,j);
				}
			}
		if(hx==0||hy==0) puts("0");
		else printf("%d\n",hx*hy);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


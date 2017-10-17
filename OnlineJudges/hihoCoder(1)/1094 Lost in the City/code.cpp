#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char map[205][205],hi[5][5];
int n,m;
void swap(char &a,char &b)
{
	a^=b;
	b=a^b;
	a^=b;
	return;
}
void rotate()
{
	swap(hi[1][1],hi[3][3]);
	swap(hi[1][1],hi[3][1]);
	swap(hi[1][3],hi[3][3]);
	swap(hi[1][2],hi[2][3]);
	swap(hi[2][1],hi[3][2]);
	swap(hi[1][2],hi[3][2]);
	return;
}
bool check(int x,int y)
{
	if(
	map[x-1][y-1]==hi[1][1]&&
	map[x-1][y]==hi[1][2]&&
	map[x-1][y+1]==hi[1][3]&&
	map[x][y-1]==hi[2][1]&&
	map[x][y]==hi[2][2]&&
	map[x][y+1]==hi[2][3]&&
	map[x+1][y-1]==hi[3][1]&&
	map[x+1][y]==hi[3][2]&&
	map[x+1][y+1]==hi[3][3])
		return true;
	return false;
}
int main()
{
	freopen("code.in","r",stdin);
	int i,j;
	bool flag;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%s",map[i]+1);
	for(i=1;i<=3;i++)
		scanf("%s",hi[i]+1);
	for(i=2;i<n;i++)
		for(j=2;j<m;j++)
		{
			if(map[i][j]!=hi[2][2])
				continue;
			flag=false;
			flag|=check(i,j);
			rotate();
			flag|=check(i,j);
			rotate();
			flag|=check(i,j);
			rotate();
			flag|=check(i,j);
			if(flag)
				printf("%d %d\n",i,j);
		}
	return 0;
}


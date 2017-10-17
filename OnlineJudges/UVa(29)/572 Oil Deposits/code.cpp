#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,idx[105][105],cnt;
char map[105][105];
void DFS(int x,int y,int num)
{
	if(x<0||x>n||y<0||y>m)
		return;
	if(map[x][y]!='@'||idx[x][y])
		return;
	idx[x][y]=num;
	for(int i=-1;i<=1;i++)
		for(int j=-1;j<=1;j++)
		{
			if((!i)&&(!j))
				continue;
			DFS(x+i,y+j,num);
		}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	while(true)
	{
		scanf("%d%d",&n,&m);
		if(!n&&!m)
			break;
		memset(idx,cnt=0,sizeof(idx));
		for(int i=1;i<=n;i++)
			scanf("%s",map[i]+1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(map[i][j]=='@'&&!idx[i][j])
					DFS(i,j,++cnt);
		printf("%d\n",cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


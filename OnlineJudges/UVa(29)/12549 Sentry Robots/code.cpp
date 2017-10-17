/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int map[105][105][2],rIght[10050],n,m,T,Ln,Rn;
bool exist[100050];
vector<int>lEft[10050];
bool fInd(int x)
{
	int v;
	for(unsigned i=0;i<lEft[x].size();i++)
	{
		v=lEft[x][i];
		if(!exist[v])
		{
			exist[v]=true;
			if(!rIght[v]||fInd(rIght[v]))
			{
				rIght[v]=x;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int q,x,y,k,ans;
	bool flag;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		memset(map,0,sizeof(map));
		memset(rIght,0,sizeof(rIght));
		scanf("%d",&q);
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&x,&y);
			map[x][y][0]=map[x][y][1]=-1;
		}
		for(int i=0;i<10050;i++)lEft[i].clear();
		scanf("%d",&q);
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&x,&y);
			map[x][y][0]=map[x][y][1]=-2;
		}
		Ln=Rn=0;
		for(int i=1;i<=n;i++)
		{
			flag=false;
			for(int j=1;j<=m;j++)
				if(map[i][j][0]==-1&&!flag)
				{
					map[i][j][0]=++Ln;
					flag=true;
				}
				else if(flag&&map[i][j][0]==-1)map[i][j][0]=Ln;
				else if(flag&&map[i][j][0]==-2)flag=false;
		}
		for(int j=1;j<=m;j++)
		{
			flag=false;
			for(int i=1;i<=n;i++)
			{
				if(map[i][j][1]==-1&&!flag)
				{
					map[i][j][1]=++Rn;
					flag=true;
				}
				else if(flag&&map[i][j][1]==-1)map[i][j][1]=Rn;
				else if(flag&&map[i][j][1]==-2)flag=false;
				if(map[i][j][1]>0)lEft[map[i][j][1]].push_back(map[i][j][0]);
			}
		}
		ans=0;
		for(int i=1;i<=Rn;i++)
		{
			memset(exist,false,sizeof(exist));
			if(fInd(i))ans++;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


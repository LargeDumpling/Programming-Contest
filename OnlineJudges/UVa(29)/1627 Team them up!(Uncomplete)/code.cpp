/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int T,n,cn,col[105],num[105],belong[105];
bool map[105][105];
void init()
{
	int x;
	memset(map,false,sizeof(map));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)while(scanf("%d",&x)!=-1&&x)map[i][x]=true;
	return;
}
/*bool build()
{
	int u,tem;
	memset(col,-1,sizeof(col));
	queue<int>q;
	cn=0;
	for(int sta=1;sta<=n;sta++)if(col[sta]==-1)
	{
		q.push(sta);
		col[sta]=tem=1;
		belong[sta]=cn+1;
		while(q.size())
		{
			u=q.front();
			q.pop();
			for(int i=1;i<=n;i++)if(u!=i&&!(map[u][i]&&map[i][u]))
			{
				if(col[i]==-1)
				{
					belong[i]=cn+1;
					col[i]=col[u]^1;
					if(col[i]==1)tem++;
					else tem--;
					q.push(i);
				}
				else if(!(col[i]^col[u]))
					return false;
			}
		}
		num[++cn]=abs(tem);
	}
	return true;
}*/
bool DFS(int u,int &tem)
{
	bool flag=true;
	belong[u]=cn+1;
	for(int i=1;i<=n&&flag;i++)if(u!=i&&!(map[u][i]&&map[i][u]))
	{
		if(col[i]==-1)
		{
			belong[i]=cn+1;
			col[i]=col[u]^1;
			if(col[i]) tem++;
			else tem--;
			flag=DFS(i,tem);
		}
		else if(col[i]>=0&&!(col[i]^col[u])) return false;
	}
	return flag;
}
bool build()
{
	memset(col,-1,sizeof(col));
	int tem;
	bool flag=true;
	cn=0;
	for(int i=1;i<=n&&flag;i++) if(col[i]==-1)
	{
		col[i]=tem=1;
		flag=DFS(i,tem);
		num[++cn]=abs(tem);
	}
	return flag;
}
bool f[105][210];
void print(int x)
{
	vector<int> A,B;
	int ty[105];
	for(int i=cn;i;i--) if(f[i-1][x-num[i]])
		ty[i]=0,x-=num[i];
	else if(f[i-1][x+num[i]])
		ty[i]=1,x+=num[i];
	for(int i=1;i<=n;i++)if(ty[belong[i]]^col[i])
		A.push_back(i);
	else
		B.push_back(i);
	printf("%d",(int)A.size());
	for(unsigned i=0;i<A.size();i++)printf(" %d",A[i]);
	printf("\n%d",(int)B.size());
	for(unsigned i=0;i<B.size();i++)printf(" %d",B[i]);
	putchar('\n');
	return;
}
void DP()
{
	memset(f,false,sizeof(f));
	f[0][n]=true;
	for(int i=0;i<cn;i++)
		for(int j=num[i+1];j<=(n<<1)-num[i+1];j++)
		{
			f[i+1][j+num[i+1]]|=f[i][j];
			f[i+1][j-num[i+1]]|=f[i][j];
		}
	int temp;
	for(temp=0;!f[cn][n-temp]&&!f[cn][n+temp]&&temp<=n;temp++);
	if(f[cn][n+temp]) print(n+temp);
	else if(f[cn][n-temp]) print(n-temp);
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		init();
		if(n==1||!build())printf("No solution\n");
		else DP();
		if(T)putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


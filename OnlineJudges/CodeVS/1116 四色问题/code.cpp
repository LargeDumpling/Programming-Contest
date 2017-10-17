#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,col[8],ans=0;
bool map[8][8];
void DFS(int u)
{
	if(u==n)
	{
		bool flag=true;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(i!=j&&map[i][j]&&col[i]==col[j])
					flag=false;
		if(flag)
			ans++;
		return;
	}
	for(int i=1;i<=4;i++)
	{
		col[u]=i;
		DFS(u+1);
	}
	return;
}
int main()
{
	int temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			scanf("%d",&temp);
			map[i][j]=map[j][i]=(bool)temp;
		}
	DFS(0);
	printf("%d",ans);
	return 0;
}


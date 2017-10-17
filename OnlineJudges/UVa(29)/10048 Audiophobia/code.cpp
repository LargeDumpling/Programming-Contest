/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int map[105][105];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n,m,q,a,b,c;
	for(int cAse=1;scanf("%d%d%d",&n,&m,&q)==3&&n;cAse++)
	{
		if(cAse!=1)putchar('\n');
		memset(map,127,sizeof(map));
		printf("Case #%d\n",cAse);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			map[a][b]=map[b][a]=min(map[a][b],c);
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)if(k!=i&&k!=j&&i!=j)
					map[i][j]=map[j][i]=min(map[i][j],max(map[i][k],map[k][j]));
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&a,&b);
			if(map[a][b]>2000000000)
				puts("no path");
			else
				printf("%d\n",map[a][b]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


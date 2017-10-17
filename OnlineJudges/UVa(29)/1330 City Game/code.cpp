/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-02-18	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,n,m;
bool map[1050][1050];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	char ord[3];
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%s",ord);
				map[i][j]=ord[0]=='F';
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


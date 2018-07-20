/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=10;
struct jz
{
	int u,v;
}E1[30];
int n,m1,m2;
int E2[MAXN][MAXN],phi[MAXN],ans[50000];
int main()
{
	int u,v;
	while(scanf("%d%d%d",&n,&m1,&m2)!=-1)
	{
		memset(E1,-1,sizeof(E1));
		memset(E2,-1,sizeof(E2));
		for(int i=0;i<m1;i++)
		{
			scanf("%d%d",&E1[i].u,&E1[i].v);
			E1[i].u--; E1[i].v--;
		}
		for(int i=0;i<m2;i++)
		{
			scanf("%d%d",&u,&v);
			u--; v--;
			E2[u][v]=E2[v][u]=i;
		}
		for(int i=0;i<n;i++)
			phi[i]=i;
		ans[0]=0;
		do
		{
			int S=0;
			bool flag=true;
			for(int i=0;i<m1;i++)
			{
				if(E2[phi[E1[i].u]][phi[E1[i].v]]==-1)
				{
					flag=false;
					break;
				}
				else S|=(1<<E2[phi[E1[i].u]][phi[E1[i].v]]);
			}
			if(flag) ans[++ans[0]]=S;
		}while(next_permutation(phi,phi+n));
		sort(ans+1,ans+ans[0]+1);
		ans[0]=unique(ans+1,ans+ans[0]+1)-ans-1;
		printf("%d\n",ans[0]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


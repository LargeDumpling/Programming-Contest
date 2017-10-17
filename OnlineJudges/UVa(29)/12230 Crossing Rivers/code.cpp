/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-08	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int N,D,p,L;
double ans,v;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	for(int cAse=1;scanf("%d%d",&N,&D)!=-1;cAse++)
	{
		if(!N&&!D)break;
		ans=0;
		for(int i=1;i<=N;i++)
		{
			scanf("%d%d%lf",&p,&L,&v);
			ans+=2.0*L/v;
			D-=L;
		}
		ans+=D;
		printf("Case %d: %.3lf\n\n",cAse,ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


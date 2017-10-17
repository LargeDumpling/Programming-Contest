/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-07	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,r;
double P[25],ans[25],tot;
bool exist[25];
void choose(int cur,int deter,double Posi)
{
	if(cur==n)
	{
		if(deter==r)
		{
			tot+=Posi;
			for(int i=1;i<=n;i++)if(exist[i])
				ans[i]+=Posi;
		}
		return;
	}
	if(deter<r&&!exist[cur+1])
	{
		exist[cur+1]=true;
		choose(cur+1,deter+1,Posi*P[cur+1]);
		exist[cur+1]=false;
	}
	choose(cur+1,deter,Posi*(1-P[cur+1]));
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	for(int cAse=1;scanf("%d%d",&n,&r)!=-1;cAse++)
	{
		if(!n&&!r)break;
		printf("Case %d:\n",cAse);
		memset(exist,false,sizeof(exist));
		for(int i=1;i<=n;i++)
		{
			scanf("%lf",&P[i]);
			ans[i]=0;
		}
		tot=0;
		choose(0,0,1);
		for(int i=1;i<=n;i++)printf("%.6lf\n",ans[i]/tot);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


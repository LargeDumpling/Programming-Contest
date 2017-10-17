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
#include<queue>
#include<algorithm>
using namespace std;
double P[1050][1050];
bool exist[1050][1050];
queue<int>q;
double solve(int n,double p)
{
	memset(exist,false,sizeof(exist));
	memset(P,0,sizeof(P));
	double ans=0;
	int x,y;
	P[0][0]=1;
	q.push(0);
	while(q.size())
	{
		x=q.front();q.pop();
		y=x%10000;
		x/=10000;
		if(x==n+1||y==n+1)
		{
			if(x==n+1)
				ans+=(n-y)*P[x][y];
			else if(y==n+1)
				ans+=(n-x)*P[x][y];
			continue;
		}
		P[x+1][y]+=P[x][y]*p;
		if(!exist[x+1][y])
		{
			exist[x+1][y]=true;
			q.push((x+1)*10000+y);
		}
		P[x][y+1]+=P[x][y]*(1-p);
		if(!exist[x][y+1])
		{
			exist[x][y+1]=true;
			q.push(x*10000+y+1);
		}
	}
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	int n;
	double p;
	for(int cAse=1;scanf("%d%lf",&n,&p)!=-1;cAse++)printf("Case %d: %.6lf\n",cAse,solve(n,p));
	fclose(stdin);
	fclose(stdout);
	return 0;
}


/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-13	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int pri[15050],en[15050],ans;
bool exist[15050];
void pre_calc()
{
	int t;
	memset(exist,true,sizeof(exist));
	for(int i=2;i<=15000;i++)
	{
		if(exist[i])pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&(t=i*pri[j])<=15050;j++)
		{
			exist[t]=false;
			if(!(i%pri[j]))break;
		}
	}
	return;
}
bool check(int x)
{
	if(x==2)return true;
	int limit=sqrt(x)+1;
	for(int i=2;i<=limit;i++)if(!(x%i))return false;
	for(int i=1;i<=en[0];i++)if(en[i]==x&&exist[i])return false;
	return true;
}
void DFS(int x,int now,int rem)
{
	if(now>=ans)return;
	if(x==en[0])
	{
		if(check(rem+1))
		{
			if(rem==1)
				rem=0; 
			now*=(rem+1);
			ans=min(ans,now);
		}
		return;
	}
	//if(now==1&&check(rem+1))
		//ans=min(ans,rem+1);
	//for(int i=x+1;i<=en[0];i++)
	DFS(x+1,now,rem);
	if(!(rem%(en[x+1]-1)))
	{
		rem/=(en[x+1]-1);
		now*=en[x+1];
		exist[x+1]=true;
		DFS(x+1,now,rem);
		while(!(rem%en[x+1]))
		{
			rem/=en[x+1];
			now*=en[x+1];
			DFS(x+1,now,rem);
		}
		exist[x+1]=false;
	}
	return;
}
int solve(int x)
{
	ans=1061109567;
	en[0]=0;
	for(int i=1;i<=pri[0];i++)if(!(x%(pri[i]-1)))en[++en[0]]=pri[i];
	memset(exist,false,sizeof(exist));
	DFS(0,1,x);
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n;
	pre_calc();
	for(int i=1;scanf("%d",&n)!=-1&&n;i++)
		printf("Case %d: %d %d\n",i,n,solve(n));
	fclose(stdin);
	fclose(stdout);
	return 0;
}


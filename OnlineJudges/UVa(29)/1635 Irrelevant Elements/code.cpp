/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-05	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,num[100050],pri[100050],en[100050];
int ans[100050];
bool exist[100050];
void pre()
{
	memset(exist,true,sizeof(exist));
	int limit=ceil(sqrt(m));
	for(int i=2;i<=limit;i++)
	{
		if(exist[i])pri[++pri[0]]=i;
		for(int j=1;j<=pri[0]&&i*pri[j]<=100000;j++)
		{
			exist[i*pri[j]]=false;
			if(!(i%pri[j]))break;
		}
	}
	return;
}
void solve()
{
	pre();
	memset(exist,true,sizeof(exist));
	int x=m,me,e;
	for(int i=1;i<=pri[0]&&x>1;i++)
	{
		if(!(x%pri[i]))
		{
			en[++en[0]]=pri[i];
			while(!(x%pri[i]))x/=pri[i];
		}
	}
	if(x>1)en[++en[0]]=x;
	for(int i=1;i<=en[0];i++)
	{
		x=m;
		me=e=0;
		while(!(x%en[i]))x/=en[i],me++;
		for(int j=1;j<n;j++)
		{
			//if(!exist[j])continue;
			x=n-j;
			while(!(x%en[i]))x/=en[i],e++;
			x=j;
			while(!(x%en[i]))x/=en[i],e--;
			if(e<me)exist[j]=false;
		}
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	while(scanf("%d%d",&n,&m)!=-1)
	{
		ans[0]=pri[0]=en[0]=0;
		solve();
		for(int i=1;i<n;i++)if(exist[i])ans[++ans[0]]=i;
		printf("%d\n",ans[0]);
		if(ans[0])printf("%d",ans[1]+1);
		for(int i=2;i<=ans[0];i++)printf(" %d",ans[i]+1);
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


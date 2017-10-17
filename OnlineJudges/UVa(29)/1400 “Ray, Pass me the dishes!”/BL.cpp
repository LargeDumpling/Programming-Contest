/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long num[500050];
int n,m,al,ar;
void get_ans(int a,int b)
{
	int ans,id=a;
	al=a;ar=a+1;ans=num[ar]-num[al];
	for(int i=a+1;i<=b;i++)
	{
		if(num[i]-num[id]>ans)
		{
			ans=num[i]-num[id];
			al=id;ar=i;
		}
		if(num[i]<num[id])id=i;
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	int a,b;
	for(int cAse=1;scanf("%d%d",&n,&m)!=-1;cAse++)
	{
		printf("Case %d:\n",cAse);
		for(int i=2;i<=n+1;i++)scanf("%lld",&num[i]);
		for(int i=1;i<=n+1;i++)num[i]+=num[i-1];
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			b++;
			get_ans(a,b);
			printf("%d %d\n",al,ar-1);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


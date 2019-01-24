/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-01-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1050;
int n,a[MAXN];
int ans,cost=2147483647;
int calc(int t)
{
	int sum=0;
	for(int i=1;i<=n;i++)
		if(a[i]<t-1)
			sum+=t-1-a[i];
		else if(t+1<a[i])
			sum+=a[i]-t-1;
	return sum;
}
int main()
{
	int tem_cost;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int t=1;t<=100;t++)
	{
		tem_cost=calc(t);
		if(tem_cost<cost)
		{
			ans=t;
			cost=tem_cost;
		}
	}
	printf("%d %d",ans,cost);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


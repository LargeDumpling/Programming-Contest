/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2019-04-06	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1050;
int n,h;
int num[MAXN],tem[MAXN];
bool check(int x)
{
	int cnt=0;
	for(int i=1;i<=x;i++)
		tem[i]=num[i];
	sort(tem+1,tem+x+1);
	for(int i=x;i>0;i-=2)
	{
		if(h<cnt+tem[i])
			return false;
		cnt+=tem[i];
	}
	return true;
}
int main()
{
	int l,mid,r;
	scanf("%d%d",&n,&h);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	l=0; r=n+1;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	printf("%d\n",l);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


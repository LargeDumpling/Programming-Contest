/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=300050;
int k,n,m;
int num[MAXN],ans[MAXN],cnt;
void print()
{
	if(ans[0]!=n) printf("-1");
	else for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return;
}
int main()
{
	scanf("%d%d%d",&k,&n,&m);
	bool flag=true;
	ans[0]=0;
	cnt=n-k;
	num[0]=1;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&num[i]);
		if(num[i]==-1)  num[i]=num[i-1];
		if(num[i]<num[i-1]) flag=false;
	}
	if(flag==false) print();
	else if(cnt<0) print();
	else if(cnt==0)
	{
		ans[0]=n;
		for(int i=1;i<=n;i++)
			ans[i]=num[i];
		print();
	}
	else
	{
		for(int i=1,j;i<=k;i++)
		{
			j=m;
			while(cnt&&num[i]<j)
			{
				ans[++ans[0]]=j;
				cnt--;
				j--;
			}
			ans[++ans[0]]=num[i];
		}
		print();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


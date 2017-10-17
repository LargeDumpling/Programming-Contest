/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-05	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int m,lenth;
char tex[40050];
bool check(int x)
{
	int flag;
	for(int i=0;i<=lenth-x;i++)
	{
		flag=0;
		for(int j=i,k;j<=lenth-x;j++)
		{
			for(k=0;k<x&&tex[i+k]==tex[j+k];k++);
			if(k==x) flag++;
		}
		if(flag>=m) return true;
	}
	return false;
}
int calc_pos(int x)
{
	int cnt=0;
	for(int i=lenth-x;i>=0;i--)
	{
		cnt=0;
		for(int j=i,k;j>=0;j--)
		{
			for(k=0;k<x&&tex[i+k]==tex[j+k];k++);
			if(k==x) cnt++;
		}
		if(cnt>=m) return i;
	}
	return -1;
}
void solve()
{
	int l,r,mid;
	if(!check(1))puts("none");
	else
	{
		l=0; r=lenth+1;
		while(l<r-1)
		{
			mid=(l+r)>>1;
			if(check(mid)) l=mid;
			else r=mid;
		}
		printf("%d %d\n",l,calc_pos(l));
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	while(scanf("%d",&m)!=-1&&m)
	{
		scanf("%s",tex);
		lenth=strlen(tex);
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


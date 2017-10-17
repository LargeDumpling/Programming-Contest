/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-05-08	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int M=8196;
const int MAXN=5050;
int n,kol[MAXN],num[MAXN],ans[MAXN];
int data[M<<1];
void clear()
{
	for(int i=0;i<n;i++)
		data[M+i]=i+1;
	memset(num,0,sizeof(num));
	return;
}
void add(int pos)
{
	for(pos=(pos+M-1)>>1;pos;pos>>=1)
		data[pos]=num[data[pos<<1]]>=num[data[pos<<1|1]]
			?data[pos<<1]:data[pos<<1|1];
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&kol[i]);
	for(int l=1;l<=n;l++)
	{
		clear();
		for(int r=l;r<=n;r++)
		{
			num[kol[r]]++;
			add(kol[r]);
			ans[data[1]]++;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}


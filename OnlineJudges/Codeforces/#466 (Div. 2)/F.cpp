/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
#define low(x) (x&-x)
using namespace std;
const int MAXN=100050;
struct jz
{
	int op,c1,c2;
}Q[MAXN];
int n,q;
int num[MAXN],root[MAXN],h[MAXN<<1],sz=0;
int son[MAXN*350][2];
set<int> data[MAXN*350];
void change(int i,int L,int R,int x,int del)
{
	int *u;
	while(i<h[0])
	{
		u=&root[i];
		if(*u==0) *u=++sz;
	}
}
int main()
{
	scanf("%d%d",&n,&q);
	h[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		h[++h[0]]=num[i];
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&Q[i].op,&Q[i].c1,&Q[i].c2);
		if(Q[i].op==2)
			h[++h[0]]=Q[i].c2;
	}
	sort(h+1,h+h[0]+1);
	h[0]=unique(h+1,h+h[0]+1)-h-1;
	for(int i=1;i<=n;i++)
	{
		num[i]=lower_bound(h+1,h+h[0]+1,num[i])-h;
		change(i,1,h[0],num[i],1);
	}
	for(int i=1;i<=q;i++)
		if(Q[i].op==2)
			Q[i].c2=lower_bound(h+1,h+h[0]+1,Q[i].c2)-h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


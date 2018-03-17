/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-10	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=300050;
const int MAXL=30;
int ch[MAXN*MAXL][2],size[MAXN*MAXL],val[MAXN*MAXL],sz=0;
int n,A[MAXN],P[MAXN];
void insert(int x)
{
	int u=0;
	for(int i=MAXL-1;0<=i;u=ch[u][(x>>(i--))&1])
	{
		size[u]++;
		if(!ch[u][(x>>i)&1])
			ch[u][(x>>i)&1]=++sz;
	}
	size[u]++;
	val[u]=x;
	return;
}
int query(int x)
{
	int u=0,d;
	for(int i=MAXL-1;0<=i;u=ch[u][d],i--)
	{
		size[u]--;
		d=(x>>i)&1;
		if(!ch[u][d]||size[ch[u][d]]==0)
			d^=1;
	}
	size[u]--;
	return x^val[u];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&P[i]);
		insert(P[i]);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",query(A[i]));
	fclose(stdin);
	fclose(stdout);
	return 0;
}


/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,C,ans;
typedef unsigned long long ull;
struct jp
{
	const static unsigned Hmod=int(1e6)+7;
	struct node
	{
		ull x;
		int cnt;
		node* next;
		node(){}
		node(ull x,int cnt,node *next):x(x),cnt(cnt),next(next){}
	}pool[15000],*fir[Hmod],*pos;
	jp()
	{
		pos=pool;
	}
	int query(ull x)
	{
		unsigned r=x%Hmod;
		for(node *p=fir[r];p;p=p-next)if(p->x==x)return p->cnt++;
		return (fir[r]=new(pis++) node(x,0,fir[r]))->cnt++;
	}
}vis;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	char tex[205];
	ans=0;
	scanf("%d%d%d",&n,&m,&C);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",tex);
		sUm(tex);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


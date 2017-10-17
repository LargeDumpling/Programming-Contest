/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-27	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct jp
{
	int a,b,c;
	bool operator<(const jp &x)const { return c<x.c; }
}e[100050];
int n,m,f[40050];
int find(int x)
{
	while(f[x]!=f[f[x]]) f[x]=f[f[x]];
	return f[x];
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int x,y;
	scanf("%d%d",&n,&m);
	for(int i=(n<<1);i;i--) f[i]=i;
	for(int i=1;i<=m;i++) scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
	sort(e+1,e+m+1);
	for(int i=m;i;i--)
	{
		x=find(e[i].a);
		y=find(e[i].b);
		if(x==y)
		{
			printf("%d",e[i].c);
			goto end;
		}
		f[x]=find(e[i].b+n);
		f[y]=find(e[i].a+n);
	}
	putchar('0');
	end:
		fclose(stdin);
		fclose(stdout);
		return 0;
}


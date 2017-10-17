#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define low(x) (x&-x)
using namespace std;
struct jp
{
	int x;
	int y;
	jp()
	{
		x=y=35000;
	}
}star[15500];
int n,num[15500],f[15500],mn=0;
bool com_x(jp a,jp b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}
bool com_y(jp a,jp b)
{
	if(a.y==b.y)
		return a.x<b.x;
	return a.y<b.y;
}
int query(int x)
{
	int sum=0;
	while(x)
	{
		sum+=f[x];
		x-=low(x);
	}
	return sum;
}
void add(int x)
{
	while(x<=mn)
	{
		f[x]++;
		x+=low(x);
	}
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&star[i].x,&star[i].y);
	sort(star+1,star+n+1,com_y);
	for(int i=1;i<=n;i++)
		if(star[i].y!=star[i-1].y)
			star[i].y=++mn;
		else
			star[i].y=mn;
	sort(star+1,star+n+1,com_x);
	for(int i=1;i<=n;i++)
	{
		num[query(star[i].y)]++;
		add(star[i].y);
	}
	for(int i=0;i<n;i++)
		printf("%d\n",num[i]);
	return 0;
}


/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-27	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int n;
struct jp
{
	int l,r;
	jp(int a=0,int b=0):l(a),r(b){}
	bool operator<(const jp X)const{return l==X.l?r<X.r:l<X.l;}
};
map<int,jp>sx,sy;
set<int>ex,ey;
void updata_x(int x,int L,int R)
{
	if(!sx.count(x))sx[x]=jp(L,R);
	else
	{
		sx[x].l=min(sx[x].l,L);
		sx[x].r=max(sx[x].r,R);
	}
	return;
}
void update_y(int x,int L,int R)
{
	if(!sy.count(x))sy[x]=jp(L,R);
	else
	{
		sy[x].l=min(sy[x].l,L);
		sy[x].r=min(sy[x].r,R);
	}
	return;
}
int fx(int l,int r)
{
	return ex.upper_bound(r)-ex.upper_bound(l-1);
}
int fy(int l,int r)
{
	return ey.upper_bound(r)-ey.upper_bound(l-1);
}
int main()
{
	int x1,y1,x2,y2;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		x1+=(1<<30);
		y1+=(1<<30);
		x2+=(1<<30);
		y2+=(1<<30);
		if(x1==x2)
		{
			if(y1>y2)swap(y1,y2);
			ex.insert(x1);
			update_x(x,y1,y2);
		}
		else if(y1==y2)
		{
			if(x1>x2)swap(x1,x2);
			ey.insert(y1);
			update_y(y,x1,x2);
		}
	}
	map<int,jp>::iterator it;
	long long ans=0;
	for(it=sx.begin();it!=sx.end();it++)
		ans=it.r-it.l+1;
	return 0;
}


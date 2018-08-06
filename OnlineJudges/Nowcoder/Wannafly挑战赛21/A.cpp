/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-03	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1000050;
struct jz
{
	int x,y;
}P[MAXN];
int T_T,n;
void read1n(int &x)
{
	char ch; bool neg=false;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
		if(ch=='-') neg=true;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	if(neg) x=-x;
	return;
}
bool check()
{
	int minx,maxx,miny,maxy;
	minx=maxx=P[1].x;
	miny=maxy=P[1].y;
	for(int i=2;i<=n;i++)
	{
		minx=min(minx,P[i].x);
		maxx=max(maxx,P[i].x);
		miny=min(miny,P[i].y);
		maxy=max(maxy,P[i].y);
	}
	for(int i=1;i<=n;i++)
		if((P[i].x==minx||P[i].x==maxx)&&(P[i].y==miny||P[i].y==maxy))
			return true;
	return false;
}
int main()
{
	int nx,ny;
	bool flag;
	read1n(T_T);
	while(T_T--)
	{
		flag=false;
		read1n(n);
		for(int i=1;i<=n;i++)
		{
			read1n(P[i].x);
			read1n(P[i].y);
		}
		flag=check();
		if(!flag)
		{
			for(int i=1;i<=n;i++)
			{
				ny=P[i].x+P[i].y;
				nx=P[i].y-P[i].x;
				P[i].x=nx;
				P[i].y=ny;
			}
			flag=check();
		}
		if(flag) puts("Yes");
		else puts("No");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


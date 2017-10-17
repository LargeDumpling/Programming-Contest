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
#include<ctime>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
struct jp
{
	ull d[3];
	jp(ull a=0,ull b=0,ull c=0)
	{
		ull v[]= {a, b, c};
		memcpy(d,v,sizeof v);
	}
	bool operator==(const jp x)const {return memcmp(d, x.d, sizeof d) == 0;}
	jp operator-(const jp x)const {
		return jp(d[0]-x.d[0],d[1]-x.d[1],d[2]-x.d[2]);
	}
	template<typename Ty>
	jp operator*(Ty x) { return jp(d[0]*x,d[1]*x,d[2]*x); }
	jp operator*(jp x) { return jp(d[0]*x.d[0],d[1]*x.d[1],d[2]*x.d[2]);}
	bool operator<(const jp x)const
	{
		if(d[0]==x.d[0])return d[1]==x.d[1]?d[2]<x.d[2]:d[1]<x.d[1];
		return d[0]<x.d[0];
	}
	template<typename Ty>
	jp operator+(const Ty x)const{return jp(d[0]+x,d[1]+x,d[2]+x);}
}H[40050],P[40050],t[40050];
char T[40050];
int m,lenth,wsa[40050],pos;
void pre()
{
	P[0]=jp(1,1,1);
	P[1]=jp(23,29,31);
	for(int i=2;i<40050;i++) P[i]=P[i-1]*P[1];
	return;
}
void init()
{
	scanf("%s",T);
	lenth=strlen(T);
	H[lenth]=jp(0,0,0);
	for(int i=lenth-1;i>=0;i--) H[i]=H[i+1]*P[1]+(T[i]-97);
	return;
}
bool cnmp(int a,int b) { return t[a]==t[b]?a<b:t[a]<t[b]; }
bool check(int x)
{
	int c=0,r;
	pos=-1;
	for(int i=0;i<lenth-x+1;i++)
	{
		wsa[i]=i;
		t[i]=H[i]-H[i+x]*P[x];
	}
	sort(wsa,wsa+lenth-x+1,cnmp);
	for(r=0;r<lenth-x+1;r++)
	{
		if(!r||!(t[wsa[r]]==t[wsa[r-1]]))c=0;
		if(++c>=m)pos=max(pos,wsa[r]);
	}
	return pos>=0;
}
void solve()
{
	if(!check(1))puts("none");
	else
	{
		int l,r,mid;
		l=1,r=lenth+1;
		while(l<r-1)
		{
			mid=(l+r)>>1;
			if(check(mid)) l=mid;
			else r=mid;
		}
		//if(l==lenth)printf("%d 0\n",l);
		check(l);
		printf("%d %d\n",l,pos);
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("hash.out","w",stdout);
	pre();
	while(scanf("%d",&m)!=-1&&m)
	{
		init();
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


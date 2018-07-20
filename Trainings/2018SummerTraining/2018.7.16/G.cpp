//LargeDumpling
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const double Pi=acos(-1.);
char V[5]="ABCD";
struct jz
{
	char X,Y,Z;
	double d,t;// t<=2*Pi/3
	void pre_cmp()
	{
		if(X<Y) swap(X,Y);
		if(X<Z) swap(X,Z);
		if(Y<Z) swap(Y,Z);
		return;
	}
	bool operator==(const jz &A,const jz &B)const
	{
		return A.X==B.X&&A.Y==B.Y&&A.Z==B.Z;
	}
};
jz calc(jz st,int len)
{
	jz ed;
	while(true)
	{
		for(int i=0;i<4;i++)
			if(st[i].X!=V[i]&&st[i].Y!=V[i]&&st[i].Z!=V[i])
				ed.Z=V[i];
		double nd,l,r=Pi*2/3-st.t;
		nd=d*sin(st.t)/sin(r);
		if(nd<=1)
		{//XZ
			l=d*sin(Pi/3)/sin(r);
			if(len<=l)
			{ // stop
				ed=st;
				break;
			}
			else
			{
				ed.X=st.X;
				ed.Y=st.Z;
				ed.d=nd;
				ed.t=Pi-r;
				if(2*Pi<3*ed.t)
				{
					swap(ed.X,ed.Y);
					ed.d=1-ed.d;
					ed.t=Pi-ed.t;
				}
				st=ed;
				len-=l;
			}
		}
		else
		{//YZ
			r=st.t-Pi/3;
			l=(1-d)*sin(Pi/3)/sin(r);
			nd=(1-st.d)*sin(st.t)/sin(r);
			if(len<=l)
			{ // stop
				ed=st;
				break;
			}
			else
			{
				ed.X=st.Z;
				ed.Y=st.Y;
				ed.d=nd;
				ed.t=Pi-r;
				if(2*Pi<3*ed.t)
				{
					swap(ed.X,ed.Y);
					ed.d=1-ed.d;
					ed.t=Pi-ed.t;
				}
				st=ed;
				len-=l;
			}
		}
	}
	return ed;
}
int main()
{
	return 0;
}



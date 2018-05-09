/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-04-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,s;
int h,m,lh,lm,ah,am,th,tm;
int main()
{
	scanf("%d%d",&n,&s);
	lh=lm=ah=am=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&h,&m);
		if(lm==-1&&lh==-1)
		{
			th=h;
			tm=m-1;
			tm+=th*60;
			if(s+1<=tm)
			{
				ah=am=0;
				break;
			}
		}
		else
		{
			th=h-lh;
			tm=m-lm-1;
			tm+=th*60;
			if(2*s+1<=tm)
			{
				am=lm+s+1;
				ah=lh+am/60;
				am%=60;
				break;
			}
		}
		lh=h;
		lm=m;
	}
	if(ah==-1&&am==-1)
	{
		am=lm+s+1;
		ah=lh+am/60;
		am%=60;
	}
	printf("%d %d",ah,am);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


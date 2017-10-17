/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int x,y,x0,yy0,len,rem;
char comd[100050];
bool exist[505][505];
int main()
{
	memset(exist,true,sizeof(exist));
	scanf("%d%d%d%d",&x,&y,&x0,&yy0);
	rem=x*y;
	scanf("%s",comd); len=strlen(comd);
	putchar('1');
	exist[x0][yy0]=false;
	for(int i=0;i<len-1;i++)
	{
		putchar(' ');
		switch(comd[i])
		{
			putchar(' ');
			case 'U':
				if(x0>1) x0--;
				break;
			case 'D':
				if(x0<x) x0++;
				break;
			case 'L':
				if(yy0>1) yy0--;
				break;
			case 'R':
				if(yy0<y) yy0++;
				break;
		}
		if(exist[x0][yy0])
		{
			exist[x0][yy0]=false;
			rem--;
			putchar('1');
		}
		else putchar('0');
	}
	printf(" %d",rem-1);
	return 0;
}


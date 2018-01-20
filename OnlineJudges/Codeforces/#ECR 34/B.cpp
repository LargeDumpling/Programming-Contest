/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-12-12	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int h1,a1,c1,h2,a2,x,y;
int main()
{
	scanf("%d%d%d%d%d",&h1,&a1,&c1,&h2,&a2);
	x=h2/a1;
	if(x*a1<h2) x++;
	h1-=(x-1)*a2;
	for(y=0;h1<=0;h1+=(c1-a2),y++);
	printf("%d\n",x+y);
	for(int i=1;i<=y;i++)
		puts("HEAL");
	for(int i=1;i<=x;i++)
		puts("STRIKE");
	fclose(stdin);
	fclose(stdout);
	return 0;
}


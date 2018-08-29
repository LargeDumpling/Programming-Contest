/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-28	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	if(n<=5*m)
	{
		for(int i=0;i<m;i++) putchar('5');
		putchar('\n');
		for(int i=0;i<m;i++) putchar('5');
	}
	else
	{
		for(int i=0;i<2230;i++)
		{
			if(i==2229) putchar('2');
			else putchar(i<m?'5':'1');
		}
		putchar('\n');
		for(int i=0;i<2230;i++)
		{
			if(i==m-1) putchar('4');
			else putchar(i<m?'5':'8');
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


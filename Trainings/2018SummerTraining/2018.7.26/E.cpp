/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-26	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int st[35];
void write1n(int x)
{
	if(!x) st[st[0]=1]=0;
	else for(st[0]=0;x;x/=10)
		st[++st[0]]=x%10;
	while(st[0])
		putchar(st[st[0]--]+'0');
	return;
}
int main()
{
	for(int i=0;i<=100;i++)
	{
		write1n(i);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


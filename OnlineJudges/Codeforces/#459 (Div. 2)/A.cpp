/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
bool exist[1050];
void pre_calc()
{
	int a=0,b=1,t;
	while(b<=1000)
	{
		t=a+b;
		exist[a=b]=true;
		b=t;
	}
	return;
}
int main()
{
	memset(exist,false,sizeof(exist));
	pre_calc();
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		if(exist[i]) putchar('O');
		else putchar('o');
	fclose(stdin);
	fclose(stdout);
	return 0;
}


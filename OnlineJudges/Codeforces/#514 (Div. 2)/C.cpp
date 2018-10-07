/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-05	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
void print(int x,int mul)
{
	if(x==1)
	{
		printf("%d",mul);
		return;
	}
	int num[2]={x/2,x/3};
	if(num[0]>num[1])
	{
		for(int i=1;i<=x-num[0];i++)
			printf("%d ",mul);
		print(x/2,mul*2);
	}
	else
	{
		for(int i=1;i<=x-num[1];i++)
			printf("%d ",mul);
		print(x/3,mul*3);
	}
	return;
}
int main()
{
	scanf("%d",&n);
	print(n,1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


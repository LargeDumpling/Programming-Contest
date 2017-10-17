/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-07	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char tex[10050];
int lenth;
bool check(int x)
{
	for(int i=0;i<x;i++)
		for(int j=x;j<lenth;j+=x)
			if(tex[i]!=tex[i+j])return false;
	return true;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	while(scanf("%s",tex)!=-1)
	{
		lenth=strlen(tex);
		for(int i=1;i<=lenth;i++) if(!(lenth%i)&&check(i))
		{
			printf("%d\n",lenth/i);
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


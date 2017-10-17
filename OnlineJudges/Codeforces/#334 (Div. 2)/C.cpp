/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,aNs;
char tex[100050];
int main()
{
	scanf("%d%s",&n,tex);
	aNs=0;
	for(int i=0;i<n;i++) if(tex[i]!=tex[i-1]) aNs++;
	aNs=min(aNs+2,n);
	printf("%d",aNs);
	return 0;
}


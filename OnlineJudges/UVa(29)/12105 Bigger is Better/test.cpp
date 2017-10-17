/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-10	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int m=12;
		for(int j=0;j<10;j++)
	for(int i=0;i<m;i++)
			printf("%d*10+%d=%d\n",i,j,(i*10+j)%m);
	return 0;
}


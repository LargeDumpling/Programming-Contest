/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-16	File created.
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
	int n=4;
	for(int n=2;n<=16;n<<=1)
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				printf("%2d ",i^j);
			putchar('\n');
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


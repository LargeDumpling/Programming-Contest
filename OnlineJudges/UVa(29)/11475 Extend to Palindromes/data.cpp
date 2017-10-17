/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-08	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int main()
{
	freopen("code.in","w",stdout);
	srand(time(NULL));
	int T=100;
	while(T--)
	{
		int lenth=100000;
		while(lenth--) putchar(rand()%26+'a');
		putchar('\n');
	}
	fclose(stdout);
	return 0;
}


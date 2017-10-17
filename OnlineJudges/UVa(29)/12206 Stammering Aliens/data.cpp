/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-06	File created.
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
	int T=rand()%100+1;
	for(int i=0;i<T;i++)
	{
		int n=rand()%1000+1,lenth=rand()%39000+n;
		printf("%d\n",n);
		for(int i=0;i<lenth;i++) putchar(rand()%26+'a');
		putchar('\n');
	}
	putchar('0');
	fclose(stdout);
	return 0;
}


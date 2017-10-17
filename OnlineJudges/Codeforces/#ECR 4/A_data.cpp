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
	freopen("A.in","w",stdout);
	srand(time(NULL));
	int n=rand()%99+2,a,b;
	a=rand()%(n-1)+2; b=rand()%(n-1)+2;
	printf("%d %d %d\n",n,a,b);
	for(int i=1;i<=n;i++) putchar(rand()%26+'a');
	fclose(stdout);
	return 0;
}


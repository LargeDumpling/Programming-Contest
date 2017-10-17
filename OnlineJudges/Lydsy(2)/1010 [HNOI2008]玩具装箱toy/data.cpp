/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main(int argc,char *argv[])
{
	freopen("code.in","w",stdout);
	int x; sscanf(argv[1],"%d",&x); srand(x);
	int n=rand()%5+1,l=rand()%5+1;
	printf("%d %d\n",n,l);
	while(n--)
		printf("%d\n",rand()%5+1);
	fclose(stdout);
	return 0;
}


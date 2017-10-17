/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-09	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
int main(int argc,char *argv[])
{
	int x;sscanf(argv[1],"%d",&x); srand(x);
	freopen("code.in","w",stdout);
	char filename[]="codex.in";
	int n,m,t=rand()%1000+1;
	for(int i=1;i<=100;i++)
		for(int j=0;j<=3000;j++)
			printf("%d %d\n",i,j);
	fclose(stdout);
	return 0;
}


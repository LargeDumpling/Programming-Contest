/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main(int argc,char* argv[])
{
	int x; sscanf(argv[1],"%d",&x); srand(x);
	freopen("in.txt","w",stdout);
	printf("%d\n",100000);
	for(int i=1;i<=100000;i++)
		printf("%d\n",i);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


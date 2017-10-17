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
int main(int argc,char *argv[])
{
	freopen("code.in","w",stdout);
	int x; sscanf(argv[1],"%d",&x); srand(x);
	int n=rand()%10+2;
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
	{
		do{ x=rand()%n+1; }while(i==x);
		printf("%d %d\n",rand()%10+1,x);
	}
	fclose(stdout);
	return 0;
}


/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-01	File created.
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
	freopen("code.in","w",stdout);
	int x; sscanf(argv[1],"%d",&x);
	srand(x);
	int n1=30000,n2=30000;
	//n1=rand()%100+1;
	//n2=rand()%100+1;
	printf("%d %d\n",n1,n2);
	n1+=n2;
	while(n1--) printf("%d %d %d\n",rand()%200+1,rand()%200+1,rand()%200+1);
	fclose(stdout);
	return 0;
}

